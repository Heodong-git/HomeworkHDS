#include <iostream>
// ㅇㅇ
// 연습용코드 

int main()
{
	float fX = 0.f;

	float fY = 0.f;

	float fPercent = 0.f;

	float fResult = 0.f;

	while (true)
	{
		system("cls");

		std::cout << "X 값 입력 :  ";
		std::cin >> fX;
		
		if (fX <= 0.f)
			continue;
		
		std::cout << "Y 값 입력 :  ";
		std::cin >> fY;
		std::cout << std::endl;

		if (fY <= 0.f)
			continue;

		std::cout << "% 값 입력, 소수점단위로 입력해라. ex) 0.01 ~ 1.00" << std::endl;
		std::cout << "% 값 입력 :  ";
		std::cin >> fPercent;
		std::cout << std::endl;
		
		if (fPercent < 0.01f || fPercent > 1.0f)
			continue;
		
		fResult = ((fY * fPercent) / fX) * 100.f;

		std::cout << std::fixed;
		std::cout.precision(2);
		std::cout << "결과값 : " << fResult << "%";
		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "확인할거 더 있으면 아무키나 눌러라." << std::endl;

		system("pause");
	}

	return 0;
}