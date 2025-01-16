#include <iostream>

using namespace std;

// 2���� ����
// ���� ����
class Vector
{
public:
	Vector() : x(0.0f), y(0.0) {}
	Vector(float x, float y)
	{
		// this : �� �Լ��� ȣ���� ��ü�� ����Ű�� ������
		this->x = x;
		this->y = y;
	}

	// ���� ����
	// a + b : a�� b�� ���� �ӽð��� ��ȯ�Ѵ�. 
	Vector operator+(const Vector& other)
	{
		Vector result;
		result.x = this->x + other.x;
		result.y = this->y + other.y;
		
		return Vector(this->x + other.x, this->y + other.y); // �ӽð�ü
	}

	// ���� ����

	Vector operator-(const Vector& other)
	{
		Vector result;
		result.x = this->x - other.x;
		result.y = this->y - other.y;

		return result;

		//return Vector(this->x - other.x, this->y - other.y); // �ӽð�ü
	}

	// ����
	 Vector operator*(float value)
	 {
	 	Vector result;
	 	result.x = this->x * value;
	 	result.y = this->y * value;
	 
	 	return result;
	 }

	 // ���Կ�����(=)
	 // a = b ... a���ٰ� b�� �����ϰ� , a�� ������ ��ȯ�Ѵ�.
	 // - �Ͻ������� �����Ϸ��� ������ش�.
	 Vector& operator =(const Vector& other)
	 {
		 this->x = other.x;
		 this->y = other.y;

		 return *this;
	 }
	 
	 // ����������
	 // ����������
 	 // ++a : a���ٰ� 1�� ���ϰ� a������ ��ȯ
	 Vector& operator++()
	 {
		 this->x += 1.0f;
		 this->y += 1.0f;
		 return *this;
	 }
	 
	 // ����������
	 // a++ : �ӽð��� a�� �����ϰ� a�� 1�� ���� �� �ӽð��� ��ȯ
	 Vector operator++(int)
	 {
		 Vector result = (*this);
		 this->x += 1.0f;
		 this->y += 1.0f;

		 return result;
	 }

	 // ������ ���� ũ��
	 float Length() const // �Լ��ڿ� const�� ����� �ٲ��� ���ϰ� �Ѵ�.
	 {

		 return sqrtf(this->x * this->x + this->y * this->y);
	 }
	 
	 // ������ ����ȭ���̰� 1�� ���ͷ� ����� �۾�) => ���� ����
	 void Normlize()
	 {
		 // ����
	 }
	 
	 // ���� ����
	 float Doc(const Vector& other)
	 {
		 // ����
		 return 0.0f; 
	 }
	 
	 // ���� ����
	 float Cross(const Vector& other)
	 {
		 // ����
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
	Vector(); // �ӽð�ü
	Vector v1(1, 1);
	Vector v2(2, 2);

	Vector v3 = v1 * 2;

	v3 = v1;
	v3++;
	v3.PrintV();


	return 0;
}