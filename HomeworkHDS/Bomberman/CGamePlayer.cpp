#include "CGamePlayer.h"
#include "CConsoleGameScreen.h"
#include <conio.h>

CGamePlayer::CGamePlayer() :
	m_RenderChar(L'★')
{
}

CGamePlayer::~CGamePlayer()
{
}

void CGamePlayer::Update(CConsoleGameScreen& _Screen)
{
	// 키보드입력 버퍼의 사이즈가 0 이라면 false, 아니면 true( 키보드가 눌리지 않았다는 의미 ) 
	if (0 == _kbhit())
	{
		return;
	}
	
	// 눌린 키가 어떤 키냐에 따라 플레이어 이동
	int Input = _getch();

	// 현재플레이어의 위치를 받아온다. 
	int4 CurPos = GetPos();
	// 맵크기를 받아온다. 
	int4 ScreenSize = _Screen.GetScreenSize();
	
	// 분기처리
	switch (Input)
	{
	case'a':
	case'A':
	{
		// 현재 플레이어의 X 좌표가 0보다 작거나 같다면 움직이지 않음
		if (0 >= CurPos.X)
		{
			return;
		}
		 
		Move(int4{ -1,0 });
	}
		break;
	case's':
	case'S':
	{
		// 배열의 최대크기보다 현재플레이어의 X좌표가 더 크거나 같다면 움직이지 않는다. 
		if (ScreenSize.X - 1 <= CurPos.Y)
		{
			return;
		}

		Move(int4{ 0,1 });
	}
		break;
	case'd':
	case'D':
	{
		// 배열의 최대크기보다 현재플레이어의 X좌표가 더 크거나 같다면 움직이지 않는다. 
		if (ScreenSize.X - 1 <= CurPos.X)
		{
			return;
		}

		Move(int4{ 1,0 });
	}
		break;
	case'w':
	case'W':
	{ 
		// 현재 플레이어의 Y 좌표가 0보다 작거나 같다면 움직이지 않는다. 
		if (0 >= CurPos.Y)
		{
			return;
		}

		Move(int4{ 0,-1 });
	}
		break;
	default:
		break;
	}
}

