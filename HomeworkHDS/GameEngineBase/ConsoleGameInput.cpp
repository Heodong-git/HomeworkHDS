#include "ConsoleGameInput.h"
#include <conio.h>

bool ConsoleGameInput::IsInput;
int ConsoleGameInput::CurKey;

ConsoleGameInput::ConsoleGameInput()
{
}

ConsoleGameInput::~ConsoleGameInput()
{
}


void ConsoleGameInput::ConsoleInputCheck()
{
	IsInput = false;

	if (0 == _kbhit())
	{
		return;
	}

	IsInput = true;

	CurKey = _getch();
}