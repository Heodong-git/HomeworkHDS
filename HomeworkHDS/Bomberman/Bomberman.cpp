#include <iostream>
#include "CConsoleGameScreen.h"
#include "CConsoleGameLine.h"
#include "CGameEngineDebug.h"
#include "CGamePlayer.h"

// 프로그램 종료시 까지 메모리가 해제되지 않을 것이기 때문에 전역에 선언
CConsoleGameScreen g_Screen;
CGamePlayer        g_Player;

int main()
{
    // 메인 실행시 릭체크 함수 호출
    // 가독성, 전역함수로 만들어서 함수호출하면 릭체크함수호출 
    LeakCheck();

    // 스크린초기화
    g_Screen.Init(int4{ 8, 8 }, L'■');

    // 플레이어 위치 세팅
    g_Player.SetPos(int4{ 0,0 });
    // 플레이어 출력문자 세팅
    g_Player.SetRenderchar(L'★');
    
    // 게임실행
    while (true)
    {
        // 
        system("cls");

        // 맵을 기본출력 문자로 바꾸어준다.  ( 배열 내 문자 이동 시 잔상 제거 ) 
        g_Screen.Clear();

        // 플레이어 업데이트, 위치변동사항 적용 
        // 맵정보를 확인하여 변동사항 체크가 가능하도록 인자로 스크린 객체를 넣어준다. 
        g_Player.Update(g_Screen);

        // 현재 플레이어의 위치, 플레이어의 출력문자를 받아와서 넣어준다. 
        g_Screen.SetPixel(g_Player.GetPos(), g_Player.GetRenderchar());

        // 현재까지 입력된 정보를 토대로 렌더 
        g_Screen.Render();
        
        // 딜레이
        Sleep(200);
    }
    
    return 0;
}
