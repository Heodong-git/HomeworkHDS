#include "Player.h"
#include <conio.h>
#include "ConsoleGameScreen.h"
#include "GameEngineDebug.h"
#include "Boom.h"
#include "Obstacle.h"

Player::Player()
{
	ArrBoomObject = new Boom[10000]();

	SetRenderChar(L'＠');
	SetPos(int4{ 7, 5 });
}

Player::~Player()
{
	if (ArrBoomObject != nullptr)
	{
		delete[] ArrBoomObject;
		ArrBoomObject = nullptr;
	}
}

bool Player::Update()
{

	if (ArrBoomObject == nullptr)
	{
		MessageBoxAssert("폭탄이 만들어지지 않았습니다.");
		return false;
	}

	for (size_t i = 0; i < BoomUseCount; i++)
	{
		ArrBoomObject[i].Update();
	}



	if (0 == _kbhit())
	{
		ConsoleGameScreen::GetMainScreen()->SetPixelChar(GetPos(), GetRenderChar());

		return true;
	}

	// 프로그램 입력이 올때까지 멈추죠?
	int Input = _getch();

	int4 NextPos = GetPos();

	switch (Input)
	{

	case 'a':
	case 'A':
	{
		NextPos += {-1, 0};
		break;
	case 'd':
	case 'D':
	{
		NextPos += {1, 0 };
	}
	break;
	case 's':
	case 'S':
	{
		NextPos += { 0, 1 };
	}
	break;
	case 'w':
	case 'W':
	{
		NextPos += { 0, -1 };
	}
	break;
	case 'f':
	case 'F':
	{
		Boom& NewBoomObject = ArrBoomObject[BoomUseCount];
		NewBoomObject.SetPos(GetPos());
		NewBoomObject.SetOwner(this);
		++BoomUseCount;

	}
	break;
	case 'q':
	case 'Q':
		return false;
	default:
		break;
	}
	}

	bool IsMove = true;

	// 플레이어가 화면 바깥으로 나갔다면 이동하지 못하게 한다.
	// 화면 바깥으로 나갔다면 , 다음 이동위치에 장애물이 있다면 이동불가
	if (true == ConsoleGameScreen::GetMainScreen()->IsOver(NextPos) ||
		true == ConsoleGameScreen::GetMainScreen()->IsObstacle(NextPos))
	{
		// 이동불가
		IsMove = false;
	}


	// 폭탄들을 전부다 검사해서 만약 나의 이동위치에 폭탄이 있다면 이동하지 않는다.
	for (size_t i = 0; i < BoomUseCount; i++)
	{
		if (
			false == ArrBoomObject[i].IsDeath() &&
			ArrBoomObject[i].GetPos() == NextPos
			)
		{
			IsMove = false;
		}
	}

	if (true == IsMove)
	{
		SetPos(NextPos);
	}

	ConsoleGameScreen::GetMainScreen()->SetPixelChar(GetPos(), GetRenderChar());

	return true;
}