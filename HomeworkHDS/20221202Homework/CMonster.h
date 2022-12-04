#pragma once
#include "ContentsMath.h"

class CEngine;
class CBullet;
class CMonster
{
private:
	// ��ġ 
	Int4 Pos;
	bool Dead = false;

	// ��µ� ����
	char DisplayChar = 'M';

public:
	void Update(CEngine& _Engine, CBullet& _Bullet);
	// ������
	void SetPos(const Int4& _Pos) { Pos = _Pos; }
	void SetDisplayChar(const char _char) { DisplayChar = _char; }
	void SetDead() { Dead = true; }

	// ����ȯ 
	const Int4& GetPos() { return Pos; }
	const char GetDisplayChar() { return DisplayChar; }

	// ��ġ�̵�
	void Move(const Int4& _Dir) { Pos += _Dir; }
	bool IsDead() { return Dead; }

};

