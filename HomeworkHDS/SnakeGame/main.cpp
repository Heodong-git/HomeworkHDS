#include <iostream>
#include <ConsoleGameScreen.h>
#include <ConsoleGameInput.h>
#include "Head.h"
#include "Body.h"
#include "Parts.h"
#include <vector>

// 전역에 스크린 클래스의 객체 생성
ConsoleGameScreen Screen;

// 스크린 사이즈 설정
int4 ScreenSize = { 3, 3 };

int main()
{
    // 릭체크
    LeckCheck();

    int a = 0;

    // 파츠를 만들어주고 
    Parts* StartParts = new Head();
    
    // 파츠가 저장될 공간의 크기는 스크린사이즈의 크기만큼 미리 할당해준다.
    Parts::GetVecParts().reserve(ScreenSize.X * ScreenSize.Y);
    // 만들어진 파츠는 동적배열에 저장한다. 
    Parts::GetVecParts().push_back(StartParts);

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

        // 업데이트를 bool 타입으로 변경하고 
        // 반환하는 값이 false 일 경우 종료되도록 작성
        // 종료시에는 화면이 보여지도록 함수를 호출하여 화면을 출력해준 후에 게임을 종료시킨다. 
        if (false == StartParts->Update())
        {
            StartParts->RecursionPrevRender();
            // 바디 렌더링
            Body::GetCurBody()->Render();

            // 화면에 출력 
            Screen.ScreenRender();
            std::cout << "Game Over" << std::endl; 
            break;
        }

        // 연결된 파츠 렌더링
        StartParts->RecursionPrevRender();
        // 바디 렌더링
        Body::GetCurBody()->Render();

        // 화면에 출력 
        Screen.ScreenRender();
        Sleep(100);
    }

    // 벡터에 저장된 동적할당된 파츠를 모두 제거한다. 
    std::vector<Parts*> vecParts = Parts::GetVecParts();

    for (size_t i = 0; i < vecParts.size(); i++)
    {
        if (nullptr != vecParts[i])
        {
             delete vecParts[i];
             vecParts[i] = nullptr;
        }
    }

    // static 변수로 선언되어있기 때문에 한번 초기화된 이후에는 초기화가 불가능함. 
    if (nullptr != Body::GetCurBody())
    {
        delete Body::GetCurBody();
    }
}
