#include <iostream>
#include <string>
#include <GameEngineBase/GameEngineDebug.h>

class Test
{
public:
	Test()
	{
		Teststr = "D:\\Project\\AR45\\WINAPI\\APIApp\\ContentsResources\\Image\\Heros.bmp";
	}
	~Test()
	{

	}

public:
	std::string Teststr;

	void MoveParent()
	{
		int Idx = 0;
		// 현재 내가 가지고 있는 문자열의 길이를 구한다.
		int Len = strlen(Teststr.c_str());

		if (2 <= Len)
		{
			// 현재 문자열의 길이가 2작거나 같다는것은 D: <--- 의 경로만 남았다는 의미이다. 
			// assert 
			MessageBoxAssert("더이상 상위 디렉터리가 존재하지 않습니다.");
		}

		// for 문을 역으로 돌아서 문자열을 찾는다. 
		for (int i = Len - 1; Len > 0; --i)
		{
			// 하나씩확인 
			char Text = Teststr.c_str()[i];

			// 같은 문자열을 찾았다면 원하는 그 문자열의 시작 인덱스를 저장
			if (Teststr.c_str()[i] == '\\')
			{
				Idx = i;
				break;
			}
		}

		// 문자열 배열을 만든다.
		char ChangeText[256] = {};

		// 배열의 시작주소를 가리키는 포인터
		char* CTextPtr = ChangeText;
	
		// 순회하면서 문자를 하나씩 넣어준다. 
		for (int i = 0; i < Idx; ++i)
		{
			CTextPtr[i] = Teststr.c_str()[i];
		}

		// 내가 가진 문자열에 대입 
		Teststr = ChangeText;
	}
};


int main()
{
	Test strTest;

	strTest.MoveParent();
	std::cout << strTest.Teststr.c_str() << std::endl;
	strTest.MoveParent();
	std::cout << strTest.Teststr.c_str() << std::endl;
	strTest.MoveParent();
	std::cout << strTest.Teststr.c_str() << std::endl;
	strTest.MoveParent();
	std::cout << strTest.Teststr.c_str() << std::endl;
	strTest.MoveParent();
	std::cout << strTest.Teststr.c_str() << std::endl;
	strTest.MoveParent();
	std::cout << strTest.Teststr.c_str() << std::endl;
	strTest.MoveParent();
	std::cout << strTest.Teststr.c_str() << std::endl;
	strTest.MoveParent();

	return 0;
}