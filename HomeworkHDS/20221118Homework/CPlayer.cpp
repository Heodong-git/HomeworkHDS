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
	printf_s("���ݷ� = %d \n", iAtt);
	printf_s("ü  �� = %d \n", iHp);
	printf_s("============================================\n");
}

void CPlayer::Damage(int _Att)
{
	iHp -= _Att;

	int Input = 0;
	printf_s("�÷��̾ %d�������� �޾ҽ��ϴ�.\n", _Att);
	Input = _getch();
	printf_s("�÷��̾�� %dü���� ���ҽ��ϴ�.\n", iHp);
	Input = _getch();
}
