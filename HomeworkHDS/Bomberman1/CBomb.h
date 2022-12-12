#pragma once
#include "CConsoleGameMath.h"
#include <time.h>

class CGamePlayer;
class CBomb
{
public:
	CBomb();
	~CBomb();

	// 복사생성자
	// RValue생성자
	// 오퍼레이터 = 
	// 함수삭제처리를 해두고, 나중에 필요한 상황이 되면 고민하여 사용여부를 결정한다. 
	CBomb(const CBomb& _Other) = delete;
	CBomb(CBomb&& _Other) noexcept = delete;
	CBomb& operator=(const CBomb& _Other) = delete;
	CBomb& operator=(CBomb&& _Other) noexcept = delete;

public:
	// 업데이트
	void Update();

	// 포지션 반환
	int4 GetPos() { return m_Pos; }
	// 렌더링문자 반환
	const wchar_t& GetRenderchar() { return m_RenderChar; }

	// 포지션 세팅
	void SetPos(const int4& _Pos) { m_Pos = _Pos; }
	void SetRenderchar(wchar_t _char) { m_RenderChar = _char;  }

private:
	int4	 m_Pos;
	wchar_t  m_RenderChar;
	clock_t  m_Creationtime;
	clock_t  m_CurTime;
	double   m_DeleteTime;
	
};

