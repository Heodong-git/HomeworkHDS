#include <iostream>

// �������ڵ� 


enum class EPick
{
	RECALCULATION = 1,
	CHECK = 2,

	EXIT = 3
};

// ����Լ� 
int Calculation(float _fX, float _fY, float _fPercent)
{ 
	float fX = _fX;
	float fY = _fY;
	float fPercent = _fPercent;
	float fResult = 0.f;
	int iInput = 0;

	// ���� 
	fResult = ((fY * fPercent) / fX) * 100.f;
	fResult = floor(fResult * 1000);
	fResult = fResult / 1000;

	// ��� �Ϸ� �� ��� 
	std::cout << std::fixed;
	std::cout.precision(4);
	std::cout << "������� " << fResult << "% �󱸿�!!!!!!";
	std::cout << std::endl;
	std::cout << std::endl;

	// ��� �� �б�ó��
	std::cout << "1�� : ��ǥ, ��� ���� �� �ۼ�Ʈ ���� ���� �Ͽ� �ٽ� ���" << std::endl;
	std::cout << "2�� : ��� �Ϸ� �� ���, ������ ��µ� ���� ���� ����" << std::endl;
	std::cout << std::endl;
	std::cout << "�ٸ� Ű �Է½� �ʱ�ȭ" << std::endl;
	std::cout << std::endl;
	std::cin >> iInput;

	// ����ó��
	if (iInput < 1 || iInput > 2)
		return 0;

	if (iInput == 1)
	{
		std::cout << "=========================����^^========================" << std::endl;
		std::cout << "% �� �Է�, �Ҽ��������� �Է� ex) 0.01 ~ 1.00" << std::endl;
		std::cout << "���� �̿��� �� ������ ����" << std::endl;
		std::cout << "% �� �Է� :  ";
		std::cin >> fPercent;
		std::cout << std::endl;

		if (fPercent < 0.01f || fPercent > 1.00f)
			return 0;

		Calculation(fX, fY, fPercent);
	}

	if (iInput == 2)
	{
		system("cls");
		std::cout << "��������� :" << fResult << "%" << std::endl;
		std::cout << "�˰ڳ� ���ڽð�!!!!!" << std::endl;
		std::cout << "�ƹ�Ű�� ������ ó������" << std::endl;
		system("pause");
		return 0;
	}

	return 0;
}


int main()
{
	while (true)
	{
		system("cls");

		float fX = 0.f;
		float fY = 0.f;
		float fPercent = 0.f;
		//int iInput = 0;

		// ���� �ƴմϴ�.
		std::cout << "�ڿ����� ������ �����" << std::endl;
		std::cout << std::endl;

		std::cout << "��ǥ �Է� :  ";
		std::cin >> fX;

		std::cout << "��� �Է� :  ";
		std::cin >> fY;
		std::cout << std::endl;

		std::cout << "% �� �Է�, �Ҽ��������� �Է� ex) 0.01 ~ 1.00" << std::endl;
		std::cout << "% �� �Է� :  ";
		std::cin >> fPercent;
		std::cout << std::endl;

		// ����Լ� 
		Calculation(fX, fY, fPercent);
	}

	return 0;
}