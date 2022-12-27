// GameArray.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//

#include <iostream>
#include "GameEngineArray.h"

class A
{
	A& operator=(const A& _A) = delete;
};

int main()
{
	LeckCheck();

	// ����ȯ�� �Ȱ̴ϴ�.
	//             int[]
	//int* ArrPtr0;
	//int* ArrPtr1;

	//int ArrPtr1[1];

	//ArrPtr1[1000000];

	// �������� ������?
	// 8����Ʈ ������?
	// ArrPtr0 = ArrPtr1;

	// GameEngineArray<A> NewArray(10);

	// �迭�� ������
	// �׳� n �ڷ����� x�� ����ٶ�� ������ �ִ°̴ϴ�.
	// �ű⿡�� �ǵ��� ����. 
	GameEngineArray<size_t> NewArray(10);

	for (size_t i = 0; i < NewArray.GetCount(); i++)
	{
		NewArray[i] = i;
	}

	NewArray.ReSize(20);

	for (size_t i = 0; i < NewArray.GetCount(); i++)
	{
		std::cout << NewArray[i] << std::endl;
	}

	//for (size_t i = 0; i < NewArray.GetCount(); i++)
	//{
	//	NewArray[i] = nullptr;
	//}

	//// GameEngineArray</*�ڷ���*/> NewArr(10);

	//// GameEngineArray<int>
	//// NewArr[10][10]
	//{
	//	GameEngineArray<GameEngineArray<Bomb*>> NewArr(10);

	//	for (size_t i = 0; i < NewArr.GetCount(); i++)
	//	{
	//		NewArr.ReSize(10);
	//	}

	//	for (size_t y = 0; y < NewArr.GetCount(); y++)
	//	{
	//		NewArr[y].ReSize(10);
	//		for (size_t x = 0; x < NewArr[y].GetCount(); x++)
	//		{
	//			NewArr[y][x] = nullptr;
	//		}
	//	}

	//}
	// NewArr[0][100];


	// NewArray[500] = true;

}
