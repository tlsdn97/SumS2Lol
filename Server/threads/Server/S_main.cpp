
#ifdef _DEBUG
#pragma comment(lib,"ServerCore\\Debug\\ServerCore.lib")
#else
#pragma comment(lib,"ServerCore\\Release\\ServerCore.lib")
#endif

#include "../ServerCore/pch.h"

// Non Blocking = > 무한대기
// recvBuffer, sendBuffer 가 비어있는데도 불구하고 무한대기
// 
// Evnet 기반 Select
// => Event Select
// 운영체재한테, Event 를 받아서 처리하고싶다.


struct Session
{
	SOCKET socket = INVALID_SOCKET;
	char recvBuffer[1000] = {};
	char sendBuffer[1000] = "Hello Im Server";
	int32 recvBytes = 0;
	int32 sendBytes = 0;
};

int main()
{
	HelloLib();

	cout << "Hello Server!" << endl;

	WSADATA wsaData;
	if (::WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		// Error
		return 0;
	}

	// Non Blocking
	SOCKET listener = ::socket(AF_INET, SOCK_STREAM, 0);
	if (listener == INVALID_SOCKET)
	{
		// Error
		return 0;
	}


	u_long on = 1;
	if (::ioctlsocket(listener, FIONBIO, &on) == SOCKET_ERROR) // listener 소켓을 논블로킹 소켓으로 만드는 함수
	{
		return 0;
	}


	// 4. Listen 준비
	if (::listen(listener, 10) == SOCKET_ERROR)
	{
		cout << "Listen Error " << endl;
		return 0;
	}

	// 블로킹 소켓 프로그래밍
	// => 쓰레드가 한 함수에 멈춰있다.

	// 넌블로킹 소켓 프로그래밍 : 함수를 일단 반환 시키고, 나중에 반환값을 받을 수있다.
	// =>

	// 유저영역에서 Event객체를 만드고
	// => 운영체재 전달해서, 네트워크 이벤트 발생하면 통지
	// => 네트워크 이벤트 상태를 보고 결정


	// WSAEventSelect 기반 소켓 프로그래밍
	// (소켓 - 이벤트객체) 네트워크 이벤트를 감지

	// 이벤트 객체 관련 함수
	// 생성 : WSACreateEvent
	// 객체 : WSACloseEvent
	// (여러 이벤트) 신호감지 : WASaitforMultipleEvnets
	// 구체적인 이벤트 확인 : WSAEumNetworkEvents

	vector<WSAEVENT> wsaEvents;
	vector<Session> sessions;
	sessions.reserve(100);

	WSAEVENT listenEvent = WSACreateEvent();
	sessions.push_back(Session{ listener });

	if (::WSAEventSelect(listener, listenEvent, FD_ACCEPT | FD_CLOSE) == SOCKET_ERROR)
		return 0;

	while (true)
	{
		//  여러 Event 객체들이 신호상태 감지
		int32 index = ::WSAWaitForMultipleEvents(wsaEvents.size(), &wsaEvents[0], FALSE, WSA_INFINITE, FALSE);

		if (index == WSA_WAIT_FAILED)
			continue;

		index -= WSA_WAIT_EVENT_0; // 감지된 해당 인덱스

		// 구체적인 이벤트 알아내기
		WSANETWORKEVENTS networkEvents;
		if (::WSAEnumNetworkEvents(sessions[index].socket, wsaEvents[index], &networkEvents) == SOCKET_ERROR)
			continue;

		if (networkEvents.lNetworkEvents & FD_ACCEPT)
		{
			SOCKADDR_IN clientAddr;
			int32 addrLen = sizeof(clientAddr);
			SOCKET clientSocket = ::accept(listener, (SOCKADDR*)&clientAddr, &addrLen);

			if (clientSocket != INVALID_SOCKET)
			{
				WSAEVENT clientEvent = ::WSACreateEvent();
				sessions.push_back({ clientSocket });
				wsaEvents.push_back(clientEvent);


				if (::WSAEventSelect(clientSocket, clientEvent, FD_READ | FD_CLOSE) == SOCKET_ERROR)
					return 0;
			}

		}

		// Client Scoket, Event  체크
		if (networkEvents.lNetworkEvents & FD_READ || networkEvents.lNetworkEvents & FD_WRITE)
		{
			// Error Check
			if ((networkEvents.lNetworkEvents & FD_READ) && (networkEvents.iErrorCode[FD_READ_BIT]) != 0)
				continue;

			if ((networkEvents.lNetworkEvents & FD_WRITE) && (networkEvents.iErrorCode[FD_WRITE_BIT]) != 0)
				continue;

			// 어떤 소켓인지
			Session& session = sessions[index];

			// Recv
			// => FD_READ => Recv를 하지 않으면  FD_READ이벤트가 들어오지 않음.
			if (session.recvBytes == 0)
			{
				int32 recvLen = ::recv(session.socket, session.recvBuffer, 1000, 0);
				if (recvLen == SOCKET_ERROR && ::WSAGetLastError() != WSAEWOULDBLOCK)
				{
					continue;
				}

				if (recvLen < 0)
					continue;

				session.recvBytes = recvLen;
				cout << session.recvBuffer << endl;
			}

			if (session.recvBytes > session.sendBytes)
			{
				int32 sendLen = ::send(session.socket, session.sendBuffer, 1000, 0);
				if (sendLen == SOCKET_ERROR && WSAGetLastError() != WSAEWOULDBLOCK)
				{
					continue;
				}

				session.sendBytes += sendLen;
				cout << "Send Len : " << session.sendBytes << endl;

				if (session.recvBytes == session.sendBytes)
				{
					session.recvBytes = 0;
					session.sendBytes = 0;
				}
			}

			if (networkEvents.lNetworkEvents & FD_CLOSE)
			{
				// disconnet 
			}

		}
	}

	::closesocket(listener);
	::WSACleanup();

	return 0;
}