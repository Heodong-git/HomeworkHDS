#include <iostream>
#include "CArray.h"


int main()
{	
	// �ٸ�������Ʈ�� �ִ� ��� ����غ��� 
	LeakCheck();

	CArray<int> TestArr(10);

	CArray<CArray<int>> TestArr1;

	TestArr.resize(20);

	TestArr.resize(30);

	TestArr.resize(40);

	return 0;
}