#include <iostream>

using namespace std;

// ���ڿ� Ư¡
// - �� �޺�Ʈ�� 0���� ������ ���ڿ��� �����ٰ� �Ǵ��Ѵ�.
// - Escape Sequence
// -- '\0' : 0
// -- '\t' : tap
// -- '\'' : '
// -- '\n' : ���� ��
// -- '\a' : �����

// ���ڿ��� ����
unsigned __int64 Length(const char* str)
{
	unsigned __int64 length = 0;
	
	for (int i = 0; true; i++)
	{
		if (str[i] == '\0')
			break;
		length++;
	}

	return length;
}

// ���ڿ� ��
bool Compare(const char* str1, const char* str2)
{
	int length1 = Length(str1);
	if (Length(str1) != Length(str2))
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
	const char* str1 = "Hello"; // ���ͳ� ���, �����Ϳ����� ����, �迭�� ũ�Ⱑ 6, ������ũ��� 5
	char str2[6] = { 'H', 'e', '\a', 'l', 'o', '\0' };
	
	cout << str1 << endl;
	cout << str2 << endl;

	return 0;
}