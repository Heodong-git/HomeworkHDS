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
	/*for (size_t i = 0; i < VecBody.size(); i++)
	{
		if (nullptr != VecBody[i])
		{
			delete VecBody[i];
			VecBody[i] = nullptr;
		}
	}*/
}

bool Body::Update()
{
	// ���߿� �� ������ Ǯ��� �� ���ɼ��� ����.
	// ���� Ű�� �����ִٸ� 
	if (true == ConsoleGameInput::GetIsInput())
	{
		// ���������� ���ٸ� return; 
		if (nullptr == GetNext())
		{
			return true;
		}

		// ���������� �ִٸ� 
		// ���������� ��ġ�� �̵� �� ���� �ִ� ��ġ�� �ȴ�. 
		SetPos(GetNext()->GetPos());
	}

	return true;
}

void Body::CreateBody()
{
	// ������ ��ġ�� ���� �ٵ��� ��ġ�� �����ش�. 
	// ���� �� ���� ��ġ�� �޾Ƶΰ� ������ �ϴ� �ɷ� �ϰ�
	// �� ��ġ�� ���� �迭�� ����� �������� ��ġ�� ���� ���ؼ� ��ġ�� ���� ��쿡��
	// SetPos
	// ������ġ�� �ް� 
	srand(time(nullptr));

	int4 RandPos = int4{ rand() % ConsoleGameScreen::GetMainScreen()->GetScreenSize().X ,
					  rand() % ConsoleGameScreen::GetMainScreen()->GetScreenSize().Y };

	bool PosCheck = true;

	for (size_t i = 0; i < Parts::GetVecParts().size(); i++)
	{
		// ���������� ��ǥ�� ���� ������ �ִ� ��ġ�� �����ϴٸ�
		if (Parts::GetVecParts()[i]->GetPos() == RandPos)
		{
			PosCheck = false;
		}
	}

	// ��ġ�� �ʴ� ��ġ��� 
	if (true == PosCheck)
	{
		// �ٵ� ���� �� �迭�� �־��ְ� ��ġ����
		CurBody = new Body();
		CurBody->SetPos(RandPos);
	}

	// ���� false �� ����� ������ġ�� �ٽ� �������ְ�
	if (false == PosCheck)
	{
		// ���ȣ��� ������ġ ������ 
		RandPos = RecursionRandPos();
		// �ٵ� ���� �� �迭�� �־��ְ� ��ġ����
		CurBody = new Body();
		CurBody->SetPos(RandPos);
	}
}

Body* Body::GetCurBody()
{
	return CurBody;
}

int4 Body::RecursionRandPos()
{
	// ���� ������ �ٵ��� ������ ��ũ���������� ���� -1 ���� ���ų� ũ�ٸ� ���̻� ������ ���� ����
	int4 ScreenSize = ConsoleGameScreen::GetMainScreen()->GetScreenSize();
	size_t MaxScreenSize = (size_t)(ScreenSize.X * ScreenSize.Y);


	if (MaxScreenSize <= Parts::GetVecParts().size())
	{
		MessageBoxAssert("���̻� ������ ������ �� �����ϴ�.");
	}

	int4 RandPos = int4{ rand() % ConsoleGameScreen::GetMainScreen()->GetScreenSize().X ,
					  rand() % ConsoleGameScreen::GetMainScreen()->GetScreenSize().Y };

	bool PosCheck = true;

	for (size_t i = 0; i < Parts::GetVecParts().size(); i++)
	{
		// ���������� ��ǥ�� ���� ������ �ִ� ��ġ�� �����ϴٸ�
		if (Parts::GetVecParts()[i]->GetPos() == RandPos)
		{
			PosCheck = false;
		}
	}	

	// ���� false �� ����� ������ġ�� �ٽ� �����ؾ��Ѵ�. 
	if (false == PosCheck)
	{
		return RandPos = RecursionRandPos();
	}

	return RandPos;
}

