#pragma once

typedef class CGameConsoleScreen
{
public:
	CGameConsoleScreen();
	~CGameConsoleScreen();

	// 복사생성자
	// RValue생성자
	// 오퍼레이터 =
	// delete Function
	ConsoleGameScreen(const ConsoleGameScreen& _Other) = delete;
	ConsoleGameScreen(ConsoleGameScreen&& _Other) noexcept = delete;
	ConsoleGameScreen& operator=(const ConsoleGameScreen& _Other) = delete;
	ConsoleGameScreen& operator=(ConsoleGameScreen&& _Other) noexcept = delete;
	
private:
	
public:
	void ScreenInit();
	void ScreenRender();
	void ScreenClear();

} CScreen;

