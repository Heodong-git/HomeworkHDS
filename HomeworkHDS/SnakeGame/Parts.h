#pragma once
#include <ConsoleGameObject.h>

// Parts Class 는 ConsoleGameObject 클래스를 상속받는다. 
class Parts : public ConsoleGameObject
{
public:
	Parts();
	Parts(wchar_t _Renderchar);
	~Parts();

	// 복사생성자 
	Parts(const Parts& _Other) = delete;
	// RValue 생성자
	Parts(Parts&& _Other) noexcept = delete;
	// 대입연산자 
	Parts& operator=(const Parts& _Other) = delete;
	Parts& operator=(Parts&& _Other) noexcept = delete;

	// 업데이트 함수를 가상함수로 만들어주고 
	// 자식클래스에서는 재정의하지 않으면 부모클래스의 Update를
	// 재정의했다면 자식클래스의 Update 를 호출하여 사용하게 된다. 
	virtual void Update();
	
	// 자신의 이전 파츠를 세팅한다. 
	void SetPrev(Parts* _Prev)
	{
		// 나자신의 이전파츠는 인자로 들어온 파츠
		m_Prev = _Prev;
		// 인자로 들어온 파츠의 다음 파츠는 나자신이 된다.
		_Prev->m_Next = this;
	}

	// 이전, 다음파츠 반환
	Parts* GetPrev() { return m_Prev; }
	Parts* GetNext() { return m_Next; }

	// 재귀업데이트, 나의 이전파츠가 있다면 업데이트
	void RecursionPrevUpdate()
	{
		// 이전 파츠가 nullptr 이라면 함수종료 
		if (nullptr == m_Prev)
		{
			return;
		}

		// 그게 아니라면 업데이트진행, 함수재귀호출
		m_Prev->Update();
		m_Prev->RecursionPrevUpdate();
	}

	// 업데이트와 마찬가지로 렌더링 재귀호출
	void RecursionPrevRender()
	{
		if (nullptr == m_Prev)
		{
			return;
		}

		m_Prev->Render();
		m_Prev->RecursionPrevRender();
	}

	Parts* GetRecursionLastParts()
	{
		// 이전 파츠가 없다면 마지막파츠인 것.
		if (nullptr == m_Prev)
		{
			return this;
		}

		// 이전 파츠가 있다면 재귀호출
		return m_Prev->GetRecursionLastParts();
	}

protected:
	// Parts Class 는 자신과 연결되어있는 이전 객체를 알 수 있어야 하기 때문에
	// 자기자신(데이터타입)의 포인터를 가지고, 자신과 연결된 객체의 주소값을 가지고 있는다. 
	Parts* m_Prev = nullptr;
	Parts* m_Next = nullptr;
	
private:
};

