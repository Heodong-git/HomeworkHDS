#include "Head.h"
#include <ConsoleGameScreen.h>
#include <ConsoleGameInput.h>
#include <conio.h>
#include "Body.h"
#include <iostream>

Head::Head()
	: Parts(L'◆')
{
}

Head::~Head()
{
}

bool Head::Update()
{
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
			return false;
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
			// 내가 이동하려는 위치에 나의 파츠중 일부가 있다면 게임종료 
			std::vector<Parts*>& CurVecParts = Parts::GetVecParts();

			for (size_t i = 0; i < CurVecParts.size(); i++)
			{
				if (NextPos == CurVecParts[i]->GetPos())
				{
					return false;
				}
			}
			
			// 종료되지 않았다면 이동진행

			// 마지막에 연결된 파츠를 받아온다.
			Parts* LastParts = GetLastParts();
			
			// 마지막 파츠의 위치를 받아온다.
			int4 PrevPos = LastParts->GetPos();

			// 연결된 파츠를 모두 앞으로 이동시킨 후 
			LastParts->RecursionNextMove();

			SetPos(NextPos);
			
			// 나의 위치가 현재 생성된 바디의 위치와 동일하다면
			// (파츠를 먹은 것) 
			if (GetPos() == Body::GetCurBody()->GetPos())
			{
				// 먹은 파츠의 위치는 내가 파츠를 먹기전에 마지막파츠가 위치해있던 자리
				Body::GetCurBody()->SetPos(PrevPos);
				Parts::GetVecParts().push_back(Body::GetCurBody());
				// 렌더링 문자를 변경시켜준다. 
				Body::GetCurBody()->SetRenderChar(L'●');
				// 마지막파츠의 이전파츠로 먹은파츠를 연결시켜준다. 
				LastParts->SetPrev(Body::GetCurBody());
				// 새로운 파츠를 만든다. 
				Body::CreateBody();
			}
		}
	}
	
	return true;
}