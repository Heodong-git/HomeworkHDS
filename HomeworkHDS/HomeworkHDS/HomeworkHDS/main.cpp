#include <iostream>

// 연습용코드 

int main()
{
	
	
	// 확인할 대상
	float fX = 0.f;
	// A가 B 의 몇퍼센트인지 
	float fY = 0.f;

	float fPercent = 0.f;
	// 결과값 
	float fResult = 0.f;
	
	// X 대비 Y의 70 % 가 X에 몇퍼센트인지에 대한걸 소수점 셋제짜리 자동버림해줘
	// X = ((B * 0.70) / A) * 100  
	// 0.85 부분은 값입력이 가능하도록 

	while (true)
	{
		system("cls");

		std::cout << "X 값 입력 :  ";
		std::cin >> fX;
		
		std::cout << "Y 값 입력 :  ";
		std::cin >> fY;
		std::cout << std::endl;

		std::cout << "% 값 입력시 소수점단위로 입력하세요. ex) 0.1~ 1.0" << std::endl;
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

		std::cout << "다른 값을 확인하려면 아무키나 누르세요." << std::endl;
		system("pause");
	}

	return 0;
}