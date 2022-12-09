#pragma once
#include "ConsoleGameMath.h"

class CConsoleGameScreen;
class CGamePlayer
{
public:
	CGamePlayer();
	~CGamePlayer();

	// ���������
	// RValue������
	// ���۷����� = 
	// �Լ�����ó���� �صΰ�, ���߿� �ʿ��� ��Ȳ�� �Ǹ� ����Ͽ� ��뿩�θ� �����Ѵ�. 
	CGamePlayer(const CGamePlayer& _Other) = delete;
	CGamePlayer(CGamePlayer&& _Other) noexcept = delete;
	CGamePlayer& operator=(const CGamePlayer& _Other) = delete;
	CGamePlayer& operator=(CGamePlayer&& _Other) noexcept = delete;

	// ������Ʈ
	void Update(CConsoleGameScreen& _Screen);

	void Move(const int4& _Pos) { m_Pos += _Pos; };
	
	// �� ����
	void SetPos(const int4& _Pos) { m_Pos = _Pos; }
	void SetRenderchar(const wchar_t _Char) { m_RenderChar = _Char; }

	// �� ��ȯ
	const int4& GetPos() { return m_Pos; }
	const wchar_t& GetRenderchar() { return m_RenderChar; }

private:
	// ��ġ
	int4 m_Pos;
	// ��¹���
	wchar_t m_RenderChar;

};

