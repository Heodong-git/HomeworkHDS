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
	// 시드값을 시간값으로
	srand(time(nullptr));

	// 랜덤 좌표 설정
	int4 RandPos = int4{ rand() % ConsoleGameScreen::GetMainScreen()->GetScreenSize().X ,
					  rand() % ConsoleGameScreen::GetMainScreen()->GetScreenSize().Y };

	// 겹치는걸 체크할 변수 
	bool PosCheck = true;

	// 현재 연결되어있는 파츠가 저장된 배열을 검사
	for (size_t i = 0; i < Parts::GetVecParts().size(); i++)
	{
		// 랜덤생성된 좌표와 현재 파츠가 있는 위치가 동일하다면
		if (Parts::GetVecParts()[i]->GetPos() == RandPos)
		{
			PosCheck = false;
		}
	}

	// true 일 경우 위치가 겹치지 않는다는 의미.
	// 그 위치에 생성한다. 
	if (true == PosCheck)
	{
		// 바디 생성 후 배열에 넣어주고 위치세팅
		CurBody = new Body();
		CurBody->SetPos(RandPos);
	}

	// 만약 false 인 경우라면 현재 설정된 위치가겹친다는 의미
	if (false == PosCheck)
	{
		// 겹치지 않는 위치가 나올때 까지 반복해야하기 때문에 함수 재귀호출
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

// 랜덤위치설정함수
int4 Body::RecursionRandPos()
{
	// 현재 생성된 바디의 개수가 스크린사이즈총 개수 -1 개와 같거나 크다면 더이상 생성할 곳이 없음
	int4 ScreenSize = ConsoleGameScreen::GetMainScreen()->GetScreenSize();
	size_t MaxScreenSize = (size_t)(ScreenSize.X * ScreenSize.Y);

	// 현재 화면이 꽉 찼기 때문에 assert / 근데 화면이 꽉찼으면 게임이긴건데
	// 게임 Win 으로 어떻게..? 
	if (MaxScreenSize <= Parts::GetVecParts().size())
	{
		MessageBoxAssert("더이상 파츠를 생성할 수 없습니다.");
	}

	// 랜덤위치설정
	int4 RandPos = int4{ rand() % ConsoleGameScreen::GetMainScreen()->GetScreenSize().X ,
					  rand() % ConsoleGameScreen::GetMainScreen()->GetScreenSize().Y };

	// 체크변수 
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
		// 재귀호출
		return RandPos = RecursionRandPos();
	}

	// 여기까지 코드가 내려와서 동작한다면 체크변수가 true 라는 의미
	return RandPos;
}

