
#include <iostream>
#include <conio.h>

int PlayerAtt = 20;
int PlayerHp = 200;

int MonsterAtt = 10;
int MonsterHp = 100;

void PlayerStatus()
{
    printf_s("�÷��̾�=====================================\n");
    printf_s("���ݷ� = %d \n", PlayerAtt);
    printf_s("ü  �� = %d \n", PlayerHp);
    printf_s("============================================\n");
}

void MonsterStatus()
{
    printf_s("����=====================================\n");
    printf_s("���ݷ� = %d \n", MonsterAtt);
    printf_s("ü  �� = %d \n", MonsterHp);
    printf_s("===========================================\n");
}

void PlayerDamage(int _Damage)
{
    PlayerHp -= _Damage;

    system("cls");

    PlayerStatus();
    MonsterStatus();

    int Input = 0;
    printf_s("�÷��̾ %d�������� �޾ҽ��ϴ�.\n", _Damage);
    Input = _getch();
    printf_s("�÷��̾�� %dü���� ���ҽ��ϴ�.\n", PlayerHp);
    Input = _getch();

}

void MonsterDamage(int _Damage)
{
    MonsterHp -= _Damage;

    system("cls");

    PlayerStatus();
    MonsterStatus();

    int Input = 0;
    printf_s("���Ͱ� %d�������� �޾ҽ��ϴ�.\n", _Damage);
    Input = _getch();
    printf_s("���ʹ� %dü���� ���ҽ��ϴ�.\n", MonsterHp);
    Input = _getch();
}

int main()
{
    while (true)
    {
        // \n
        // int Value = system("D:\\AR45\\CPlusPlus\\x64\\Debug\\01.Program.exe");
        system("cls");
        PlayerStatus();
        MonsterStatus();

        int Value = _getch();

        PlayerDamage(MonsterAtt);
        MonsterDamage(PlayerAtt);
    }
}
