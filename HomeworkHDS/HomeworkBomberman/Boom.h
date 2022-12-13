#pragma once
#include "ConsoleGameMath.h"
#include "ConsoleGameObject.h"

// ���� :

class ConsoleGameScreen;
class Player;
class BoomExplosion;

class Boom : public ConsoleGameObject
{
public:
	// constrcuter destructer
	Boom();
	~Boom();

	// delete Function
	Boom(const Boom& _Other) = delete;
	Boom(Boom&& _Other) noexcept = delete;
	Boom& operator=(const Boom& _Other) = delete;
	Boom& operator=(Boom&& _Other) noexcept = delete;

	void Update();

	bool IsDeath()
	{
		return 0 > Time;
	}

	void SetDeath() { Fire = true; }
	void SetOwner(Player* _Owner) { Owner = _Owner; }
	Player* const GetOwner() { return Owner; }
	void BoomCheck(const int _Range);

protected:

private:
	Player* Owner = nullptr;
	BoomExplosion* ArrBoomExplosion;
	bool Fire = false;
	int Time = 20;
	int Range = 3;
	int FireTime = 0;
};
