#pragma once
#include "Parts.h"

class Body : public Parts
{
public:
	Body();
	~Body();

	// delete Function
	Body(const Body& _Other) = delete;
	Body(Body&& _Other) noexcept = delete;
	Body& operator=(const Body& _Other) = delete;
	Body& operator=(Body&& _Other) noexcept = delete;

	// 부모클래스에 선언되어 있는 가상함수를 재정의해서 사용
	void Update() override;

	static void CreateBody();
	static Body* GetCurBody();

protected:

private:
	static Body* CurBody;
};

