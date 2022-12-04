#pragma once


class CPlayer
{
private:
	int iAtt;
	int iHp;
	
public:
	int GetAtt() { return iAtt; }
	int GetHp()  { return iHp; }

public:
	void StatusRender();
	void Damage(int _Att);
	bool IsDead() { return iHp <= 0; }

public:
	CPlayer();
	~CPlayer();
};

