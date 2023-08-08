#include <iostream>
#include <ConsoleGameScreen.h>
#include <ConsoleGameInput.h>
#include "Head.h"
#include "Body.h"
#include "Parts.h"
#include <vector>

// ������ ��ũ�� Ŭ������ ��ü ����
ConsoleGameScreen Screen;

// ��ũ�� ������ ����
int4 ScreenSize = { 3, 3 };

int main()
{
    // ��üũ
    LeckCheck();

    int a = 0;

    // ������ ������ְ� 
    Parts* StartParts = new Head();
    
    // ������ ����� ������ ũ��� ��ũ���������� ũ�⸸ŭ �̸� �Ҵ����ش�.
    Parts::GetVecParts().reserve(ScreenSize.X * ScreenSize.Y);
    // ������� ������ �����迭�� �����Ѵ�. 
    Parts::GetVecParts().push_back(StartParts);

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

        // ������Ʈ�� bool Ÿ������ �����ϰ� 
        // ��ȯ�ϴ� ���� false �� ��� ����ǵ��� �ۼ�
        // ����ÿ��� ȭ���� ���������� �Լ��� ȣ���Ͽ� ȭ���� ������� �Ŀ� ������ �����Ų��. 
        if (false == StartParts->Update())
        {
            StartParts->RecursionPrevRender();
            // �ٵ� ������
            Body::GetCurBody()->Render();

            // ȭ�鿡 ��� 
            Screen.ScreenRender();
            std::cout << "Game Over" << std::endl; 
            break;
        }

        // ����� ���� ������
        StartParts->RecursionPrevRender();
        // �ٵ� ������
        Body::GetCurBody()->Render();

        // ȭ�鿡 ��� 
        Screen.ScreenRender();
        Sleep(100);
    }

    // ���Ϳ� ����� �����Ҵ�� ������ ��� �����Ѵ�. 
    std::vector<Parts*> vecParts = Parts::GetVecParts();

    for (size_t i = 0; i < vecParts.size(); i++)
    {
        if (nullptr != vecParts[i])
        {
             delete vecParts[i];
             vecParts[i] = nullptr;
        }
    }

    // static ������ ����Ǿ��ֱ� ������ �ѹ� �ʱ�ȭ�� ���Ŀ��� �ʱ�ȭ�� �Ұ�����. 
    if (nullptr != Body::GetCurBody())
    {
        delete Body::GetCurBody();
    }
}
