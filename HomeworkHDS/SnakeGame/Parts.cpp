#include "Parts.h"

// Parts 클래스의 Parts() (생성자) 
Parts::Parts() :
	m_PrevParts(nullptr)
{
}

// Parts 클래스는 객체가 만들어질 때 어떤 문자로 표시될 것인지 세팅받는다. 
Parts::Parts(wchar_t _Renderchar) :
	ConsoleGameObject(_Renderchar)
{
}

// Parts 클래스의 ~Parts() (소멸자)
Parts::~Parts()
{
}

void Parts::Update()
{
}
