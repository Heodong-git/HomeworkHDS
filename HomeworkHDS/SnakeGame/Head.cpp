#include "Head.h"
#include <ConsoleGameScreen.h>
#include <conio.h>

Head::Head()
	: Parts(L'��')
{
}

Head::~Head()
{
}

void Head::Update()
{
	// Ű�Է��� ���ٸ� ������Ʈ ����x 
	if (0 == _kbhit())
	{
		return;
	}

	// Ű�Է��� �޾Ҵٸ� �� ���� �޾Ƶΰ�
	int Input = _getch();

	// �̵��� ��ġ�� �޾Ƶд�. 
	// �Ʒ� �б�ó������ ����
	int4 NextPos = GetPos();

	// ���� ���� �б�ó�� 
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

	// �̵����ɻ��� true 
	bool IsMove = true;


	// ������ġ�� ȭ��ٱ��̶�� �̵��Ұ�ó��
	if (true == ConsoleGameScreen::GetMainScreen()->IsOver(NextPos))
	{
		// �̵��Ұ�
		IsMove = false;
	}

	// IsMove �� true �� ��쿡�� ��ġ�� �̵������ش�. 
	if (true == IsMove)
	{
		SetPos(NextPos);
	}
}