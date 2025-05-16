#include "framework.h"

// ��������Ϳ� �޸� ����
// ����޸� vs ������ �޸�
// MMU�� �ü���� ����¡

// ���� �޸�
// 1. ����޸��� �ּҿ� ������ �޸���� �ּҰ� ���� �ٸ���.
// 2. ����޸𸮿��� RAM�� ���Ե��� ���� �� �ִ�. (���������ġ�� �޸� �Ϻθ� �� �� �ִ�.)
// => �ʿ��� ��ü �����͸� RAM�� �ø��� �ʾƵ� �� �� �ִ�.

// MMU (Memory Management Unit)
// ����޸��� �ּҸ� �������޸� �ּҷ� ����.
// �ü�� �����Ϳ� ������ ���´�. Ȥ�� �ٸ� ���α׷��� �ּҰ��� �Ǥ����� ������ ���´�.

// ����¡
// �ü���� �޸𸮸� Ȱ���ϰ� ������ �� ������ ������ ������ �ϴ°�.
// 1. �� ���μ������� ����޸𸮸� �ְ� ������������ ���� ������ �� ���� �����.
// 2. �޸� ����ȭ�� ���� �� �ִ�. (������ ������ �ø� ���)

// => ������ �޸𸮴� �ü���� ����ϰڴ�.

class Player
{
public:

	Player() {cout << "Player�� ������ ȣ��" << endl; }
	~Player() {cout << "Player�� �Ҹ��� ȣ��" << endl; }

public:

	int _hp = 0;
	int _atk = 0; 
};

class Knight : public Player
{
public:

	Knight() { cout << "Knight�� ������ ȣ��" << endl; }
	~Knight() { cout << "Knight�� �Ҹ��� ȣ��" << endl; }

public:

	int _stamina = 0;
};

int main()
{
	Player* p = new Player(); // T1

	p->_hp = 10;
	p->_atk = 5;

	delete p; // T2

	// p�� ��������� (Danging Poninter)
	p->_hp = 50; // �޸� ���� ... T1

	// Release���� �޸𸮿����÷ο찡 �Ͼ�� ���������� ����ȴ�.
	Knight* k = reinterpret_cast<Knight*>(new Player());

	// k->_stamina = 50;

	delete k;

	SYSTEM_INFO s_info;
	::GetSystemInfo(&s_info);

	cout << s_info.dwPageSize << endl; // ������ �Ѱ��� ������ 4kb
	cout << s_info.dwAllocationGranularity << endl; // �޸𸮸� �Ҵ��� �� �� ������ ����� �Ҵ� : 2B

	int* temp = (int*)::VirtualAlloc(nullptr, 4, MEM_RELEASE | MEM_COMMIT, PAGE_READWRITE);
	*temp = 100;

	::VirtualFree(temp, 0, MEM_RELEASE);

	(*temp) = 10; // ���������, �޸� ����
	// new, delete�� �ٷ� VirtualAlloc, Free�� ������ �ʴ´�.

	return 0;
}