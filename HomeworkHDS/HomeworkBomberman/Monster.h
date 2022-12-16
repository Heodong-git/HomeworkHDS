#pragma once
#include "ConsoleGameMath.h"
#include "ConsoleGameObject.h"
#include "Boom.h"
#include "CArray.h"

class Monster : public ConsoleGameObject
{
public:
	// constrcuter destructer
	Monster();
	~Monster();

	// delete Function
	Monster(const Monster& _Other) = delete;
	Monster(Monster&& _Other) noexcept = delete;
	Monster& operator=(const Monster& _Other) = delete;
	Monster& operator=(Monster&& _Other) noexcept = delete;

	bool Update();
	void Init();
	void SetNumber(const int _Number) { Number = _Number; }
protected:

private:
	int Dir = 0;
	int Time = 0;
	int4 ScreenSize;
	int Number = 0;
};


