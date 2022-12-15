#include <iostream>
#include "CArray.h"


int main()
{	
	// 다른프로젝트에 있는 헤더 사용해보기 
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	CArray<int> TestArr(10);

	CArray<CArray<int>> TestArr1;

	TestArr.resize(20);

	TestArr.resize(30);

	TestArr.resize(40);

	return 0;
}