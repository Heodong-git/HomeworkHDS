#include <iostream>

int MyStringCount(const char* _String)
{
    // ������ üũ�� ����
    int Count = 0;

    const char* CheckString = _String;
    
    // �ݺ����� ����Ͽ� 0�� ���ö� ���� �˻� 
    for (int i = 0; i < INT_MAX; ++i)
    {
        // 0�� �ƴ϶�� ������ ���� ����
        if (CheckString[i] != 0)
        {
            ++Count;
        }

        // 0�� ���� ��� ���ڿ��� ���̶�� �ǹ�
        else if (CheckString[i] == 0)
        {
            // �ݺ��� ���� 
            break;
        }
    }

    // ���ڿ��� ���̰� üũ �Ǿ��� ������ �� ���� ��ȯ
    return Count;
}

int main()
{
    // ������� 5, 11, 8, 6 �� ������ �ȴ�. 
    int Len0 = MyStringCount("aaaaa");
    int Len1 = MyStringCount("fasdjklfasd");
    int Len2 = MyStringCount("wew00000");   
    int Len3 = MyStringCount("gnvmkv");

    int Test = MyStringCount("�������ƾ��ѱ���ڿ������׽�Ʈ����");
    
    printf_s("%d", Test);
    printf_s("\n");
    printf_s("Len0 ������ ���ڿ� ���� : %d", Len0);
    printf_s("\n");
    printf_s("Len1 ������ ���ڿ� ���� : %d", Len1);
    printf_s("\n");
    printf_s("Len2 ������ ���ڿ� ���� : %d", Len2);
    printf_s("\n");
    printf_s("Len3 ������ ���ڿ� ���� : %d", Len3);

    return 0;
}
