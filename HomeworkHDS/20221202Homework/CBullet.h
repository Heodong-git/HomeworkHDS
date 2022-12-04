#pragma once
#include "ContentsMath.h"

class CEngine;
class CBullet
{
private:
	// 위치 
	Int4 Pos;
	int Att = 1;

	// 출력될 문자 
	char DisplayChar = 'B';

public:
	
	// 값세팅
	void SetPos(const Int4& _Pos) { Pos = _Pos; }
	void SetDisplayChar(const char _char) { DisplayChar = _char; }

	// 값반환 
	const Int4& GetPos() { return Pos; }
	const char GetDisplayChar() { return DisplayChar; }
	const int GetAtt() { return Att; }

};

