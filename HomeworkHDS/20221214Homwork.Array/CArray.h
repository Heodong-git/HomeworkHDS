#pragma once
// �ٸ������� �ִ� ��� ����� ������ �ٽ��ۼ�
#include "..\HomeworkBomberman\GameEngineDebug.h"

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
		resize(_Size);
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
	// �迭�� ũ�� ��ȯ 
	size_t GetSize() 
	{ 
		return m_Size; 
	}

	// ���ڷ� ���� ���� ũ��� �ٽ� ������. 
	void resize(size_t _Size)
	{
		// ����� 0 �̶�� ���Ʈ
		if (0 == _Size)
		{
			MessageBoxAssert("�迭�� ũ�Ⱑ 0�Դϴ�.");
			return;
		}

		// ����� �޴´�.
		size_t Size = _Size;

		// ����ó�� , �̹� �迭�� �����Ҵ� �Ǿ� ���� ���
		if (nullptr != m_DataPtr)
		{
			delete[] m_DataPtr;
			m_DataPtr = nullptr;

			m_DataPtr = new DataType[Size];
		}

		// 
		else if (nullptr == m_DataPtr)
		{
			m_DataPtr = new DataType[Size];
		}
	
	}
	
private:
	DataType* m_DataPtr = nullptr;
	// �迭�� ũ�� 
	size_t m_Size;
};

