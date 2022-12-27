// List.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//

#include <iostream>
#include <list>
#include <vector>
#include <GameEngineDebug.h>

// ��� stl�ڷᱸ������ ��ȸ ��ĵ��� �ʼ����� ��ɵ��� ������ �������̽�(Ŭ���� �Լ� ��ü ������ �Ѹ����� ���)�� ����Ѵ�.
// �״�� �� �ڷᱸ���� Ư¡���� �κж����� � �ڷᱸ���� ������ ������
// � �ڷᱸ���� ������ ���� ���� ��ɵ��� �����ϰ� �˴ϴ�.

// 1. �����ֿ����� 
// 2. push_front ����� ������.

typedef int DataType;

class GameEngineList
{

private:
	class ListNode
	{
	public:
		ListNode* Front = nullptr;
		ListNode* Back = nullptr;
		DataType Value;



	public:
		ListNode() {}
		~ListNode() {}
	};

public:
	class iterator
	{
		// ���� �и��� �������� �������� �����ڸ� ����ϰ� ������
		// � Ŭ���� ���Ը�ŭ�� ���� ���� public���� �����ϰڴ�.
		friend GameEngineList;

	private:
		ListNode* CurNode;

	public:
		iterator& operator++()
		{
			CurNode = CurNode->Back;
			return *this;
		}

		DataType& operator*() const noexcept
		{
			return CurNode->Value;
		}

		bool operator!=(const iterator _Iter) const noexcept
		{
			return _Iter.CurNode != CurNode;
		}

	};


public:
	GameEngineList()
	{
		FrontNode = new ListNode();
		BackNode = new ListNode();

		// List�� ����� ����� ���̳�� ����̶�� �մϴ�.
		FrontNode->Back = BackNode;
		BackNode->Front = FrontNode;
	}

	// constrcuter destructer
	GameEngineList(size_t _Count)
	{
	}

	// �Ҹ��ڿ��� �����Ҵ�� ����Ʈ ��� ����
	~GameEngineList()
	{
		// ���۳�带 ������ ���� ���ʳ�带 �޾ƿ´�. 
		ListNode* Node = FrontNode->Back;

		// ��尡 BackNode�� �ƴ϶�� �ݺ�
		// (Front ~ Back ������ Node �� ��� ����) 
		while (Node != BackNode)
		{ 
			// ���� ���� 
			ListNode* DeleteNode = Node;
			
			// ���� ����� ���� ��带 �޾ƿ´�.
			ListNode* NextNode = DeleteNode->Back;

			// ��带 �����Ѵ�. 
			if (nullptr != DeleteNode)
			{
				delete DeleteNode;
				DeleteNode = nullptr;
			}

			// ���� �� ���� ���� ���� ���� ����� ���� ��尡 �ȴ�.
			Node = NextNode;
		}

		// ������ ���̳�带 �����Ѵ�. 
		if (nullptr != FrontNode)
		{
			delete FrontNode;
			FrontNode = nullptr;
		}

		if (nullptr != BackNode)
		{
			delete BackNode;
			BackNode = nullptr;
		}

		// ������� 0���� �ʱ�ȭ 
		DataSize = 0;
	}


	// delete Function
	GameEngineList(const GameEngineList& _Other) = delete;
	GameEngineList(GameEngineList&& _Other) noexcept
	{
		// ����ȭ������ �̰� ����մϴ�.
	}
	GameEngineList& operator=(GameEngineList&& _Other) noexcept = delete;

	size_t size()
	{
		return DataSize;
	}

	iterator begin()
	{
		iterator Return = iterator();
		Return.CurNode = FrontNode->Back;
		return Return;
	}

	iterator end()
	{
		iterator Return = iterator();
		Return.CurNode = BackNode;
		return Return;
	}

	void erase(const iterator& Iter)
	{
		ListNode* Node = Iter.CurNode;

		if (BackNode == Node || FrontNode == Node)
		{
			return;
		}

		if (nullptr == Node)
		{
			return;
		}

		ListNode* DeleteFrontNode = Node->Front;
		ListNode* DeleteBackNode = Node->Back;

		delete Node;
		Node = nullptr;

		DeleteFrontNode->Back = DeleteBackNode;
		DeleteBackNode->Front = DeleteFrontNode;


		return;
	}

	void clear()
	{
	}

