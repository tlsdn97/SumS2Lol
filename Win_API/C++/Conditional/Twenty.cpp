#include <iostream>

using namespace std;

// ��ȩ��
// 1. 1 ~500�� ���ڸ� ��ǻ�Ͱ� ����������. (����)
// 2. �÷��̾ ���� �Է���
// 3. �̸� 9�� �ݺ����� ���� �������
// 4. UP / DOWN

int main()
{
	// ����
	srand(time(NULL));

	int playerNum = 0;
	int computerNum = rand() % 500 + 1; // 0 ~ 499 + 1

	int count = 0;
	while (true)
	{
		cin >> playerNum;

		if (computerNum > playerNum)
		{
			cout << "UP" << endl;
		}
		else if (computerNum < playerNum)
		{
			cout << "DOWN" << endl;
		}
		else
		{
			cout << "�����Դϴ�." << endl;
			break;
		}

		count++;

		if (count >= 9)
			break;
	}


	return 0;
}