#pragma once
#include "ContentsMath.h"

class CEngine;
class CBullet;
class CMonster
{
private:
	// 위치 
	Int4 Pos;
	bool Dead = false;

	// 출력될 문자
	char DisplayChar = 'M';

public:
	void Update(CEngine& _Engine, CBullet& _Bullet);
	// 값세팅
	void SetPos(const Int4& _Pos) { Pos = _Pos; }
	void SetDisplayChar(const char _char) { DisplayChar = _char; }
	void SetDead() { Dead = true; }

	// 값반환 
	const Int4& GetPos() { return Pos; }
	const char GetDisplayChar() { return DisplayChar; }

	// 위치이동
	void Move(const Int4& _Dir) { Pos += _Dir; }
	bool IsDead() { return Dead; }

};

