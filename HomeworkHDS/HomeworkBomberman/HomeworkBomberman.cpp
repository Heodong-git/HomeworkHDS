#include <iostream>
#include "ConsoleGameScreen.h"
#include "Player.h"
#include "GameEngineDebug.h"
#include "Obstacle.h"
#include <conio.h>

ConsoleGameScreen Screen;
// 이렇게 생성해도 됩니다.
Player MainPlayer;
Obstacle MainObstacle;

int main()
{
    LeckCheck();

    // 지역변수로 만들어졌어.
    Screen.ScreenInit({ 15, 11 }, L'■');
    MainObstacle.Init({ 15, 11 });
    // 

    // ■■
    // ■■

    // 정상종료를 시켜줘야 하는데.
    while (true)
    {
        // AA
        // AA
        system("cls");
        // AA
        // AA
        Screen.ScreenClear();

        // 오브젝트 업데이트
        MainObstacle.Update();
        // 플레이어 업데이트 
        bool End = MainPlayer.Update();
        
        // 화면에 그린다.
        Screen.ScreenRender();
        Sleep(100);

        if (false == End)
        {
            printf_s("게임을 종료했습니다.");
            break;
        }
    }

}
