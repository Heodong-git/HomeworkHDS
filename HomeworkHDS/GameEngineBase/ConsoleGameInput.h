#pragma once
// Ό³Έν :
class ConsoleGameInput
{
public:
	static int GetKey()
	{
		return CurKey;
	}

	static bool GetIsInput()
	{
		return IsInput;
	}

	static void ConsoleInputCheck();

	// constrcuter destructer
	ConsoleGameInput();
	~ConsoleGameInput();

	// delete Function
	ConsoleGameInput(const ConsoleGameInput& _Other) = delete;
	ConsoleGameInput(ConsoleGameInput&& _Other) noexcept = delete;
	ConsoleGameInput& operator=(const ConsoleGameInput& _Other) = delete;
	ConsoleGameInput& operator=(ConsoleGameInput&& _Other) noexcept = delete;

protected:

private:
	static bool IsInput;
	static int CurKey;
};

