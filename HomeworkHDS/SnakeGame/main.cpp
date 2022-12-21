// SnakeGame.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <ConsoleGameScreen.h>
#include "Head.h"

// 전역에 스크린 클래스의 객체 생성
ConsoleGameScreen Screen;

// 스크린 사이즈 설정
int4 ScreenSize = { 15, 11 };

int main()
{
    // 릭체크
    LeckCheck();

    // 파츠를 만들어주고 
    Parts* StartPart = new Head();

    // 스크린초기화 
    Screen.ScreenInit(ScreenSize, L'■');

    while (true)
    {
        // 화면을 지우고 
        system("cls");

        // 스크린을 초기상태로 (잔상제거)
        Screen.ScreenClear();

        // 파츠 업데이트
        StartPart->Update();

        // 파츠 렌더링 ( 스크린의 위치에 세팅 ) 
        StartPart->Render();

        // 화면에 출력 
        Screen.ScreenRender();
        Sleep(100);
    }


    delete StartPart;
}
