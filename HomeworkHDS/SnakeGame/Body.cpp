#include "Body.h"
#include <iostream>
#include <ConsoleGameScreen.h>
#include <ConsoleGameInput.h>

// static ������ �׻� ��ü�� ������ش�. 
Body* Body::CurBody = nullptr;

Body::Body() :
	Parts(L'��')
{
}

Body::~Body()
{
}

void Body::Update()
{
	// ���߿� �� ������ Ǯ��� �� ���ɼ��� ����.
	// ���� Ű�� �����ִٸ� 
	if (true == ConsoleGameInput::GetIsInput())
	{
		// ���������� ���ٸ� return; 
		if (nullptr == GetNext())
		{
			return;
		}

		// ���������� �ִٸ� 
		// ���������� ��ġ�� �̵� �� ���� �ִ� ��ġ�� �ȴ�. 
		SetPos(GetNext()->GetPos());
	}
}

void Body::CreateBody()
{
	// �ٵ����� �����Ҵ�
	CurBody = new Body();

	// ������ ��ġ�� ���� �ٵ��� ��ġ�� �����ش�. 
	CurBody->SetPos({ rand() % ConsoleGameScreen::GetMainScreen()->GetScreenSize().X , 
		              rand() % ConsoleGameScreen::GetMainScreen()->GetScreenSize().Y });
}


Body* Body::GetCurBody()
{
	return CurBody;
}
