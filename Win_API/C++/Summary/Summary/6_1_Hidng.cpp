#include <iostream>

using namespace std;

// ���α׷���
// - ���� 
// - ��? (�ẻ ����� ���)
// - ���? (�����)

// ��������(�������) vs ��ü����(��ü)
// ��ü : �Ӽ��� ����� ���� �޸𸮿� �Ҵ�Ǿ��ִ� ��
// ��üȭ : (class �ڷ�����) �޸𸮿� �Ҵ��ϴ� ��
// �ν��Ͻ� : �Ӽ��� ����� �Ȱ����� �޸𸮿� �Ҵ�Ǿ��ִ� ��
// �ν��Ͻ�ȭ : 

// 1. ��ü������ 3�Ӽ�
//	- ���м�
//		=> �ܺο��� ����(����) �����ؼ� �ٲ��� ���ϰ� �Ϸ���
//      ==> ����Լ� �������� ������ų����
//  - ���������� : public(���� ��𿡼���) / protected(����Լ�, �ڽ��� ����Լ�) / private(����Լ�, friend)
struct Vector // ����
{
public:
	float x;
	float y;
};

class Car // ��ü(�Ӽ�,���)
{
public:
	// ����Լ�
	// - ���
	// ��������� ���� ���� => �Ӽ��� �ٷ�� '���'
	// ����Լ��� ��ü�� �־�� ȣ���� �����ϴ�.
	void PrintCar() { cout << _engine << endl; }
	int GetEngine() { return _engine; }
	void SetEngine(int engine) {
		if (engine < 0) return;

		this->_engine = engine; }

private:
	// �������
	// - �Ӽ�
	int _engine;
	int _handle;
	int _wheels;
	int _doors;
};

//  - ��Ӽ�
// 
// 
//  - ������
// 
// 2. Ŭ������ ������/�Ҹ���
// 3. Ŭ������ �������̵� / �����ε�
// 4. Vector�� ���ؼ� �����ؿ���(���� / ����)

int main()
{
	Car car;
	
	// ����� ��� �ڵ�
	car.SetEngine(5);
	cout << car.GetEngine() << endl;

}