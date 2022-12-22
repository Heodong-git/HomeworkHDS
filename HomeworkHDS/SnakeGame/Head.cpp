#include "Head.h"
#include <ConsoleGameScreen.h>
#include <ConsoleGameInput.h>
#include <conio.h>
#include "Body.h"

Head::Head()
	: Parts(L'��')
{
}

Head::~Head()
{
}

void Head::Update()
{
	// ��忡 ����Ǿ� �ִ� ���� ������ ���ٸ� �������� ����
	if (nullptr != GetPrev())
	{
		// �ִٸ� ������ ��;�����Ʈ
		RecursionPrevUpdate();
		// ������ ��ͷ�����
		RecursionPrevRender();
	}

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
		// ���� ����Ǿ� �ִ� ������ �ֱ� ������ �� �κе� ���� 
		if (true == IsMove)
		{
			// ����Լ��� ȣ���Ͽ� ���� ������ ������ �޾ƿ´�.
			Parts* PrevParts = GetRecursionLastParts();
			
			// ������ġ�� ���� ������ ������ ��ġ
			int4 CurPos = PrevParts->GetPos();

			// �ڽ��� �̵���ġ�� �������ش�.
			SetPos(NextPos);
 
			// ���� �ٵ��� ������ġ�� ���� ��ġ�� ���ٸ� ( ���� �ٵ� �Ծ��ٸ� ) 
			if (Body::GetCurBody()->GetPos() == GetPos())
			{
				// ���� �ٵ��� ��ġ�� ������ ���� �����ϴ� ��ġ
				Body::GetCurBody()->SetPos(CurPos);
				// ���� ������ ������ ���� ������ ���� ������ �ȴ�. 
				PrevParts->SetPrev(Body::GetCurBody());
				// ������ġ�� �ٵ� ����
				Body::CreateBody();
			}
		}
	}
	
}