#include "CConsoleGameScreen.h"
#include "CConsoleGameLine.h"
#include "CGameEngineDebug.h"
#include "CGamePlayer.h"
#include "CBomb.h"
#include <iostream>
// 프로그램 종료시 까지 메모리가 해제되지 않을 것이기 때문에 전역에 선언
CConsoleGameScreen g_Screen;
CGamePlayer        g_Player;

int main()
{
    // 메인 실행시 릭체크 함수 호출
    // 가독성, 전역함수로 만들어서 함수호출하면 릭체크함수호출 
    LeakCheck();

    // 스크린초기화
    CConsoleGameScreen::GetMainScreen()->Init(int4{ 8, 8 }, L'■');
    CConsoleGameScreen::GetMainScreen()->SetPlayer(&g_Player);

    // 플레이어 초기화, 세팅
    g_Player.Init(CConsoleGameScreen::GetMainScreen()->GetScreenSize());
    g_Player.SetPos(int4{ 0,0 });
    // 플레이어 출력문자 세팅
    g_Player.SetRenderchar(L'★');

    // 게임실행
    while (true)
    {
        // 
        system("cls");

        // 맵을 기본출력 문자로 바꾸어준다.  ( 배열 내 문자 이동 시 잔상 제거 ) 
        CConsoleGameScreen::GetMainScreen()->Clear();

        // 플레이어 업데이트, 위치변동사항 적용 
        if (false == g_Player.Update())
        {
            return 0;
        }

        // 현재 플레이어의 위치, 플레이어의 출력문자를 받아와서 넣어준다. 
        CConsoleGameScreen::GetMainScreen()->SetPixel(g_Player.GetPos(), g_Player.GetRenderchar());
       
        // 현재 폭탄의 개수가 0개가 아니라면 업데이트 
        if (0 != g_Player.GetCurBombCount())
        {
            for (size_t i = 0; i < g_Player.GetCurBombCount(); i++)
            {
                if (nullptr != g_Player.GetBombArr()[i])
                {
                    g_Player.GetBombArr()[i]->Update();
                }
            }
        }

        // 폭탄 세팅
        CConsoleGameScreen::GetMainScreen()->SetPixel(g_Player.GetBombArr(), g_Player.GetCurBombCount());

        // 현재까지 입력된 정보를 토대로 렌더 
        CConsoleGameScreen::GetMainScreen()->Render();
        std::cout << "최대 설치 개수 : " << g_Player.GetMaxBombCount() << std::endl;
        std::cout << "현재 설치 개수 : " << g_Player.GetInstallationCount() << std::endl;
        std::cout << "다음 생성될 폭탄인덱스 : " << g_Player.GetCurBombIdx() << std::endl;
        

        // 딜레이
        Sleep(200);
    }

    return 0;
}
