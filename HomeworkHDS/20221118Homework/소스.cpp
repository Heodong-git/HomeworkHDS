
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "CPlayer.h"
#include "CMonster.h"

int PlayerAtt = 20;
int PlayerHp = 200;

int MonsterAtt = 10;
int MonsterHp = 100;


// �÷��̾� ������ ���� ��µǴ� ���ڿ��� �������� ������ ����

void StatusRender(const char* _Name, int _Att, int _Hp)
{
    printf_s("%s=====================================\n", _Name);
    printf_s("���ݷ� = %d \n", _Att);
    printf_s("ü  �� = %d \n", _Hp);
    printf_s("============================================\n");
}

void Damage(int _PlayerAtt, int _MonsterAtt)
{
    PlayerHp -= _MonsterAtt;

    system("cls");

    StatusRender("�÷��̾�", MonsterAtt, PlayerHp);
    StatusRender("����", PlayerAtt, MonsterHp);

    int Input = 0;
    printf_s("�÷��̾ %d�������� �޾ҽ��ϴ�.\n", _MonsterAtt);
    Input = _getch();
    printf_s("�÷��̾�� %dü���� ���ҽ��ϴ�.\n", PlayerHp);
    Input = _getch();

    MonsterHp -= _PlayerAtt;

    system("cls");

    StatusRender("�÷��̾�", MonsterAtt, PlayerHp);
    StatusRender("����", PlayerAtt, MonsterHp);

    printf_s("�÷��̾ %d�������� �޾ҽ��ϴ�.\n", _MonsterAtt);
    printf_s("�÷��̾�� %dü���� ���ҽ��ϴ�.\n", PlayerHp);

    printf_s("���Ͱ� %d�������� �޾ҽ��ϴ�.\n", _PlayerAtt);
    Input = _getch();
    printf_s("���ʹ� %dü���� ���ҽ��ϴ�.\n", MonsterHp);
    Input = _getch();
}

int main()
{
    CPlayer Player;
    CMonster Monster;

    while (true)
    {
        // \n
        // int Value = system("D:\\AR45\\CPlusPlus\\x64\\Debug\\01.Program.exe");
        system("cls");
        
        // �� ��ü���� ���� ���
        // �Լ��� Ȱ���ؼ� �� ��ü�� �Լ��� ȣ���ϴ� ������� ����
        Player.StatusRender();
        Monster.StatusRender();

        int Value = _getch();

        Monster.Damage(Player.GetAtt());
        Player.Damage(Monster.GetAtt());
    }
}
