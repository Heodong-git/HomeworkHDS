#pragma once
#include "CConsoleGameMath.h"

// 클래스 전방선언, 이런 클래스가 존재 할 것이다~ 
// 직접 객체를 사용하는 것은 불가능, 포인터변수를 선언할 수 있음 
class CConsoleGameScreen;
class CBomb;

class CGamePlayer
{
public:
	CGamePlayer();
	~CGamePlayer();

	// 복사생성자
	// RValue생성자
	// 오퍼레이터 = 
	// 함수삭제처리를 해두고, 나중에 필요한 상황이 되면 고민하여 사용여부를 결정한다. 
	CGamePlayer(const CGamePlayer& _Other) = delete;
	CGamePlayer(CGamePlayer&& _Other) noexcept = delete;
	CGamePlayer& operator=(const CGamePlayer& _Other) = delete;
	CGamePlayer& operator=(CGamePlayer&& _Other) noexcept = delete;

public:
	// 업데이트
	bool Update();

	void Move(const int4& _Pos) { m_Pos += _Pos; };

	// 값 세팅
	void Init(const int4& _ScreenSize);
	void SetPos(const int4& _Pos) { m_Pos = _Pos; }
	void SetRenderchar(const wchar_t _Char) { m_RenderChar = _Char; }

	// 값 반환
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
	// 위치
	int4 m_Pos;
	// 출력문자
	wchar_t m_RenderChar;

	// 폭탄을 저장할 배열, 스크린이 먼저 만들어지기 때문에
	// 이 주소값에 폭탄을 저장할 동적배열을 할당한다. 최대개수는 맵가로 * 세로로 하면 될 것 같은데?
	CBomb** m_BombArr;
	int m_MaxBombCount;
	int m_CurBombCount;
	int m_InstallationCount;
	int m_CurBombIdx;
};



// 배운문법 : 순환참조, 클래스전방선언 , 정적변수 ( static) 
// cpp 에는 아무리 많은 헤더를 인클루드 해놓아도 문제가 발생하지않음
// 헤더를 모두 컴파일 한 후에 cpp가 컴파일되기 때문. 맞나? 

// 쌤의 코드 . 플레이어가 게임스크린을 가지고 있는다. 
// 게임스크린 클래스를 전방선언하여 포인터타입 변수를 들고 있고, 그 포인터타입 변수가 
// 생성된 게임스크린 객체의 주소값을 가지고 있을 수 있도록 처리
// 이렇게 처리했다가 정적변수를 배우고나서 스크린 객체 생성시 데이터영역에 메모리를 할당하도록 변경


// 0. 게임스크린은 정적변수로 선언해서 사용
// 1. 폭탄 생성 후, 폭탄 릭 제거 ㅇㅇ
// 2. 폭탄 여러개 나오게 하기    ㅇㅇ
// 3. 플레이어가 폭탄을 못지나가게 하기 ㅇㅇ 
// 4. 폭탄이 일정 시간 후에 사라지게 하기 업데이트에서 일정시간이 지나면 제거 (지워지긴지워지는데...)


// 일단 Bomb 만들어 