#include "Parts.h"

// Parts Ŭ������ Parts() (������) 
Parts::Parts() :
	m_PrevParts(nullptr)
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

void Parts::Update()
{
}
