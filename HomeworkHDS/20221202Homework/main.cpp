#include <iostream>
#include "CEngine.h"
#include "CPlayer.h"
#include "CMonster.h"
#include "CBullet.h"
#include <windows.h>

int main()
{
	// 플레이어이동 a, s, d, w
	// 몬스터 고정 , SetPos 함수로 위치변경
	// 총알 이동   j, k, l, i 

	// 객체생성
	CEngine Engine;
	CPlayer NewPlayer;
	CMonster NewMonster;
	CBullet NewBullet;

	// 객체별 값 세팅
	Engine.Init();
	Engine.SetMap('a');

	NewPlayer.SetPos(Int4{ 2,2 });
	NewMonster.SetPos(Int4{ 0,0 });
	NewBullet.SetPos(Int4{ 2,1 });

	// 플레이어,몬스터,총알 출력문자 세팅
	/*NewPlayer.SetDisplayChar('3');
	NewMonster.SetDisplayChar('1');
	NewBullet.SetDisplayChar('5');*/

	while (true)
	{
		system("cls");
		
		NewPlayer.Update(Engine);

		// 몬스터데드상태가 아닐때만 동작 
		if (!NewMonster.IsDead())
		{
			// 몬스터업데이트 
			NewBullet.Update(Engine, NewMonster);
			NewMonster.Update(Engine, NewBullet);
		}

		// 플레이어에 세팅된 값을 활용하여 맵세팅
		Engine.SetTile(NewPlayer.GetPos(), NewPlayer.GetDisplayChar());

		// 몬스터가 데드상태가 아닐때만 호출 
		if (!NewMonster.IsDead())
		{
			// 맵에 출력 
			Engine.SetTile(NewMonster.GetPos(), NewMonster.GetDisplayChar());
			Engine.SetTile(NewBullet.GetPos(), NewBullet.GetDisplayChar());
		}

		// 화면출력
		Engine.Render();

		printf_s("\n");
		printf_s("%s", "플레이어 이동 : A S D W\n");
		printf_s("%s", "총알 이동     : J K L I\n");

		// 화면딜레이 
		Sleep(300);
	}

	return 0;
}