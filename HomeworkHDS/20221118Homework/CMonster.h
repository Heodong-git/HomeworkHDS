#pragma once

class CMonster
{
private:
	int iAtt;
	int iHp;

public:
	int GetAtt() { return iAtt; }
	int GetHp() { return iHp; }

	void StatusRender();
	void Damage(int _Att);
	bool IsDead() { return iHp <= 0; }

public:
	CMonster();
	~CMonster();
};

