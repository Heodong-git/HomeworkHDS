#pragma once
#include "Parts.h"

// ������ �Ϻ��� ��� Ŭ������ ���� Ŭ������ ��ӹ޴´�
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
	// �θ�Ŭ������ ����Ǿ� �ִ� �����Լ��� �������ؼ� ���
	void Update() override;
};

