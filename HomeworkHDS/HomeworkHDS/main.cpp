#include <iostream>
#include <vector>
#include <string>


// �����̱� �������ڵ� 

void Pick(const std::vector<std::string>& _vNameInfo)
{
	int Pick = (int)(_vNameInfo.size());
	srand((unsigned int)time(0));
	int a = rand();
	int Random = rand() % Pick;

	std::cout << _vNameInfo[Random] << " �� ��÷�Դϴ�!!!! " << std::endl;
	system("pause");
}


int main()
{

	// ���ڿ��� ������ �����迭 
	std::vector<std::string> vNameInfo;

	vNameInfo.push_back("������");
	vNameInfo.push_back("�㵿��");
	vNameInfo.push_back("�رٻ�");
	vNameInfo.push_back("������");
	vNameInfo.push_back("���ػ�");
	vNameInfo.push_back("����");
	vNameInfo.push_back("������");
	vNameInfo.push_back("������");
	vNameInfo.push_back("������");
	vNameInfo.push_back("������");
	vNameInfo.push_back("������");
	vNameInfo.push_back("������");
	vNameInfo.push_back("���μ�");
	vNameInfo.push_back("�̱ǵ�");
	vNameInfo.push_back("������");
	vNameInfo.push_back("�����");
	vNameInfo.push_back("���ؿ�");

	while (true)
	{
		system("cls");
		
		std::cout << "�����̱⸦ �����Ͻðڽ��ϱ�?" << std::endl;
		std::cout << "1�� : ���� " << std::endl;
		std::cout << "2�� : ���� " << std::endl;

		int Input = 0;
		std::cin >> Input;

		if (Input == 1)
		{
			Pick(vNameInfo);
		}

		if (Input == 2)
		{
			return 0;
		}

		else
		{
			continue;
		}
	}

	return 0;
}