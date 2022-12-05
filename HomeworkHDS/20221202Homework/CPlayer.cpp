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

	// Ű�����Է� ������ ����� 0 �̶�� false, �ƴϸ� true( Ű���尡 ������ �ʾҴٴ� �ǹ� ) 
	if (0 == _kbhit())
	{
		return;
	}

	// ���ȴٸ� �Ʒ� �ڵ� ����
	// ���� �� ���� 
	int Input = _getch();

	// �÷��̾��� ������ġ�� �޾ƿ´�.
	Int4 CurPos = GetPos();

	// ���� ���� �����̳Ŀ� ���� ����
	// �����غ��� ����ġ�� ���� ���Ŀ� �����ص� ��������Ű����� 
	switch (Input)
	{
	case 'a':
	case 'A':
	{
		// ������ġ�� X ���� 0���� �۰ų� ���ٸ� �̵����� �ʴ´�.
		if (0 >= CurPos.X)
		{
			//SetPos(CurPos);
			return;
		}
		// �̵� 
		Move({ -1, 0 });
		
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

	}
		break;
	default:
		break;
	}

	// �̵� �� ������ �÷��̾ �ִ� ��ġ�� ������ ���õ� ���ڷ� ����
	const char Setchar = _Engine.GetChar();
	// �÷��̾ �̵��ϱ��� ��ġ�� �޾Ƴ��� ������ ���ڸ��� 
	// �ʿ� ���õǾ��ִ� ���ڰ��� �����Ѵ�. 
	_Engine.SetTile(CurPos, Setchar);
}
