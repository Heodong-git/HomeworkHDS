// List.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <list>
#include <vector>
#include <GameEngineDebug.h>

// 모든 stl자료구조들은 순회 방식등의 필수적인 기능들이 동일한 인터페이스(클래스 함수 객체 등등등을 총망라한 방법)를 사용한다.
// 그대신 그 자료구조의 특징적인 부분때문에 어떤 자료구조는 가지고 있지만
// 어떤 자료구조는 가지고 있지 못한 기능들이 존재하게 됩니다.

// 1. 릭없애오세요 
// 2. push_front 만들어 오세요.

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
		// 나는 분명히 여러가지 접근제한 지정자를 사용하고 있지만
		// 어떤 클래스 에게만큼은 나의 모든걸 public으로 공개하겠다.
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

		// List를 만드는 방식중 더미노드 방식이라고 합니다.
		FrontNode->Back = BackNode;
		BackNode->Front = FrontNode;
	}

	// constrcuter destructer
	GameEngineList(size_t _Count)
	{
	}

	// 소멸자에서 동적할당된 리스트 모두 제거
	~GameEngineList()
	{
		// 시작노드를 제외한 가장 앞쪽노드를 받아온다. 
		ListNode* Node = FrontNode->Back;

		// 노드가 BackNode가 아니라면 반복
		// (Front ~ Back 사이의 Node 를 모두 제거) 
		while (Node != BackNode)
		{ 
			// 지울 노드는 
			ListNode* DeleteNode = Node;
			
			// 지울 노드의 다음 노드를 받아온다.
			ListNode* NextNode = DeleteNode->Back;

			// 노드를 제거한다. 
			if (nullptr != DeleteNode)
			{
				delete DeleteNode;
				DeleteNode = nullptr;
			}

			// 제거 후 다음 기준 노드는 지운 노드의 다음 노드가 된다.
			Node = NextNode;
		}

		// 양쪽의 더미노드를 제거한다. 
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

		// 사이즈는 0으로 초기화 
		DataSize = 0;
	}


	// delete Function
	GameEngineList(const GameEngineList& _Other) = delete;
	GameEngineList(GameEngineList&& _Other) noexcept
	{
		// 최적화때문에 이걸 사용합니다.
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
		// 노드생성 후 생성한 노드에 데이터 저장
		ListNode* NewNode = new ListNode();
		NewNode->Value = _Data;

		// 가장앞쪽노드의 다음노드를 받아온다.
		ListNode* Node = FrontNode->Back;
		
		// 생성한 노드를 front 와 받아온 노드 사이에 연결해준다.
		FrontNode->Back = NewNode;
		NewNode->Front = FrontNode;

		NewNode->Back = Node;
		Node->Front = NewNode;

		// 데이터가 추가되었기 때문에 ++ 
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
		// 노드형 시퀸스 자료구조 입니다.

		// 크기가 정해져있지 않습니다.
		std::list<size_t> IntList = std::list<size_t>();


		for (size_t i = 0; i < 10; i++)
		{
			IntList.push_front(i);
			// 내부에 존재하는 배열의 크기입니다.
			// std::cout << "Capacity" << IntVector.capacity() << std::endl;
			// 내가 집어넣은 데이터의 크기입니다.
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
		// 노드형 시퀸스 자료구조 입니다.

		// 크기가 정해져있지 않습니다.
		GameEngineList IntList = GameEngineList();


		for (size_t i = 0; i < 10; i++)
		{
			IntList.push_back(i);
			// 내부에 존재하는 배열의 크기입니다.
			// std::cout << "Capacity" << IntVector.capacity() << std::endl;
			// 내가 집어넣은 데이터의 크기입니다.
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

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
