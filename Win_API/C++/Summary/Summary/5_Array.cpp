#include <iostream>

using namespace std;


// 1. ��� ������ 3����
// ����� ���ÿ� �ʱ�ȭ (Ref)
// #define ��ũ��
// const
// enum
// 
// 2. ������ ����
// 3. �迭, �迭�� �������� �������

#define PI 3.141592f

// ������ ���
// ������
enum PlayerState
{
	IDLE = 5,
	RUN = 1,
	FALLING = 2,
	SLEEPING = (1 << 5),
};

// ������
// (�ڷ���)* (�����̸�): ������ ����
// (����) * (����) : ����������
// *(����) : ����������(��Ż������)
// (�ڷ���)** (�����̸�): ����������

// (����) & (����) : ��Ʈ And������
// (����) && (����) : And������
// (�ڷ���)& (�����̸�) = (�ʱ�ȭ) : Reference ����
// &(����) : �ּҿ�����

// ������ ������
// (ptr + 1) => �������� �ڷ����� ���� ������ ũ�Ⱑ �޶����� �ȴ�.

void PrintArr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
}

void PrintArr(int arr[][3], int size)
{
	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			cout << arr[y][x] << endl;
		}
	}
}

int main()
{
	// const (�ڷ���) : ������ => ���� �Ұ���
	const int temp = 1;
	PlayerState curState = PlayerState::IDLE;

	// const (�ڷ���)* const : �б�����
	// const �ڷ���& : �б� ����
	const int& ref = temp;
	const int* ptr = &temp;

	int aInt = 1;
	int* ptr2 = &aInt;
	cout << &aInt << endl;
	cout << (ptr2) << endl;
	cout << (ptr2 + 1) << endl;

	int arr[10]; // �����迭
	// [index] : �������ٿ�����
	//  []  []  []  []  [x]  []  []  []  []  []  []  []
	//  10  14  18  1C  20
	// - ���������ϴµ� �ɸ��� �ð����⵵ (���)

	for (int i = 0; i < 10; i++)
	{
		arr[i] = i;
	}


	ptr2 = &arr[0];
	PrintArr(&arr[0], 10);
	/*for (int i = 0; i < 10; i++)
	{
		cout << *(ptr2 + i) << endl;
		cout << ptr2[i] << endl;
		cout << arr[i] << endl;
	}*/

	int arr2[2][3] = { {1,2,3}, 
					   {4,5,6} };
	//PrintArr(&arr2[0][0], 6);
	PrintArr(arr2, 2);

	return 0;
}