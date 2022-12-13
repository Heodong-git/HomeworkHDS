#pragma once
#include "ConsoleGameObject.h"

class BoomExplosion : public ConsoleGameObject
{
public:
	// constrcuter destructer
	BoomExplosion();
	~BoomExplosion();

	// delete Function
	BoomExplosion(const BoomExplosion& _Other) = delete;
	BoomExplosion(BoomExplosion&& _Other) noexcept = delete;
	BoomExplosion& operator=(const BoomExplosion& _Other) = delete;
	BoomExplosion& operator=(BoomExplosion&& _Other) noexcept = delete;

	void Update();

private:
	int4 Pos;	// À§Ä¡
};

