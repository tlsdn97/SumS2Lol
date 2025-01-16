#include <iostream>

using namespace std;

// 문자열 특징
// - 맨 뒷비트가 0으로 끝나야 문자열이 끝났다고 판단한다.
// - Escape Sequence
// -- '\0' : 0
// -- '\t' : tap
// -- '\'' : '
// -- '\n' : 다음 줄
// -- '\a' : 경고음

// 문자열의 길이
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

// 문자열 비교
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
	const char* str1 = "Hello"; // 리터널 상수, 데이터영역에 저장, 배열의 크기가 6, 문자의크기는 5
	char str2[6] = { 'H', 'e', '\a', 'l', 'o', '\0' };
	
	cout << str1 << endl;
	cout << str2 << endl;

	return 0;
}