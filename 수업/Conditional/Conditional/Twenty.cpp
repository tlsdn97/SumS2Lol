#include <iostream>

using namespace std;

#pragma region 스무고개
//for (int i = 0; i < 9; i++)
//{
//	cin >> playerNum;
//	cout << playerNum << endl;
//	cout << computerNum << endl;
//
//	if (computerNum > playerNum)
//	{
//		cout << "computer 숫자가 더 큽니다" << endl;
//	}
//
//	else if (computerNum < playerNum)
//	{
//		cout << "playerNum 숫자가 더 큽니다" << endl;
//	}
//
//	else
//	{
//		cout << "정답입니다.." << endl;
//
//	}
//
//}
#pragma endregion

int main()
{
	// 시점
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
			cout << "정답입니다" << endl;
		}
		
		count++;


	}



	return 0;
}