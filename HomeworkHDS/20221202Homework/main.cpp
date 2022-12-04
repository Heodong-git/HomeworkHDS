#include <iostream>
#include "CEngine.h"
#include "CPlayer.h"
#include "CMonster.h"
#include "CBullet.h"
#include <windows.h>

int main()
{
	// �÷��̾��̵� a, s, d, w
	// �����̵�   j, k, l, i
	// �Ѿ� ��ġ����, SetPos �Լ��� ����

	// ��ü����
	CEngine Engine;
	CPlayer NewPlayer;
	CMonster NewMonster;
	CBullet NewBullet;

	// ��ü�� �� ����
	Engine.Init();
	Engine.SetMap('a');
	Engine.Render();

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

		// ȭ������� 
		Sleep(400);
	}

	return 0;
}