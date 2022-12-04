#include "CEngine.h"
#include <iostream>
#include "ContentsMath.h"

void CEngine::Init()
{
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			GameMap[i][j] = 0;
		}

		// 문자열의 끝에 널문자 삽입 
		GameMap[i][5] = 0;
	}
}

void CEngine::SetMap(const char _Text)
{
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			GameMap[i][j] = _Text;
			GameMap[i][j + 1] = 0;
		}
	}

	// 어떤 문자로 세팅되었는지 알 수 있도록 저장
	Curchar = _Text;
}

// 맵출력 
void CEngine::Render()
{
	for (int i = 0; i < 5; ++i)
	{
		printf_s("%s", GameMap[i]);
		printf_s("\n");
	}
}

// 플레이어,몬스터, 불릿에 설정된 문자값으로 출력
void CEngine::SetTile(const Int4& _Pos, char _Char)
{
	Int4 Pos = _Pos;
	char DisplayChar = _Char;
	GameMap[Pos.Y][Pos.X] = DisplayChar;
}