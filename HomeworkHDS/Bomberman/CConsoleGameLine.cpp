#include "CConsoleGameLine.h"
#include "CGameEngineDebug.h"
#include <iostream>

CConsoleGameLine::CConsoleGameLine() :
	m_Arr{},
	m_BaseChar(L'��'),
	m_XSize(0)
{
}

CConsoleGameLine::~CConsoleGameLine()
{
	// �����Ҵ��� �޸� ����
	// �����迭�� �Ҵ��߱� ������ �����迭 delete 
	if (nullptr != m_Arr)
	{
		delete[] m_Arr;
		m_Arr = nullptr;
	}
}

void CConsoleGameLine::Init(const size_t _XSize, wchar_t _Char)
{
	// ����ó��
	// ���� �迭�� �ּҰ��� �����ϴ� ������ nullptr �� �ƴ϶�� �̹� ������ �Ǿ� �ִٴ� �ǹ�
	// assert ó��
	if (nullptr != m_Arr)
	{
		MessageBoxAssert("��ũ�� ������ �̹� �����Ǿ� �ֽ��ϴ�.");
		return;
	}

	// X ������ ����
	m_XSize = _XSize;

	// ��¹��� ����
	m_BaseChar = _Char;

	// �ι��ڸ� �����ϱ� ���� + 1 ��ŭ �߰��� �����Ҵ�
	// new wchar_t[10]; �̶�� �����ϸ� 11���� �Ҵ��ϴ°Ű�.. 10���ε����� �������̴ϱ� �ű⿡ 0 ���� ����
	// 10����� 11�� ¥�� wchar_t Ÿ���� �����ϴ� �迭..  11���� �迭 22 ����Ʈ�迭 
	m_Arr = new wchar_t[_XSize + 1];

	// ���� ����ŭ �ݺ��ؼ� ���ڸ� �����Ѵ�. 
	for (size_t i = 0; i < m_XSize; i++)
	{
		m_Arr[i] = _Char;	
	}

	// �������� �ι��ڸ� �����Ͽ� ���ڿ��� ���� �� �� �ֵ��� ó�����ش�. 
	m_Arr[m_XSize] = 0;
}

void CConsoleGameLine::Render()
{
	wprintf_s(m_Arr);
}

void CConsoleGameLine::Clear()
{
	// ���� �����Ǿ� �ִ� �迭�� ���� ���̽� ���ڸ� �����Ͽ�
	// ���� �ʱ���·� �����. 
	for (size_t i = 0; i < m_XSize; i++)
	{
		m_Arr[i] = m_BaseChar;
	}

	// �۾��� �Ϸ� �Ǿ��ٸ� �������� 0�� �����Ͽ� ���ڿ��� ���� �� �� �ֵ��� ó��
	m_Arr[m_XSize] = 0;
}

wchar_t ErrorCode = -1;
wchar_t& CConsoleGameLine::operator[](size_t _Index)
{
	if (0 > _Index)
	{
		// �ε����� ���� 0���� �۴ٸ� �ε������� ���� ���� ���� ���̴�.
		MessageBoxAssert("Index �� ���� 0���� ���� ���� �Է��Ͽ����ϴ�.")
		return ErrorCode;
	}

	if (m_XSize <= _Index)
	{
		MessageBoxAssert("Index �� ���� �ִ� ������ ū ���� �ԷµǾ����ϴ�.")
		return ErrorCode;
	}

	// �� ���ǹ��� �ɸ��� �ʾҴٸ� ���� ��ȯ�Ѵ�.
	return m_Arr[_Index];
}


