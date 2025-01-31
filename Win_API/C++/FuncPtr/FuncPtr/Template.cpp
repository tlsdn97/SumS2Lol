#include <iostream>

using namespace std;

// Template : ���� Ʋ
// => ������ ���� ���� ����� ����

// ���ø��Լ� : �Լ�(���)�� ���� Ʋ
template <typename T = int>
void PrintNum(T num)
{
	cout << num << endl;
}

// ���ø��Լ��� Ư��ȭ
template<>
void PrintNum(double num)
{
	cout << "Double �� �Լ� ����!!" << endl;
	cout << num << endl;
}

// ���ø� Ŭ����
// : Ŭ����(���赵)�� ���� ����Ʋ
// 
template<typename T = float> // ���ø� Ŭ������ �⺻���� ���� (���ø� Ŭ������ ��Ÿ���� <>�� ������ �� ����.)
class Vector
{
public:
	Vector() :x(T()), y(T()) {}
	Vector(T x, T y) : x(x), y(y) {}

	// ���������� �����ε� 
	// ���������� : a + b => a�� b�� ���ϰ� �ӽð��� ��ȯ�Ѵ�.
	Vector<T> operator+(const Vector<T>& other)
	{
		Vector<T> result;
		result.x = x + other.x;
		result.y = y + other.y;

		return result;
	}

	void PrintVector()
	{
		cout << "X : " << x << endl;
		cout << "Y : " << y << endl;
	}
	

	T x;
	T y;
};

template<>
class Vector<double>
{
public:
	Vector() :x(double()), y(double()) {}
	Vector(double x, double y) : x(x), y(y) {}

	// ���������� �����ε� 
	// ���������� : a + b => a�� b�� ���ϰ� �ӽð��� ��ȯ�Ѵ�.
	Vector<double> operator+(const Vector<double>& other)
	{
		Vector<double> result;
		result.x = x + other.x;
		result.y = y + other.y;

		return result;
	}

	void PrintVector()
	{
		cout << "Double Ư��ȭ" << endl;

		cout << "X : " << x << endl;
		cout << "Y : " << y << endl;
	}

	double x;
	double y;
};

class Player
{
public:

private:
};

int main()
{
	int aInt = 1;
	PrintNum(aInt); // =>

	double aDouble = 1.1;
	PrintNum<double>(aDouble);

	Vector<int> v1(1,1);
	Vector<int> v2(2,3);
	Vector<int> temp = v1 + v2;
	temp.PrintVector();

	Vector<> fv1(1.1f,2.3f);

	Vector<double> dv1(2.2,2.5);
	Vector<double> dv2(1.1,3.3);
	Vector<double> temp2 = dv1 + dv2;
	temp2.PrintVector();

	return 0;
}