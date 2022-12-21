#pragma once
#include "..\HomeworkBomberman\GameEngineDebug.h"
// typedef int DataType;

// 설명 :
template<typename DataType>
class CArray
{
public:
	CArray()
		: Count(0)
		, DataPtr(nullptr)
	{

	}

	// constrcuter destructer
	CArray(size_t _Count)
		: Count(_Count)
		, DataPtr(nullptr)
	{
		// 10개짜리를 만들어달라고 한거니까.
		// 할당해서 만들어내야 하니까.
		resize(Count);
	}

	~CArray()
	{
		Clear();
	}


	// delete Function
	CArray(const CArray& _Other) = delete;
	CArray(CArray&& _Other) noexcept = delete;

	CArray& operator=(const CArray& _Other)
	{
		resize(_Other.Count);

		for (size_t i = 0; i < Count; i++)
		{
			DataPtr[i] = _Other.DataPtr[i];
		}

		return *this;
	}

	CArray& operator=(CArray&& _Other) noexcept = delete;

	size_t GetSize()
	{
		return Count;
	}

	void Clear()
	{
		if (nullptr != DataPtr)
		{
			delete[] DataPtr;
			DataPtr = nullptr;
		}
	}

	DataType& operator[](size_t _Index)
	{
		if (Count <= _Index)
		{
			MessageBoxAssert("배열의 인덱스를 넘겼습니다");
		}

		return DataPtr[_Index];
	}

	void resize(size_t _Count)
	{
		if (0 == _Count)
		{
			MessageBoxAssert("배열의 크기가 0일수 없습니다.");
		}

		// 현재 배열을 받아둔다. 
		DataType* PrevData = DataPtr;

		// 인자로 들어온 값으로 동적배열을 할당한다.
		DataPtr = new DataType[_Count];

		// 이전 데이터가 nullptr 이었다면
		// 처음 배열을 할당하는 것이기 때문에 
		// 동적배열은 만들어졌고, 배열내부적으로 할당된 배열의 개수를 알아야 하기 때문에
		// Count 변수에 값을 대입해주고 함수종료 
		if (nullptr == PrevData)
		{
			Count = _Count;
			return;
		}

		// 그게 아니라면 생성된 배열이 있다는 의미
		// 복사할 개수 = 인자로 들어온 값으로 넣어준뒤 
		size_t CopySize = _Count;

		// 기존배열보다 인자로 들어온 값이 더 크다면
		// 기존배열의 크기만큼 복사한다. 
		if (Count < _Count)
		{
			CopySize = Count;
		}

		// 데이터복사
		for (size_t i = 0; i < CopySize; i++)
		{
			// A = A
			DataPtr[i] = PrevData[i];
		}

		// 배열의 크기는 인자로 들어온 값이 된다. 
		Count = _Count;

		// 기존데이터를 제거한다. 
		if (nullptr != PrevData)
		{
			delete[] PrevData;
			PrevData = nullptr;
		}
	}


protected:

private:
	// 배열의 크기
	size_t Count = 0;
	DataType* DataPtr = nullptr;
};

