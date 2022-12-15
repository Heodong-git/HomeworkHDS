#include "ConsoleGameScreen.h"
#include <iostream>
#include "Obstacle.h"
///////////////////////// ConsoleGameLine 

//ConsoleGameLine::~ConsoleGameLine()
//{
//	if (nullptr != Arr)
//	{
//		delete[] Arr;
//		Arr = nullptr;
//	}
//}

//wchar_t ErrorChar = -1;
//wchar_t& ConsoleGameLine::operator[](size_t _Index)
//{
//	if (0 > _Index)
//	{
//		MessageBoxAssert("������ ������ �Ѱܼ� �����Ϸ��� �߽��ϴ�");
//		return ErrorChar;
//	}
//
//	if (XCount <= _Index)
//	{
//		MessageBoxAssert("������ ������ �Ѱܼ� �����Ϸ��� �߽��ϴ�");
//		return ErrorChar;
//	}
//
//	return Arr[_Index];
//}

//void ConsoleGameLine::Init(size_t _XCount, wchar_t _Char)
//{
//	if (nullptr != Arr)
//	{
//		MessageBoxAssert("������ �ι��ʱ�ȭ �߽��ϴ�");
//		return;
//	}
//
//	Arr = new wchar_t[_XCount + 1]();
//
//	BaseChar = _Char;
//
//	for (size_t i = 0; i < _XCount; i++)
//	{
//		Arr[i] = BaseChar;
//	}
//
//	Arr[_XCount] = 0;
//
//	XCount = _XCount;
//}
//
//void ConsoleGameLine::Render()
//{
//	wprintf_s(Arr);
//}
//
//void ConsoleGameLine::Clear()
//{
//	for (size_t i = 0; i < XCount; i++)
//	{
//		Arr[i] = BaseChar;
//	}
//	Arr[XCount] = 0;
//}


///////////////////////// ConsoleGameScreen

ConsoleGameScreen* ConsoleGameScreen::MainScreen = nullptr;

ConsoleGameScreen::ConsoleGameScreen()
{
	MainScreen = this;
}

ConsoleGameScreen::~ConsoleGameScreen()
{
	//// ����ڵ�
	//if (nullptr != Lines)
	//{
	//	delete[] Lines;
	//	Lines = nullptr;
	//}
}

void ConsoleGameScreen::ScreenInit(const int4& _Size, wchar_t _Char)
{
	// ����ڵ�
	// �迭�� ũ�Ⱑ 0�� �ƴ϶�� �ǹ̴� �̹� ��ũ���� ��������ٴ� �ǹ�
	if (0 != Lines.GetSize())
	{
		MessageBoxAssert("��ũ���� �ι��ʱ�ȭ �߽��ϴ�");
		return;
	}

	// Array Ŭ���� ���ο��� �̻��� ���� ������ ���Ʈó�����̰�
	// ��ũ���ʱ�ȭ������ �迭�� ����� �޾ұ� ������ Array Ŭ������ ����� �������迭��
	// ���·� ȭ���� �������ش�. 
	const int XSize = _Size.X;
	const int YSize = _Size.Y;

	// �����ڵ� ����
	setlocale(LC_ALL, "KOR");

	BaseChar = _Char;

	ScreenSize = _Size;

	// �迭�� ���ο� ũ��� ����
	Lines.resize(YSize);
	
	// ������ ������ ������ŭ �ݺ�
	// �̶� Getsize() �� y���� ����, ���� ���� ( ���η� ������ ��������ִ��� ) 
	for (size_t y = 0; y < Lines.GetSize(); ++y)
	{   
		// y��° �࿡ �ִ� Array�� XSize (���� ����) ��ŭ ����
		// ���ڿ��� ���� �� �� �ֵ��� �ι��� ������ ���� + 1
		Lines[y].resize(XSize + 1);

		// y��° ���� x��° ���� ���� ����
		for (int x = 0; x < Lines[y].GetSize(); ++x)
		{
			Lines[y][x] = BaseChar;
		} 

		// ������ �Ϸ�Ǹ� �� ���� ���� �ι��� ����
		Lines[y][XSize] = 0;
	}
}

bool ConsoleGameScreen::IsOver(int4 _Pos)
{
	if (0 > _Pos.X)
	{
		return true;
	}

	if (0 > _Pos.Y)
	{
		return true;
	}

	if (ScreenSize.X <= _Pos.X)
	{
		return true;
	}

	if (ScreenSize.Y <= _Pos.Y)
	{
		return true;
	}

	return false;
}

bool ConsoleGameScreen::IsObstacle(int4 _Pos)
{

	wchar_t Renderchar = Obstacle::GetMainObstacle()->GetRenderChar();

	if (Lines[_Pos.Y][_Pos.X] == Renderchar)
	{
		return true;
	}

	return false;
}


wchar_t ConsoleGameScreen::IsRenderchar(int4 _Pos)
{
	return Lines[_Pos.Y][_Pos.X];
}

void ConsoleGameScreen::SetPixelChar(int4 _Pos, wchar_t _Char)
{
	if (true == IsOver(_Pos))
	{
		MessageBoxAssert("��ũ���� �ٱ��� �����Ϸ��� �߽��ϴ�.");
		return;
	}

	// ConsoleGameLine& XLine = Lines[_Pos.Y];

	Lines[_Pos.Y][_Pos.X] = _Char;
}

// �迭��ü�� ���̽����ڷ� ���� 
void ConsoleGameScreen::ScreenClear()
{
	// ��������� Array �� ���ڸ� ��� ���̽����ڷ� �����ϰ� 0�� �־��ش�. 
	for (size_t y = 0; y < Lines.GetSize(); ++y)
	{
		size_t XSize = Lines[y].GetSize();
			
		for (size_t x = 0; x < XSize; ++x)
		{
			Lines[y][x] = BaseChar;
		}

		// ������ ������ �ι��� ����
		Lines[y][XSize] = 0;
	}
}

// ������ �������迭�� ���!
void ConsoleGameScreen::ScreenRender()
{
	for (size_t y = 0; y < Lines.GetSize(); ++y)
	{
		wprintf_s(&Lines[y][0]);
		wprintf_s(L"\n");

	}
}