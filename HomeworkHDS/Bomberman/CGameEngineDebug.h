#pragma once
#include <Windows.h>
#include <assert.h>

// ���� :
class GameEngineDebug
{
public:
	// constrcuter destructer
	GameEngineDebug();
	~GameEngineDebug();

	// delete Function
	GameEngineDebug(const GameEngineDebug& _Other) = delete;
	GameEngineDebug(GameEngineDebug&& _Other) noexcept = delete;
	GameEngineDebug& operator=(const GameEngineDebug& _Other) = delete;
	GameEngineDebug& operator=(GameEngineDebug&& _Other) noexcept = delete;

protected:

private:

};


void LeakCheck();

// ��ũ���Լ��� Ȱ���Ͽ� �������� ���̰� ���ϴ� ���� �־��ְ� �ʿ��� ������  ȣ���ϱ� ����
// � ������ ���� �������� �ؽ�Ʈ�� ���� Ȯ���� �� ���� 
#define MessageBoxAssert(MsgText) MessageBoxA(nullptr, MsgText, "Error", MB_OK);	assert(false);