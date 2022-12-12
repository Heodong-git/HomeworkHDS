#include "CBomb.h"
#include "CConsoleGameScreen.h"
#include <time.h>
#include <stdio.h>
#include <Windows.h>
#include "CGamePlayer.h"

CBomb::CBomb() :
	m_RenderChar(L'◎'),
	m_CurTime(0),
	m_DeleteTime(0)
{
	// 만들어진시간
	m_Creationtime = clock();
}

CBomb::~CBomb()
{
}



// 일정시간이 지나면 없어지도록.
void CBomb::Update()
{
	// 현재시간에서 만들어진 시간을 빼주고 3초가 경과했을 경우에 자기자신을 제거
	m_CurTime = clock();
	// 현재시간 - 만들어진시간
	m_DeleteTime = double(m_CurTime - m_Creationtime) / CLOCKS_PER_SEC;
	
	// 플레이어 받아오기
	CGamePlayer* Player = CConsoleGameScreen::GetMainScreen()->GetPlayer();

	// 
	if (3 <= m_DeleteTime)
	{	
		// 스크린베이스 출력문자 받아오기 
		const wchar_t RenderChar = CConsoleGameScreen::GetMainScreen()->GetBaseChar();
		
		// 3초가 지났으면 그자리의 출력문자를 베이스 문자로 변경
		// 지우는건 흠.. 
		SetRenderchar(RenderChar);
		//int& Count = Player->GetInstallationCount();
		//--Count;
		m_DeleteTime = 0;
		m_CurTime = 0;
	}


}



