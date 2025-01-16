#include <iostream>

using namespace std;

// 변수 (바구니)
// (자료형) (변수이름) = (초기화);

// 연산자
// 변수들을 가동하는 방법


// 사칙연산 (이항연산자)
// + - * / (%)

// a + b : a와 b를 더한 임시값을 반환한다.
// a - b : ''
// a * b : ''
// (정수형)
// a /  b  : a를 b로 나눈 몫 임시값에 담고 반환한다.
// (실수형)
// a / b  : a를 b로 나눈 임시 값을 반환한다.

// a % b : 정수형끼리 나머지 임시갑슬 반환한다,
// => 순환구조 만들 때 쓰인다.

// 증감연산자(단항연산자)
// ++a : 전위연산자 : a의 원본에 1을 더하고 원본을 반환한다.
// a++ : 후위연산자 : a를 복사한 임시값을 만들고, a에다 1을 더하고 임시값을 반환한다.

// 비교 연산자
// ==, !=, <, >, <=, >=
// 반환값이 bool
// a > b : a가 b보다 크면 true, 그게 아니면 false 반환

// 삼항연산자
// (조건,bool) ? (a) : (b)
// 조건이 true면 a반환, false면 b반환
// aiint = (cint > 0) ? 50 : 100;

// = : 대입연산자
// a = b : a에다가 b를 넣고 a의 원본을 반환한다.

// 논리연산자
// !,&&, ||
// !(bool) :  역으로 바꾼다.
// a && b :  a와 b가 둘다 true 일 떄  true, 그게 아니면 false 반환
// a || b : a와 b 둘둘 하나낙 true 면 true 그게 아니면 false 반환


int main()
{
	int aint = 3;
	// stack 영역에 4바이트 만큼 할당받고 데이터는 1이다.

	int bint = 5;
	int cint = bint % aint; // 3의 나머지 0,1,2

	cint = ++aint; // 4
	// cout << aint << endl;  // 출력 : 4
	// cout << cint++ << endl; // 출력 : 4, cint : 5
	// 
	// cout << cint << endl; // 4
	cint = aint++; // 

	bool check1 = (aint > bint); // f
	bool check2 = (aint == bint) && check1; //f
	bool check3 = 3; // t

	aint = 3;
	bool check4 = !check1 || !check3; // t
	bool check5 = (check4 || check2) && (aint > 2); // t
	bool check6 = (++aint == 4) && (aint++ == 5); // f

	cout << check1 << endl;
	cout << check2 << endl;
	cout << check3 << endl;
	cout << check4 << endl;
	cout << check5 << endl;
	cout << check6 << endl;

	return 0;
}