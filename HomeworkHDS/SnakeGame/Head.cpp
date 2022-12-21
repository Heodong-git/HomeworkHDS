#include "Head.h"
#include <ConsoleGameScreen.h>
#include <conio.h>

Head::Head()
	: Parts(L'◆')
{
}

Head::~Head()
{
}

void Head::Update()
{
	// 키입력이 없다면 업데이트 진행x 
	if (0 == _kbhit())
	{
		return;
	}

	// 키입력을 받았다면 그 값을 받아두고
	int Input = _getch();

	// 이동할 위치를 받아둔다. 
	// 아래 분기처리에서 연산
	int4 NextPos = GetPos();

	// 값에 따른 분기처리 
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
	break;
	case 'q':
	case 'Q':
		return;
	default:
		break;
	}
	}

	// 이동가능상태 true 
	bool IsMove = true;


	// 다음위치가 화면바깥이라면 이동불가처리
	if (true == ConsoleGameScreen::GetMainScreen()->IsOver(NextPos))
	{
		// 이동불가
		IsMove = false;
	}

	// IsMove 가 true 일 경우에만 위치를 이동시켜준다. 
	if (true == IsMove)
	{
		SetPos(NextPos);
	}
}