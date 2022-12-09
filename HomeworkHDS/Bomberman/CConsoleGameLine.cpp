#include "CConsoleGameLine.h"
#include "CGameEngineDebug.h"
#include <iostream>

CConsoleGameLine::CConsoleGameLine() :
	m_Arr{},
	m_BaseChar(L'□'),
	m_XSize(0)
{
}

CConsoleGameLine::~CConsoleGameLine()
{
	// 동적할당한 메모리 제거
	// 동적배열을 할당했기 때문에 동적배열 delete 
	if (nullptr != m_Arr)
	{
		delete[] m_Arr;
		m_Arr = nullptr;
	}
}

void CConsoleGameLine::Init(const size_t _XSize, wchar_t _Char)
{
	// 예외처리
	// 현재 배열의 주소값을 저장하는 변수가 nullptr 이 아니라면 이미 생성이 되어 있다는 의미
	// assert 처리
	if (nullptr != m_Arr)
	{
		MessageBoxAssert("스크린 라인이 이미 생성되어 있습니다.");
		return;
	}

	// X 사이즈 저장
	m_XSize = _XSize;

	// 출력문자 저장
	m_BaseChar = _Char;

	// 널문자를 삽입하기 위해 + 1 만큼 추가로 동적할당
	// new wchar_t[10]; 이라고 가정하면 11개를 할당하는거고.. 10번인덱스가 마지막이니까 거기에 0 ㅇㅇ ㅇㅋ
	// 10개라면 11개 짜리 wchar_t 타입을 저장하는 배열..  11개의 배열 22 바이트배열 
	m_Arr = new wchar_t[_XSize + 1];

	// 들어온 값만큼 반복해서 문자를 대입한다. 
	for (size_t i = 0; i < m_XSize; i++)
	{
		m_Arr[i] = _Char;	
	}

	// 마지막에 널문자를 삽입하여 문자열의 끝을 알 수 있도록 처리해준다. 
	m_Arr[m_XSize] = 0;
}

void CConsoleGameLine::Render()
{
	wprintf_s(m_Arr);
}

void CConsoleGameLine::Clear()
{
	// 현재 생성되어 있는 배열에 전부 베이스 문자를 삽입하여
	// 맵을 초기상태로 만든다. 
	for (size_t i = 0; i < m_XSize; i++)
	{
		m_Arr[i] = m_BaseChar;
	}

	// 작업이 완료 되었다면 마지막에 0을 삽입하여 문자열의 끝을 알 수 있도록 처리
	m_Arr[m_XSize] = 0;
}

wchar_t ErrorCode = -1;
wchar_t& CConsoleGameLine::operator[](size_t _Index)
{
	if (0 > _Index)
	{
		// 인덱스의 값이 0보다 작다면 인덱스보다 작은 값을 넣은 것이다.
		MessageBoxAssert("Index 의 값을 0보다 작은 값을 입력하였습니다.")
		return ErrorCode;
	}

	if (m_XSize <= _Index)
	{
		MessageBoxAssert("Index 의 값이 최대 값보다 큰 값이 입력되었습니다.")
		return ErrorCode;
	}

	// 위 조건문에 걸리지 않았다면 값을 반환한다.
	return m_Arr[_Index];
}


