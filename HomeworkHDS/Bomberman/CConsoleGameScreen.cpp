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
	// 동적할당 된 메모리 제거
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
	// 예외처리, 스크린을 한번 더 만들고자 한다면 현재로써는 
	// 다시 만들 이유가 없기 때문에 어썰트처리(매크로함수) 
	// 이후에 스크린을 다시 만들어야 된다면 코드 재작성
	if (nullptr != m_Line)
	{
		MessageBoxAssert("스크린이 이미 생성되어 있습니다.");
		return;
	}

	// 국가코드 지정
	setlocale(LC_ALL, "KOR");

	// 현재 스크린사이즈를 알 수 있도록 값 저장
	m_ScreenSize = _ScreenSize;
	// 마찬가지로 문자값 저장 
	m_BaseChar = _Char;

	// 동적배열 할당 , 배열의 크기는 ScreenSize.Y 의 값만큼
	// m_Line 변수는 힙영역에 할당된 동적배열의 시작주소값을 가지게 된다. 
	// 인덱스를 통한 접근이 가능
	m_Line = new CConsoleGameLine[m_ScreenSize.Y];
	
	// ScreenSize.Y 의 값만큼 반복, GameLine 클래스의 초기화함수를 호출하여
	// 내부적으로 가진 배열에 동적할당을 하여 이차원배열처럼 사용할 수 있도록 처리
	// 생성한 배열에 X 축의 길이만큼 문자를 삽입한다. 
	for (size_t i = 0; i < m_ScreenSize.Y; i++)
	{
		m_Line[i].Init(m_ScreenSize.X, m_BaseChar);
	}	
}

void CConsoleGameScreen::Render()
{
	// 현재 생성되어 있는 라인 수만큼 출력
	for (size_t i = 0; i < m_ScreenSize.Y; i++)
	{
		m_Line[i].Render();
		// 한줄 출력되었다면 엔터 
		wprintf_s(L"\n");
	}
}

// 모든 배열을 베이스 문자로 세팅, (잔상지우기) 
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
	// m_Line[_Pos.Y]; <--- 얘는 생성된 CConsoleGameLine 타입 배열의 N번째 녀석 <---- 얘를 반환하고
	// 얘는 CConsoleGameLine 클래스이기 때문에  내부에 구현한 오퍼레이터[] 함수를 호출하면 
	// wchar_t& 타입의 본인이 소유한 m_Arr배열의 [ ? ] 번째 데이터를 반환한다. 

	m_Line[_Pos.Y][_Pos.X] = _Char;

	// wchar_t 
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
