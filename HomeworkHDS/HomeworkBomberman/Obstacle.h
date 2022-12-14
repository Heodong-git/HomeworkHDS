#pragma once
#include "ConsoleGameObject.h"

class Obstacle : public ConsoleGameObject
{
private:
	static Obstacle* MainObstacle;

public:
	static Obstacle* GetObstacle()
	{
		return MainObstacle;
	}

public:
	// constrcuter destructer
	Obstacle();
	~Obstacle();

	// delete Function
	Obstacle(const Obstacle& _Other) = delete;
	Obstacle(Obstacle&& _Other) noexcept = delete;
	Obstacle& operator=(const Obstacle& _Other) = delete;
	Obstacle& operator=(Obstacle&& _Other) noexcept = delete;

public:
	void Init(const int4 _Size);
	void Update();
	Obstacle* GetObstacleArr() { return m_ObstacleArr; }

public:
	Obstacle* m_ObstacleArr = nullptr;
	int4 m_ScreenSize;
	int m_ObstacleSize = 0;
};