	void push_back(const DataType& _Data)
	{
		ListNode* NewNode = new ListNode();
		NewNode->Value = _Data;

		ListNode* FrontNode = BackNode->Front;
		FrontNode->Back = NewNode;
		BackNode->Front = NewNode;

		NewNode->Front = FrontNode;
		NewNode->Back = BackNode;

		++DataSize;

	}

	void push_front(const DataType& _Data)
	{
		// ������ �� ������ ��忡 ������ ����
		ListNode* NewNode = new ListNode();
		NewNode->Value = _Data;

		// ������ʳ���� ������带 �޾ƿ´�.
		ListNode* Node = FrontNode->Back;
		
		// ������ ��带 front �� �޾ƿ� ��� ���̿� �������ش�.
		FrontNode->Back = NewNode;
		NewNode->Front = FrontNode;

		NewNode->Back = Node;
		Node->Front = NewNode;

		// �����Ͱ� �߰��Ǿ��� ������ ++ 
		++DataSize;
	}

	void resize(size_t _Count)
	{
	}


private:
	size_t DataSize = 0;
	ListNode* FrontNode = nullptr;
	ListNode* BackNode = nullptr;
};


int main()
{
	LeckCheck();

	std::cout << "stdList" << std::endl;
	{
		// push_back
		// ����� ������ �ڷᱸ�� �Դϴ�.

		// ũ�Ⱑ ���������� �ʽ��ϴ�.
		std::list<size_t> IntList = std::list<size_t>();


		for (size_t i = 0; i < 10; i++)
		{
			IntList.push_front(i);
			// ���ο� �����ϴ� �迭�� ũ���Դϴ�.
			// std::cout << "Capacity" << IntVector.capacity() << std::endl;
			// ���� ������� �������� ũ���Դϴ�.
			std::cout << "Size" << IntList.size() << std::endl;
		}

		// []

		//   I
		// 0 2 3 4 5 6 7 8 9
		{
			std::list<size_t>::iterator StartIter = IntList.begin();
			std::list<size_t>::iterator EndIter = IntList.end();
			for (; StartIter != EndIter; ++StartIter)
			{
				std::cout << *StartIter << std::endl;
			}

			int a = 0;
		}
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "myList" << std::endl;

	{
		// push_back
		// ����� ������ �ڷᱸ�� �Դϴ�.

		// ũ�Ⱑ ���������� �ʽ��ϴ�.
		GameEngineList IntList = GameEngineList();


		for (size_t i = 0; i < 10; i++)
		{
			IntList.push_back(i);
			// ���ο� �����ϴ� �迭�� ũ���Դϴ�.
			// std::cout << "Capacity" << IntVector.capacity() << std::endl;
			// ���� ������� �������� ũ���Դϴ�.
			std::cout << "Size" << IntList.size() << std::endl;
		}


		{
			GameEngineList::iterator StartIter = IntList.begin();

			++StartIter;

			//IntList.erase(StartIter);
		}

		// []

		//   I
		// 0 2 3 4 5 6 7 8 9
		{

			// IntList[0]
			GameEngineList::iterator StartIter = IntList.begin();
			GameEngineList::iterator EndIter = IntList.end();

			for (; StartIter != EndIter; ++StartIter)
			{
				std::cout << *StartIter << std::endl;
			}

			int a = 0;
		}
	}


}

// ���α׷� ����: <Ctrl+F5> �Ǵ� [�����] > [��������� �ʰ� ����] �޴�
// ���α׷� �����: <F5> Ű �Ǵ� [�����] > [����� ����] �޴�

// ������ ���� ��: 
//   1. [�ַ�� Ž����] â�� ����Ͽ� ������ �߰�/�����մϴ�.
//   2. [�� Ž����] â�� ����Ͽ� �ҽ� ��� �����մϴ�.
//   3. [���] â�� ����Ͽ� ���� ��� �� ��Ÿ �޽����� Ȯ���մϴ�.
//   4. [���� ���] â�� ����Ͽ� ������ ���ϴ�.
//   5. [������Ʈ] > [�� �׸� �߰�]�� �̵��Ͽ� �� �ڵ� ������ ����ų�, [������Ʈ] > [���� �׸� �߰�]�� �̵��Ͽ� ���� �ڵ� ������ ������Ʈ�� �߰��մϴ�.
//   6. ���߿� �� ������Ʈ�� �ٽ� ������ [����] > [����] > [������Ʈ]�� �̵��ϰ� .sln ������ �����մϴ�.
