#include <iostream>

using namespace std;

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}


void Sort(int arr[], int size)
{
	int temp = 0;
	for (int j = 0; j < size - 1; j++)
	{
		for (int i = 0; i < size - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				Swap(arr[i], arr[i + 1]);
			}
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



void Lotto(int* arr)
{
	int count = 0;
	while (count != 7)
	{
		int randvalue = 1 + rand() % 45;

		bool find = false;

		for (int j = 0; j < count; j++)
		{
			if (arr[j] == randvalue)
			{
				find = true;
			}
					break;
		}
		if (find == false)
		{
			arr[count] = randvalue;
			count++;
		}

	}
}

int main()
{
	srand(time(0));

	int lotto[7];
	Lotto(lotto);
	Sort(lotto, 7);

	for (int i = 0; i < 7; i++)
	{
		cout << lotto[i] << endl;
	}

	return 0;
}