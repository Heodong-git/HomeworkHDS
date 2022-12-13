#include "CGamePlayer.h"
#include "CConsoleGameScreen.h"
#include <conio.h>
#include "CBomb.h"
#include "CGameEngineDebug.h"

CGamePlayer::CGamePlayer() :
	m_RenderChar(L'��'),
	m_BombArr(nullptr),
	m_MaxBombCount(0),
	m_CurBombCount(0),
	m_InstallationCount(0),
	m_CurBombIdx(0)
{

}

CGamePlayer::~CGamePlayer()
{
	// ���������Ͱ� nullptr�� �ƴ϶�� �����Ҵ�� �޸𸮰� �ִ� ��
	if (nullptr != m_BombArr)
	{
		for (size_t i = 0; i < m_CurBombCount; ++i)
		{
			// �� �����ͺ����� nullptr�� �ƴ϶�� ��ź�� �ִ°���
			// ���� ��ġ�� ��ź ��ŭ ����
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
	// �ϴ� �װ���
	m_BombArr = new CBomb * [m_MaxBombCount];
}


bool CGamePlayer::Update()
{
	// Ű�����Է� ������ ����� 0 �̶�� false, �ƴϸ� true( Ű���尡 ������ �ʾҴٴ� �ǹ� ) 
	if (0 == _kbhit())
	{ 
		CConsoleGameScreen::GetMainScreen()->SetPixel(GetPos(), GetRenderchar());
		return true;
	}

	// ���� Ű�� � Ű�Ŀ� ���� �÷��̾� �̵�
	int Input = _getch();

	// �÷��̾ �̵��ؾ��� ��ġ�� �޾ƿ´�. 
	int4 NextPos = GetPos();

	// ��ũ�⸦ �޾ƿ´�. 

	// �б�ó��
	switch (Input)
	{
	case'a':
	case'A':
	{
		if (LeftBombCheck())
		{
			break;
		}

		NextPos += { -1, 0};
	}
	break;
	case's':
	case'S':
	{

		if (DownBombCheck())
		{
			break;
		}

		NextPos += { 0, 1};
	}
	break;
	case'd':
	case'D':
	{
		
		if (RightBombCheck())
		{
			break;
		}
		NextPos += { 1, 0};
	}
	break;
	case'w':
	case'W':
	{
	
		if (UpBombCheck())
		{
			break;
		}

		NextPos += { 0, -1};
	}
	break;
	case'x':
	case'X':
	{
		// X Ű�� �Է� �Ǿ��ٸ� ��ź��ġ 
		// �÷��̾�� ������ ��ġ�� ��ź�� ���� ��쿡�� ��ġ
		// ��ź��ġ������ �ִ밳������ ���� ��쿡�� ��ġ

		// �ִ� ���� -1 �� ���� ���� �ε����� ���ٸ�
		// �ִ� ������ŭ ��ġ �� ���̴�. 
		if (m_MaxBombCount == m_CurBombIdx)
		{
			break;
		}

		// ������ ��ġ�� ��ź�� ���� ��쿡�� ��ġ
		if (false == BombOverlapCheck())
		{
			// �迭�� ���ο� ��źŬ���� �����Ҵ� 
			m_BombArr[m_CurBombIdx] = new CBomb;
			// ��ġ����
			m_BombArr[m_CurBombIdx]->SetPos(GetPos());

			// ������ź���� +
			++m_CurBombCount;
			// ��ġ�� ��ź ���� + 
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

	// �迭�� ����� �ʾ��� ��쿡�� �̵������ش�.  
	if (false == CConsoleGameScreen::GetMainScreen()->IsOver(NextPos))
	{
		SetPos(NextPos);
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
	// �÷��̾��� ��ġ�� ��ġ�� ��ź�� �ִٸ�.
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
	// �̵��Ϸ��� ��ġ�� ��ź�� �ִ���
	int4 CurPlayerPos = GetPos();
	int4 NextPlayerPos;

	// ��
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
	// �̵��Ϸ��� ��ġ�� ��ź�� �ִ���
	int4 CurPlayerPos = GetPos();
	int4 NextPlayerPos;

	// ��
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
	// �̵��Ϸ��� ��ġ�� ��ź�� �ִ���
	int4 CurPlayerPos = GetPos();
	int4 NextPlayerPos;

	// ��
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
	// �̵��Ϸ��� ��ġ�� ��ź�� �ִ���
	int4 CurPlayerPos = GetPos();
	int4 NextPlayerPos;

	// ��
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

