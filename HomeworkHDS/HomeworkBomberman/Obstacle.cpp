#include "Obstacle.h"
#include "ConsoleGameScreen.h"

Obstacle* Obstacle::MainObstacle = nullptr;

Obstacle::Obstacle()
{
	SetRenderChar(L'¡Ø');
	MainObstacle = this;
}

Obstacle::~Obstacle()
{
	if (nullptr != m_BasicObstacleArr)
	{
		delete[] m_BasicObstacleArr;
		m_BasicObstacleArr = nullptr;
	}
}

void Obstacle::Init(const int4 _Size)
{
	m_ScreenSize = _Size;
	m_ObstacleSize = (m_ScreenSize.X + m_ScreenSize.Y) / 2;
	m_BasicObstacleArr = new Obstacle[m_ObstacleSize];
}

void Obstacle::Update()
{
	ConsoleGameScreen* MainScreen = ConsoleGameScreen::GetMainScreen();
	int4 RenderPos = {};

	
	/*for (int y = 0; y < m_ScreenSize.Y; y += 2)
	{   
		int Idx = 0;
		for (int x = 0; x < m_ScreenSize.X; x += 2)
		{
			if(Idx >= m_ObstacleSize)
			m_BasicObstacleArr[Idx].SetPos(int4{ x,y });
			++Idx;
		}
	}*/

	for (int y = 0; y < m_ScreenSize.Y; y += 2)
	{
		for (int x = 0; x < m_ScreenSize.X; x += 2)
		{
			MainScreen->SetPixelChar(int4{ x, y }, GetRenderChar());
        }
	}
	
	
}
