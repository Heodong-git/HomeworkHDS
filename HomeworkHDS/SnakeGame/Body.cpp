#include "Body.h"
#include <iostream>
#include <ConsoleGameScreen.h>
#include <ConsoleGameInput.h>

// static 변수는 항상 실체를 만들어준다. 
Body* Body::CurBody = nullptr;
Body::Body() :
	Parts(L'★')
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
	// 나중에 이 제한을 풀어야 할 가능성이 높다.
	// 현재 키가 눌려있다면 
	if (true == ConsoleGameInput::GetIsInput())
	{
		// 다음파츠가 없다면 return; 
		if (nullptr == GetNext())
		{
			return true;
		}

		// 다음파츠가 있다면 
		// 다음파츠의 위치는 이동 전 내가 있던 위치가 된다. 
		SetPos(GetNext()->GetPos());
	}

	return true;
}

void Body::CreateBody()
{
	// 랜덤한 위치에 다음 바디의 위치를 정해준다. 
	// 먼저 이 랜덤 위치를 받아두고 세팅을 하는 걸로 하고
	// 이 위치랑 현재 배열에 저장된 파츠들의 위치를 먼저 비교해서 겹치지 않을 경우에만
	// SetPos
	// 랜덤위치를 받고 
	srand(time(nullptr));

	int4 RandPos = int4{ rand() % ConsoleGameScreen::GetMainScreen()->GetScreenSize().X ,
					  rand() % ConsoleGameScreen::GetMainScreen()->GetScreenSize().Y };

	bool PosCheck = true;

	for (size_t i = 0; i < Parts::GetVecParts().size(); i++)
	{
		// 랜덤생성된 좌표와 현재 파츠가 있는 위치가 동일하다면
		if (Parts::GetVecParts()[i]->GetPos() == RandPos)
		{
			PosCheck = false;
		}
	}

	// 겹치지 않는 위치라면 
	if (true == PosCheck)
	{
		// 바디 생성 후 배열에 넣어주고 위치세팅
		CurBody = new Body();
		CurBody->SetPos(RandPos);
	}

	// 만약 false 인 경우라면 랜덤위치를 다시 설정해주고
	if (false == PosCheck)
	{
		// 재귀호출로 랜덤위치 설정후 
		RandPos = RecursionRandPos();
		// 바디 생성 후 배열에 넣어주고 위치세팅
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
	// 현재 생성된 바디의 개수가 스크린사이즈총 개수 -1 개와 같거나 크다면 더이상 생성할 곳이 없음
	int4 ScreenSize = ConsoleGameScreen::GetMainScreen()->GetScreenSize();
	size_t MaxScreenSize = (size_t)(ScreenSize.X * ScreenSize.Y);


	if (MaxScreenSize <= Parts::GetVecParts().size())
	{
		MessageBoxAssert("더이상 파츠를 생성할 수 없습니다.");
	}

	int4 RandPos = int4{ rand() % ConsoleGameScreen::GetMainScreen()->GetScreenSize().X ,
					  rand() % ConsoleGameScreen::GetMainScreen()->GetScreenSize().Y };

	bool PosCheck = true;

	for (size_t i = 0; i < Parts::GetVecParts().size(); i++)
	{
		// 랜덤생성된 좌표와 현재 파츠가 있는 위치가 동일하다면
		if (Parts::GetVecParts()[i]->GetPos() == RandPos)
		{
			PosCheck = false;
		}
	}	

	// 만약 false 인 경우라면 랜덤위치를 다시 설정해야한다. 
	if (false == PosCheck)
	{
		return RandPos = RecursionRandPos();
	}

	return RandPos;
}

