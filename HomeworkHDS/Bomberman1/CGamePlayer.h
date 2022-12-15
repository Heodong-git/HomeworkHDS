#pragma once
#include "CConsoleGameMath.h"

// Ŭ���� ���漱��, �̷� Ŭ������ ���� �� ���̴�~ 
// ���� ��ü�� ����ϴ� ���� �Ұ���, �����ͺ����� ������ �� ���� 
class CConsoleGameScreen;
class CBomb;

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

public:
	// ������Ʈ
	bool Update();

	void Move(const int4& _Pos) { m_Pos += _Pos; };

	// �� ����
	void Init(const int4& _ScreenSize);
	void SetPos(const int4& _Pos) { m_Pos = _Pos; }
	void SetRenderchar(const wchar_t _Char) { m_RenderChar = _Char; }

	// �� ��ȯ
	const int4& GetPos() { return m_Pos; }
	const wchar_t& GetRenderchar() { return m_RenderChar; }
	CBomb** GetBombArr();
	const int GetCurBombCount() { return m_CurBombCount; }
	const int GetMaxBombCount() { return m_MaxBombCount; }
	const int GetCurBombIdx() { return m_CurBombIdx;  }
	int& GetInstallationCount() { return m_InstallationCount; }

	bool BombOverlapCheck();
	bool LeftBombCheck();
	bool RightBombCheck();
	bool UpBombCheck();
	bool DownBombCheck();

private:
	// ��ġ
	int4 m_Pos;
	// ��¹���
	wchar_t m_RenderChar;

	// ��ź�� ������ �迭, ��ũ���� ���� ��������� ������
	// �� �ּҰ��� ��ź�� ������ �����迭�� �Ҵ��Ѵ�. �ִ밳���� �ʰ��� * ���η� �ϸ� �� �� ������?
	CBomb** m_BombArr;
	int m_MaxBombCount;
	int m_CurBombCount;
	int m_InstallationCount;
	int m_CurBombIdx;
};



// ���� : ��ȯ����, Ŭ�������漱�� , �������� ( static) 
// cpp ���� �ƹ��� ���� ����� ��Ŭ��� �س��Ƶ� ������ �߻���������
// ����� ��� ������ �� �Ŀ� cpp�� �����ϵǱ� ����. �³�? 

// ���� �ڵ� . �÷��̾ ���ӽ�ũ���� ������ �ִ´�. 
// ���ӽ�ũ�� Ŭ������ ���漱���Ͽ� ������Ÿ�� ������ ��� �ְ�, �� ������Ÿ�� ������ 
// ������ ���ӽ�ũ�� ��ü�� �ּҰ��� ������ ���� �� �ֵ��� ó��
// �̷��� ó���ߴٰ� ���������� ������ ��ũ�� ��ü ������ �����Ϳ����� �޸𸮸� �Ҵ��ϵ��� ����


// 0. ���ӽ�ũ���� ���������� �����ؼ� ���
// 1. ��ź ���� ��, ��ź �� ���� ����
// 2. ��ź ������ ������ �ϱ�    ����
// 3. �÷��̾ ��ź�� ���������� �ϱ� ���� 
// 4. ��ź�� ���� �ð� �Ŀ� ������� �ϱ� ������Ʈ���� �����ð��� ������ ���� (���������������µ�...)


// �ϴ� Bomb ����� 