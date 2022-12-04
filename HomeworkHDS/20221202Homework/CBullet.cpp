#include "CBullet.h"
#include "CMonster.h"
#include "CEngine.h"
#include <conio.h>
#include <Windows.h>

void CBullet::Update(CEngine& _Engine, CMonster& _Monster)
{
	// 몬스터가 현재 데드상태라면 return;
	if (IsDead() == true)
	{
		return;
	}

	// 키보드가 눌리지 않았다면 0 
	if (0 == _kbhit())
	{
		return;
	}
	// 눌렸다면 아래 코드 동작
	// 눌린 값 저장 
	int Input = _getch();

	// 눌린 값이 무엇이냐에 따라서 동작
	switch (Input)
	{
	case 'j':
	case 'J':
	{
		// 몬스터의 현재위치를 받아온다.
		Int4 CurPos = GetPos();

		// 현재위치의 X 값이 0보다 작거나 같다면 이동하지 않는다.
		if (0 >= CurPos.X)
		{
			//SetPos(CurPos);
			return;
		}

		// 이동 
		Move({ -1, 0 });

		// 이동 후 이전에 플레이어가 있던 위치를 기존에 세팅된 문자로 변경
		const char Setchar = _Engine.GetChar();
		// 플레이어가 이동하기전 위치를 받아놨기 때문에 그자리에 
		// 맵에 세팅되어있는 문자값을 세팅한다. 
		_Engine.SetTile(CurPos, Setchar);
	}
	break;
	case 'i':
	case 'I':
	{
		Int4 CurPos = GetPos();

		// 현재위치의 Y 값이 0보다 작거나 같다면 이동하지 않는다. 
		if (0 >= CurPos.Y)
		{
			return;
		}

		Move({ 0, -1 });

		const char Setchar = _Engine.GetChar();
		_Engine.SetTile(CurPos, Setchar);
	}
	break;
	case 'k':
	case 'K':
	{
		Int4 CurPos = GetPos();

		// 현재위치의 Y 값이 4보다 크거나 같다면 이동하지 않는다.
		if (4 <= CurPos.Y)
		{
			return;
		}

		Move({ 0, 1 });

		const char Setchar = _Engine.GetChar();
		_Engine.SetTile(CurPos, Setchar);
	}
	break;
	case 'l':
	case 'L':
	{
		Int4 CurPos = GetPos();

		// 현재위치의 X 값이 4보다 크거나 같다면 이동하지 않는다.
		if (4 <= CurPos.X)
		{
			return;
		}
		Move({ 1, 0 });

		const char Setchar = _Engine.GetChar();
		_Engine.SetTile(CurPos, Setchar);
	}
	break;
	default:
		break;
	}

	
	Int4 BulletPos = GetPos();
	Int4 MonsterPos = _Monster.GetPos();

	// 현재 몬스터의 위치와 총알의 위치가 동일하다면 
	// 둘다 데드처리 후 출력되는 문자변경
	if (BulletPos == MonsterPos)
	{
		// 데드상태를 true로 만든다. 
		SetDead();
		_Monster.SetDead();

		// 현재위치에 엔진맵으로 사용된 문자값을 대입
		const char MapText = _Engine.GetChar();

		_Engine.SetTile(GetPos(), MapText);
	}
}
