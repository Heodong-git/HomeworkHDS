
#include "Boom.h"
#include <conio.h>
#include "ConsoleGameScreen.h"
#include "Player.h"
#include <Windows.h>
#include "BoomExplosion.h"
#include "Obstacle.h"

Boom::Boom()
{
	SetRenderChar(L'��');
}

Boom::~Boom()
{

}

void Boom::Update()
{
	if (0 > Time)
	{
		return; 
	}

	// Ÿ�� - �����̰� 0 ���� ���� ��쿡 �����ϴ� �ڵ�, ���� 
	if (0 > --Time - Delay)
	{
		int4 BoomPos = GetPos();

		for (int i = 1; i < Range + 1; i++)
		{
			int4 LeftPos = BoomPos + int4{ -i , 0 };

			if (false == ConsoleGameScreen::GetMainScreen()->IsOver(LeftPos))
			{
				// �� �迭�� ��ġ�� �ִ� ��¹��ڰ� ��ֹ��̶��? 
				/*if (ConsoleGameScreen::GetMainScreen()->IsRenderchar(LeftPos) ==
					Obstacle::GetObstacle()->GetRenderChar())
				{
					
				}*/
				BoomCheck(LeftPos);
			    ConsoleGameScreen::GetMainScreen()->SetPixelChar(LeftPos, L'��');
			}
			int4 RightPos = BoomPos + int4{ i , 0 };
			if (false == ConsoleGameScreen::GetMainScreen()->IsOver(RightPos))
			{
				BoomCheck(RightPos);
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(RightPos, L'��');
			}
			int4 UpPos = BoomPos + int4{ 0, -i };
			if (false == ConsoleGameScreen::GetMainScreen()->IsOver(UpPos))
			{
				BoomCheck(UpPos);
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(UpPos, L'��');
			}
			int4 DownPos = BoomPos + int4{ 0, i };
			if (false == ConsoleGameScreen::GetMainScreen()->IsOver(DownPos))
			{
				BoomCheck(DownPos);
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(DownPos, L'��');
			}
		}

		return;
	}
	//   ��
	//   ��
	//�ڡڡݡڡ�
	//   ��
	//   ��

	// 1. ���������� ����� ������.
	// 1-1. ���� ������ �� �Ʒ��� 1�����̶� ���̰� �ض�.
	// 1-2. �׳� ����ũ�� ��ü�� ���̰� ������.			
	// 1-3. �ð����� ������ ���̰� ������.
	// 
	// ���ڰ� ǥ�÷� ���� ������ �ϼ���.
	// 2. ������������� �ٸ� ��ź�� ������ ���� ��������.
	ConsoleGameScreen::GetMainScreen()->SetPixelChar(GetPos(), GetRenderChar());
}

// �̷��� ���ʿ䰡 ������ !!
void Boom::BoomCheck(const int4& _Pos)
{
	// �÷��̾ �޾ƿ´�. 
	Player* Player = GetOwner();
	// �÷��̾ ������ �չ迭�� �޾ƿ´�. 
	Boom* ArrBoom = Player->GetBoomArr();
	// ���� �÷��̾ ��ġ�� ��ź�� ������ �޾ƿ´�. 
	int PlayerUseBoomCount = Player->GetBoomUseCount();
	// ������ź�� ��ġ�� �޾ƿ´�
	int4 FirePos = _Pos;

	// �÷��̾ ��ġ�� ��ź�� ������ŭ �ݺ�
	for (int i = 0; i < PlayerUseBoomCount; i++)
	{
		// ���� ��ź�� �����ϴ� ��ġ�� ���� ��ġ�� �����ϴ� ��ź�� �ִٸ� 
		if (FirePos == ArrBoom[i].GetPos())
		{
				ArrBoom[i].Delay = 20;	
		}
	}
}


