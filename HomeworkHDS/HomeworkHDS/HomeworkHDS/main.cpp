#include <iostream>

// �������ڵ� 

int main()
{
	
	
	// Ȯ���� ���
	float fX = 0.f;
	// A�� B �� ���ۼ�Ʈ���� 
	float fY = 0.f;

	float fPercent = 0.f;
	// ����� 
	float fResult = 0.f;
	
	// X ��� Y�� 70 % �� X�� ���ۼ�Ʈ������ ���Ѱ� �Ҽ��� ����¥�� �ڵ���������
	// X = ((B * 0.70) / A) * 100  
	// 0.85 �κ��� ���Է��� �����ϵ��� 

	while (true)
	{
		system("cls");

		std::cout << "X �� �Է� :  ";
		std::cin >> fX;
		
		std::cout << "Y �� �Է� :  ";
		std::cin >> fY;
		std::cout << std::endl;

		std::cout << "% �� �Է½� �Ҽ��������� �Է��ϼ���. ex) 0.1~ 1.0" << std::endl;
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

		std::cout << "�ٸ� ���� Ȯ���Ϸ��� �ƹ�Ű�� ��������." << std::endl;
		system("pause");
	}

	return 0;
}