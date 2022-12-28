// Map.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <map>
#include <GameEngineDebug.h>

typedef int KeyType;
typedef int ValueType;

class GameEnginePair
{
public:
    KeyType first;
    ValueType second;
};

class GameEngineMap
{
private:
    class BinaryNode
    {
    public:
        BinaryNode* Parent = nullptr;
        BinaryNode* LeftChild = nullptr;
        BinaryNode* RightChild = nullptr;
        GameEnginePair Pair;

        BinaryNode* MinNode()
        {
            if (nullptr == LeftChild)
            {
                return this;
            }

            return LeftChild->MinNode();
        }

        BinaryNode* MaxNode()
        {
            if (nullptr == RightChild)
            {
                return this;
            }

            return RightChild->MaxNode();
        }

        BinaryNode* ParentNext(const KeyType& _Key)
        {
            if (Pair.first > _Key)
            {
                return this;
            }

            if (nullptr == Parent)
            {
                return nullptr;
            }

            return Parent->ParentNext(_Key);
        }

        BinaryNode* NextNode()
        {
            if (nullptr == RightChild)
            {
                return Parent->ParentNext(Pair.first);
            }

            return RightChild->MinNode();
        }


        void ChildChange(BinaryNode* _Old, BinaryNode* _New)
        {
            if (_Old == RightChild)
            {
                RightChild = _New;
            }

            if (_Old == LeftChild)
            {
                LeftChild = _New;

            }

            if (nullptr != _New)
            {
                _New->Parent = this;
            }
        }


        BinaryNode* find(const KeyType& _Key)
        {
            if (Pair.first == _Key)
            {
                return this;
            }
            else if (Pair.first > _Key)
            {
                if (nullptr == LeftChild)
                {
                    return nullptr;
                }

                return LeftChild->find(_Key);
            }
            else if (Pair.first < _Key)
            {
                if (nullptr == RightChild)
                {
                    return nullptr;
                }

                return RightChild->find(_Key);
            }

            return nullptr;

        }

        void Insert(const GameEnginePair& _Pair)
        {
            if (Pair.first > _Pair.first)
            {
                if (nullptr == LeftChild)
                {
                    LeftChild = new BinaryNode();
                    LeftChild->Pair = _Pair;
                    LeftChild->Parent = this;
                    return;
                }

                return LeftChild->Insert(_Pair);
            }
            else if (Pair.first < _Pair.first)
            {
                if (nullptr == RightChild)
                {
                    RightChild = new BinaryNode();
                    RightChild->Pair = _Pair;
                    RightChild->Parent = this;
                    return;
                }

                RightChild->Insert(_Pair);
            }
            else
            {
                MessageBoxAssert("키가 겹치는 pair를 insert했습니다");
            }
        }

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

        void Relase()
        {
            if (nullptr != LeftChild)
            {
                LeftChild->Relase();
            }
            if (nullptr != RightChild)
            {
                RightChild->Relase();
            }
            delete this;
        }

        // 후위 순회
        void LastOrder()
        {
            if (nullptr != LeftChild)
            {
                LeftChild->LastOrder();
            }
            if (nullptr != RightChild)
            {
                RightChild->LastOrder();
            }
            std::cout << Pair.first << std::endl;
        }

        // 중위 순회
        void MidOrder()
        {
            if (nullptr != LeftChild)
            {
                LeftChild->MidOrder();
            }
            std::cout << Pair.first << std::endl;
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
            CurNode = CurNode->NextNode();
            return *this;
        }
    };

public:
    void insert(const GameEnginePair& _Pair)
    {
        if (nullptr == RootNode)
        {
            RootNode = new BinaryNode();
            RootNode->Pair = _Pair;
            return;
        }

        RootNode->Insert(_Pair);
    }

    iterator find(const KeyType& _Key)
    {
        if (nullptr == RootNode)
        {
            return end();
        }

        iterator NewIter;
        NewIter.CurNode = RootNode->find(_Key);
        return NewIter;
    }

