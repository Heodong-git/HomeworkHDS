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
//		MessageBoxAssert("라인의 범위를 넘겨서 수정하려고 했습니다");
//		return ErrorChar;
//	}
//
//	if (XCount <= _Index)
//	{
//		MessageBoxAssert("라인의 범위를 넘겨서 수정하려고 했습니다");
//		return ErrorChar;
//	}
//
//	return Arr[_Index];
//}

//void ConsoleGameLine::Init(size_t _XCount, wchar_t _Char)
//{
//	if (nullptr != Arr)
//	{
//		MessageBoxAssert("라인을 두번초기화 했습니다");
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
	//// 방어코드
	//if (nullptr != Lines)
	//{
	//	delete[] Lines;
	//	Lines = nullptr;
	//}
}

void ConsoleGameScreen::ScreenInit(const int4& _Size, wchar_t _Char)
{
	// 방어코드
	// 배열의 크기가 0이 아니라는 의미는 이미 스크린이 만들어졌다는 의미
	if (0 != Lines.GetSize())
	{
		MessageBoxAssert("스크린을 두번초기화 했습니다");
		return;
	}

	// Array 클래스 내부에서 이상한 값이 들어오면 어썰트처리중이고
	// 스크린초기화에서는 배열의 사이즈를 받았기 때문에 Array 클래스를 사용해 이차원배열의
	// 형태로 화면을 구상해준다. 
	const int XSize = _Size.X;
	const int YSize = _Size.Y;

	// 국가코드 지정
	setlocale(LC_ALL, "KOR");

	BaseChar = _Char;

	ScreenSize = _Size;

	// 배열을 새로운 크기로 생성
	Lines.resize(YSize);
	
	// 생성된 라인의 개수만큼 반복
	// 이때 Getsize() 는 y축의 길이, 행의 개수 ( 세로로 몇줄이 만들어져있는지 ) 
	for (size_t y = 0; y < Lines.GetSize(); ++y)
	{   
		// y번째 행에 있는 Array에 XSize (열의 개수) 만큼 생성
		// 문자열의 끝을 알 수 있도록 널문자 삽입을 위해 + 1
		Lines[y].resize(XSize + 1);

		// y번째 행의 x번째 열에 문자 대입
		for (int x = 0; x < Lines[y].GetSize(); ++x)
		{
			Lines[y][x] = BaseChar;
		} 

		// 한줄이 완료되면 그 열의 끝에 널문자 삽입
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
		MessageBoxAssert("스크린의 바깥을 수정하려고 했습니다.");
		return;
	}

	// ConsoleGameLine& XLine = Lines[_Pos.Y];

	Lines[_Pos.Y][_Pos.X] = _Char;
}

// 배열전체를 베이스문자로 설정 
void ConsoleGameScreen::ScreenClear()
{
	// 현재소유한 Array 의 문자를 모두 베이스문자로 삽입하고 0을 넣어준다. 
	for (size_t y = 0; y < Lines.GetSize(); ++y)
	{
		size_t XSize = Lines[y].GetSize();
			
		for (size_t x = 0; x < XSize; ++x)
		{
			Lines[y][x] = BaseChar;
		}

		// 한줄이 끝나면 널문자 삽입
		Lines[y][XSize] = 0;
	}
}

// 생성한 이차원배열을 출력!
void ConsoleGameScreen::ScreenRender()
{
	for (size_t y = 0; y < Lines.GetSize(); ++y)
	{
		wprintf_s(&Lines[y][0]);
		wprintf_s(L"\n");

	}
}