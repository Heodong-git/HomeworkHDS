#pragma once
#include "CConsoleGameMath.h"

class CConsoleGameLine;
class CBomb;
class CGamePlayer;

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
	// ��ź�� ��¹��� ��ȯ
	const wchar_t& GetBombRenderChar();
	// ���� �ش���ġ�� ǥ�õǰ� �ִ� ���� ��ȯ
	const wchar_t& GetRenderChar(const int4& _Pos);
	// ���̽� ���� ��ȯ
	const wchar_t& GetBaseChar() { return m_BaseChar; }
	// �����Ϳ����� �����ϴ� ���ν�ũ���� �ּҰ��� ��ȯ 
	static CConsoleGameScreen* GetMainScreen() { return m_MainScreen; }
	CGamePlayer* const  GetPlayer() { return m_Player; }

	// ��ũ�� �ʱ�ȭ
	void Init(const int4& _ScreenSize, wchar_t _Char);
	// ��ũ�� ������
	void Render();
	// ��ũ�� Ŭ���� ( ����¹��ڸ� �⺻���ڷ� ����, �ܻ��� ����� ���� ) 
	void Clear();
	// ��ũ�� �ȼ� �� ����
	void SetPixel(const int4& _Pos, wchar_t _Char);
	void SetPixel(CBomb** const _Bomb, const int _BombCount);
	void SetPlayer(CGamePlayer* _Player) { m_Player = _Player; }

	// ȭ���� ������� Ȯ��
	bool IsOver(int4 _Pos);

	int PlayerBombInstallCount();

	// ���� ����� ���� ���, Ŭ��������, �ڽ�Ŭ���� ���ο��� ��밡��
protected:


	// Ŭ���� ���ο����� ��밡�� 
private:
	// ��ũ�� ũ��
	int4 m_ScreenSize;
	// ��ũ���� �����ϱ� ���� ����Ŭ������ �ּҰ��� �����ϱ����� ����
	CConsoleGameLine* m_Line;
	CGamePlayer*	  m_Player;
	// ��ũ���� �����ϴ� �⺻ ���ڸ� �����ϱ� ���� ���� 
	wchar_t m_BaseChar;
	wchar_t m_BombChar;
	static CConsoleGameScreen* m_MainScreen;
	int m_PlayerBombInstallCount;
	// ==========================================================================

}CScreen;