    iterator erase(const iterator& _Other)
    {
        // 삭제할 노드 
        BinaryNode* DeleteNode = _Other.CurNode;
        // 삭제할 노드의 부모노드
        BinaryNode* ParentNode = DeleteNode->Parent;
        // 삭제할 노드의 왼쪽자식노드
        BinaryNode* LeftChildNode = DeleteNode->LeftChild;
        // 삭제할 노드의 오른쪽자식노드 
        BinaryNode* RightChildNode = DeleteNode->RightChild;

        // 삭제할 노드가 nullptr 이라면 assert
        if (nullptr == DeleteNode)
        {
            MessageBoxAssert("end를 삭제하려고 했습니다.");
            iterator iter;
            iter.CurNode = nullptr;
            return iter;
        }

        // 삭제할 노드가 왼쪽,오른쪽자식노드가 없다면
        if (nullptr == LeftChildNode && nullptr == RightChildNode)
        {
            // 부모노드가 있다면
            if (nullptr != ParentNode)
            {
                // 부모노드의 자식노드를 nullptr 처리 ( 나자신 ) 
                ParentNode->ChildChange(DeleteNode, nullptr);
            }

            // 루트노드가 삭제되는거라면 루트노드를 nullptr 처리
            if (RootNode == DeleteNode)
            {
                RootNode = nullptr;

                iterator iter;
                iter.CurNode = nullptr;

                return iter;
            }

            // 지워질 노드의 다음노드를 iterator 에 담아서 반환한다. 
            iterator iter;
            iter.CurNode = DeleteNode->NextNode();

            delete DeleteNode;
            DeleteNode = nullptr;

            return iter;
        }

        // 여기는 자식노드가 있을 경우 
        BinaryNode* ChangeNode = nullptr;
        BinaryNode* ChangeParentNode = nullptr;

        // 왼쪽자식노드가 있다면
        if (nullptr != LeftChildNode)
        {
            ChangeNode = LeftChildNode->MaxNode();
            ChangeParentNode = ChangeNode->Parent;
        }

        // 오른쪽 자식노드가 있다면
        else if (nullptr != RightChildNode)
        {
            // 체인지노드 = 오른쪽자식노드의 자식중에서 가장작은녀석
            ChangeNode = RightChildNode->MinNode();
            // 체인지부모노드 = 우측자식노드중에서 가장작은녀석의 부모노드
            ChangeParentNode = ChangeNode->Parent;
        }

        // 바뀔노드의부모노드가 nullptr이 아니라면
        if (nullptr != ChangeParentNode)
        {
            // 상황 : 2 erase 
            // ChangeNode : 3 , ChangeParentNode = 10
            // 10의 왼쪽자식은 3으로 그대로 남아있어야 하는데
            // 3의 왼쪽자식은 nullptr 이기때문에 nullptr을 10의 왼쪽자식으로 넣어주게 되고
            // 그럼 맵에 3은 저장은 되어있지만 10의 왼쪽자식이 아니기 때문에 2를 삭제하고
            // 10의 왼쪽자식이 없는 걸로 연산이 되어서 다음 노드를 반환하게 되면 10이 나오는것 같다. 
            // 일단 주석
            // ChangeParentNode->ChildChange(ChangeNode, ChangeNode->LeftChild);
        }

        // 부모노드가 nullptr이 아니라면
        // 부모노드의 지워진 노드의 자리에 체인지노드를 넣어준다. 
        if (nullptr != ParentNode)
        {
            ParentNode->ChildChange(DeleteNode, ChangeNode);
        }

        // 만약, 지워지는노드의 왼쪽자식노드가 바뀔노드가 아니라면 
        if (LeftChildNode != ChangeNode)
        {
            // 바뀔노드의 왼쪽자식으로 지워질노드의 왼쪽자식노드를 연결한다. 
            ChangeNode->LeftChild = LeftChildNode;

            // 만약 지워질노드의 왼쪽자식노드가 nullptr이 아니라면 
            // 지워질노드의 왼쪽자식노드의 부모노드는 체인지노드가 된다. 
            if (nullptr != LeftChildNode)
            {
               LeftChildNode->Parent = ChangeNode;
            }
            
        }

        // 만약 지워지는노드의 오른쪽자식노드가 바뀔노드가 아니라면
        if (RightChildNode != ChangeNode)
        {
            
            ChangeNode->RightChild = RightChildNode;
            
            if (nullptr != RightChildNode)
            {
                RightChildNode->Parent = ChangeNode;
            }
           
        }

        if (RootNode == DeleteNode)
        {
            RootNode = ChangeNode;
        }

        // 만약 지울 노드의 우측 노드가 있다면
        if (nullptr != RightChildNode)
        {
            iterator iter;
            iter.CurNode = RightChildNode->MinNode();

            delete DeleteNode;
            DeleteNode = nullptr;

            return iter;
        }

        // 우측노드가 없다면
        iterator iter;
        iter.CurNode = DeleteNode->NextNode();

        delete DeleteNode;
        DeleteNode = nullptr;

        return iter;
    }

