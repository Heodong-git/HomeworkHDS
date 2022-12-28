// Map.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
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
                MessageBoxAssert("Ű�� ��ġ�� pair�� insert�߽��ϴ�");
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

        // ���� ��ȸ
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

        // ���� ��ȸ
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
        // ���� �и��� �������� �������� �����ڸ� ����ϰ� ������
        // � Ŭ���� ���Ը�ŭ�� ���� ���� public���� �����ϰڴ�.
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
        // ������ ��� 
        BinaryNode* DeleteNode = _Other.CurNode;
        // ������ ����� �θ���
        BinaryNode* ParentNode = DeleteNode->Parent;
        // ������ ����� �����ڽĳ��
        BinaryNode* LeftChildNode = DeleteNode->LeftChild;
        // ������ ����� �������ڽĳ�� 
        BinaryNode* RightChildNode = DeleteNode->RightChild;

        // ������ ��尡 nullptr �̶�� assert
        if (nullptr == DeleteNode)
        {
            MessageBoxAssert("end�� �����Ϸ��� �߽��ϴ�.");
            iterator iter;
            iter.CurNode = nullptr;
            return iter;
        }

        // ������ ��尡 ����,�������ڽĳ�尡 ���ٸ�
        if (nullptr == LeftChildNode && nullptr == RightChildNode)
        {
            // �θ��尡 �ִٸ�
            if (nullptr != ParentNode)
            {
                // �θ����� �ڽĳ�带 nullptr ó�� ( ���ڽ� ) 
                ParentNode->ChildChange(DeleteNode, nullptr);
            }

            // ��Ʈ��尡 �����Ǵ°Ŷ�� ��Ʈ��带 nullptr ó��
            if (RootNode == DeleteNode)
            {
                RootNode = nullptr;

                iterator iter;
                iter.CurNode = nullptr;

                return iter;
            }

            // ������ ����� ������带 iterator �� ��Ƽ� ��ȯ�Ѵ�. 
            iterator iter;
            iter.CurNode = DeleteNode->NextNode();

            delete DeleteNode;
            DeleteNode = nullptr;

            return iter;
        }

        // ����� �ڽĳ�尡 ���� ��� 
        BinaryNode* ChangeNode = nullptr;
        BinaryNode* ChangeParentNode = nullptr;

        // �����ڽĳ�尡 �ִٸ�
        if (nullptr != LeftChildNode)
        {
            ChangeNode = LeftChildNode->MaxNode();
            ChangeParentNode = ChangeNode->Parent;
        }

        // ������ �ڽĳ�尡 �ִٸ�
        else if (nullptr != RightChildNode)
        {
            // ü������� = �������ڽĳ���� �ڽ��߿��� ���������༮
            ChangeNode = RightChildNode->MinNode();
            // ü�����θ��� = �����ڽĳ���߿��� ���������༮�� �θ���
            ChangeParentNode = ChangeNode->Parent;
        }

        // �ٲ����Ǻθ��尡 nullptr�� �ƴ϶��
        if (nullptr != ChangeParentNode)
        {
            // ��Ȳ : 2 erase 
            // ChangeNode : 3 , ChangeParentNode = 10
            // 10�� �����ڽ��� 3���� �״�� �����־�� �ϴµ�
            // 3�� �����ڽ��� nullptr �̱⶧���� nullptr�� 10�� �����ڽ����� �־��ְ� �ǰ�
            // �׷� �ʿ� 3�� ������ �Ǿ������� 10�� �����ڽ��� �ƴϱ� ������ 2�� �����ϰ�
            // 10�� �����ڽ��� ���� �ɷ� ������ �Ǿ ���� ��带 ��ȯ�ϰ� �Ǹ� 10�� �����°� ����. 
            // �ϴ� �ּ�
            // ChangeParentNode->ChildChange(ChangeNode, ChangeNode->LeftChild);
        }

        // �θ��尡 nullptr�� �ƴ϶��
        // �θ����� ������ ����� �ڸ��� ü������带 �־��ش�. 
        if (nullptr != ParentNode)
        {
            ParentNode->ChildChange(DeleteNode, ChangeNode);
        }

        // ����, �������³���� �����ڽĳ�尡 �ٲ��尡 �ƴ϶�� 
        if (LeftChildNode != ChangeNode)
        {
            // �ٲ����� �����ڽ����� ����������� �����ڽĳ�带 �����Ѵ�. 
            ChangeNode->LeftChild = LeftChildNode;

            // ���� ����������� �����ڽĳ�尡 nullptr�� �ƴ϶�� 
            // ����������� �����ڽĳ���� �θ���� ü������尡 �ȴ�. 
            if (nullptr != LeftChildNode)
            {
               LeftChildNode->Parent = ChangeNode;
            }
            
        }

        // ���� �������³���� �������ڽĳ�尡 �ٲ��尡 �ƴ϶��
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

        // ���� ���� ����� ���� ��尡 �ִٸ�
        if (nullptr != RightChildNode)
        {
            iterator iter;
            iter.CurNode = RightChildNode->MinNode();

            delete DeleteNode;
            DeleteNode = nullptr;

            return iter;
        }

        // ������尡 ���ٸ�
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

    // ���� ��ȸ
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

    // ���� ��ȸ
    void LastOrder()
    {
        if (nullptr == RootNode)
        {
            return;
        }
        RootNode->LastOrder();
    }

    // ���� ��ȸ
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
    //    // ������˰����� ����� �ڰ����� Ž�� 2�� Ʈ�� �ڷᱸ���Դϴ�.
    //    //      Key  Value
    //    std::map<const char*, MonsterData> DataMap;

    //    DataMap.insert(std::make_pair("��ũ", MonsterData{ 10, 100 }));
    //    // Ű�� ��ġ�� ����� ���µ� 
    //    DataMap.insert(std::make_pair("�巡��", MonsterData{ 50, 1000 }));


    //    std::map<const char*, MonsterData>::iterator StartIter = DataMap.begin();
    //    std::map<const char*, MonsterData>::iterator EndIter = DataMap.end();

    //    for (; StartIter != EndIter; ++StartIter)
    //    {
    //        // for�� Ű��
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

        //std::cout << "���� ��ȸ" << std::endl;
        //DataMap.FirstOrder();
        //std::cout << "���� ��ȸ" << std::endl;
        //DataMap.LastOrder();
        //std::cout << "���� ��ȸ" << std::endl;
        //DataMap.MidOrder();

       
        // �ڽĳ�尡 ������ : ����� ������
        // �ڽĳ�尡 �Ѵ� ���� �� : ����� ������
        // �ϴ� ���� �߰��� �����ͷδ� ��� ����� ����
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
