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
	


private:
	// Parts Class 는 자신과 연결되어있는 이전 객체를 알 수 있어야 하기 때문에
	// 자기자신(데이터타입)의 포인터를 가지고, 자신과 연결된 객체의 주소값을 가지고 있는다. 
	Parts* m_PrevParts = nullptr;
	
};

