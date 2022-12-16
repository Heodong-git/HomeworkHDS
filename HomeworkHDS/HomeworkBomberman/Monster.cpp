#include "Monster.h"
#include "ConsoleGameScreen.h"
#include "ConsoleGameObject.h"



Monster::Monster() :
	Dir(1),
	Time(0),
	Number(0)
{
	SetRenderChar(L'��');
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
	// ������������ �޾ƿ´�.
	int4 Pos = GetPos();
	
	if (Number == 1)
	{
		// ������������ X ���� ��ũ�� X���� �������̶�� Dir = -1 
		if (Pos.X == ScreenSize.X - 1)
		{
			Dir = -1;
		}

		// ������������ X ���� 0 ���� �۰ų� ũ�ٸ� Dir = 1  
		if (Pos.X == 0)
		{
			Dir = 1;
		}

		Pos.X += Dir;


		SetPos(Pos);
		ConsoleGameScreen::GetMainScreen()->SetPixelChar(GetPos(), GetRenderChar());

	}

	if (Number == 2)
	{
		if (Pos.Y == ScreenSize.Y - 1)
		{
			Dir = -1;
		}

		if (Pos.Y == 0)
		{
			Dir = 1;
		}

		Pos.Y += Dir;


		SetPos(Pos);
		ConsoleGameScreen::GetMainScreen()->SetPixelChar(GetPos(), GetRenderChar());

	}

	return true;
}