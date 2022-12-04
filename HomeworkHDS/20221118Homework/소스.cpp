
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "CPlayer.h"
#include "CMonster.h"

int PlayerAtt = 20;
int PlayerHp = 200;

int MonsterAtt = 10;
int MonsterHp = 100;


// 플레이어 데미지 이후 출력되는 문자열이 연속으로 나오게 수정

void StatusRender(const char* _Name, int _Att, int _Hp)
{
    printf_s("%s=====================================\n", _Name);
    printf_s("공격력 = %d \n", _Att);
    printf_s("체  력 = %d \n", _Hp);
    printf_s("============================================\n");
}

void Damage(int _PlayerAtt, int _MonsterAtt)
{
    PlayerHp -= _MonsterAtt;

    system("cls");

    StatusRender("플레이어", MonsterAtt, PlayerHp);
    StatusRender("몬스터", PlayerAtt, MonsterHp);

    int Input = 0;
    printf_s("플레이어가 %d데미지를 받았습니다.\n", _MonsterAtt);
    Input = _getch();
    printf_s("플레이어는 %d체력이 남았습니다.\n", PlayerHp);
    Input = _getch();

    MonsterHp -= _PlayerAtt;

    system("cls");

    StatusRender("플레이어", MonsterAtt, PlayerHp);
    StatusRender("몬스터", PlayerAtt, MonsterHp);

    printf_s("플레이어가 %d데미지를 받았습니다.\n", _MonsterAtt);
    printf_s("플레이어는 %d체력이 남았습니다.\n", PlayerHp);

    printf_s("몬스터가 %d데미지를 받았습니다.\n", _PlayerAtt);
    Input = _getch();
    printf_s("몬스터는 %d체력이 남았습니다.\n", MonsterHp);
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
        
        // 각 객체들의 정보 출력
        // 함수를 활용해서 각 객체의 함수를 호출하는 방식으로 변경
        Player.StatusRender();
        Monster.StatusRender();

        int Value = _getch();

        Monster.Damage(Player.GetAtt());
        Player.Damage(Monster.GetAtt());
    }
}
