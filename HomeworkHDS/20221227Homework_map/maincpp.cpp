// Map.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//
#include <GameEngineDebug.h>
#include <iostream>
#include <map>


typedef int KeyType;
typedef int ValueType;

// Ű��, ���������͸� �����ϱ� ���� Ŭ����
class GameEnginePair
{
public:
    KeyType first;
    ValueType second;
};

// map Ŭ���� 
class GameEngineMap
{
private:
    class BinaryNode
    {
    public:
        BinaryNode* Parent = nullptr;           // �θ���
        BinaryNode* LeftChild = nullptr;        // �����ڽ�
        BinaryNode* RightChild = nullptr;       // �������ڽ�
        GameEnginePair Pair;                    // Ű��, ���������͸� ���� Ŭ���� 

    
        // Ŭ���� ���ο��� Ű���� ���ڷ� �޾Ƽ� �ش��ϴ� Ű���� ���� �����͸� ã�´�.
        BinaryNode* find(const KeyType& _Key)
        {
            // ������ �ִ� Pair �� Ű���� ���ڷ� ���� Ű���� ���ٸ�, ã�� ����� ���̴�. 
            if (Pair.first == _Key)
            {
                return this;
            }

            // ���ڷ� ���� Ű���� �� �۴ٸ� �����ڽ��� Ȯ���Ѵ�. 
            else if (Pair.first > _Key)
            {
                // ��, �����ڽ��� ���� ���¶�� ����� ���� ���̴�.  nullptr ��ȯ
                if (nullptr == LeftChild)
                {
                    return nullptr;
                }

                // �װ� �ƴ϶�� �������� Ž���Ѵ�. 
                return LeftChild->find(_Key);
            }

            // ���ڷ� ���� Ű���� �� ũ�ٸ�
            else if (Pair.first < _Key)
            {
                // Ű���� �� ũ���� ������ �ڽ��� ���ٸ� ����� ���°��̴�. nullptr ��ȯ
                if (nullptr == RightChild)
                {
                    return nullptr;
                }

                // ���������� Ž���Ѵ�. 
                return RightChild->find(_Key);
            }

            // �ΰ�� ��� �ش���� �ʴ´ٸ� nullptr ��ȯ, ������ 
            return nullptr;

        }

        // �߰�, ���ڷ� ���� Pair �� Ű��, ����� ��带 �����Ͽ� �߰��Ѵ�. 
        void Insert(const GameEnginePair& _Pair)
        {
            // ��Ʈ����� Ű������ ���ڷ� ���� Ű���� ���۴ٸ�, ���ʿ��߰��Ѵ�. 
            if (Pair.first > _Pair.first)
            {
                // ���� ���� ��尡 nullptr �̶��, ���ڸ��� �߰��Ѵ�. 
                if (nullptr == LeftChild)
                {
                    // ������ , ������ ����
                    LeftChild = new BinaryNode();
                    LeftChild->Pair = _Pair;

                    // �θ��带 ���� ����
                    LeftChild->Parent = this;
    
                    return;
                }

                // Ű���� ��������, ���� �ڽĳ�尡 �ִٸ� ���ȣ��
                return LeftChild->Insert(_Pair);
            }

            // ��Ʈ����� Ű������ ���ڷ� ���� Ű���� ��ũ�ٸ� �����ʿ� �߰��Ѵ�. 
            else if (Pair.first < _Pair.first)
            {
                // ���� �������ڽĳ�尡 nullptr �̶�� ���� ��ü�� �������ڽĳ�忡 �߰��Ѵ�.
                if (nullptr == RightChild)
                {
                    // ������ �� ������ ����
                    RightChild = new BinaryNode();
                    RightChild->Pair = _Pair;
                    // �θ���
                    RightChild->Parent = this;
                    return;
                }

                // ���� �������ڽĳ�尡 �ִٸ� ���ȣ��
                RightChild->Insert(_Pair);
            }
            
            // �� ���� ����� Ű���� ��ġ�� ������ �Ǵ��Ѵ�.
            else
            {
                MessageBoxAssert("Ű�� ��ġ�� pair�� insert�߽��ϴ�");
            }
        }

        // ������ȸ
        // ��Ʈ , ���� , ������ ���� 
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

        // ���� ��ȸ
        // ���� , ������ , ��Ʈ ���� 
        void LastOrder()
        {
            // ���� �ڽ��� �ִٸ� ������ �ڽ��� ������ȸ �Լ� ȣ��
            if (nullptr != LeftChild)
            {
                LeftChild->LastOrder();
            }

            // �����ڽ��� ���� ������ �ڽ��� �ִٸ� ������ �ڽ��� ������ȸ �Լ� ȣ��
            if (nullptr != RightChild)
            {
                RightChild->LastOrder();
            }

            // ��� 
            std::cout << Pair.first << std::endl;
        }

        // ���� ��ȸ
        // ���� , ��Ʈ , ������ ���� 
        void MidOrder()
        {
            // �����ڽ��� �ִٸ� ���� �ڽ��� ������ȸ �Լ� ȣ��
            if (nullptr != LeftChild)
            {
                LeftChild->MidOrder();
            }

            // ���� �ڽ��� ���ٸ� ��µǰ� ����
            std::cout << Pair.first << std::endl;

            // ������ �ڽ��� �ִ��� Ȯ���Ͽ� �ݺ�����
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
            return *this;
        }
    };

public:
    void insert(const GameEnginePair& _Pair)
    {
        // ���� �ƹ� �����͵� �߰����� ���� ���¿����� insert
        if (nullptr == RootNode)
        {
            RootNode = new BinaryNode();
            RootNode->Pair = _Pair;
            return;
        }
        
        // ���� ��Ʈ ��尡 �ִٸ� Ŭ�������������� ������ insert ȣ�� 
        RootNode->Insert(_Pair);
    }

    // Ű���� ���ڷ� �ް� �ش��ϴ� �����͸� ã�´�. 
    iterator find(const KeyType& _Key)
    {
        // ���� ��Ʈ��尡 nullptr �̶�� 
        // �����Ͱ� ����Ǿ� ���� ���� ��, nullptr ��ȯ
        if (nullptr == RootNode)
        {
            return end();
        }

        // ����� �����Ͱ� �ִٸ�
        // iterator �� ����� �����Ͽ� find�Լ��� ã���� �� ��ȯ���ش�.
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

    // ���� ��ȸ
    void FirstOrder()
    {
        if (nullptr == RootNode)
        {
            return;
        }
        RootNode->FirstOrder();
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
    // ����Ǿ� �ִ� 
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
           // ���� ��Ʈ��尡 nullptr�� �ƴ϶�� �����Ͱ� ����Ǿ� �ִٴ� �ǹ��̴�.
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

        std::cout << "���� ��ȸ" << std::endl;
        DataMap.FirstOrder();
        std::cout << "���� ��ȸ" << std::endl;
        DataMap.LastOrder();
        std::cout << "���� ��ȸ" << std::endl;
        DataMap.MidOrder();

        int a = 0;
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
