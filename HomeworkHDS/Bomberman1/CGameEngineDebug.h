#pragma once
#include <Windows.h>
#include <assert.h>

// 설명 :
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

// 매크로함수를 활용하여 가독성을 높이고 원하는 값을 넣어주고 필요한 곳마다  호출하기 위함
// 어떤 사유로 인해 터졌는지 텍스트를 통해 확인할 수 있음 
#define MessageBoxAssert(MsgText) MessageBoxA(nullptr, MsgText, "Error", MB_OK);	assert(false);