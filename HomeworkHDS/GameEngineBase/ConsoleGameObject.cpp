#include "ConsoleGameObject.h"
#include "ConsoleGameScreen.h"

ConsoleGameObject::ConsoleGameObject()
{
}

ConsoleGameObject::ConsoleGameObject(wchar_t _Renderchar)
	: RenderChar(_Renderchar)
{
	
}

ConsoleGameObject::~ConsoleGameObject()
{
}

void ConsoleGameObject::Render()
{
	ConsoleGameScreen::GetMainScreen()->SetPixelChar(GetPos(), GetRenderChar());
}