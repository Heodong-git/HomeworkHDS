#pragma once
#include "ConsoleGameMath.h"

class CConsoleGameScreen;
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

	// 업데이트
	void Update(CConsoleGameScreen& _Screen);

	void Move(const int4& _Pos) { m_Pos += _Pos; };
	
	// 값 세팅
	void SetPos(const int4& _Pos) { m_Pos = _Pos; }
	void SetRenderchar(const wchar_t _Char) { m_RenderChar = _Char; }

	// 값 반환
	const int4& GetPos() { return m_Pos; }
	const wchar_t& GetRenderchar() { return m_RenderChar; }

private:
	// 위치
	int4 m_Pos;
	// 출력문자
	wchar_t m_RenderChar;

};

