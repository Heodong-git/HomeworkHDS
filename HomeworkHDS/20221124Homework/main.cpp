#include <iostream>

int StringCount(const char* _String)
{
    int Count = 0;

    while (0 != _String[Count])
    {
        ++Count;
    }

    return Count;
}

// ���ڿ��� ������?
bool StringCompair(const char* _Text0, const char* _Text1)
{
    // ���� ���ڿ��� ���̰� ���������� üũ�Ѵ�
    int First = StringCount(_Text0);
    int Second = StringCount(_Text1);

    // ���ڿ��� ���̰� �ٸ��ٸ� ���� �ٸ� ���ڿ� �� ���̴�. 
    if (First != Second)
    {
        return false;
    }
    
    // ���ڿ��� ���̸�ŭ �ݺ�, �ι��ڸ� ������ ���̰� 10�̶��
    // 0 ~ 9 ���� �� 10���ݺ��Ѵ�. 
    for (int i = 0; i < First; ++i)
    {
        // �ϳ��� ���Ͽ� ���� �ٸ��ٸ� �ٸ� ���ڿ� �� ���̴�.
        if (_Text0[i] != _Text1[i])
        {
            return false;
        }
    }
  
    // for �� ���ο� if ���� �ɸ��� �ʰ� ������ ���ڿ����� ������ Ȯ�� �� 
    // �Ʒ� �ڵ�� �����Դٸ� ���� ���� ���ڿ��̶�� �ǹ��̴�. 
    return true;
}

// ���ڿ� ��ġ�� 
void StringMerge(char* _Result, const char* _Text0, const char* _Text1)
{
    int First = StringCount(_Text0);
    int Second = StringCount(_Text1);

    int ConnectIdx = 0;

    for(int i = 0; i < First; ++i)
    {
        // �ι��ڰ� ���ö� ���� ���ڿ��� �����Ѵ�. 
        if (0 != _Text0[i])
        {
            _Result[i] = _Text0[i];
        }   
        ++ConnectIdx;
    }

    // ���簡 �Ϸ�� �� ���� �ε������� ������ ������
    // �����ε������� �ι�°�� ���� ������ ���ڿ��� �ι��ڰ� ���ö� ���� 
    // �̾ �������ش�.
    
    for (int i = 0; i < Second; ++i)
    {
        if (0 != _Text1[i])
        {
            _Result[ConnectIdx] = _Text1[i];
            ++ConnectIdx;
        }
    }

    // ��� �۾��� �Ϸ�Ǿ��ٸ� ������� ������ ���ڿ��� 0�� �����ؼ� ���� �˼� �ֵ��� ó���Ѵ�.
    _Result[ConnectIdx] = 0;
}


void StringChange(char* _Text, const char* _Old, const char* _New)
{
    // �ι��ڸ� �� ���ڿ� ���̷� ���Ѵ�.  
    int TextCount = 0;
    while (0 != _Text[TextCount])
    {
        ++TextCount;
    }

    // �ٲ��� ���ڿ��� ���̸� ���Ѵ�.
    int OldTextCount = 0;
    while (0 != _Old[OldTextCount])
    {
        ++OldTextCount;
    }

    // �� ���ڿ��� ���̸� ���Ѵ�.
    int NewTextCount = 0;
    while (0 != _New[NewTextCount])
    {
        ++NewTextCount;
    }
    
    // ��� ���ڸ� �ٲپ�� ���� ������ ���Ѵ�. 
    int ChangeTextCount = 0;
    
    // �ٲ��� ���� �ε����� ���Ѵ�.
    int ChangeIdx = 0;
    for (int i = 0; i < TextCount + 1; ++i)
    {
        // �ݺ����鼭 ������ ���ڸ� ã�´�.
        if (_Text[i] == _Old[0])
        {
            ChangeIdx = i;
            // ã�Ҵٸ� ���� ���ڿ��� Ȯ���Ѵ�. 
            for (int j = 0; j < OldTextCount; ++j)
            {
                if (_Text[i + j] == _Old[j])
                {
                    ++ChangeTextCount;
                }
            }

            // �ٲ��� ���ڿ� �������� Ȯ���� �Ʊ� ������ for�� ����
            break;
        }
    }

    // ������ ���ڸ� �־��ش�. 
    // �� �� ������ �ؽ�Ʈ�������� ���ο� �ؽ�Ʈ�� ������ �۴ٸ� ����ó���ؾ��ϴµ�.. �װ� ex�ε�
    // �ؽ�Ʈ������ � �� ������ ����ؼ� �ٲ��ְ� �� ���� �ε����� ��ĭ�� ���� 
    int Value = ChangeTextCount - NewTextCount;

    // ���� �ؽ�Ʈ�� ������ ���ٸ� �̷��� ó��
    if (Value == 0)
    {
       for (int i = 0; i < ChangeTextCount; ++i)
       {
           _Text[ChangeIdx + i] = _New[i];
       }
   
    }
    
    // ���� �ؽ�Ʈ ������ �ٸ��ٸ� �۾��� �Ϸ� �ǰ� ���� ���� �ε����� ������ ä���ش�. 
    else
    {
        for (int i = 0; i < ChangeTextCount; ++i)
        {
            _Text[ChangeIdx + i] = _New[i];
        }

        int MoveIdx = ChangeIdx + ChangeTextCount;
        for (int i = 0; i < INT_MAX; ++i)
        {
            _Text[MoveIdx + i] = _Text[MoveIdx + i + 1];
            
            // ���ڿ��� ���� ������ for �� ���� 
            if (_Text[MoveIdx + i] == 0)
                break;
        }
    }
    
}

