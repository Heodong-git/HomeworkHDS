#include <iostream>
#include <string>

class Test
{
public:
	Test()
	{
		Teststr = "D:\Project\AR45\WINAPI\APIApp\ContentsResources\Image\Heros.bmp";
	}
	~Test()
	{

	}

public:
	std::string Teststr;

	void MoveParent(const std::string& _Text)
	{
		int Idx = 0;
		// 현재 내가 가지고 있는 문자열의 길이를 구한다.
		int Len = strlen(Teststr.c_str());

		// for 문을 역으로 돌아서 문자열을 찾는다. 
		for (int i = Len; Len > 0; --i)
		{
			std::cout << Teststr.c_str() + i - 1 << std::endl;

			// 같은 문자열을 찾았다면 원하는 그 문자열의 시작 인덱스를 저장
			if (!(strcmp(Teststr.c_str() + i - 1, _Text.c_str())))
			{
				// 찾았으면 종료
				// Idx 번째는 H 라는 의미이고, 그전인덱스에 존재하는 \ 도 지워야하기 때문에 - 1
				Idx = i - 1;
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

		// Idx 번째는 문자열의 끝이기 때문에 0 삽입 
		ChangeText[Idx] = 0;

		// 내가 가진 문자열에 대입 
		Teststr = ChangeText;
	}
};


int main()
{
	Test strTest;

	strTest.MoveParent("WINAPI");

	std::cout << strTest.Teststr.c_str() << std::endl;
	
	return 0;
}