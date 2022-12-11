#pragma once
#include "ConsoleGameMath.h"

class CConsoleGameLine;

typedef class CConsoleGameScreen
{
public:
	CConsoleGameScreen();
	~CConsoleGameScreen();

	// ���������
	// RValue������
	// ���۷����� = 
	// �Լ�����ó���� �صΰ�, ���߿� �ʿ��� ��Ȳ�� �Ǹ� ����Ͽ� ��뿩�θ� �����Ѵ�. 
	CConsoleGameScreen(const CConsoleGameScreen& _Other) = delete;
	CConsoleGameScreen(CConsoleGameScreen&& _Other) noexcept = delete;
	CConsoleGameScreen& operator=(const CConsoleGameScreen& _Other) = delete;
	CConsoleGameScreen& operator=(CConsoleGameScreen&& _Other) noexcept = delete;

	// ����ȯ

	// ��ũ�������� ��ȯ
	const int4& GetScreenSize() { return m_ScreenSize; }
	// �����Ϳ����� �����ϴ� ���ν�ũ���� �ּҰ��� ��ȯ 
	static CConsoleGameScreen* GetMainScreen() { return m_MainScreen; }

	// ��ũ�� �ʱ�ȭ
	void Init(const int4& _ScreenSize, wchar_t _Char);
	// ��ũ�� ������
	void Render();
	// ��ũ�� Ŭ���� ( ����¹��ڸ� �⺻���ڷ� ����, �ܻ��� ����� ���� ) 
	void Clear();
	// ��ũ�� �ȼ� �� ����
	void SetPixel(const int4& _Pos, wchar_t _Char);

	// ȭ���� ������� Ȯ��
	bool IsOver(int4 _Pos);

	// ���� ����� ���� ���, Ŭ��������, �ڽ�Ŭ���� ���ο��� ��밡��
protected:
	
	
	// Ŭ���� ���ο����� ��밡�� 
private:
	// ��ũ�� ũ��
	int4 m_ScreenSize;
	// ��ũ���� �����ϱ� ���� ����Ŭ������ �ּҰ��� �����ϱ����� ����
	CConsoleGameLine* m_Line;
	// ��ũ���� �����ϴ� �⺻ ���ڸ� �����ϱ� ���� ���� 
	wchar_t m_BaseChar;
	static CConsoleGameScreen* m_MainScreen;

	// ==========================================================================

}CScreen;

