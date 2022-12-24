#pragma once
#include <ConsoleGameObject.h>
#include <vector>
// Parts Class �� ConsoleGameObject Ŭ������ ��ӹ޴´�. 
class Parts : public ConsoleGameObject
{
public:
	Parts();
	Parts(wchar_t _Renderchar);
	~Parts();

	// ��������� 
	Parts(const Parts& _Other) = delete;
	// RValue ������
	Parts(Parts&& _Other) noexcept = delete;
	// ���Կ����� 
	Parts& operator=(const Parts& _Other) = delete;
	Parts& operator=(Parts&& _Other) noexcept = delete;

	// ������Ʈ �Լ��� �����Լ��� ������ְ� 
	// �ڽ�Ŭ���������� ���������� ������ �θ�Ŭ������ Update��
	// �������ߴٸ� �ڽ�Ŭ������ Update �� ȣ���Ͽ� ����ϰ� �ȴ�. 
	virtual bool Update();
	
	// �ڽ��� ���� ������ �����Ѵ�. 
	void SetPrev(Parts* _Prev)
	{
		// ���ڽ��� ���������� ���ڷ� ���� ����
		m_Prev = _Prev;
		// ���ڷ� ���� ������ ���� ������ ���ڽ��� �ȴ�.
		_Prev->m_Next = this;
	}

	// ����, �������� ��ȯ
	Parts* GetPrev() { return m_Prev; }
	Parts* GetNext() { return m_Next; }

	// ��;�����Ʈ, ���� ���������� �ִٸ� ������Ʈ
	void RecursionNextMove();

	// ������Ʈ�� ���������� ������ ���ȣ��
	void RecursionPrevRender();

	Parts* GetLastParts()
	{
		if (nullptr == m_Prev)
		{
			return this;
		}

		return m_Prev->GetLastParts();
	}

	static std::vector<Parts*>& GetVecParts() { return VecParts; }
	static std::vector<Parts*>& GetVecNoneEquipParts() { return VecNoneEquipParts; }

protected:
	// Parts Class �� �ڽŰ� ����Ǿ��ִ� ���� ��ü�� �� �� �־�� �ϱ� ������
	// �ڱ��ڽ�(������Ÿ��)�� �����͸� ������, �ڽŰ� ����� ��ü�� �ּҰ��� ������ �ִ´�. 
	Parts* m_Prev = nullptr;
	Parts* m_Next = nullptr;
	
private:
	static std::vector<Parts*> VecParts;
	static std::vector<Parts*> VecNoneEquipParts;
};

