#pragma once
#include "ContentsMath.h"

class CEngine;
class CMonster;
class CBullet
{
private:
	// 위치 
	Int4 Pos;
	int Att = 1;
	bool Dead = false;

	// 출력될 문자 
	char DisplayChar = 'B';

public:
	void Update(CEngine& _Engine, CMonster& _Monster);
	// 값세팅
	void SetPos(const Int4& _Pos) { Pos = _Pos; }
	void SetDisplayChar(const char _char) { DisplayChar = _char; }
	void SetDead() { Dead = true; }

	// 값반환 
	const Int4& GetPos() { return Pos; }
	const char GetDisplayChar() { return DisplayChar; }
	const int GetAtt() { return Att; }
	bool IsDead() { return Dead; }

	// 위치이동
	void Move(const Int4& _Dir) { Pos += _Dir; }
};