void StringChangeEx(char* _Text, const char* _Old, const char* _New)
{
    // �ι��ڸ� �� ���ڿ� ���̷� ���Ѵ�.  
    int TextCount = 0;
    while (0 != _Text[TextCount])
    {
        ++TextCount;
    }

    // �ٲ��� ���ڿ��� ���̸� ���Ѵ�.
    int OldTextCount = 0;
    while (0 != _Old[OldTextCount])
    {
        ++OldTextCount;
    }

    // �� ���ڿ��� ���̸� ���Ѵ�.
    int NewTextCount = 0;
    while (0 != _New[NewTextCount])
    {
        ++NewTextCount;
    }

    // �ٲ���� ���� ���� 
    int ChangeTextCount = 0;

    // �ٲ��� ���� �ε����� ���Ѵ�.
    int ChangeIdx = 0;
    for (int i = 0; i < TextCount + 1; ++i)
    {
        // �ݺ����鼭 ������ ���ڸ� ã�´�.
        if (_Text[i] == _Old[0])
        {
            ChangeIdx = i;
            // ã�Ҵٸ� ���� ���ڿ��� Ȯ���Ѵ�. 
            for (int j = 0; j < OldTextCount; ++j)
            {
                if (_Text[ChangeIdx + j] == _Old[j])
                {
                    // �����ؾ��� ���ڰ��� �߰�
                    ++ChangeTextCount;
                }
            }

            // �ٲ��� ���ڿ� �������� Ȯ���� �Ʊ� ������ for�� ����
            break;
        }
    }
    
    // ���ڿ� ����üũ 
    bool Check = OldTextCount >= NewTextCount;

    // true ��� ���� �ؽ�Ʈ�� �� ��ų� ����
    if (Check)
    {
        // �� ���ڿ��� �ε��� �� 
        int NewIdx = 0;

        // ConnectIdx = �ش� �ε������� ���ڸ� �̾�ٿ��ش�. 
        // �̾�ٿ��� �ε��� = �ٲ��� �ε�����ȣ + �����ؾ��� ���ڰ��� 
        int ConnectIdx = ChangeIdx + ChangeTextCount;

        // ���ڿ��� ���� ������ ���� ����
        while (0 != _New[NewIdx])
        {
            // ����
            _Text[ChangeIdx] = _New[NewIdx];

            // ����� ������ Index + 1
            ++ChangeIdx;
            ++NewIdx;
        }

        // ���ڿ��� ���� ������ ���� ����
        while (0 != _Text[ConnectIdx])
        {
            // ����
            _Text[ChangeIdx] = _Text[ConnectIdx];

            // ���� �� ������ Index + 1
            ++ChangeIdx;
            ++ConnectIdx;
        }

        // �۾��� ��� �����ٸ� ���ڿ��� ��� �Էµ� ���̰� 
        // ChangeIdx �� �ι��ڰ� �� �ڸ��� ���̴�. 0����.
        _Text[ChangeIdx] = 0;
    }

    // ���ο� �ؽ�Ʈ ���ڿ��� ���̰� ���� ���ڿ����� ��ٸ� �Ʒ� ������� ����
    else
    {
        // �־��� ���ڹ迭�� Index ��
        int Count = 0;
        // �̾ �ٿ������ ������ �����ε��� 
        int ConnectIdx = ChangeIdx + ChangeTextCount;

        // ����� ���ڿ��� ���� ���ڿ��� ���� �����صд�. 
        // ConnectIdx ���� ���ڿ��� ������ ����

        int TextIdx = 0;
        char Text[100] = {};

        // �̾���� ���ڿ��� ���� �����صΰ�
        // ������ �Ϸ� �Ǿ��� ������ ������������ �ٽ� �̾��ش�
        while (0 != _Text[ConnectIdx])
        {
            Text[TextIdx] = _Text[ConnectIdx];
            ++TextIdx;
            ++ConnectIdx;
        }

        // ���ڿ� ����
        while (0 != _New[Count])
        {
            _Text[ChangeIdx] = _New[Count];

            ++ChangeIdx;
            ++Count;
        }

        // �����صξ��� ���ڿ��� �̾�ٿ��ش�. 
        int TextCount = 0;
        while (0 != Text[TextCount])
        {
            _Text[ChangeIdx] = Text[TextCount];
            ++ChangeIdx;
            ++TextCount;
        }

        // �ڵ尡 ������� �����Դٸ� ��� �۾��� ������ ������
        // ���������� ����� �ε��� ������°�� 0�� �־��ش�. 
        // ���� �״��� ��° �ε��� ������ �����Ǿ� �ֱ� ������ 0 ���� 
        _Text[ChangeIdx] = 0;
    }
}
int main()
{
    // StrngChange
    {
        char Arr[100] = "aaa bbb ccc";

        StringChange(Arr, "bbb", "ddd");
        printf("StringChange : %s\n", Arr);
    }
    // --------------------------------------------------- // 

    // StringChangeEx 
    {
        char Arr[100] = "aaa bbb check";
       
        StringChangeEx(Arr, "bbb", "Te������������");
        printf("%s", "============================\n");
        printf("StringChangeEx : %s\n", Arr);
    }

 
    // StringCompair
	char Arr[20] = "�ߵǳ�?";
	{
        // true
		bool result = StringCompair(Arr, "�ߵǳ�?");

        int a = 0;
	}

	{
        // false
		bool result = StringCompair(Arr, "�߾ȵǳ�???");

		int a = 0;
	}


    // StringMerge
    {
        char Arr[100] = "";
        printf("%s", "============================\n");
        StringMerge(Arr, "test", "Game Game testest");
        //Arr = "test Game"

        printf("StringMerge : %s\n\n\n\n", Arr);
    }




}
