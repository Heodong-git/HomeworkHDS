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

		DataType* PrevData = DataPtr;

		DataPtr = new DataType[_Count];

		if (nullptr == PrevData)
		{
			Count = _Count;
			return;
		}

		size_t CopySize = _Count;

		if (Count < _Count)
		{
			CopySize = Count;
		}

		for (size_t i = 0; i < CopySize; i++)
		{
			// A = A
			DataPtr[i] = PrevData[i];
		}

		// 10   20
		Count = _Count;

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

