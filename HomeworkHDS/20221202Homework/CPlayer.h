#pragma once
#include "ContentsMath.h"	

class CEngine;

class CPlayer
{
private:
	// ��ġ 
	Int4 Pos;

	// ��µ� ���� (�÷��̾�) 
	char DisplayChar = '*';

public:
	void Update(CEngine& _Engine);
	// ������
	void SetPos(const Int4& _Pos) { Pos = _Pos; }
	void SetDisplayChar(const char _char) { DisplayChar = _char; }

	// ����ȯ 
	const Int4& GetPos() { return Pos; }
	const char GetDisplayChar() { return DisplayChar; }

	// ��ġ�̵�
	void Move(const Int4& _Dir) { Pos += _Dir; }
};

