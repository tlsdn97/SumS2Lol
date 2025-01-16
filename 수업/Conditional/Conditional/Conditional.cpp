#include <iostream>

using namespace std;

// 분기문
// if(조건문)
//  {
// 실행문
// }
// else if(조건절)
// {}
// {}
// else
// {}

//swicth (정수형) .. 정수형 아니면 쓸수가 없다.
// {
// case :
// break;
// 
// defalut;
// }

// while (조건)
// {
//  실행문 
//	제어문
//	contiue
//	탈출(break)
// }

// for (초기화; 제어; 조건;)
// {
// contiue
// break;
// }

int main()
{
	int count = 0;
	while (true)
	{
		count++;
			if (count == 3)
				continue;

			cout << count << endl;
				if(count >= 10);
	}

	for (int i = 0; i < 10; i++)
	{
		if (i == 3)

			continue;
			cout << i << endl;
	}

	return 0;
}