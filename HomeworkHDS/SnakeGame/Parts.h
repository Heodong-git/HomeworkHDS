#pragma once
#include <ConsoleGameObject.h>

// Parts Class �� ConsoleGameObject Ŭ������ ��ӹ޴´�. 
class Parts : public ConsoleGameObject
{
public:
	Parts();
	Parts(wchar_t _Renderchar);
	~Parts();

	// ��������� 
	Parts(const Parts& _Other) = delete;
	// RValue ������
	Parts(Parts&& _Other) noexcept = delete;
	// ���Կ����� 
	Parts& operator=(const Parts& _Other) = delete;
	Parts& operator=(Parts&& _Other) noexcept = delete;

	// ������Ʈ �Լ��� �����Լ��� ������ְ� 
	// �ڽ�Ŭ���������� ���������� ������ �θ�Ŭ������ Update��
	// �������ߴٸ� �ڽ�Ŭ������ Update �� ȣ���Ͽ� ����ϰ� �ȴ�. 
	virtual void Update();
	


private:
	// Parts Class �� �ڽŰ� ����Ǿ��ִ� ���� ��ü�� �� �� �־�� �ϱ� ������
	// �ڱ��ڽ�(������Ÿ��)�� �����͸� ������, �ڽŰ� ����� ��ü�� �ּҰ��� ������ �ִ´�. 
	Parts* m_PrevParts = nullptr;
	
};

