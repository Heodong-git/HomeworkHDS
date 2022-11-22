#include <iostream>
#include <vector>
#include <string>


// 랜덤뽑기 연습용코드 

void Pick(const std::vector<std::string>& _vNameInfo)
{
	int Pick = (int)(_vNameInfo.size());
	srand((unsigned int)time(0));
	int a = rand();
	int Random = rand() % Pick;

	std::cout << _vNameInfo[Random] << " 님 당첨입니다!!!! " << std::endl;
	system("pause");
}


int main()
{

	// 문자열을 저장할 동적배열 
	std::vector<std::string> vNameInfo;

	vNameInfo.push_back("최지혜");
	vNameInfo.push_back("허동석");
	vNameInfo.push_back("해근샘");
	vNameInfo.push_back("샘근해");
	vNameInfo.push_back("근해샘");
	vNameInfo.push_back("김김김");
	vNameInfo.push_back("최최최");
	vNameInfo.push_back("허허허");
	vNameInfo.push_back("지나감");
	vNameInfo.push_back("공부해");
	vNameInfo.push_back("열심히");
	vNameInfo.push_back("안진형");
	vNameInfo.push_back("강민수");
	vNameInfo.push_back("이권도");
	vNameInfo.push_back("이유민");
	vNameInfo.push_back("서대식");
	vNameInfo.push_back("이준열");

	while (true)
	{
		system("cls");
		
		std::cout << "랜덤뽑기를 실행하시겠습니까?" << std::endl;
		std::cout << "1번 : 실행 " << std::endl;
		std::cout << "2번 : 종료 " << std::endl;

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