#include "Body.h"
#include <iostream>
#include <ConsoleGameScreen.h>
#include <ConsoleGameInput.h>

// static 변수는 항상 실체를 만들어준다. 
Body* Body::CurBody = nullptr;

Body::Body() :
	Parts(L'●')
{
}

Body::~Body()
{
}

void Body::Update()
{
	// 나중에 이 제한을 풀어야 할 가능성이 높다.
	// 현재 키가 눌려있다면 
	if (true == ConsoleGameInput::GetIsInput())
	{
		// 다음파츠가 없다면 return; 
		if (nullptr == GetNext())
		{
			return;
		}

		// 다음파츠가 있다면 
		// 다음파츠의 위치는 이동 전 내가 있던 위치가 된다. 
		SetPos(GetNext()->GetPos());
	}
}

void Body::CreateBody()
{
	// 바디파츠 동적할당
	CurBody = new Body();

	// 랜덤한 위치에 다음 바디의 위치를 정해준다. 
	CurBody->SetPos({ rand() % ConsoleGameScreen::GetMainScreen()->GetScreenSize().X , 
		              rand() % ConsoleGameScreen::GetMainScreen()->GetScreenSize().Y });
}


Body* Body::GetCurBody()
{
	return CurBody;
}
