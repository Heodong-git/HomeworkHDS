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
    LeakCheck();

    g_Screen.Init(int4{ 10, 10 }, L'■');
    g_Player.SetPos(int4{ 0,0 });
    g_Player.SetRenderchar(L'★');
    
    while (true)
    {
        system("cls");

        // 맵초기화상태로 클리어 
        g_Screen.Clear();

        // 플레이어 업데이트, 위치변동사항 적용 
        // 맵정보를 확인하여 변동사항 체크가 가능하도록 인자로 스크린 객체를 넣어준다. 
        g_Player.Update(g_Screen);
        g_Screen.SetPixel(g_Player.GetPos(), g_Player.GetRenderchar());

        // 변경점을 토대로 렌더링
        g_Screen.Render();
        
        Sleep(200);
    }
    
    return 0;
}