    iterator& RightNodeCheck()
    {

    }
        

    iterator begin()
    {
        if (nullptr == RootNode)
        {
            return end();
        }

        iterator NewIter;
        NewIter.CurNode = RootNode->MinNode();
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

    void Relase()
    {
        if (nullptr == RootNode)
        {
            return;
        }
        RootNode->Relase();
        RootNode = nullptr;
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
    void MidOrder()
    {
        if (nullptr == RootNode)
        {
            return;
        }
        RootNode->MidOrder();
    }

    ~GameEngineMap()
    {
        if (nullptr != RootNode)
        {
            RootNode->Relase();
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

    //{
    //    // 레드블랙알고리즘을 사용한 자가균형 탐색 2진 트리 자료구조입니다.
    //    //      Key  Value
    //    std::map<const char*, MonsterData> DataMap;

    //    DataMap.insert(std::make_pair("오크", MonsterData{ 10, 100 }));
    //    // 키는 겹치면 상관은 없는데 
    //    DataMap.insert(std::make_pair("드래곤", MonsterData{ 50, 1000 }));


    //    std::map<const char*, MonsterData>::iterator StartIter = DataMap.begin();
    //    std::map<const char*, MonsterData>::iterator EndIter = DataMap.end();

    //    for (; StartIter != EndIter; ++StartIter)
    //    {
    //        // for가 키고
    //        // StartIter.operator->().first
    //        std::cout << "Key : " << StartIter->first << std::endl;
    //        std::cout << "Value : " << StartIter->second.Att << std::endl;

    //    }

    //}


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

        std::map<int, int>::iterator DeleteNextIter = DataMap.erase(DataMap.find(2));
        //std::map<int, int>::iterator StartIter = DataMap.begin();
        //std::map<int, int>::iterator EndIter = DataMap.end();

        //for (; StartIter != EndIter; ++StartIter)
        //{
        //    std::cout << StartIter->first << std::endl;
        //}

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

        DataMap.insert(make_pair(20, 1));
        DataMap.insert(make_pair(2, 1));
        DataMap.insert(make_pair(10, 1));
        DataMap.insert(make_pair(3, 1));
        DataMap.insert(make_pair(5, 1));
        DataMap.insert(make_pair(4, 1));
        DataMap.insert(make_pair(15, 1));
        DataMap.insert(make_pair(16, 1));
        DataMap.insert(make_pair(30, 1));
        DataMap.insert(make_pair(25, 1));
       

        GameEngineMap::iterator FindIter = DataMap.find(99);

        if (FindIter != DataMap.end())
        {
            FindIter->first;
            FindIter->second;
        }

        //std::cout << "전위 순회" << std::endl;
        //DataMap.FirstOrder();
        //std::cout << "후위 순회" << std::endl;
        //DataMap.LastOrder();
        //std::cout << "중위 순회" << std::endl;
        //DataMap.MidOrder();

       
        // 자식노드가 없을때 : 제대로 동작함
        // 자식노드가 둘다 있을 때 : 제대로 동작함
        // 일단 현재 추가된 데이터로는 모두 제대로 동작
        GameEngineMap::iterator ResultIter = DataMap.erase(DataMap.find(30));

        GameEngineMap::iterator StartIter = DataMap.begin();
        GameEngineMap::iterator EndIter = DataMap.end();

        for (;
            StartIter != EndIter;
            ++StartIter
            )
        {
            if (StartIter->first == 8)
            {
                int a = 0;
            }

            std::cout << StartIter->first << std::endl;
        }


    }


}
