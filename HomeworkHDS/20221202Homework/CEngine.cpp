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

		// ���ڿ��� ���� �ι��� ���� 
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

	// � ���ڷ� ���õǾ����� �� �� �ֵ��� ����
	Curchar = _Text;
}

// ����� 
void CEngine::Render()
{
	for (int i = 0; i < 5; ++i)
	{
		printf_s("%s", GameMap[i]);
		printf_s("\n");
	}
}

// �÷��̾�,����, �Ҹ��� ������ ���ڰ����� ���
void CEngine::SetTile(const Int4& _Pos, char _Char)
{
	Int4 Pos = _Pos;
	char DisplayChar = _Char;
	GameMap[Pos.Y][Pos.X] = DisplayChar;
}