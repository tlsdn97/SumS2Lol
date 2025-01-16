#include <iostream>

using namespace std;

// 메모리 4영역
// - CODE :
// - DATA : 전역변수, 정적변수
// -- 생성주기 : 실행과 동시에 생성 / 프로그램 종료시 해제
// 
// - STACK : [지역변수 매개변수 반환주소값 => 스택프레임]
// -- 생성주기 : 함수 호출됬을 때 할당/ 함수 종료시 해체
// 
// - HEAP : 사용자가 직접 제어하는 메모리

int aint = 1;

// 동적할당 => HEAP 영역에 메모리를 할당하는 작업
// - 운영체제가 도아주는 작업(Kenel 영역)

// malloc / free  => C 스타일
// new / delete => C++ 스타일
// new[] / delete[]

// void* ?
// 타고 들어가면 void(정해지지 않았다.) =? 무엇이든 올 수 있다.
// 모든 자료형을 가리킬 수 있는 얘

//int aint = 1;
//void* temp = (void*)&aint;
//*(int*)ptr = 1;

// for (int i = 0; i < 25; i++)
	// {
	// 	*(temp + i) = i;
	// }
	// int* temp = (int*)ptr;
	// for (int i = 0; i < 25; i++)
	// {
	// 	cout << *(temp + i) << endl;
	// }

class Player
{
public:
	Player(int hp, int atk) : _hp(hp), _atk(atk) { cout << " 생성자 호출 " << endl; }
	~Player()  { cout << " 소멸자 호출 " << endl; }

private:
	int _hp;
	int _atk;
};


int main()
{
#pragma region Mallco/Free
	void* ptr = malloc(100);
	int* temp = (int*)ptr;

	 for (int i = 0; i < 25; i++)
	 {
	 	*(temp + i) = i;
	 }
	 int* temp = (int*)ptr;
	 for (int i = 0; i < 25; i++)
	 {
	 	//cout << *(temp + i) << endl;
	 } 
	 free(ptr);
#pragma endregion


	int* temp3 = new int(); // HEAP에 4바이트 만큼 동적 할당
	int* temp4 = new int[25]; // HEAP에  100바이트 

	Player* p = new Player(100, 10);

	delete p;
	delete[] temp4;
	delete temp3;

	

	return 0;
}