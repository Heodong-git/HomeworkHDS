// Map.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <GameEngineDebug.h>
#include <iostream>
#include <map>


typedef int KeyType;
typedef int ValueType;

// 키값, 실제데이터를 저장하기 위한 클래스
class GameEnginePair
{
public:
    KeyType first;
    ValueType second;
};

// map 클래스 
class GameEngineMap
{
private:
    class BinaryNode
    {
    public:
        BinaryNode* Parent = nullptr;           // 부모노드
        BinaryNode* LeftChild = nullptr;        // 왼쪽자식
        BinaryNode* RightChild = nullptr;       // 오른쪽자식
        GameEnginePair Pair;                    // 키값, 실제데이터를 가진 클래스 

    
        // 클래스 내부에서 키값을 인자로 받아서 해당하는 키값을 가진 데이터를 찾는다.
        BinaryNode* find(const KeyType& _Key)
        {
            // 가지고 있는 Pair 의 키값과 인자로 들어온 키값이 같다면, 찾는 대상인 것이다. 
            if (Pair.first == _Key)
            {
                return this;
            }

            // 인자로 들어온 키값이 더 작다면 왼쪽자식을 확인한다. 
            else if (Pair.first > _Key)
            {
                // 단, 왼쪽자식이 없는 상태라면 대상이 없는 것이다.  nullptr 반환
                if (nullptr == LeftChild)
                {
                    return nullptr;
                }

                // 그게 아니라면 왼쪽으로 탐색한다. 
                return LeftChild->find(_Key);
            }

            // 인자로 들어온 키값이 더 크다면
            else if (Pair.first < _Key)
            {
                // 키값이 더 크지만 오른쪽 자식이 없다면 대상이 없는것이다. nullptr 반환
                if (nullptr == RightChild)
                {
                    return nullptr;
                }

                // 오른쪽으로 탐색한다. 
                return RightChild->find(_Key);
            }

            // 두경우 모두 해당되지 않는다면 nullptr 반환, 대상없음 
            return nullptr;

        }

        // 추가, 인자로 들어온 Pair 의 키값, 밸류를 노드를 생성하여 추가한다. 
        void Insert(const GameEnginePair& _Pair)
        {
            // 루트노드의 키값보다 인자로 들어온 키값이 더작다면, 왼쪽에추가한다. 
            if (Pair.first > _Pair.first)
            {
                // 현재 왼쪽 노드가 nullptr 이라면, 그자리에 추가한다. 
                if (nullptr == LeftChild)
                {
                    // 노드생성 , 데이터 저장
                    LeftChild = new BinaryNode();
                    LeftChild->Pair = _Pair;

                    // 부모노드를 나로 지정
                    LeftChild->Parent = this;
    
                    return;
                }

                // 키값이 더작지만, 왼쪽 자식노드가 있다면 재귀호출
                return LeftChild->Insert(_Pair);
            }

            // 루트노드의 키값보다 인자로 들어온 키값이 더크다면 오른쪽에 추가한다. 
            else if (Pair.first < _Pair.first)
            {
                // 만약 오른쪽자식노드가 nullptr 이라면 현재 객체의 오른쪽자식노드에 추가한다.
                if (nullptr == RightChild)
                {
                    // 노드생성 후 데이터 저장
                    RightChild = new BinaryNode();
                    RightChild->Pair = _Pair;
                    // 부모설정
                    RightChild->Parent = this;
                    return;
                }

                // 현재 오른쪽자식노드가 있다면 재귀호출
                RightChild->Insert(_Pair);
            }
            
            // 그 외의 경우라면 키값이 겹치는 것으로 판단한다.
            else
            {
                MessageBoxAssert("키가 겹치는 pair를 insert했습니다");
            }
        }

        // 전위순회
        // 루트 , 왼쪽 , 오른쪽 순서 
        void FirstOrder()
        {
            std::cout << Pair.first << std::endl;

            if (nullptr != LeftChild)
            {
                LeftChild->FirstOrder();
            }
            if (nullptr != RightChild)
            {
                RightChild->FirstOrder();
            }
        }

        // 후위 순회
        // 왼쪽 , 오른쪽 , 루트 순서 
        void LastOrder()
        {
            // 왼쪽 자식이 있다면 오른쪽 자식의 후위순회 함수 호출
            if (nullptr != LeftChild)
            {
                LeftChild->LastOrder();
            }

            // 왼쪽자식이 없고 오른쪽 자식이 있다면 오른쪽 자식의 후위순회 함수 호출
            if (nullptr != RightChild)
            {
                RightChild->LastOrder();
            }

            // 출력 
            std::cout << Pair.first << std::endl;
        }

        // 중위 순회
        // 왼쪽 , 루트 , 오른쪽 순서 
        void MidOrder()
        {
            // 왼쪽자식이 있다면 왼쪽 자식의 중위순회 함수 호출
            if (nullptr != LeftChild)
            {
                LeftChild->MidOrder();
            }

            // 왼쪽 자식이 없다면 출력되고 나서
            std::cout << Pair.first << std::endl;

            // 오른쪽 자식이 있는지 확인하여 반복수행
            if (nullptr != RightChild)
            {
                RightChild->MidOrder();
            }
        }

