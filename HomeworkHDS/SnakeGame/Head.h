#pragma once
#include "Parts.h"

// 파츠의 일부인 헤드 클래스는 파츠 클래스를 상속받는다
class Head : public Parts
{
public:
	Head();
	~Head();

	// delete Function
	Head(const Head& _Other) = delete;
	Head(Head&& _Other) noexcept = delete;
	Head& operator=(const Head& _Other) = delete;
	Head& operator=(Head&& _Other) noexcept = delete;

protected:
	// 부모클래스에 선언되어 있는 가상함수를 재정의해서 사용
	void Update() override;
};

