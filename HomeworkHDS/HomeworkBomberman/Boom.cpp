
#include "Boom.h"
#include <conio.h>
#include "ConsoleGameScreen.h"
#include "Player.h"
#include <Windows.h>
#include "BoomExplosion.h"
#include "Obstacle.h"

Boom::Boom()
{
	SetRenderChar(L'◎');
}

Boom::~Boom()
{

}

void Boom::Update()
{
	// 현재 레인지가 설정된 레인지보다 크다면 리턴
	if (CurRange > Range)
	{
		return;
	}

	// 시간이 0보다 작아졌다면 그 틱에서는 ++CurRange 
	if (0 > --Time)
	{
		++CurRange;
	}

	// 현재 폭탄의 위치 
	int4 BoomPos = GetPos();
	// 위치에 폭탄 출력
	ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos, GetRenderChar());

	// 
		for (int i = 1; i < CurRange; i++)
		{
			int4 LeftPos = BoomPos + int4{ -i , 0 };

			if (false == ConsoleGameScreen::GetMainScreen()->IsOver(LeftPos))
			{
				BoomCheck(LeftPos);
			    ConsoleGameScreen::GetMainScreen()->SetPixelChar(LeftPos, L'♥');
			}
			int4 RightPos = BoomPos + int4{ i , 0 };
			if (false == ConsoleGameScreen::GetMainScreen()->IsOver(RightPos))
			{
				BoomCheck(RightPos);
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(RightPos, L'♥');
			}
			int4 UpPos = BoomPos + int4{ 0, -i };
			if (false == ConsoleGameScreen::GetMainScreen()->IsOver(UpPos))
			{
				BoomCheck(UpPos);
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(UpPos, L'♥');
			}
			int4 DownPos = BoomPos + int4{ 0, i };
			if (false == ConsoleGameScreen::GetMainScreen()->IsOver(DownPos))
			{
				BoomCheck(DownPos);
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(DownPos, L'♥');
			}
		}
		return;
	
}

// 이런걸 할필요가 없었다 !!
void Boom::BoomCheck(const int4& _Pos)
{
	// 플레이어를 받아온다. 
	Player* Player = GetOwner();
	// 플레이어가 소유한 붐배열을 받아온다. 
	Boom* ArrBoom = Player->GetBoomArr();
	// 현재 플레이어가 설치한 폭탄의 개수를 받아온다. 
	int PlayerUseBoomCount = Player->GetBoomUseCount();
	// 현재폭탄의 위치를 받아온다
	int4 FirePos = _Pos;

	// 플레이어가 설치한 폭탄의 개수만큼 반복
	for (int i = 0; i < PlayerUseBoomCount; i++)
	{
		// 현재 폭탄이 폭발하는 위치와 같은 위치에 존재하는 폭탄이 있다면 
		if (FirePos == ArrBoom[i].GetPos())
		{
				ArrBoom[i].Time = -1;	
		}
	}
}


