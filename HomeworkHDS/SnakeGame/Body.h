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
	void Update() override;

	static void CreateBody();
	static Body* GetCurBody();

protected:

private:
	static Body* CurBody;
};

