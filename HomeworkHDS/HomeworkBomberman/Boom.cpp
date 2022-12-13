
#include "Boom.h"
#include <conio.h>
#include "ConsoleGameScreen.h"
#include "Player.h"
#include <Windows.h>
#include "BoomExplosion.h"
Boom::Boom()
{
	SetRenderChar(L'��');
	ArrBoomExplosion = new BoomExplosion[100];
}

Boom::~Boom()
{
	if (nullptr != ArrBoomExplosion)
	{
		delete[] ArrBoomExplosion;
		ArrBoomExplosion = nullptr;
	}
}

void Boom::Update()
{
	if (FireTime > 16)
	{
		Fire = false;
	}

	// ������Ʈ �Լ��� ȣ��Ǹ�
	// if���� �˻��ϸ鼭 �ð��� �پ��� �ǰ� 0���ϰ� �Ǹ� if���� �ڵ尡 ����ȴ�. 
	// Boom Ŭ������ bool ���� Fire�� false �����̸� if�� ���Խ� true �� ����ǰ� �����ڵ� ����
	if (0 > --Time || Fire == true)
	{
		
		// ������ ���ӵǴ� �ð�üũ�� ���� �������� ������
		++FireTime;

		// ��ź�� ������ ��ġ�� �ٸ� ��ź�� �ִٸ� SetDeath;
		// ��ź�迭�� �����ͼ� ��ġ���޾ƿ� �� ���� ��ź�� ������ ��ġ�� ��ź�� �������
		Player* Player = GetOwner();
		Boom* ArrBoom = Player->GetBoomArr();

			// ���߹���üũ�� ��� �� ���ΰ�? 
			int4 BoomPos = GetPos();
	
			// FireTime ������ 1���� ���ų�ũ�� 5���� �������� 1�� ������ŭ
			if (0 < FireTime && 5 >= FireTime)
			{
				// ������ŭ �ݺ�����, ��ź �ֺ��� ������ŭ ��Ʈ�� ��µǰ� �Ѵ�.
				Range = 1;

				// FireTime �� ������ �����ϴ� ���� �ش��ϴ� ��ġ�� ��Ʈ�� ���
				// �̰� ���ͽ��÷������� �ٲٰ� ���� ��ġ�� �޾ƿͼ� ����ϴ°ɷ�
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos + int4{ Range , 0 }, L'��');
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos + int4{ -Range, 0 }, L'��');
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos + int4{ 0, Range }, L'��');
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos + int4{ 0, -Range }, L'��');
				BoomCheck(Range);
			}

			// FireTime ������ 5���� ũ�� 10���� ������ 2�ǹ������� 
			if (5 < FireTime && 10 > FireTime)
			{
				Range = 1;
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos + int4{ Range , 0 }, L'��');
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos + int4{ -Range, 0 }, L'��');
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos + int4{ 0, Range }, L'��');
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos + int4{ 0, -Range }, L'��');

				BoomCheck(Range);

				Range = 2;
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos + int4{ Range , 0 }, L'��');
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos + int4{ -Range, 0 }, L'��');
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos + int4{ 0, Range }, L'��');
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos + int4{ 0, -Range }, L'��');

				BoomCheck(Range);
			}

			if (15 > FireTime && 10 < FireTime)
			{
				Range = 1;
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos + int4{ Range , 0 }, L'��');
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos + int4{ -Range, 0 }, L'��');
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos + int4{ 0, Range }, L'��');
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos + int4{ 0, -Range }, L'��');

				BoomCheck(Range);

				Range = 2;
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos + int4{ Range , 0 }, L'��');
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos + int4{ -Range, 0 }, L'��');
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos + int4{ 0, Range }, L'��');
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos + int4{ 0, -Range }, L'��');

				BoomCheck(Range);

				Range = 3;
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos + int4{ Range , 0 }, L'��');
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos + int4{ -Range, 0 }, L'��');
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos + int4{ 0, Range }, L'��');
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(BoomPos + int4{ 0, -Range }, L'��');

				BoomCheck(Range);
			}
		return;
	}

	//   ��
	//   ��
	//�ڡڡݡڡ�
	//   ��
	//   ��

	// 1. ���������� ����� ������.
	// 1-1. ���� ������ �� �Ʒ��� 1�����̶� ���̰� �ض�. ����.
	// 1-2. �׳� ����ũ�� ��ü�� ���̰� ������.			����.
	// 1-3. �ð����� ������ ���̰� ������.
	// 
	// ���ڰ� ǥ�÷� ���� ������ �ϼ���.


	// 2. ������������� �ٸ� ��ź�� ������ ���� ��������.
	ConsoleGameScreen::GetMainScreen()->SetPixelChar(GetPos(), GetRenderChar());
}

void Boom::BoomCheck(const int _Range)
{
	const int CurRange = _Range;
	Player* Player = GetOwner();
	Boom* ArrBoom = Player->GetBoomArr();
	int4 CurPos = GetPos();

	for (size_t i = 0; i < (size_t)(Player->GetBoomUseCount()); i++)
	{
		if (ArrBoom[i].GetPos() == CurPos + int4{ Range , 0 })
		{
			ArrBoom[i].SetDeath();
		}

		if (ArrBoom[i].GetPos() == CurPos + int4{ Range , 0 })
		{
			{
				ArrBoom[i].SetDeath();
			}
		}

		if (ArrBoom[i].GetPos() == CurPos + int4{ Range , 0 })
		{
			{
				ArrBoom[i].SetDeath();
			}
		}

		if (ArrBoom[i].GetPos() == CurPos + int4{ Range , 0 })
		{
			{
				ArrBoom[i].SetDeath();
			}
		}
	}
}


