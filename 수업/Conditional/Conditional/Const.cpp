#include <iostream>

using namespace std;

// 매크로 
#define STUN			 1
#define SUBDUE			 1 << 1
#define SLEEP			 1 << 2
#define TRANSITION		 1 << 3

//  열거형
enum  State
{
	// 양의 정수
	State_STUN = 1,
	State_SUBDUE = 1 << 1,
	State_SLEEP = 1 << 2,
	State_TRANSITION = 1 << 3
};

// 부호가 없는 정수

// 비트연산
// &, |, ^, >>, <<
// & : 비트 and 연산
// | : 비트 or 연산
// ^ : 비트 Xor 연산  => 비트가 같으면 0, 다르면 1
// ... a ^ b ^ b => a

// << : 좌측 시프트 연산
// - x 
// 맨 완쪽 비트는 버려지게 된다.
// 오른쪽 비트는 0으로 채워짐

// >> : 우측 시프트 연산
// - /2.. 
// 맨 오른쪽 비트는 버려지게 된다.
// 맨 왼족 비트는 부호를 따르게 된다.

// 내가 지금 무슨 cc기에 걸렸는지 확인
unsigned char bitFlag = 0;
const unsigned char stun = 1;
const unsigned char subdue = (1 << 1);
const unsigned char sleep = (1 << 2);
const unsigned char transition = (1 << 3);

int main()
{
	//  기절, 수면
	bitFlag = stun | sleep;

	// 기절에 걸려 있습니까?
	// & stun => 비트마스크
	if (bitFlag & STUN)
	{
		cout << "기절에 걸려 있습니다" << endl;
	}

	// 제압에 걸리고 기절이 풀림
	bitFlag |= subdue;
	bitFlag ^= stun;

	// 제압이고 변이생태인지 질문
	if ((bitFlag & subdue) && (bitFlag & transition))
	{
		cout << "제압 변이상태 입니다." << endl;
	}

	return 0;
}