#include "CMonster.h"
#include <iostream>
#include <conio.h>

CMonster::CMonster() :
	iAtt(10),
	iHp(100)
{
}

CMonster::~CMonster()
{
}

void CMonster::StatusRender()
{
	printf_s("=====================================\n");
	printf_s("���ݷ� = %d \n", iAtt);
	printf_s("ü  �� = %d \n", iHp);
	printf_s("============================================\n");
}

void CMonster::Damage(int _Att)
{
	iHp -= _Att;

	int Input = 0;
	printf_s("���Ͱ� %d�������� �޾ҽ��ϴ�.\n", _Att);
	Input = _getch();
	printf_s("���� %dü���� ���ҽ��ϴ�.\n", iHp);
	Input = _getch();
}
