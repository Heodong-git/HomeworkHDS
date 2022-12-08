#include "CConsoleGameScreen.h"
#include "CConsoleGameLine.h"
#include "CGameEngineDebug.h"
#include <assert.h>
#include <iostream>

CConsoleGameScreen::CConsoleGameScreen() :
	m_Line(nullptr),
	m_BaseChar(L'■')
{
}

CConsoleGameScreen::~CConsoleGameScreen()
{
	// 동적할당한 메모리 제거
	for (size_t i = 0; i < m_ScreenSize.Y; i++)
	{
		// 동적배열을 할당했기 때문에 동적배열 delete
		if (nullptr != m_Line) 
		{
			delete[] m_Line;
			m_Line = nullptr;
		}
	}
}

void CConsoleGameScreen::Init(const int4& _ScreenSize, wchar_t _Char)
{
	// 예외처리, 현재 스크린이 만들어져 있다면 assert 처리
	if (nullptr != m_Line)
	{
		MessageBoxAssert("스크린이 이미 생성되어 있습니다.");
		return;
	}

	// 국가코드 지정
	setlocale(LC_ALL, "KOR");

	// 라인이 만들어져 있지 않다면 생성한다.
	// 현재 스크린사이즈를 알 수 있도록 값 저장
	m_ScreenSize = _ScreenSize;
	// 마찬가지로 문자값 저장 
	m_BaseChar = _Char;

	// 동적배열 할당, 스크린사이즈 Y 개수만큼 
	// m_Line 변수는 힙영역에 할당된 동적배열의 시작주소값을 가지게 된다. 
	// 인덱스를 통한 접근이 가능
	m_Line = new CConsoleGameLine[m_ScreenSize.Y];
	
	// X의 개수만큼 문자값을 넣어준다. 
	for (size_t i = 0; i < m_ScreenSize.Y; i++)
	{
		// 라인클래스의 초기화함수 호출, 인자로 스크린사이즈, 초기화할 문자를 넣어준다. 
		m_Line[i].Init(m_ScreenSize.X, m_BaseChar);
	}	
}

void CConsoleGameScreen::Render()
{
	// 현재 생성되어 있는 라인 수만큼 출력
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

// 픽셀문자 세팅 
void CConsoleGameScreen::SetPixel(const int4& _Pos, wchar_t _Char)
{
	bool Check = IsOver(_Pos);

	if (Check)
	{
		MessageBoxAssert("스크린의 범위를 벗어납니다.");
		return;
	}
	
	// 위에 if문에 걸리지 않았다면 아래 코드동작, 정상적으로 이동가능
	
	// 이걸 가능하게 하기 위해 오퍼레이터연산자 활용
	m_Line[_Pos.Y][_Pos.X] = _Char;
}

// 포지션이 맵을 벗어났는지?
bool CConsoleGameScreen::IsOver(int4 _Pos)
{
	if (0 > _Pos.X)
	{
		MessageBoxAssert("X축 좌표가 0보다 작습니다.")
		return true;
	}

	if (0 > _Pos.Y)
	{
		MessageBoxAssert("Y축 좌표가 0보다 작습니다.")
		return true;
	}

	if (m_ScreenSize.X <= _Pos.X)
	{
		MessageBoxAssert("X축 좌표가 X축 최대 크기보다 큽니다.")
		return true;
	}

	if (m_ScreenSize.Y <= _Pos.Y)
	{
		MessageBoxAssert("X축 좌표가 0보다 작습니다.")
		return true;
	}

	// 모두 해당되지 않는다면 화면을 벗어나지 않은 것.
	return false;
}
