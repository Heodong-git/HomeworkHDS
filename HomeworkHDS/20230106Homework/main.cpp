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
		// ���� ���� ������ �ִ� ���ڿ��� ���̸� ���Ѵ�.
		int Len = strlen(Teststr.c_str());

		// for ���� ������ ���Ƽ� ���ڿ��� ã�´�. 
		for (int i = Len; Len > 0; --i)
		{
			std::cout << Teststr.c_str() + i - 1 << std::endl;

			// ���� ���ڿ��� ã�Ҵٸ� ���ϴ� �� ���ڿ��� ���� �ε����� ����
			if (!(strcmp(Teststr.c_str() + i - 1, _Text.c_str())))
			{
				// ã������ ����
				// Idx ��°�� H ��� �ǹ��̰�, �����ε����� �����ϴ� \ �� �������ϱ� ������ - 1
				Idx = i - 1;
				break;
			}
		}

		// ���ڿ� �迭�� �����.
		char ChangeText[256] = {};

		// �迭�� �����ּҸ� ����Ű�� ������
		char* CTextPtr = ChangeText;
	
		// ��ȸ�ϸ鼭 ���ڸ� �ϳ��� �־��ش�. 
		for (int i = 0; i < Idx; ++i)
		{
			CTextPtr[i] = Teststr.c_str()[i];
		}

		// Idx ��°�� ���ڿ��� ���̱� ������ 0 ���� 
		ChangeText[Idx] = 0;

		// ���� ���� ���ڿ��� ���� 
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