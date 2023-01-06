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
		// ���� ���� ������ �ִ� ���ڿ��� ���̸� ���Ѵ�.
		int Len = strlen(Teststr.c_str());

		if (2 <= Len)
		{
			// ���� ���ڿ��� ���̰� 2�۰ų� ���ٴ°��� D: <--- �� ��θ� ���Ҵٴ� �ǹ��̴�. 
			// assert 
			MessageBoxAssert("���̻� ���� ���͸��� �������� �ʽ��ϴ�.");
		}

		// for ���� ������ ���Ƽ� ���ڿ��� ã�´�. 
		for (int i = Len - 1; Len > 0; --i)
		{
			// �ϳ���Ȯ�� 
			char Text = Teststr.c_str()[i];

			// ���� ���ڿ��� ã�Ҵٸ� ���ϴ� �� ���ڿ��� ���� �ε����� ����
			if (Teststr.c_str()[i] == '\\')
			{
				Idx = i;
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

		// ���� ���� ���ڿ��� ���� 
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