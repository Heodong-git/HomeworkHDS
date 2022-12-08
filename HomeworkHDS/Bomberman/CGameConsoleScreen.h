#pragma once

typedef class CGameConsoleScreen
{
public:
	CGameConsoleScreen();
	~CGameConsoleScreen();

	// ���������
	// RValue������
	// ���۷����� =
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

