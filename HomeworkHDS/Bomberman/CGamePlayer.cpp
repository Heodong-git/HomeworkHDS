#include "CGamePlayer.h"
#include "CConsoleGameScreen.h"
#include <conio.h>

CGamePlayer::CGamePlayer() :
	m_RenderChar(L'��')
{
}

CGamePlayer::~CGamePlayer()
{
}

void CGamePlayer::Update()
{
	// Ű�����Է� ������ ����� 0 �̶�� false, �ƴϸ� true( Ű���尡 ������ �ʾҴٴ� �ǹ� ) 
	if (0 == _kbhit())
	{
		return;
	}
	
	// ���� Ű�� � Ű�Ŀ� ���� �÷��̾� �̵�
	int Input = _getch();

	// �����÷��̾��� ��ġ�� �޾ƿ´�. 
	int4 CurPos = this->GetPos();

	// ��ũ�⸦ �޾ƿ´�. 
	int4 ScreenSize = CConsoleGameScreen::GetMainScreen()->GetScreenSize();
	
	// �б�ó��
	switch (Input)
	{
	case'a':
	case'A':
	{
		// ���� �÷��̾��� X ��ǥ�� 0���� �۰ų� ���ٸ� �������� ����
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
		// �迭�� �ִ�ũ�⺸�� �����÷��̾��� X��ǥ�� �� ũ�ų� ���ٸ� �������� �ʴ´�. 
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
		// �迭�� �ִ�ũ�⺸�� �����÷��̾��� X��ǥ�� �� ũ�ų� ���ٸ� �������� �ʴ´�. 
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
		// ���� �÷��̾��� Y ��ǥ�� 0���� �۰ų� ���ٸ� �������� �ʴ´�. 
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

	// ���� �迭�� ����ٸ� ���� ��ġ�� �������ش�. 
	if (true == CConsoleGameScreen::GetMainScreen()->IsOver(GetPos()))
	{
		SetPos(CurPos);
	}
}

