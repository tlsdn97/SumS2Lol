#pragma once
class Program
{
public:
	Program();
	~Program();

	void Update();
	void Render(HDC hdc);

	static HDC backbuffer;
	// Buffer : �ӽ� �����(�� ���������� �����ϰų�, ���޹��� ��)
	// backBuffer : ȭ�鿡 ��������� ������ �ӽ������� �׸��� �׸� ��

private:
	shared_ptr<Scene> _scene;

	HBITMAP _hBitMap;
};

