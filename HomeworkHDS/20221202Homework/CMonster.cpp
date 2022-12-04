#include "CMonster.h"
#include "CEngine.h"
#include "CBullet.h"
#include <Windows.h>
#include <conio.h>

void CMonster::Update(CEngine& _Engine, CBullet& _Bullet)
{
	// ���Ͱ� ���� ������¶�� return;
	if (IsDead() == true)
	{
		return;
	}

	// Ű���尡 ������ �ʾҴٸ� 0 
	if (0 == _kbhit())
	{
		return;
	}
	// ���ȴٸ� �Ʒ� �ڵ� ����
	// ���� �� ���� 
	int Input = _getch();

	// ���� ���� �����̳Ŀ� ���� ����
	switch (Input)
	{
	case 'j':
	case 'J':
	{
		// ������ ������ġ�� �޾ƿ´�.
		Int4 CurPos = GetPos();

		// ������ġ�� X ���� 0���� �۰ų� ���ٸ� �̵����� �ʴ´�.
		if (0 >= CurPos.X)
		{
			//SetPos(CurPos);
			return;
		}

		// �̵� 
		Move({ -1, 0 });

		// �̵� �� ������ �÷��̾ �ִ� ��ġ�� ������ ���õ� ���ڷ� ����
		const char Setchar = _Engine.GetChar();
		// �÷��̾ �̵��ϱ��� ��ġ�� �޾Ƴ��� ������ ���ڸ��� 
		// �ʿ� ���õǾ��ִ� ���ڰ��� �����Ѵ�. 
		_Engine.SetTile(CurPos, Setchar);
	}
	break;
	case 'i':
	case 'I':
	{
		Int4 CurPos = GetPos();

		// ������ġ�� Y ���� 0���� �۰ų� ���ٸ� �̵����� �ʴ´�. 
		if (0 >= CurPos.Y)
		{
			return;
		}

		Move({ 0, -1 });

		const char Setchar = _Engine.GetChar();
		_Engine.SetTile(CurPos, Setchar);
	}
	break;
	case 'k':
	case 'K':
	{
		Int4 CurPos = GetPos();

		// ������ġ�� Y ���� 4���� ũ�ų� ���ٸ� �̵����� �ʴ´�.
		if (4 <= CurPos.Y)
		{
			return;
		}

		Move({ 0, 1 });

		const char Setchar = _Engine.GetChar();
		_Engine.SetTile(CurPos, Setchar);
	}
	break;
	case 'l':
	case 'L':
	{
		Int4 CurPos = GetPos();

		// ������ġ�� X ���� 4���� ũ�ų� ���ٸ� �̵����� �ʴ´�.
		if (4 <= CurPos.X)
		{
			return;
		}
		Move({ 1, 0 });

		const char Setchar = _Engine.GetChar();
		_Engine.SetTile(CurPos, Setchar);
	}
	break;
	default:
		break;
	}

	// �б�ó�� �Ϸ� �� �Ѿ� ��ġ�� üũ�Ͽ� ���� ���� ��ġ�� �ִٸ� �Ѵ� ����.. ��.. 
	// �ҷ��� ��ġ�� ��������, ���� �ҷ��� ��ġ�� ���Ͱ� �̵��� ��ġ�� �����ϴٸ� ���͵��� 

	Int4 BulletPos = _Bullet.GetPos();
	Int4 MonsterPos = GetPos();

	// ���� ���� ��ġ�� �����ϴٸ� 
	if (BulletPos == MonsterPos)
	{
		// �ϴ� ü���� 0���� ���� ������¸� true�� ����� 
		MonsterDamage(_Bullet.GetAtt());

		// ������ġ�� ���������� ���� ���ڰ��� ����
		const char MapText = _Engine.GetChar();

		_Engine.SetTile(MonsterPos, MapText);
	}

}

void CMonster::MonsterDamage(int _Damage)
{
	Hp -= _Damage;

	if (Hp < 0)
	{
		Hp = 0;
	}
}
