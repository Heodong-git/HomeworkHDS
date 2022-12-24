#include "Head.h"
#include <ConsoleGameScreen.h>
#include <ConsoleGameInput.h>
#include <conio.h>
#include "Body.h"
#include <iostream>

Head::Head()
	: Parts(L'��')
{
}

Head::~Head()
{
}

bool Head::Update()
{
	// ����� ������Ʈ������ Ű�Է��� �Ǿ��� ���� ������Ʈ�� �����Ѵ�.
	if (true == ConsoleGameInput::GetIsInput())
	{
		// ���� Ű�� �޾ƿ´�. 
		int Input = ConsoleGameInput::GetKey();
		
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
			return false;
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
		// ���� ����Ǿ� �ִ� ������ �ֱ� ������ �� �κе� ���� 
		if (true == IsMove)
		{
			// ���� �̵��Ϸ��� ��ġ�� ���� ������ �Ϻΰ� �ִٸ� �������� 
			std::vector<Parts*>& CurVecParts = Parts::GetVecParts();

			for (size_t i = 0; i < CurVecParts.size(); i++)
			{
				if (NextPos == CurVecParts[i]->GetPos())
				{
					return false;
				}
			}
			
			// ������� �ʾҴٸ� �̵�����

			// �������� ����� ������ �޾ƿ´�.
			Parts* LastParts = GetLastParts();
			
			// ������ ������ ��ġ�� �޾ƿ´�.
			int4 PrevPos = LastParts->GetPos();

			// ����� ������ ��� ������ �̵���Ų �� 
			LastParts->RecursionNextMove();

			SetPos(NextPos);
			
			// ���� ��ġ�� ���� ������ �ٵ��� ��ġ�� �����ϴٸ�
			// (������ ���� ��) 
			if (GetPos() == Body::GetCurBody()->GetPos())
			{
				// ���� ������ ��ġ�� ���� ������ �Ա����� ������������ ��ġ���ִ� �ڸ�
				Body::GetCurBody()->SetPos(PrevPos);
				Parts::GetVecParts().push_back(Body::GetCurBody());
				// ������ ���ڸ� ��������ش�. 
				Body::GetCurBody()->SetRenderChar(L'��');
				// ������������ ���������� ���������� ��������ش�. 
				LastParts->SetPrev(Body::GetCurBody());
				// ���ο� ������ �����. 
				Body::CreateBody();
			}
		}
	}
	
	return true;
}