#include <iostream>

using namespace std;

#pragma region ������
//for (int i = 0; i < 9; i++)
//{
//	cin >> playerNum;
//	cout << playerNum << endl;
//	cout << computerNum << endl;
//
//	if (computerNum > playerNum)
//	{
//		cout << "computer ���ڰ� �� Ů�ϴ�" << endl;
//	}
//
//	else if (computerNum < playerNum)
//	{
//		cout << "playerNum ���ڰ� �� Ů�ϴ�" << endl;
//	}
//
//	else
//	{
//		cout << "�����Դϴ�.." << endl;
//
//	}
//
//}
#pragma endregion

int main()
{
	// ����
	srand(time(NULL));

	int playerNum = 0;
	int computerNum = rand() % 500 + 1;

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
			cout << "�����Դϴ�" << endl;
		}
		
		count++;


	}



	return 0;
}