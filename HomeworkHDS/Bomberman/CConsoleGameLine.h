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
	// 배열의 주소값을 저장할 포인터변수
	wchar_t* m_Arr;
	// 배열에 저장할 베이스 문자
	wchar_t m_BaseChar;
	// 현재 몇개짜리 배열이 생성되었는지 알 수 있도록 저장할 변수 
	size_t m_XSize;
};

