#pragma once
#include "ConsoleGameMath.h"

// Ŭ���� ���漱��, �̷� Ŭ������ ���� �� ���̴�~ 
// ���� ��ü�� ����ϴ� ���� �Ұ���, �����ͺ����� ������ �� ���� 
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

public:
	// ������Ʈ
	void Update();

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



// ���� : ��ȯ����, Ŭ�������漱�� , �������� ( static) 
// cpp ���� �ƹ��� ���� ����� ��Ŭ��� �س��Ƶ� ������ �߻���������
// ����� ��� ������ �� �Ŀ� cpp�� �����ϵǱ� ����. �³�? 

// ���� �ڵ� . �÷��̾ ���ӽ�ũ���� ������ �ִ´�. 
// ���ӽ�ũ�� Ŭ������ ���漱���Ͽ� ������Ÿ�� ������ ��� �ְ�, �� ������Ÿ�� ������ 
// ������ ���ӽ�ũ�� ��ü�� �ּҰ��� ������ ���� �� �ֵ��� ó��
// �̷��� ó���ߴٰ� ���������� ������ ��ũ�� ��ü ������ �����Ϳ����� �޸𸮸� �Ҵ��ϵ��� ����


// 0. ���ӽ�ũ���� ���������� �����ؼ� ���
// 1. ��ź ���� ��, ��ź �� ����
// 2. ��ź ������ ������ �ϱ�
// 3. �÷��̾ ��ź�� ���������� �ϱ�  
// 4. ��ź�� ���� �ð� �Ŀ� ������� �ϱ�


// �ϴ� Bomb ����� 