    public:
        BinaryNode()
        {

        }
        ~BinaryNode()
        {
            if (nullptr != LeftChild)
            {
                delete LeftChild;
                LeftChild = nullptr;
            }

            if (nullptr != RightChild)
            {
                delete RightChild;
                RightChild = nullptr;
            }
        }
    };

public:
    class iterator
    {
        // 나는 분명히 여러가지 접근제한 지정자를 사용하고 있지만
        // 어떤 클래스 에게만큼은 나의 모든걸 public으로 공개하겠다.
        friend GameEngineMap;

    private:
        BinaryNode* CurNode;

    public:
        bool operator==(const iterator& _Other)
        {
            return _Other.CurNode == CurNode;
        }

        bool operator!=(const iterator& _Other)
        {
            return _Other.CurNode != CurNode;
        }

        //_NODISCARD pointer operator->() const noexcept {
        //    return pointer_traits<pointer>::pointer_to(**this);
        //}


        GameEnginePair* operator->()
        {
            if (nullptr == CurNode)
            {
                return nullptr;
            }

            return &CurNode->Pair;
        }


        iterator& operator++()
        {
            return *this;
        }
    };

public:
    void insert(const GameEnginePair& _Pair)
    {
        // 현재 아무 데이터도 추가되지 않은 상태에서의 insert
        if (nullptr == RootNode)
        {
            RootNode = new BinaryNode();
            RootNode->Pair = _Pair;
            return;
        }
        
        // 현재 루트 노드가 있다면 클래스내부적으로 구현한 insert 호출 
        RootNode->Insert(_Pair);
    }

    // 키값을 인자로 받고 해당하는 데이터를 찾는다. 
    iterator find(const KeyType& _Key)
    {
        // 현재 루트노드가 nullptr 이라면 
        // 데이터가 저장되어 있지 않은 것, nullptr 반환
        if (nullptr == RootNode)
        {
            return end();
        }

        // 저장된 데이터가 있다면
        // iterator 에 대상을 저장하여 find함수로 찾아준 후 반환해준다.
        iterator NewIter;
        NewIter.CurNode = RootNode->find(_Key);
        return NewIter;
    }

    iterator end()
    {
        iterator NewIter;
        NewIter.CurNode = nullptr;
        return NewIter;
    }

    // 전위 순회
    void FirstOrder()
    {
        if (nullptr == RootNode)
        {
            return;
        }
        RootNode->FirstOrder();
    }

    // 후위 순회
    void LastOrder()
    {
        if (nullptr == RootNode)
        {
            return;
        }
        RootNode->LastOrder();
    }

    // 중위 순회
    // 저장되어 있는 
    void MidOrder()
    {
        if (nullptr == RootNode)
        {
            return;
        }
        RootNode->MidOrder();
    }

public:
       GameEngineMap()
       {

       }
       ~GameEngineMap()
       {
           // 현재 루트노드가 nullptr이 아니라면 데이터가 저장되어 있다는 의미이다.
           if (nullptr != RootNode)
           {
               if (nullptr != RootNode->LeftChild)
               {
                   delete RootNode->LeftChild;
                   RootNode->LeftChild = nullptr;
               }

               if (nullptr != RootNode->RightChild)
               {
                   delete RootNode->RightChild;
                   RootNode->RightChild = nullptr;
               }

               delete RootNode;
               RootNode = nullptr;
           }
       }

public:
    BinaryNode* RootNode = nullptr;
};

GameEnginePair make_pair(KeyType _Key, KeyType _Value)
{
    return { _Key , _Value };
}

int main()
{
    LeckCheck();

    {
        std::map<int, int> DataMap;

        DataMap.insert(std::make_pair(10, 10));
        DataMap.insert(std::make_pair(2, 2));
        DataMap.insert(std::make_pair(5, 5));
        DataMap.insert(std::make_pair(7, 7));
        DataMap.insert(std::make_pair(8, 8));
        DataMap.insert(std::make_pair(3, 3));
        DataMap.insert(std::make_pair(20, 20));

        std::map<int, int>::iterator FindIter = DataMap.find(99);

        if (FindIter != DataMap.end())
        {
            FindIter->first;
            FindIter->second;
        }

        int a = 0;

    }

    {
        std::map<int, int> DataMap;

        DataMap.insert(std::make_pair(1, 1));
        DataMap.insert(std::make_pair(2, 1));
        DataMap.insert(std::make_pair(3, 1));
        DataMap.insert(std::make_pair(4, 1));
        DataMap.insert(std::make_pair(5, 1));
        DataMap.insert(std::make_pair(6, 1));
        DataMap.insert(std::make_pair(7, 1));
    }

    {
        GameEngineMap DataMap;

        DataMap.insert(make_pair(10, 1));
        DataMap.insert(make_pair(2, 1));
        DataMap.insert(make_pair(5, 1));
        DataMap.insert(make_pair(7, 1));
        DataMap.insert(make_pair(8, 1));
        DataMap.insert(make_pair(3, 1));
        DataMap.insert(make_pair(21, 1));
        DataMap.insert(make_pair(22, 1));
        DataMap.insert(make_pair(23, 1));
        DataMap.insert(make_pair(24, 1));
        DataMap.insert(make_pair(25, 1));

        GameEngineMap::iterator FindIter = DataMap.find(99);

        if (FindIter != DataMap.end())
        {
            FindIter->first;
            FindIter->second;
        }

        std::cout << "전위 순회" << std::endl;
        DataMap.FirstOrder();
        std::cout << "후위 순회" << std::endl;
        DataMap.LastOrder();
        std::cout << "중위 순회" << std::endl;
        DataMap.MidOrder();

        int a = 0;
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
