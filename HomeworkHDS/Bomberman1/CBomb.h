#pragma once
#include "CConsoleGameMath.h"
#include <time.h>

class CGamePlayer;
class CBomb
{
public:
	CBomb();
	~CBomb();

	// ���������
	// RValue������
	// ���۷����� = 
	// �Լ�����ó���� �صΰ�, ���߿� �ʿ��� ��Ȳ�� �Ǹ� ����Ͽ� ��뿩�θ� �����Ѵ�. 
	CBomb(const CBomb& _Other) = delete;
	CBomb(CBomb&& _Other) noexcept = delete;
	CBomb& operator=(const CBomb& _Other) = delete;
	CBomb& operator=(CBomb&& _Other) noexcept = delete;

public:
	// ������Ʈ
	void Update();

	// ������ ��ȯ
	int4 GetPos() { return m_Pos; }
	// ���������� ��ȯ
	const wchar_t& GetRenderchar() { return m_RenderChar; }

	// ������ ����
	void SetPos(const int4& _Pos) { m_Pos = _Pos; }
	void SetRenderchar(wchar_t _char) { m_RenderChar = _char;  }

private:
	int4	 m_Pos;
	wchar_t  m_RenderChar;
	clock_t  m_Creationtime;
	clock_t  m_CurTime;
	double   m_DeleteTime;
	
};

