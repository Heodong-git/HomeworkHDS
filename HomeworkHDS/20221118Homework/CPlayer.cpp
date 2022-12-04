#include "CPlayer.h"
#include <iostream>
#include <conio.h>

CPlayer::CPlayer() :
	iAtt(10),
	iHp(100)
{
}

CPlayer::~CPlayer()
{
}

void CPlayer::StatusRender()
{
	printf_s("=====================================\n");
	printf_s("공격력 = %d \n", iAtt);
	printf_s("체  력 = %d \n", iHp);
	printf_s("============================================\n");
}

void CPlayer::Damage(int _Att)
{
	iHp -= _Att;

	int Input = 0;
	printf_s("플레이어가 %d데미지를 받았습니다.\n", _Att);
	Input = _getch();
	printf_s("플레이어는 %d체력이 남았습니다.\n", iHp);
	Input = _getch();
}
