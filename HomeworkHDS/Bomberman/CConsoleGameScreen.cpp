#include "CConsoleGameScreen.h"
#include "CConsoleGameLine.h"
#include "CGameEngineDebug.h"
#include <assert.h>
#include <iostream>

CConsoleGameScreen::CConsoleGameScreen() :
	m_Line(nullptr),
	m_BaseChar(L'��')
{
}

CConsoleGameScreen::~CConsoleGameScreen()
{
	// �����Ҵ��� �޸� ����
	for (size_t i = 0; i < m_ScreenSize.Y; i++)
	{
		// �����迭�� �Ҵ��߱� ������ �����迭 delete
		if (nullptr != m_Line) 
		{
			delete[] m_Line;
			m_Line = nullptr;
		}
	}
}

void CConsoleGameScreen::Init(const int4& _ScreenSize, wchar_t _Char)
{
	// ����ó��, ���� ��ũ���� ������� �ִٸ� assert ó��
	if (nullptr != m_Line)
	{
		MessageBoxAssert("��ũ���� �̹� �����Ǿ� �ֽ��ϴ�.");
		return;
	}

	// �����ڵ� ����
	setlocale(LC_ALL, "KOR");

	// ������ ������� ���� �ʴٸ� �����Ѵ�.
	// ���� ��ũ������� �� �� �ֵ��� �� ����
	m_ScreenSize = _ScreenSize;
	// ���������� ���ڰ� ���� 
	m_BaseChar = _Char;

	// �����迭 �Ҵ�, ��ũ�������� Y ������ŭ 
	// m_Line ������ �������� �Ҵ�� �����迭�� �����ּҰ��� ������ �ȴ�. 
	// �ε����� ���� ������ ����
	m_Line = new CConsoleGameLine[m_ScreenSize.Y];
	
	// X�� ������ŭ ���ڰ��� �־��ش�. 
	for (size_t i = 0; i < m_ScreenSize.Y; i++)
	{
		// ����Ŭ������ �ʱ�ȭ�Լ� ȣ��, ���ڷ� ��ũ��������, �ʱ�ȭ�� ���ڸ� �־��ش�. 
		m_Line[i].Init(m_ScreenSize.X, m_BaseChar);
	}	
}

void CConsoleGameScreen::Render()
{
	// ���� �����Ǿ� �ִ� ���� ����ŭ ���
	for (size_t i = 0; i < m_ScreenSize.Y; i++)
	{
		m_Line[i].Render();
		wprintf_s(L"\n");
	}
}

void CConsoleGameScreen::Clear()
{
	for (size_t i = 0; i < m_ScreenSize.Y; i++)
	{
		m_Line[i].Clear();
	}
}

// �ȼ����� ���� 
void CConsoleGameScreen::SetPixel(const int4& _Pos, wchar_t _Char)
{
	bool Check = IsOver(_Pos);

	if (Check)
	{
		MessageBoxAssert("��ũ���� ������ ����ϴ�.");
		return;
	}
	
	// ���� if���� �ɸ��� �ʾҴٸ� �Ʒ� �ڵ嵿��, ���������� �̵�����
	
	// �̰� �����ϰ� �ϱ� ���� ���۷����Ϳ����� Ȱ��
	m_Line[_Pos.Y][_Pos.X] = _Char;
}

// �������� ���� �������?
bool CConsoleGameScreen::IsOver(int4 _Pos)
{
	if (0 > _Pos.X)
	{
		MessageBoxAssert("X�� ��ǥ�� 0���� �۽��ϴ�.")
		return true;
	}

	if (0 > _Pos.Y)
	{
		MessageBoxAssert("Y�� ��ǥ�� 0���� �۽��ϴ�.")
		return true;
	}

	if (m_ScreenSize.X <= _Pos.X)
	{
		MessageBoxAssert("X�� ��ǥ�� X�� �ִ� ũ�⺸�� Ů�ϴ�.")
		return true;
	}

	if (m_ScreenSize.Y <= _Pos.Y)
	{
		MessageBoxAssert("X�� ��ǥ�� 0���� �۽��ϴ�.")
		return true;
	}

	// ��� �ش���� �ʴ´ٸ� ȭ���� ����� ���� ��.
	return false;
}
