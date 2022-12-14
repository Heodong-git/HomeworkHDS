
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
	if (0 > Time)
	{
		return; 
	}

	// 타임 - 딜레이가 0 보다 작을 경우에 동작하는 코드, 폭발 
	if (0 > --Time - Delay)
	{
		int4 BoomPos = GetPos();

		for (int i = 1; i < Range + 1; i++)
		{
			int4 LeftPos = BoomPos + int4{ -i , 0 };

			if (false == ConsoleGameScreen::GetMainScreen()->IsOver(LeftPos))
			{
				// 그 배열의 위치에 있는 출력문자가 장애물이라면? 
				/*if (ConsoleGameScreen::GetMainScreen()->IsRenderchar(LeftPos) ==
					Obstacle::GetObstacle()->GetRenderChar())
				{
					
				}*/
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
	//   ★
	//   ★
	//★★◎★★
	//   ★
	//   ★

	// 1. 쾅쾅쾅쾅을 만들어 오세요.
	// 1-1. 왼쪽 오른쪽 위 아래에 1개만이라도 보이게 해라.
	// 1-2. 그냥 범위크기 전체로 보이게 만들어라.			
	// 1-3. 시간차로 범위가 보이게 만들어라.
	// 
	// 십자가 표시로 먼저 나오게 하세요.
	// 2. 쾅쾅쾅쾅범위에 다른 폭탄이 있으면 개도 쾅쾅쾅쾅.
	ConsoleGameScreen::GetMainScreen()->SetPixelChar(GetPos(), GetRenderChar());
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
				ArrBoom[i].Delay = 20;	
		}
	}
}


