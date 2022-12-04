#pragma once
#include "ContentsMath.h"	

class CEngine;

class CPlayer
{
private:
	// 위치 
	Int4 Pos;

	// 출력될 문자 (플레이어) 
	char DisplayChar = '*';

public:
	void Update(CEngine& _Engine);
	// 값세팅
	void SetPos(const Int4& _Pos) { Pos = _Pos; }
	void SetDisplayChar(const char _char) { DisplayChar = _char; }

	// 값반환 
	const Int4& GetPos() { return Pos; }
	const char GetDisplayChar() { return DisplayChar; }

	// 위치이동
	void Move(const Int4& _Dir) { Pos += _Dir; }
};

