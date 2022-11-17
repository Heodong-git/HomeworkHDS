#include <iostream>

// 연습용코드 


enum class EPick
{
	RECALCULATION = 1,
	CHECK = 2,

	EXIT = 3
};

// 계산함수 
int Calculation(float _fX, float _fY, float _fPercent)
{ 
	float fX = _fX;
	float fY = _fY;
	float fPercent = _fPercent;
	float fResult = 0.f;
	int iInput = 0;

	// 계산식 
	fResult = ((fY * fPercent) / fX) * 100.f;
	fResult = floor(fResult * 1000);
	fResult = fResult / 1000;

	// 계산 완료 후 출력 
	std::cout << std::fixed;
	std::cout.precision(4);
	std::cout << "결과값은 " << fResult << "% 라구욧!!!!!!";
	std::cout << std::endl;
	std::cout << std::endl;

	// 출력 후 분기처리
	std::cout << "1번 : 목표, 재료 고정 후 퍼센트 값만 변경 하여 다시 계산" << std::endl;
	std::cout << "2번 : 계산 완료 값 출력, 이전에 출력된 내용 전부 삭제" << std::endl;
	std::cout << std::endl;
	std::cout << "다른 키 입력시 초기화" << std::endl;
	std::cout << std::endl;
	std::cin >> iInput;

	// 예외처리
	if (iInput < 1 || iInput > 2)
		return 0;

	if (iInput == 1)
	{
		std::cout << "=========================재계산^^========================" << std::endl;
		std::cout << "% 값 입력, 소수점단위로 입력 ex) 0.01 ~ 1.00" << std::endl;
		std::cout << "범위 이외의 값 설정시 종료" << std::endl;
		std::cout << "% 값 입력 :  ";
		std::cin >> fPercent;
		std::cout << std::endl;

		if (fPercent < 0.01f || fPercent > 1.00f)
			return 0;

		Calculation(fX, fY, fPercent);
	}

	if (iInput == 2)
	{
		system("cls");
		std::cout << "최종결과값 :" << fResult << "%" << std::endl;
		std::cout << "알겠냐 이자시가!!!!!" << std::endl;
		std::cout << "아무키나 누르면 처음부터" << std::endl;
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

		// 제가 아닙니다.
		std::cout << "★엿같은 버섯의 계산기★" << std::endl;
		std::cout << std::endl;

		std::cout << "목표 입력 :  ";
		std::cin >> fX;

		std::cout << "재료 입력 :  ";
		std::cin >> fY;
		std::cout << std::endl;

		std::cout << "% 값 입력, 소수점단위로 입력 ex) 0.01 ~ 1.00" << std::endl;
		std::cout << "% 값 입력 :  ";
		std::cin >> fPercent;
		std::cout << std::endl;

		// 계산함수 
		Calculation(fX, fY, fPercent);
	}

	return 0;
}