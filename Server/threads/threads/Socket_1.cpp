#include "framework.h"

#pragma comment(lib,"ws2_32.lib")

using namespace std;

// Socket : ��Ʈ��ũ ���α׷��ֿ���, ���� ����� ����.
// - ip �ּ� : ����Ʈ �ּ�
// - ��Ʈ�ѹ� : ����Ʈ ��ȣ��
// - ��������(Protocol) :  ��� �Ծ�


// 0. ����
// IP�ּ� : IPV4, IPV6 ���� ������ ����
// UDP, TCP/IP ����

// ���� ���� Ŭ���̾�Ʈ.
int main()
{
	// ������ ����(����) �ʱ�ȭ
	// ���� ���� wsaData�� ä���ִ´�.
	
	WSADATA wsaData;
	if (::WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		return 0;

	// 1. Client Socket �����
	SOCKET clientSocket = ::socket(AF_INET, SOCK_STREAM, 0);
	{
		int32 errorCode = ::WSAGetLastError();
		cout << "Socket Error : " << errorCode << endl;

		return 0;
	}

	// 2. Server ����(IP, ��Ʈ��ȣ)
	SOCKADDR_IN serverAddr;
	::memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET; // IPv4
	::inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr); // 127.0.0.1 :  �ڱ� pc �ּ�
	serverAddr.sin_port = ::htons(7777); //�򿣵�� ǥ������� �ٲ�

	// 3. ����
	if (::connect(clientSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
	{
		int32 errorCode = ::WSAGetLastError();
		cout << "Socket Error : " << errorCode << endl;

		return 0;
	}

	cout << "Connet To Server!" << endl;

	while (true)
	{

	}

	::closesocket(clientSocket);
	::WSACleanup();


	return 0;
}