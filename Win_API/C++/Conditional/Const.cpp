#include <iostream>

using namespace std;

// ��ũ��
#define STUN			  1
#define SUBDUE			  1 << 1
#define SLEEP			  1 << 2
#define TRANSITION		  1 << 3

// ������
enum State
{
	// ���� ����
	State_STUN = 1,
	State_SUBDUE = 1 << 1,
	State_SLEEP = 1 << 2,
	State_TRANSITION = 1 << 3
};

// ��ȣ�� ���� ����

// ��Ʈ ����
// &, |, ^, >>, <<
// & : ��Ʈ and ����
// | : ��Ʈ or ����
// ^ : ��Ʈ xor ���� => ��Ʈ�� ������ 0, �ٸ��� 1
// ... a ^ b ^ b => a 

// << : ���� ����Ʈ ����
// - x2
// �� ���ʺ�Ʈ�� �������� �ȴ�.
// �����ʺ�Ʈ�� 0���� ä����

// >> : ���� ����Ʈ ����
// �� ������ ��Ʈ�� �������� �ȴ�.
// �� ���ʺ�Ʈ�� ��ȣ�� �����Եȴ�.

// ���� ���� cc�⿡ �ɷȴ��� Ȯ��
unsigned char bitFlag = 0;
const unsigned char stun = 1;
const unsigned char subdue = (1 << 1);
const unsigned char sleep = (1 << 2);
const unsigned char transition = (1 << 3);

int main()
{
	// ����, ����
	bitFlag = stun | sleep;

	// ������ �ɷ��ֽ��ϱ�?
	// & stun => ��Ʈ����ũ
	if (bitFlag & STUN)
	{
		cout << "������ �ɷ��ֽ��ϴ�." << endl;
	}

	// ���п� �ɸ���, ������ Ǯ��
	bitFlag |= subdue;
	bitFlag ^= stun;
	
	// �����̰� ���̻������� ����
	if ((bitFlag & subdue) && (bitFlag & transition))
	{
		cout << "���� ���� �����Դϴ�." << endl;
	}

	return 0;
}