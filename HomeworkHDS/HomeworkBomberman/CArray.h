#pragma once
#include "GameEngineDebug.h"

template <typename DataType>
class CArray
{
public:
	// constrcuter destructer
	CArray() :
		m_DataPtr(nullptr),
		m_Size(0)
	{

	}

	CArray(size_t _Size) :
		m_DataPtr(nullptr),
		m_Size(_Size)
	{
		resize(m_Size);
	}
	~CArray()
	{
		if (nullptr != m_DataPtr)
		{
			delete[] m_DataPtr;
			m_DataPtr = nullptr;
		}
	}

	// delete Function
	CArray(const CArray& _Other) = delete;
	CArray(CArray&& _Other) noexcept = delete;
	CArray& operator=(const CArray& _Other) = delete;
	CArray& operator=(CArray&& _Other) noexcept = delete;

public:
	// 배열의 크기 반환 
	const size_t GetSize() 
	{ 
		return m_Size; 
	}

	// 인자로 들어온 값의 크기로 다시 만들어낸다. 
	void resize(size_t _Size)
	{
		// 사이즈가 0 이라면 어썰트
		if (0 == _Size)
		{
			MessageBoxAssert("배열의 크기가 0입니다.");
			return;
		}

		// 사이즈를 받는다.
		m_Size = _Size;

		// 예외처리. 이미 배열이 동적할당 되어 있을 경우
		if (nullptr != m_DataPtr)
		{
			delete[] m_DataPtr;
			m_DataPtr = nullptr;

			m_DataPtr = new DataType[m_Size];
		}

		// 동적할당 되어있지 않다면 사이즈만큼 동적배열 할당
		else if (nullptr == m_DataPtr)
		{
			m_DataPtr = new DataType[m_Size];
		}
	
	}
	
	DataType& operator[](size_t Index)
	{
		if (m_Size + 1 <= Index)
		{
			MessageBoxAssert("인덱스의 값이 배열의 크기보다 큽니다.");
		}

		return m_DataPtr[Index];
	}
private:
	DataType* m_DataPtr = nullptr;
	// 배열의 크기 
	size_t m_Size;
};

