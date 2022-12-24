#include "Parts.h"

std::vector<Parts*> Parts::VecParts;

// Parts Ŭ������ Parts() (������) 
Parts::Parts() :
	m_Prev(nullptr),
	m_Next(nullptr)
{
}

// Parts Ŭ������ ��ü�� ������� �� � ���ڷ� ǥ�õ� ������ ���ù޴´�. 
Parts::Parts(wchar_t _Renderchar) :
	ConsoleGameObject(_Renderchar)
{
}

// Parts Ŭ������ ~Parts() (�Ҹ���)
Parts::~Parts()
{
}

bool Parts::Update()
{
	return true;
}

// ���� ���� ������ �̵���Ų��. 
void Parts::RecursionNextMove()
{
	if (nullptr == m_Next)
	{
		return;
	}

	// ���������� �ִٸ�
	// ���� ��ġ�� ���� ������ ��ġ�� �ȴ�. 
	SetPos(m_Next->GetPos());

	return m_Next->RecursionNextMove();
}

// ���� ������
void Parts::RecursionPrevRender()
{
	// �ڱ��ڽ��� ������
	Render();

	// ���� ������ ���ٸ� return;
	if (nullptr == m_Prev)
	{
		return;
	}

	// ���������� �ִٸ� ������
	return m_Prev->RecursionPrevRender();
}
