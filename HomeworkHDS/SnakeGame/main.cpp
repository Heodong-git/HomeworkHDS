// SnakeGame.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//

#include <iostream>
#include <ConsoleGameScreen.h>
#include "Head.h"

// ������ ��ũ�� Ŭ������ ��ü ����
ConsoleGameScreen Screen;

// ��ũ�� ������ ����
int4 ScreenSize = { 15, 11 };

int main()
{
    // ��üũ
    LeckCheck();

    // ������ ������ְ� 
    Parts* StartPart = new Head();

    // ��ũ���ʱ�ȭ 
    Screen.ScreenInit(ScreenSize, L'��');

    while (true)
    {
        // ȭ���� ����� 
        system("cls");

        // ��ũ���� �ʱ���·� (�ܻ�����)
        Screen.ScreenClear();

        // ���� ������Ʈ
        StartPart->Update();

        // ���� ������ ( ��ũ���� ��ġ�� ���� ) 
        StartPart->Render();

        // ȭ�鿡 ��� 
        Screen.ScreenRender();
        Sleep(100);
    }


    delete StartPart;
}
