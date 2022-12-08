#pragma once
#include "CConsoleGameScreen.h"

class CConsoleGameLine
{
public:
	CConsoleGameLine();
	~CConsoleGameLine();

	void Init(const size_t _XSize, wchar_t _Char);
	void Render();
	void Clear();

	wchar_t& operator[](size_t _Index);

private:
	// �迭�� �ּҰ��� ������ �����ͺ���
	wchar_t* m_Arr;
	// �迭�� ������ ���̽� ����
	wchar_t m_BaseChar;
	// ���� �¥�� �迭�� �����Ǿ����� �� �� �ֵ��� ������ ���� 
	size_t m_XSize;
};

