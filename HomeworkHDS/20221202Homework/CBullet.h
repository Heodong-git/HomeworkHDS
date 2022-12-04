#pragma once
#include "ContentsMath.h"

class CEngine;
class CMonster;
class CBullet
{
private:
	// ��ġ 
	Int4 Pos;
	int Att = 1;
	bool Dead = false;

	// ��µ� ���� 
	char DisplayChar = 'B';

public:
	void Update(CEngine& _Engine, CMonster& _Monster);
	// ������
	void SetPos(const Int4& _Pos) { Pos = _Pos; }
	void SetDisplayChar(const char _char) { DisplayChar = _char; }
	void SetDead() { Dead = true; }

	// ����ȯ 
	const Int4& GetPos() { return Pos; }
	const char GetDisplayChar() { return DisplayChar; }
	const int GetAtt() { return Att; }
	bool IsDead() { return Dead; }

	// ��ġ�̵�
	void Move(const Int4& _Dir) { Pos += _Dir; }
};

