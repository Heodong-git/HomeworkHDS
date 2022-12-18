#pragma once
#include "ConsoleGameMath.h"
#include "CArray.h"
#include "ConsoleGameObject.h"

// Ό³Έν :
class Monster : public ConsoleGameObject
{

public:
	static size_t MonsterUpdateCount;

	static Monster* CreateMonster(int4 _Pos, int4 _Dir);

	static void AllMonsterInit(wchar_t _BaseChar);

	static void AllMonsterUpdate();

	// delete Function
	Monster(const Monster& _Other) = delete;
	Monster(Monster&& _Other) noexcept = delete;

	Monster& operator=(const Monster& _Other)
	{
		return *this;
	}

	Monster& operator=(Monster&& _Other) noexcept = delete;

	void SetDir(int4 _Dir)
	{
		Dir = _Dir;
	}

	bool IsMonster(int4 _Pos);

	static CArray<Monster>& GetAllMonster() { return AllMonster; }

	void Update();

	void SetDead() { Dead = true; }

	Monster();
	~Monster();

protected:

private:
	static CArray<Monster> AllMonster;

	int4 Dir;
	bool Dead = false;
	void Init();

};

