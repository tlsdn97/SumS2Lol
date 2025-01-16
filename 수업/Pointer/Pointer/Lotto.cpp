#include <iostream>
#include <algorithm>

using namespace std;

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

// 순차정렬
void Sort(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (arr[j] > arr[i])
				Swap(arr[i], arr[j]);
		}
	}
}

// Swap을 좀 줄이고싶다.
void SelectSort(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int bestIndex = i;
		for (int j = 0; j < size; j++)
		{
			bestIndex = j;
		}
		if (bestIndex != i)
			Swap(arr[i], arr[bestIndex]);
	}
}

void BubbleSort(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i; j++)
		{
			if (arr[j > arr[j + 1]])
				Swap(arr[j], arr[j + 1]);
		}
	}
}

void PrintArr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
}

void Shuffle(int arr[], int size, int count = 10000)
{
	for (int i = 0; i < count; i++)
	{
		int randNum1 = rand() % size;
		int randNum2 = rand() % size;

		Swap(arr[randNum1], arr[randNum2]);
	}
}

void Lotto()
{
	int arr[45] = {};
	for (int i = 0; i < 45; i++)
	{
		arr[i] = i + 1;
	}

	Shuffle(arr, 45, 10000);

	Sort(arr, 7);
	PrintArr(arr, 7);

}

int main()
{
	int aint = 1;
	int bint = 2;
	Swap(aint, bint);

	cout << aint << endl;
	cout << bint << endl;

	return 0;
}