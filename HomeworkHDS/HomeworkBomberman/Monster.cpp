#include "Monster.h"
#include "ConsoleGameScreen.h"
#include "ConsoleGameObject.h"



Monster::Monster() : 
	Dir(1),
	Time(0)
{
	SetRenderChar(L'♨');
	
}

Monster::~Monster()
{
}


void Monster::Init()
{
	ScreenSize = ConsoleGameScreen::GetMainScreen()->GetScreenSize();
	SetPos(int4{ ScreenSize.X - 1, 4 });
}

bool Monster::Update()
{
	// 현재포지션을 받아온다.
	int4 Pos = GetPos();
	
	// 현재포지션의 X 값이 스크린 X축의 마지막이라면 Dir = -1 
	if (Pos.X == ScreenSize.X - 1)
	{
		Dir = -1;
	}

	// 현재포지션이 X 값이 0 보다 작거나 크다면 Dir = 1  
	if (Pos.X == 0)
	{
		Dir = 1;
	}

	Pos.X += Dir;

	
	SetPos(Pos);
	ConsoleGameScreen::GetMainScreen()->SetPixelChar(GetPos(), GetRenderChar());

	return true;
}