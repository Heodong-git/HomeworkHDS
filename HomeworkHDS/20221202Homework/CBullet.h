#pragma once
#include "ContentsMath.h"

class CEngine;
class CBullet
{
private:
	// ��ġ 
	Int4 Pos;
	int Att = 1;

	// ��µ� ���� 
	char DisplayChar = 'B';

public:
	
	// ������
	void SetPos(const Int4& _Pos) { Pos = _Pos; }
	void SetDisplayChar(const char _char) { DisplayChar = _char; }

	// ����ȯ 
	const Int4& GetPos() { return Pos; }
	const char GetDisplayChar() { return DisplayChar; }
	const int GetAtt() { return Att; }

};

