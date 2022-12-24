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

	// �θ�Ŭ������ ����Ǿ� �ִ� �����Լ��� �������ؼ� ���
	bool Update() override;

	static void CreateBody();
	static Body* GetCurBody();

	static int4 RecursionRandPos();
protected:

private:
	static Body* CurBody;
};

