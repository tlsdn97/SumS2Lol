#ifdef _DEBUG
#pragma comment(lib,"ServerCore\\Debug\\ServerCore.lib")
#else
#pragma comment(lib,"ServerCore\\Release\\ServerCore.lib")
#endif

#include "../ServerCore/pch.h"

int main()
{
	WSAData wsaData;
	if (::WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		return 0;

	// 1. Client Socket �����
	SOCKET clientSocket = ::socket(AF_INET, SOCK_STREAM, 0);
	if (clientSocket == INVALID_SOCKET)
	{
		int errorCode = ::WSAGetLastError();
		cout << "Socket Error : " << errorCode << endl;

		return 0;
	}

	u_long on = 1;
	if (::ioctlsocket(clientSocket, FIONBIO, &on) == INVALID_SOCKET)
	{
		return 0;
	}

	// 2. Server ����(IP, ��Ʈ��ȣ)
	SOCKADDR_IN serverAddr;
	::memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET; // IPv4
	inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr); // 127.0.0.1 : �ڱ� PC �ּ�
	serverAddr.sin_port = ::htons(7777); // �򿣵�� ǥ������� �ٲ�

	// 3. ����
		while (true)
		{
			int errorCode = ::WSAGetLastError();
			cout << "Socket Error : " << errorCode << endl;
			if (::connect(clientSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
			{
				if (::WSAGetLastError() == WSAEWOULDBLOCK)
				{
					continue;
				}

				if (::WSAGetLastError() == WSAEISCONN)
				{
					break;
				}

				cout << "Socket Error : " << endl;

				return 0;
			}
		}

	cout << "Connet To Server!!" << endl;

	while (true)
	{
		char sendBuffer[100] = "Hello world";
		char recvBuffer[1000];
		memset(recvBuffer, 0, sizeof(recvBuffer));


			if (::send(clientSocket, sendBuffer, sizeof(sendBuffer), 0) == SOCKET_ERROR)
			{
					if (::WSAGetLastError() == WSAEWOULDBLOCK)
					{
						continue;
					}

				break;
			}

			int32 recvLen = 0;
			if (recvLen = ::recv(clientSocket, recvBuffer, sizeof(recvBuffer), 0))
			{
				if (recvLen <= 0)
				{
					if (::WSAGetLastError() == WSAEWOULDBLOCK)
					{
						continue;
						break;
					}
				}
			}
	}

	// ���� �ݱ�
	::closesocket(clientSocket);
	::WSACleanup();

	return 0;
}
