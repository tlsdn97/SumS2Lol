#include <iostream>
#include <Windows.h>
#include <winSock2.h>
#include <MSWSock.h>
#include <WS2tcpip.h>

#pragma comment(lib,"ws2_32.lib")

using namespace std;

int main()
{
	cout << "hellow Server!" << endl;

	WSADATA wsaData;
	if (::WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		//Error
		return 0;
	}

	// 1. ListenSocket �����
	// ListenSocket : Ŭ���̾�Ʈ�� �޾��ִ� ������ ��Ȱ
	SOCKET listener = ::socket(AF_INET, SOCK_STREAM, 0);
	if (listener == INVALID_SOCKET)
	{
		// Error
		return 0;
	}

	// 2. Server(��)�� ���� ����
	SOCKADDR_IN serverAddr; // ���� ���� ����
	::memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET; // IPv4
	serverAddr.sin_addr.s_addr = ::htonl(INADDR_ANY); // �ϰ� �˾Ƽ� IP�ּ� ����, ���� �ּ�
	serverAddr.sin_port = ::htons(7777); //�򿣵�� ǥ������� �ٲ�

	if (::bind(listener, (SOCKADDR*)&serverAddr, sizeof(serverAddr) == SOCKET_ERROR))
	{
		// Error
		return 0;
	}

	// 4.����(Accept) �غ�
	if (::listen(listener, 10) == SOCKET_ERROR)
	{
		// Error
		return 0;
	}

	// 5. Accept
	while (true)
	{
		SOCKADDR_IN clientAddr;
		::memset(&clientAddr, 0, sizeof(clientAddr));
		int addrLen = sizeof(clientAddr);

		// listener���� ���� ��� ���� Ŭ���̾�Ʈ�� �޾Ƽ����� ����
		SOCKET clientSocket = ::accept(listener, (SOCKADDR*)&clientAddr, &addrLen);
		if (clientSocket == INVALID_SOCKET)
		{
			// Error
			return 0;
		}

		// Ŭ���̾�Ʈ ����
		char ipAddress[16];
		::inet_ntop(AF_INET, &clientAddr.sin_addr, ipAddress, sizeof(ipAddress));
		cout << "Client Connted !! Client IP :" << ipAddress << endl;
	}

	::closesocket(listener);
	::WSACleanup();

	return 0;
}