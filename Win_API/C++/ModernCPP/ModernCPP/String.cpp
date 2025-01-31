#include <iostream>

using namespace std;

// ���ڿ� Ư¡
// - �� �޺�Ʈ�� 0���� ������ ���ڿ��� �����ٰ� �Ǵ��Ѵ�.
// - Escape Sequence
// -- '\0' : 0
// -- '\t' : tap
// -- '\'' : '
// -- '\n' : ������

// ���ڿ��� ����
unsigned __int64 Length(const char* str)
{
	unsigned __int64 count = 0;
	for (int i = 0; true ; i++)
	{
		if (str[i] == '\0')
			break;
		count++;
	}

	return count;
}

// ���ڿ� ��
bool Compare(const char* str1, const char* str2)
{
	int length1 = Length(str1);
	if (length1 != Length(str2))
		return false;

	for (int i = 0; i < length1; i++)
	{
		if (str1[i] != str2[i])
			return false;
	}

	return true;
}

int main()
{
	const char* str1 = "Hello";
	char str2[6] = { 'H','e','\a','l','o', '\0' };

	cout << str1 << endl;
	cout << str2 << endl;

	return 0;
}