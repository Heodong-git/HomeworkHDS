#include <iostream>
#include <ConsoleGameScreen.h>
#include <ConsoleGameInput.h>
#include "Head.h"
#include "Body.h"

// 전역에 스크린 클래스의 객체 생성
ConsoleGameScreen Screen;

// 스크린 사이즈 설정
int4 ScreenSize = { 5, 5 };

int main()
{
    // 릭체크
    LeckCheck();

    // 파츠를 만들어주고 
    Parts* StartParts = new Head();

    // 스크린초기화 
    Screen.ScreenInit(ScreenSize, L'□');

    // 바디를 생성하여 스크린 내부의 랜덤한 위치에 생성(정확히는 데이터만 입력) 
    Body::CreateBody();

    while (true)
    {
        // staitc 함수이기 때문에 객체없이 호출이 가능
        // 눌린 키 체크 
        ConsoleGameInput::ConsoleInputCheck();

        // Q , q 버튼이 눌렸다면 게임을 종료하도록 설정
        if (true == ConsoleGameInput::GetIsInput() &&
            ('Q' == ConsoleGameInput::GetKey() ||
                'q' == ConsoleGameInput::GetKey()))
        {
            break;
        }

        // 화면을 지우고 
        system("cls");

        // 스크린을 초기상태로 (잔상제거)
        Screen.ScreenClear();

        // 바디 업데이트
        Body::GetCurBody()->Update();

        // 머리 업데이트
        StartParts->Update();

        // 바디 렌더링
        Body::GetCurBody()->Render();

        // 파츠 렌더링 ( 스크린의 위치에 세팅 ) 
        StartParts->Render();

        // 화면에 출력 
        Screen.ScreenRender();
        Sleep(100);
    }

    if (nullptr != StartParts)
    {
        delete StartParts;
        StartParts = nullptr;
    }
}
