#include "Head.h"
#include <ConsoleGameScreen.h>
#include <ConsoleGameInput.h>
#include <conio.h>
#include "Body.h"

Head::Head()
	: Parts(L'◆')
{
}

Head::~Head()
{
}

void Head::Update()
{
	// 헤드에 연결되어 있는 이전 파츠가 없다면 실행하지 않음
	if (nullptr != GetPrev())
	{
		// 있다면 파츠의 재귀업데이트
		RecursionPrevUpdate();
		// 파츠의 재귀렌더링
		RecursionPrevRender();
	}

	// 헤드의 업데이트에서는 키입력이 되었을 때만 업데이트를 수행한다.
	if (true == ConsoleGameInput::GetIsInput())
	{
		// 눌린 키를 받아온다. 
		int Input = ConsoleGameInput::GetKey();
		
		// 이동할 위치를 받아둔다. 
		// 아래 분기처리에서 연산
		int4 NextPos = GetPos();

		// 값에 따른 분기처리 
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

		// 이동가능상태 true 
		bool IsMove = true;

		// 다음위치가 화면바깥이라면 이동불가처리
		if (true == ConsoleGameScreen::GetMainScreen()->IsOver(NextPos))
		{
			// 이동불가
			IsMove = false;
		}

		// IsMove 가 true 일 경우에만 위치를 이동시켜준다. 
		// 현재 연결되어 있는 파츠가 있기 때문에 그 부분도 연산 
		if (true == IsMove)
		{
			// 재귀함수를 호출하여 가장 마지막 파츠를 받아온다.
			Parts* PrevParts = GetRecursionLastParts();
			
			// 현재위치는 가장 마지막 파츠의 위치
			int4 CurPos = PrevParts->GetPos();

			// 자신을 이동위치로 세팅해준다.
			SetPos(NextPos);
 
			// 만약 바디의 현재위치가 나의 위치와 같다면 ( 내가 바디를 먹었다면 ) 
			if (Body::GetCurBody()->GetPos() == GetPos())
			{
				// 현재 바디의 위치는 이전에 내가 존재하던 위치
				Body::GetCurBody()->SetPos(CurPos);
				// 가장 마지막 파츠의 이전 파츠는 현재 파츠가 된다. 
				PrevParts->SetPrev(Body::GetCurBody());
				// 랜덤위치에 바디 생성
				Body::CreateBody();
			}
		}
	}
	
}