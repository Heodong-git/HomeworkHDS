#include "CPlayer.h"
#include <conio.h>
#include "CEngine.h"

void CPlayer::Update(CEngine& _Engine)
{
	// 숙제 1. 화면 바깥으로 못나가게 만드세요. (완료)
	// 숙제 2. 잔상 지우세요. (완료)

	// 이건 안해도 됩니다.
	// 이것도 다했다.
	// 숙제 3. 몬스터를 1마리 만드세요.  
	// 숙제 4. 총알을 1개 만드세요.  
	// 숙제 5. 총알이 몬스터를 만나면 둘다 사라지게 하세요.

	// 누르고 나서 뭘 눌렀는지 알려주는 함수.
	// 진짜 뭔가를 눌

	// 키보드입력 버퍼의 사이즈가 0 이라면 false, 아니면 true( 키보드가 눌리지 않았다는 의미 ) 
	if (0 == _kbhit())
	{
		return;
	}

	// 눌렸다면 아래 코드 동작
	// 눌린 값 저장 
	int Input = _getch();

	// 플레이어의 현재위치를 받아온다.
	Int4 CurPos = GetPos();

	// 눌린 값이 무엇이냐에 따라서 동작
	// 생각해보니 스위치문 동작 이후에 수정해도 상관없을거같은데 
	switch (Input)
	{
	case 'a':
	case 'A':
	{
		// 현재위치의 X 값이 0보다 작거나 같다면 이동하지 않는다.
		if (0 >= CurPos.X)
		{
			//SetPos(CurPos);
			return;
		}
		// 이동 
		Move({ -1, 0 });
		
	}
		break;
	case 'w':
	case 'W':
	{
		Int4 CurPos = GetPos();

		// 현재위치의 Y 값이 0보다 작거나 같다면 이동하지 않는다. 
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

		// 현재위치의 Y 값이 4보다 크거나 같다면 이동하지 않는다.
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

		// 현재위치의 X 값이 4보다 크거나 같다면 이동하지 않는다.
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

	// 이동 후 이전에 플레이어가 있던 위치를 기존에 세팅된 문자로 변경
	const char Setchar = _Engine.GetChar();
	// 플레이어가 이동하기전 위치를 받아놨기 때문에 그자리에 
	// 맵에 세팅되어있는 문자값을 세팅한다. 
	_Engine.SetTile(CurPos, Setchar);
}
