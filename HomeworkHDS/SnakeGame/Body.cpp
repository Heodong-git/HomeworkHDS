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
	// �õ尪�� �ð�������
	srand(time(nullptr));

	// ���� ��ǥ ����
	int4 RandPos = int4{ rand() % ConsoleGameScreen::GetMainScreen()->GetScreenSize().X ,
					  rand() % ConsoleGameScreen::GetMainScreen()->GetScreenSize().Y };

	// ��ġ�°� üũ�� ���� 
	bool PosCheck = true;

	// ���� ����Ǿ��ִ� ������ ����� �迭�� �˻�
	for (size_t i = 0; i < Parts::GetVecParts().size(); i++)
	{
		// ���������� ��ǥ�� ���� ������ �ִ� ��ġ�� �����ϴٸ�
		if (Parts::GetVecParts()[i]->GetPos() == RandPos)
		{
			PosCheck = false;
		}
	}

	// true �� ��� ��ġ�� ��ġ�� �ʴ´ٴ� �ǹ�.
	// �� ��ġ�� �����Ѵ�. 
	if (true == PosCheck)
	{
		// �ٵ� ���� �� �迭�� �־��ְ� ��ġ����
		CurBody = new Body();
		CurBody->SetPos(RandPos);
	}

	// ���� false �� ����� ���� ������ ��ġ����ģ�ٴ� �ǹ�
	if (false == PosCheck)
	{
		// ��ġ�� �ʴ� ��ġ�� ���ö� ���� �ݺ��ؾ��ϱ� ������ �Լ� ���ȣ��
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

// ������ġ�����Լ�
int4 Body::RecursionRandPos()
{
	// ���� ������ �ٵ��� ������ ��ũ���������� ���� -1 ���� ���ų� ũ�ٸ� ���̻� ������ ���� ����
	int4 ScreenSize = ConsoleGameScreen::GetMainScreen()->GetScreenSize();
	size_t MaxScreenSize = (size_t)(ScreenSize.X * ScreenSize.Y);

	// ���� ȭ���� �� á�� ������ assert / �ٵ� ȭ���� ��á���� �����̱�ǵ�
	// ���� Win ���� ���..? 
	if (MaxScreenSize <= Parts::GetVecParts().size())
	{
		MessageBoxAssert("���̻� ������ ������ �� �����ϴ�.");
	}

	// ������ġ����
	int4 RandPos = int4{ rand() % ConsoleGameScreen::GetMainScreen()->GetScreenSize().X ,
					  rand() % ConsoleGameScreen::GetMainScreen()->GetScreenSize().Y };

	// üũ���� 
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
		// ���ȣ��
		return RandPos = RecursionRandPos();
	}

	// ������� �ڵ尡 �����ͼ� �����Ѵٸ� üũ������ true ��� �ǹ�
	return RandPos;
}

