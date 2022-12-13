
#include "Boom.h"
#include <conio.h>
#include "ConsoleGameScreen.h"
#include "Player.h"
#include <Windows.h>
#include "BoomExplosion.h"
Boom::Boom()
{
	SetRenderChar(L'◎');
	ArrBoomExplosion = new BoomExplosion[100];
}

Boom::~Boom()
{
	if (nullptr != ArrBoomExplosion)
	{
		delete[] ArrBoomExplosion;
		ArrBoomExplosion = nullptr;
	}
}

void Boom::Update()
{
	if (FireTime > 16)
	{
		Fire = false;
	}

	// 업데이트 함수가 호출되면
	// if문을 검사하면서 시간이 줄어들게 되고 0이하가 되면 if문의 코드가 실행된다. 
	// Boom 클래스의 bool 변수 Fire는 false 상태이며 if문 진입시 true 로 변경되고 폭발코드 실행
	if (0 > --Time || Fire == true)
	{
		
		// 폭발이 지속되는 시간체크를 위해 지속적인 값증가
		++FireTime;

		// 폭탄이 터지는 위치에 다른 폭탄이 있다면 SetDeath;
		// 폭탄배열을 가져와서 위치를받아온 후 현재 폭탄이 터지는 위치에 폭탄이 있을경우
		Player* Player = GetOwner();
		Boom* ArrBoom = Player->GetBoomArr();

			// 폭발범위체크는 어떻게 할 것인가? 
			int4 BoomPos = GetPos();
	
			// FireTime 변수가 1보다 같거나크고 5보다 작을때는 1의 범위만큼
			if (0 < FireTime && 5 >= FireTime)
			{
				// 범위만큼 반복실행, 폭탄 주변을 범위만큼 하트로 출력되게 한다.
				Range = 1;

				// FireTime 의 조건이 만족하는 동안 해당하는 위치는 하트로 출력
				// 이걸 붐익스플로전으로 바꾸고 걔의 위치를 받아와서 출력하는걸로
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos + int4{ Range , 0 }, L'♥');
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos + int4{ -Range, 0 }, L'♥');
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos + int4{ 0, Range }, L'♥');
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos + int4{ 0, -Range }, L'♥');
				BoomCheck(Range);
			}

			// FireTime 변수가 5보다 크고 10보다 작을땐 2의범위까지 
			if (5 < FireTime && 10 > FireTime)
			{
				Range = 1;
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos + int4{ Range , 0 }, L'♥');
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos + int4{ -Range, 0 }, L'♥');
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos + int4{ 0, Range }, L'♥');
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos + int4{ 0, -Range }, L'♥');

				BoomCheck(Range);

				Range = 2;
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos + int4{ Range , 0 }, L'♥');
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos + int4{ -Range, 0 }, L'♥');
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos + int4{ 0, Range }, L'♥');
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos + int4{ 0, -Range }, L'♥');

				BoomCheck(Range);
			}

			if (15 > FireTime && 10 < FireTime)
			{
				Range = 1;
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos + int4{ Range , 0 }, L'♥');
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos + int4{ -Range, 0 }, L'♥');
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos + int4{ 0, Range }, L'♥');
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos + int4{ 0, -Range }, L'♥');

				BoomCheck(Range);

				Range = 2;
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos + int4{ Range , 0 }, L'♥');
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos + int4{ -Range, 0 }, L'♥');
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos + int4{ 0, Range }, L'♥');
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos + int4{ 0, -Range }, L'♥');

				BoomCheck(Range);

				Range = 3;
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos + int4{ Range , 0 }, L'♥');
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos + int4{ -Range, 0 }, L'♥');
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos + int4{ 0, Range }, L'♥');
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos + int4{ 0, -Range }, L'♥');

				BoomCheck(Range);
			}
		return;
	}

	//   ★
	//   ★
	//★★◎★★
	//   ★
	//   ★

	// 1. 쾅쾅쾅쾅을 만들어 오세요.
	// 1-1. 왼쪽 오른쪽 위 아래에 1개만이라도 보이게 해라. ㅇㅇ.
	// 1-2. 그냥 범위크기 전체로 보이게 만들어라.			ㅇㅇ.
	// 1-3. 시간차로 범위가 보이게 만들어라.
	// 
	// 십자가 표시로 먼저 나오게 하세요.


	// 2. 쾅쾅쾅쾅범위에 다른 폭탄이 있으면 개도 쾅쾅쾅쾅.
	ConsoleGameScreen::GetMainScreen()->SetPixelChar(GetPos(), GetRenderChar());
}

void Boom::BoomCheck(const int _Range)
{
	const int CurRange = _Range;
	Player* Player = GetOwner();
	Boom* ArrBoom = Player->GetBoomArr();
	int4 CurPos = GetPos();

	for (size_t i = 0; i < (size_t)(Player->GetBoomUseCount()); i++)
	{
		if (ArrBoom[i].GetPos() == CurPos + int4{ Range , 0 })
		{
			ArrBoom[i].SetDeath();
		}

		if (ArrBoom[i].GetPos() == CurPos + int4{ Range , 0 })
		{
			{
				ArrBoom[i].SetDeath();
			}
		}

		if (ArrBoom[i].GetPos() == CurPos + int4{ Range , 0 })
		{
			{
				ArrBoom[i].SetDeath();
			}
		}

		if (ArrBoom[i].GetPos() == CurPos + int4{ Range , 0 })
		{
			{
				ArrBoom[i].SetDeath();
			}
		}
	}
}


