#include <iostream>

using namespace std;

// 2차원 벡터
// 힘과 방향
class Vector
{
public:
	Vector() : x(0.0f), y(0.0) {}
	Vector(float x, float y)
	{
		// this : 이 함수를 호출한 객체를 가리키는 포인터
		this->x = x;
		this->y = y;
	}

	// 덧엠 연산
	// a + b : a와 b를 더한 임시값을 반환한다. 
	Vector operator+(const Vector& other)
	{
		Vector result;
		result.x = this->x + other.x;
		result.y = this->y + other.y;
		
		return Vector(this->x + other.x, this->y + other.y); // 임시객체
	}

	// 뺄셈 연산

	Vector operator-(const Vector& other)
	{
		Vector result;
		result.x = this->x - other.x;
		result.y = this->y - other.y;

		return result;

		//return Vector(this->x - other.x, this->y - other.y); // 임시객체
	}

	// 곱셉
	 Vector operator*(float value)
	 {
	 	Vector result;
	 	result.x = this->x * value;
	 	result.y = this->y * value;
	 
	 	return result;
	 }

	 // 대입연산자(=)
	 // a = b ... a에다가 b를 대입하고 , a의 원본을 반환한다.
	 // - 암시적으로 컴파일러가 만들어준다.
	 Vector& operator =(const Vector& other)
	 {
		 this->x = other.x;
		 this->y = other.y;

		 return *this;
	 }
	 
	 // 증감연산자
	 // 전위연산자
 	 // ++a : a에다가 1을 더하고 a원본을 반환
	 Vector& operator++()
	 {
		 this->x += 1.0f;
		 this->y += 1.0f;
		 return *this;
	 }
	 
	 // 후위연산자
	 // a++ : 임시값에 a를 복사하고 a에 1을 더한 후 임시값을 반환
	 Vector operator++(int)
	 {
		 Vector result = (*this);
		 this->x += 1.0f;
		 this->y += 1.0f;

		 return result;
	 }

	 // 벡터의 힘의 크기
	 float Length() const // 함수뒤에 const는 멤버를 바꾸지 못하게 한다.
	 {

		 return sqrtf(this->x * this->x + this->y * this->y);
	 }
	 
	 // 벡터의 정규화길이가 1인 벡터로 만드는 작업) => 단위 벡터
	 void Normlize()
	 {
		 // 구현
	 }
	 
	 // 벡터 내적
	 float Doc(const Vector& other)
	 {
		 // 구현
		 return 0.0f; 
	 }
	 
	 // 벡터 외적
	 float Cross(const Vector& other)
	 {
		 // 구현
		 return 0.0f;
	 }


	 void PrintV()
	 {
		 cout << "x :" << x << endl;
		 cout << "y :" << y <<endl;
	 }

	float x;
	float y;
};

// Vector operator*(Vector& a, const float value)
// {
// 	return Vector(a.x * value, a.y * value);
// }

int main()
{
	Vector(); // 임시객체
	Vector v1(1, 1);
	Vector v2(2, 2);

	Vector v3 = v1 * 2;

	v3 = v1;
	v3++;
	v3.PrintV();


	return 0;
}