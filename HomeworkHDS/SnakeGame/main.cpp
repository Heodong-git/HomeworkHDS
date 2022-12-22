#include <iostream>
#include <ConsoleGameScreen.h>
#include <ConsoleGameInput.h>
#include "Head.h"
#include "Body.h"

// ������ ��ũ�� Ŭ������ ��ü ����
ConsoleGameScreen Screen;

// ��ũ�� ������ ����
int4 ScreenSize = { 5, 5 };

int main()
{
    // ��üũ
    LeckCheck();

    // ������ ������ְ� 
    Parts* StartParts = new Head();

    // ��ũ���ʱ�ȭ 
    Screen.ScreenInit(ScreenSize, L'��');

    // �ٵ� �����Ͽ� ��ũ�� ������ ������ ��ġ�� ����(��Ȯ���� �����͸� �Է�) 
    Body::CreateBody();

    while (true)
    {
        // staitc �Լ��̱� ������ ��ü���� ȣ���� ����
        // ���� Ű üũ 
        ConsoleGameInput::ConsoleInputCheck();

        // Q , q ��ư�� ���ȴٸ� ������ �����ϵ��� ����
        if (true == ConsoleGameInput::GetIsInput() &&
            ('Q' == ConsoleGameInput::GetKey() ||
                'q' == ConsoleGameInput::GetKey()))
        {
            break;
        }

        // ȭ���� ����� 
        system("cls");

        // ��ũ���� �ʱ���·� (�ܻ�����)
        Screen.ScreenClear();

        // �ٵ� ������Ʈ
        Body::GetCurBody()->Update();

        // �Ӹ� ������Ʈ
        StartParts->Update();

        // �ٵ� ������
        Body::GetCurBody()->Render();

        // ���� ������ ( ��ũ���� ��ġ�� ���� ) 
        StartParts->Render();

        // ȭ�鿡 ��� 
        Screen.ScreenRender();
        Sleep(100);
    }

    if (nullptr != StartParts)
    {
        delete StartParts;
        StartParts = nullptr;
    }
}
