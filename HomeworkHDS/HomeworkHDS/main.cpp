#include <iostream>
// ����
// �������ڵ� 

int main()
{
	float fX = 0.f;

	float fY = 0.f;

	float fPercent = 0.f;

	float fResult = 0.f;

	while (true)
	{
		system("cls");

		std::cout << "X �� �Է� :  ";
		std::cin >> fX;
		
		if (fX <= 0.f)
			continue;
		
		std::cout << "Y �� �Է� :  ";
		std::cin >> fY;
		std::cout << std::endl;

		if (fY <= 0.f)
			continue;

		std::cout << "% �� �Է�, �Ҽ��������� �Է��ض�. ex) 0.01 ~ 1.00" << std::endl;
		std::cout << "% �� �Է� :  ";
		std::cin >> fPercent;
		std::cout << std::endl;
		
		if (fPercent < 0.01f || fPercent > 1.0f)
			continue;
		
		fResult = ((fY * fPercent) / fX) * 100.f;

		std::cout << std::fixed;
		std::cout.precision(2);
		std::cout << "����� : " << fResult << "%";
		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "Ȯ���Ұ� �� ������ �ƹ�Ű�� ������." << std::endl;

		system("pause");
	}

	return 0;
}