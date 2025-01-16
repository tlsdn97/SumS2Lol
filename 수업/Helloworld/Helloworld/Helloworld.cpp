#include <iostream> // 다른 헤더파일 붙혀넣기

// 1. cpu 와 memory
// - CPU : central processing( 논리 연산, 연산, 제어) unit
// - RAM : Random Access Memory

// 폰 노이만이 사람의 뇌를 컴퓨터에 도입
// CPU에서 연산,처리한 데이터들을 RAM에 저장한다.

// cpu (버스) ram 병목현상 : 

// 2. 기억장치
// - RAM :
// -- 현재 실행되는 프로그램이 RAM에 올라오게 된다.(휘발성)
// -- CPU와 거리 : 상대적으로 가깝다. (5cm)
// 
// - HDD/SSD : 
// -- 영구적인 저장, 게임저장 ... 게임을 시작하면 ram에 필요한 데이터를 여기서 뽑아온다(비휘발성)
// -- CPU와 거리 : 상대적으로 멀다. (30cm)


int main()
{
	// std:: => standard lib 
	// cout => console out 
	// endl => end line
	std::cout <<  "Hello world" << std::endl;

	int aint = 1;
	int bint = 2;

	int cint = aint + bint;

	return 0;
}