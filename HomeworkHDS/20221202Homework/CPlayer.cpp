#include "CPlayer.h"
#include <conio.h>
#include "CEngine.h"

void CPlayer::Update(CEngine& _Engine)
{
	// ���� 1. ȭ�� �ٱ����� �������� ���弼��. (�Ϸ�)
	// ���� 2. �ܻ� ���켼��. (�Ϸ�)

	// �̰� ���ص� �˴ϴ�.
	// �̰͵� ���ߴ�.
	// ���� 3. ���͸� 1���� ���弼��.  
	// ���� 4. �Ѿ��� 1�� ���弼��.  
	// ���� 5. �Ѿ��� ���͸� ������ �Ѵ� ������� �ϼ���.

	// ������ ���� �� �������� �˷��ִ� �Լ�.
	// ��¥ ������ ��

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
	case 'a':
	case 'A':
	{
		// �÷��̾��� ������ġ�� �޾ƿ´�.
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
	case 'w':
	case 'W':
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
	case 's':
	case 'S':
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
	case 'd':
	case 'D':
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
}
