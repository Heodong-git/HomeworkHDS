#include "CBomb.h"
#include "CConsoleGameScreen.h"
#include <time.h>
#include <stdio.h>
#include <Windows.h>
#include "CGamePlayer.h"

CBomb::CBomb() :
	m_RenderChar(L'��'),
	m_CurTime(0),
	m_DeleteTime(0)
{
	// ��������ð�
	m_Creationtime = clock();
}

CBomb::~CBomb()
{
}



// �����ð��� ������ ����������.
void CBomb::Update()
{
	// ����ð����� ������� �ð��� ���ְ� 3�ʰ� ������� ��쿡 �ڱ��ڽ��� ����
	m_CurTime = clock();
	// ����ð� - ��������ð�
	m_DeleteTime = double(m_CurTime - m_Creationtime) / CLOCKS_PER_SEC;
	
	// �÷��̾� �޾ƿ���
	CGamePlayer* Player = CConsoleGameScreen::GetMainScreen()->GetPlayer();

	// 
	if (3 <= m_DeleteTime)
	{	
		// ��ũ�����̽� ��¹��� �޾ƿ��� 
		const wchar_t RenderChar = CConsoleGameScreen::GetMainScreen()->GetBaseChar();
		
		// 3�ʰ� �������� ���ڸ��� ��¹��ڸ� ���̽� ���ڷ� ����
		// ����°� ��.. 
		SetRenderchar(RenderChar);
		//int& Count = Player->GetInstallationCount();
		//--Count;
		m_DeleteTime = 0;
		m_CurTime = 0;
	}


}



