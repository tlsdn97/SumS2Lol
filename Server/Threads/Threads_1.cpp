#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <thread>

using namespace std;

// ���� ����
// 1. �񵿱� ���α׷� , �ͺ��ŷ(�ϳ��� �Լ��� ���� ������ �ٸ� �Լ��� �����Ű�� ���ϴ� ��)
// 2. ȿ�������� ��������

void HelloThread()
{
	cout << "Hello Thread" << endl;
}

int main()
{
	std::thread t(&HelloThread);

	
	t.join();
	// join : t �� ���� ������ ���
	// joinable : join ��������
	// get_id : ������ ���̵�
	// detach : ������ �и�
	// hardware_concurrency : ���� ��밡���� ������ ����


	return 0;
}