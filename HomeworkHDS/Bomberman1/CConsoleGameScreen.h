#pragma once
#include "CConsoleGameMath.h"

class CConsoleGameLine;
class CBomb;
class CGamePlayer;

typedef class CConsoleGameScreen
{
public:
	CConsoleGameScreen();
	~CConsoleGameScreen();

	// 복사생성자
	// RValue생성자
	// 오퍼레이터 = 
	// 함수삭제처리를 해두고, 나중에 필요한 상황이 되면 고민하여 사용여부를 결정한다. 
	CConsoleGameScreen(const CConsoleGameScreen& _Other) = delete;
	CConsoleGameScreen(CConsoleGameScreen&& _Other) noexcept = delete;
	CConsoleGameScreen& operator=(const CConsoleGameScreen& _Other) = delete;
	CConsoleGameScreen& operator=(CConsoleGameScreen&& _Other) noexcept = delete;

	// 값반환

	// 스크린사이즈 반환
	const int4& GetScreenSize() { return m_ScreenSize; }
	// 폭탄의 출력문자 반환
	const wchar_t& GetBombRenderChar();
	// 현재 해당위치에 표시되고 있는 문자 반환
	const wchar_t& GetRenderChar(const int4& _Pos);
	// 베이스 문자 반환
	const wchar_t& GetBaseChar() { return m_BaseChar; }
	// 데이터영역에 존재하는 메인스크린의 주소값을 반환 
	static CConsoleGameScreen* GetMainScreen() { return m_MainScreen; }
	CGamePlayer* const  GetPlayer() { return m_Player; }

	// 스크린 초기화
	void Init(const int4& _ScreenSize, wchar_t _Char);
	// 스크린 렌더링
	void Render();
	// 스크린 클리어 ( 맵출력문자를 기본문자로 세팅, 잔상을 지우기 위함 ) 
	void Clear();
	// 스크린 픽셀 값 세팅
	void SetPixel(const int4& _Pos, wchar_t _Char);
	void SetPixel(CBomb** const _Bomb, const int _BombCount);
	void SetPlayer(CGamePlayer* _Player) { m_Player = _Player; }

	// 화면을 벗어났는지 확인
	bool IsOver(int4 _Pos);

	int PlayerBombInstallCount();

	// 추후 상속을 배우고 사용, 클래스내부, 자식클래스 내부에서 사용가능
protected:


	// 클래스 내부에서만 사용가능 
private:
	// 스크린 크기
	int4 m_ScreenSize;
	// 스크린을 구성하기 위한 라인클래스의 주소값을 저장하기위한 변수
	CConsoleGameLine* m_Line;
	CGamePlayer*	  m_Player;
	// 스크린을 구성하는 기본 문자를 저장하기 위한 변수 
	wchar_t m_BaseChar;
	wchar_t m_BombChar;
	static CConsoleGameScreen* m_MainScreen;
	int m_PlayerBombInstallCount;
	// ==========================================================================

}CScreen;

