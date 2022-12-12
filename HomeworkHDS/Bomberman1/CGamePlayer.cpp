#include "CGamePlayer.h"
#include "CConsoleGameScreen.h"
#include <conio.h>
#include "CBomb.h"
#include "CGameEngineDebug.h"

CGamePlayer::CGamePlayer() :
	m_RenderChar(L'★'),
	m_BombArr(nullptr),
	m_MaxBombCount(0),
	m_CurBombCount(0),
	m_InstallationCount(0),
	m_CurBombIdx(0)
{

}

CGamePlayer::~CGamePlayer()
{
	// 이중포인터가 nullptr이 아니라면 동적할당된 메모리가 있는 것
	if (nullptr != m_BombArr)
	{
		for (size_t i = 0; i < m_CurBombCount; ++i)
		{
			// 이 포인터변수가 nullptr이 아니라면 폭탄이 있는거임
			// 현재 설치된 폭탄 만큼 제거
			if (nullptr != m_BombArr[i])
			{
				delete m_BombArr[i];
				m_BombArr[i] = nullptr;
			}
		}
		delete[] m_BombArr;
	}
	
}


void CGamePlayer::Init(const int4& _ScreenSize)
{
	m_MaxBombCount = 7;
	//m_BombArr = new CBomb*[m_MaxBombCount];
	// 일단 네개만
	m_BombArr = new CBomb * [m_MaxBombCount];
}


bool CGamePlayer::Update()
{
	// 키보드입력 버퍼의 사이즈가 0 이라면 false, 아니면 true( 키보드가 눌리지 않았다는 의미 ) 
	if (0 == _kbhit())
	{
		return true;
	}

	// 눌린 키가 어떤 키냐에 따라 플레이어 이동
	int Input = _getch();

	// 현재플레이어의 위치를 받아온다. 
	int4 CurPos = this->GetPos();

	// 맵크기를 받아온다. 
	int4 ScreenSize = CConsoleGameScreen::GetMainScreen()->GetScreenSize();

	// 분기처리
	switch (Input)
	{
	case'a':
	case'A':
	{
		// 현재 플레이어의 X 좌표가 0보다 작거나 같다면 움직이지 않음
		if (0 >= CurPos.X)
		{
			break;
		}
		
		if (LeftBombCheck())
		{
			break;
		}

		Move(int4{ -1,0 });
	}
	break;
	case's':
	case'S':
	{
		// 배열의 최대크기보다 현재플레이어의 X좌표가 더 크거나 같다면 움직이지 않는다. 
		if (ScreenSize.X - 1 <= CurPos.Y)
		{
			break;
		}

		if (DownBombCheck())
		{
			break;
		}

		Move(int4{ 0,1 });
	}
	break;
	case'd':
	case'D':
	{
		// 배열의 최대크기보다 현재플레이어의 X좌표가 더 크거나 같다면 움직이지 않는다. 
		if (ScreenSize.X - 1 <= CurPos.X)
		{
			break;
		}

		if (RightBombCheck())
		{
			break;
		}
		Move(int4{ 1,0 });
	}
	break;
	case'w':
	case'W':
	{
		// 현재 플레이어의 Y 좌표가 0보다 작거나 같다면 움직이지 않는다. 
		if (0 >= CurPos.Y)
		{
			break;
		}

		if (UpBombCheck())
		{
			break;
		}

		Move(int4{ 0,-1 });
	}
	break;
	case'x':
	case'X':
	{
		// X 키가 입력 되었다면 폭탄설치 
		// 플레이어와 동일한 위치에 폭탄이 없는 경우에만 설치
		// 폭탄설치개수가 최대개수보다 작을 경우에만 설치

		// 최대 개수 -1 의 값과 현재 인덱스가 같다면
		// 최대 개수만큼 설치 된 것이다. 
		if (m_MaxBombCount == m_CurBombIdx)
		{
			break;
		}

		// 동일한 위치에 폭탄이 없을 경우에만 설치
		if (false == BombOverlapCheck())
		{
			// 배열에 새로운 폭탄클래스 동적할당 
			m_BombArr[m_CurBombIdx] = new CBomb;
			// 위치세팅
			m_BombArr[m_CurBombIdx]->SetPos(GetPos());

			// 현재폭탄개수 +
			++m_CurBombCount;
			// 설치된 폭탄 개수 + 
			++m_InstallationCount;
			// 
			++m_CurBombIdx;
		}
	}
	break;
	case'q':
	case'Q':
		return false;
	break;
	default:
		break;
	}

	// 만약 배열을 벗어났다면 이전 위치로 변경해준다. 
	if (true == CConsoleGameScreen::GetMainScreen()->IsOver(GetPos()))
	{
		SetPos(CurPos);
	}
	return true;
}


CBomb** CGamePlayer::GetBombArr()
{
	return m_BombArr;
}


bool CGamePlayer::BombOverlapCheck()
{
	const int4 PlayerPos = GetPos();
	// 플레이어의 위치에 설치된 폭탄이 있다면.
	for (size_t i = 0; i < m_CurBombCount; i++)
	{
		if (nullptr == m_BombArr[i])
		{
			continue;
		}

		if (m_BombArr[i]->GetPos() == PlayerPos)
		{
			return true;
		}
	}

	return false;
}


bool CGamePlayer::LeftBombCheck()
{
	// 이동하려는 위치에 폭탄이 있는지
	int4 CurPlayerPos = GetPos();
	int4 NextPlayerPos;

	// 좌
	NextPlayerPos = CurPlayerPos + int4{ -1, 0 };

	for (size_t i = 0; i < m_CurBombCount; i++)
	{
		if (nullptr == m_BombArr[i])
		{
			continue;
		}

		if (m_BombArr[i]->GetPos() == NextPlayerPos)
		{
			return true;
		}
	}

	return false;
}

bool CGamePlayer::RightBombCheck()
{
	// 이동하려는 위치에 폭탄이 있는지
	int4 CurPlayerPos = GetPos();
	int4 NextPlayerPos;

	// 우
	NextPlayerPos = CurPlayerPos + int4{ 1, 0 };

	for (size_t i = 0; i < m_CurBombCount; i++)
	{
		if (nullptr == m_BombArr[i])
		{
			continue;
		}

		if (m_BombArr[i]->GetPos() == NextPlayerPos)
		{
			return true;
		}
	}
	return false;
}

bool CGamePlayer::UpBombCheck()
{
	// 이동하려는 위치에 폭탄이 있는지
	int4 CurPlayerPos = GetPos();
	int4 NextPlayerPos;

	// 상
	NextPlayerPos = CurPlayerPos + int4{ 0, -1 };

	for (size_t i = 0; i < m_CurBombCount; i++)
	{
		if (nullptr == m_BombArr[i])
		{
			continue;
		}

		if (m_BombArr[i]->GetPos() == NextPlayerPos)
		{
			return true;
		}
	}
	return false;
}

bool CGamePlayer::DownBombCheck()
{
	// 이동하려는 위치에 폭탄이 있는지
	int4 CurPlayerPos = GetPos();
	int4 NextPlayerPos;

	// 하
	NextPlayerPos = CurPlayerPos + int4{ 0, 1 };

	for (size_t i = 0; i < m_CurBombCount; i++)
	{
		if (nullptr == m_BombArr[i])
		{
			continue;
		}

		if (m_BombArr[i]->GetPos() == NextPlayerPos)
		{
			return true;
		}
	}

	return false;
}

