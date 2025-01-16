#include <iostream>

using namespace std;

// Reference : 참조
// (자료형) & (참조이름) = (초기화);

// - 어셈블리어 관점
// => 동일한 작업

// c++ 관점
// ptr
// 1. 위험하다 (nullptr에 접근, 초기화 되지않은 영역접근 가능)
// 2. 쓰기 어렵다.
// 
// ref
// 1. 누군가의 별칭
// => nullptr 참조가 불가능 하다.
// => 반드시 유효한 변수의 별명이여야한다.
// 2. 쓰기 쉽다.

// ptr 
// - 장점
// = > nullptr을 가리킬 수 있다.

// ref 
// - 장점
// => 쓰기 쉽다.


void PrintRef(int& ref)
{
	cout << ref << endl;
}

int main()
{
	int aint = 1;
	int bint = 2;
	int* ptr = &aint;
	int& ref = aint;

	ref++;
	(*ptr)++;

	PrintRef(aint);
	PrintRef(bint);

	return 0;
}