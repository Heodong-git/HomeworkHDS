#include "Parts.h"

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

void Parts::Update()
{
}
