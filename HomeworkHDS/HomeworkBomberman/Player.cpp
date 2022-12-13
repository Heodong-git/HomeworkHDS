#include "Player.h"
#include <conio.h>
#include "ConsoleGameScreen.h"
#include "GameEngineDebug.h"
#include "Boom.h"

Player::Player()
{
	ArrBoomObject = new Boom[10000]();

	SetRenderChar(L'��');
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
		MessageBoxAssert("��ź�� ��������� �ʾҽ��ϴ�.");
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

	// ���α׷� �Է��� �ö����� ������?
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

	// �÷��̾ ȭ�� �ٱ����� �����ٸ� �̵����� ���ϰ� �Ѵ�.
	// ȭ�� �ٱ����� �����ٸ�
	if (true == ConsoleGameScreen::GetMainScreen()->IsOver(NextPos))
	{
		// �̵��Ұ�
		IsMove = false;
	}

	// ��ź���� ���δ� �˻��ؼ� ���� ���� �̵���ġ�� ��ź�� �ִٸ� �̵����� �ʴ´�.
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