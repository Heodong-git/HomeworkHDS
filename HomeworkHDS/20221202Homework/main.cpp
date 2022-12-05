#include <iostream>
#include "CEngine.h"
#include "CPlayer.h"
#include "CMonster.h"
#include "CBullet.h"
#include <windows.h>

int main()
{
	// �÷��̾��̵� a, s, d, w
	// ���� ���� , SetPos �Լ��� ��ġ����
	// �Ѿ� �̵�   j, k, l, i 

	// ��ü����
	CEngine Engine;
	CPlayer NewPlayer;
	CMonster NewMonster;
	CBullet NewBullet;

	// ��ü�� �� ����
	Engine.Init();
	Engine.SetMap('a');

	NewPlayer.SetPos(Int4{ 2,2 });
	NewMonster.SetPos(Int4{ 0,0 });
	NewBullet.SetPos(Int4{ 2,1 });

	// �÷��̾�,����,�Ѿ� ��¹��� ����
	/*NewPlayer.SetDisplayChar('3');
	NewMonster.SetDisplayChar('1');
	NewBullet.SetDisplayChar('5');*/

	while (true)
	{
		system("cls");
		
		NewPlayer.Update(Engine);

		// ���͵�����°� �ƴҶ��� ���� 
		if (!NewMonster.IsDead())
		{
			// ���;�����Ʈ 
			NewBullet.Update(Engine, NewMonster);
			NewMonster.Update(Engine, NewBullet);
		}

		// �÷��̾ ���õ� ���� Ȱ���Ͽ� �ʼ���
		Engine.SetTile(NewPlayer.GetPos(), NewPlayer.GetDisplayChar());

		// ���Ͱ� ������°� �ƴҶ��� ȣ�� 
		if (!NewMonster.IsDead())
		{
			// �ʿ� ��� 
			Engine.SetTile(NewMonster.GetPos(), NewMonster.GetDisplayChar());
			Engine.SetTile(NewBullet.GetPos(), NewBullet.GetDisplayChar());
		}

		// ȭ�����
		Engine.Render();

		printf_s("\n");
		printf_s("%s", "�÷��̾� �̵� : A S D W\n");
		printf_s("%s", "�Ѿ� �̵�     : J K L I\n");

		// ȭ������� 
		Sleep(300);
	}

	return 0;
}