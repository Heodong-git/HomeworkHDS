#include <iostream>
#include "CArray.h"


int main()
{	
	// 다른프로젝트에 있는 헤더 사용해보기 
	LeakCheck();

	CArray<int> TestArr(10);

	CArray<CArray<int>> TestArr1;

	TestArr.resize(20);

	TestArr.resize(30);

	TestArr.resize(40);

	return 0;
}