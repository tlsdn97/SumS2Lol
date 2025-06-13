#include "framework.h"

using namespace std;

// TCP/IP
// ���ŷ �Լ�
// recv 
// send
// accept
// connect

// UDP
// �ͺ��ŷ �Լ�
// recvfrom
// sendto

// => ������������ Ŀ�η���Buffer �� ���� �� send or recv

// send... ���� Ŀ�ο��� send buffer�� �� á�����... ���
// ���� 5000���� �÷��̾ send �ҷ����ϴµ� ��á�ٸ� ��� �� ���ΰ�? ... =? �ͺ��ŷ

int main()
{

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

	// SO_KEEPALIVE => �ֱ������� ������ ������� Ȯ���ϴ� �ɼ�
	bool enable = true;
	::setsockopt(listener, SOL_SOCKET, SO_KEEPALIVE, (char*)&enable, sizeof(enable));

	LINGER linger;
	linger.l_onoff = 1;
	linger.l_linger = 5;
	// ������ �ϴ� ���� ������ �ϰ� ������ �����...(������ ���� ������Ŵ)
	::setsockopt(listener, SOL_SOCKET, SO_LINGER, (char*)(&linger), sizeof(linger));

	int32 recvBufferSize = 0;
	int32 optionLen = sizeof(recvBufferSize);
	::getsockopt(listener, SOL_SOCKET, SO_RCVBUF, (char*)(&recvBufferSize), &optionLen);
	cout << "Kenel Recv Buffer Size : " << recvBufferSize << endl;

	int32 sendBufferSize = 0;
	optionLen = sizeof(sendBufferSize);
	::getsockopt(listener, SOL_SOCKET, SO_SNDBUF, (char*)(&sendBufferSize), &optionLen);
	cout << "Kenel Send Buffer Size : " << sendBufferSize << endl;

	// SO_REUSEADDR
	// IP �ּ� �� ��Ʈ��ȣ�� ������ ���ΰ�?
	::setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, (char*)(&enable), sizeof(enable));

	// TCP_NODELAY ... ������ true
	// ������ ��Ҵٰ� �ѹ��� ���� : ���̱� �˰���
	// => ����: �����ð� ����
	// => ����: ���� ��Ŷ���� ������ ������ �� �߻��ϴ� ������� ����

	enable = true;
	::setsockopt(listener, IPPROTO_TCP, TCP_NODELAY, (char*)(&enable), sizeof(enable));

	return 0;
}