#include "framework.h"	

using namespace std;

// ���ŷ�Լ� , ����ŷ �Լ� ������ �� ����
// ���� ���α׷��� , �񵿱� ���α׷��� ������ �� ����

// TCP UDP
// ���� : 

// TCP : ��ȭ
// 1. ���� ������ �Ǿ��ִ��� Ȯ��
// 2. ������ ����Ǿ��ִ�. �� ���� �Ǿ��ִ����� ����
// 3. ��輺 x
// 4. �ӵ� UDP ���ؼ� ����
// EX) ����, ���� �����̵Ǿ��ִ��� �ŷ��ʿ��� �۾�

// UDP : ���� 
// 1. ���� ���Ῡ�ΰ� �ʿ䰡 ����.
// 2. ������ ����x �� ���� �Ǿ����� ����x
// 3. ��輺 o 
// 4. �ӵ� TCP ���ؼ� ����
// EX) ��Ʈ����, ����, ������ �������κ��� ���� �ӵ� �ʿ��� �۾�.

 
int Clinent_UDP()
{

	WSAData wsaData;
	if (::WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		return 0;

	// 1. Client Socket �����
	SOCKET clientSocket = ::socket(AF_INET, SOCK_DGRAM, 0);
	if (clientSocket == INVALID_SOCKET)
	{
		int errorCode = ::WSAGetLastError();
		cout << "Socket Error : " << errorCode << endl;

		return 0;
	}

	// 2. Server ����(IP, ��Ʈ��ȣ)
	SOCKADDR_IN serverAddr;
	::memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET; // IPv4
	inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr); // 127.0.0.1 : �ڱ� PC �ּ�
	serverAddr.sin_port = ::htons(7777); // �򿣵�� ǥ������� �ٲ�

	// 3. ����
	if (::connect(clientSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
	{
		int errorCode = ::WSAGetLastError();
		cout << "Socket Error : " << errorCode << endl;

		return 0;
	}

	cout << "Connet To Server!!" << endl;

	while (true)
	{
		char sendBuffer[100] = "Hello World!";

		for (int32 i = 0; i < 10; i++)
		{
			int32 resultCode = ::sendto(clientSocket, sendBuffer, sizeof(sendBuffer), 0,
				(SOCKADDR*)&serverAddr, sizeof(serverAddr));

			if (resultCode == SOCKET_ERROR)
			{
				int32 error = ::WSAGetLastError();
				cout << "Send Error" << endl;
				return 0;
			}
			cout << "Send Data Len : " << sizeof(sendBuffer) << endl;
		}
	}

	// ���� �ݱ�
	::closesocket(clientSocket);
	::WSACleanup();

	return 0;
}

int Srerver_UDP()
{
	cout << "Hello Server!" << endl;

	WSADATA wsaData;
	if (::WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		// Error
		return 0;
	}

	// 1. ListenSocket �����
	// ListenSocket : Ŭ���̾�Ʈ�� �޾��ִ� ������ ����
	SOCKET serverSocket = ::socket(AF_INET, SOCK_DGRAM, 0);
	if (serverSocket == INVALID_SOCKET)
	{
		// Error
		return 0;
	}

	// 2. Server(��) ���� ����
	SOCKADDR_IN serverAddr; // ���� ���� ����
	::memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET; // IPv4
	serverAddr.sin_addr.s_addr = ::htonl(INADDR_ANY); // �ϰ� �˾Ƽ� IP�ּ� ����, ���� �ּ�
	serverAddr.sin_port = ::htons(7777); // �򿣵�� ǥ������� �ٲ�

	if (::bind(serverSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
	{
		cout << "Binding Error" << endl;
		return 0;
	}

	// 5. Accept
	while (true)
	{
		while (true)
		{
			SOCKADDR_IN clientAddr;
			::memset(&clientAddr, 0, sizeof(clientAddr));
			int32 addrLen = sizeof(clientAddr);

			char recvBuffer[1000];

			memset(recvBuffer, 0, 1000);

			int recvLen = ::recvfrom(serverSocket, recvBuffer, sizeof(recvBuffer), 0,
				(SOCKADDR*)(&clientAddr), &addrLen);
			if (recvLen <= 0)
			{
				int32 errorCode = ::WSAGetLastError();
				cout << "Recv Error" << endl;

				return 0;
			}

			cout << "Recv Data : " << recvBuffer << endl;
			cout << "Recv Len : " << recvLen << endl;
		}
	}

	::closesocket(serverSocket);
	::WSACleanup();

	return 0;
}

int Server_TCP()
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

	// 2. Server ����(IP, ��Ʈ��ȣ)
	SOCKADDR_IN serverAddr;
	::memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET; // IPv4
	inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr); // 127.0.0.1 : �ڱ� PC �ּ�
	serverAddr.sin_port = ::htons(7777); // �򿣵�� ǥ������� �ٲ�

	// 3. ����
	if (::connect(clientSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
	{
		int errorCode = ::WSAGetLastError();
		cout << "Socket Error : " << errorCode << endl;

		return 0;
	}

	cout << "Connet To Server!!" << endl;

	while (true)
	{
		char sendBuffer[100] = "Hello World!";

		for (int32 i = 0; i < 10; i++)
		{
			int32 resultCode = ::send(clientSocket, sendBuffer, sizeof(sendBuffer), 0);

			if (resultCode == SOCKET_ERROR)
			{
				int32 error = ::WSAGetLastError();
				cout << "Send Error" << endl;
				return 0;
			}
			cout << "Send Data Len : " << sizeof(sendBuffer) << endl;
		}
	}

	// ���� �ݱ�
	::closesocket(clientSocket);
	::WSACleanup();

	return 0;
}

int Client_TCP()
{
	cout << "Hello Server!" << endl;

	WSADATA wsaData;
	if (::WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		// Error
		return 0;
	}

	// 1. ListenSocket �����
	// ListenSocket : Ŭ���̾�Ʈ�� �޾��ִ� ������ ����
	SOCKET listener = ::socket(AF_INET, SOCK_STREAM, 0);
	if (listener == INVALID_SOCKET)
	{
		// Error
		return 0;
	}

	// 2. Server(��) ���� ����(IP �ּ�, ��Ʈ��ȣ)
	SOCKADDR_IN serverAddr; // ���� ���� ����
	::memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET; // IPv4
	serverAddr.sin_addr.s_addr = ::htonl(INADDR_ANY); // �ϰ� �˾Ƽ� IP�ּ� ����, ���� �ּ�
	serverAddr.sin_port = ::htons(7777); // �򿣵�� ǥ������� �ٲ�(1~1000)

	// 3. Listener Setting
	if (::bind(listener, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
	{
		cout << "Binding Error" << endl;
		return 0;
	}

	// 4. Listen �غ�
	if (::listen(listener, 10) == SOCKET_ERROR)
	{
		cout << "Listen Error" << endl;
		return 0;
	}

	// 5. Accept
	while (true)
	{
		SOCKADDR_IN clientAddr;
		::memset(&clientAddr, 0, sizeof(clientAddr));
		int32 addrLen = sizeof(clientAddr);

		char recvBuffer[1000]; // �������� Recv����...<-> Ŀ�η��� Recv����, Socket Recv Buffer

		memset(recvBuffer, 0, 1000);

		SOCKET clientSocket = ::accept(listener, (SOCKADDR*)&clientAddr, &addrLen);
		if (clientSocket == INVALID_SOCKET)
		{
			return 0;
		}

		while (true)
		{
			int recvLen = ::recv(clientSocket, recvBuffer, sizeof(recvBuffer), 0);
			if (recvLen <= 0)
			{
				int32 errorCode = ::WSAGetLastError();
				cout << "Recv Error" << endl;

				return 0;
			}

			cout << "Recv Data : " << recvBuffer << endl;
			cout << "Recv Len : " << recvLen << endl;
		}
	}

	::closesocket(listener);
	::WSACleanup();

	return 0;
}