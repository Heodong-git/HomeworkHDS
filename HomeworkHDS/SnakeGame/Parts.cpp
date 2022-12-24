#include "Parts.h"

std::vector<Parts*> Parts::VecParts;

// Parts 클래스의 Parts() (생성자) 
Parts::Parts() :
	m_Prev(nullptr),
	m_Next(nullptr)
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

bool Parts::Update()
{
	return true;
}

// 나의 다음 파츠를 이동시킨다. 
void Parts::RecursionNextMove()
{
	if (nullptr == m_Next)
	{
		return;
	}

	// 다음파츠가 있다면
	// 나의 위치는 다음 파츠의 위치가 된다. 
	SetPos(m_Next->GetPos());

	return m_Next->RecursionNextMove();
}

// 파츠 렌더링
void Parts::RecursionPrevRender()
{
	// 자기자신을 렌더링
	Render();

	// 이전 파츠가 없다면 return;
	if (nullptr == m_Prev)
	{
		return;
	}

	// 이전파츠가 있다면 렌더링
	return m_Prev->RecursionPrevRender();
}
