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

// 문자열이 동일한지 확인 
bool StringCompair(const char* _Text0, const char* _Text1)
{
    // 먼저 문자열의 길이가 같은지부터 체크한다
    int First = StringCount(_Text0);
    int Second = StringCount(_Text1);

    // 문자열의 길이가 다르다면 서로 다른 문자열 인 것이다. 
    if (First != Second)
    {
        return false;
    }
    
    for (int i = 0; i < First; ++i)
    {
        // 하나씩 비교하여 서로 다르다면 다른 문자열 인 것이다.
        if (_Text0[i] != _Text1[i])
        {
            return false;
        }
    }
  
    // for 문 내부에 if 문에 걸리지 않고 끝까지 문자열길이 끝까지 확인 후 
    // 아래 코드로 내려왔다면 서로 같은 문자열이라는 의미이다. 
    return true;
}

// 문자열 합치기 
void StringMerge(char* _Result, const char* _Text0, const char* _Text1)
{
    int First = StringCount(_Text0);
    int Second = StringCount(_Text1);

    int ConnectIdx = 0;

    for(int i = 0; i < First; ++i)
    {
        // 널문자가 나올때 까지 문자열을 복사한다. 
        if (0 != _Text0[i])
        {
            _Result[i] = _Text0[i];
        }   
        ++ConnectIdx;
    }

    // 복사가 완료된 후 다음 인덱스값을 얻어놨기 때문에
    // 다음인덱스부터 두번째로 들어온 인자의 문자열의 널문자가 나올때 까지 
    // 이어서 대입해준다.
    
    for (int i = 0; i < Second; ++i)
    {
        if (0 != _Text1[i])
        {
            _Result[ConnectIdx] = _Text1[i];
            ++ConnectIdx;
        }
    }

    // 모든 작업이 완료되었다면 결과값에 마지막 문자열에 0을 대입해서 끝을 알수 있도록 처리한다.
    _Result[ConnectIdx] = 0;

    return;
}

void StringChange(char* _Text, const char* _Old, const char* _New)
{
    // 널문자를 뺀 문자열 길이룰 구한다.  
    int TextCount = 0;
    while (0 != _Text[TextCount])
    {
        ++TextCount;
    }

    // 바꿔줄 문자열의 길이를 구한다.
    int OldTextCount = 0;
    while (0 != _Old[OldTextCount])
    {
        ++OldTextCount;
    }

    // 새 문자열의 길이를 구한다.
    int NewTextCount = 0;
    while (0 != _New[NewTextCount])
    {
        ++NewTextCount;
    }
    
    // 몇개의 문자를 바꾸어야 할지 개수를 구한다. 
    int ChangeTextCount = 0;
    
    // 바꿔줄 시작 인덱스를 구한다.
    int ChangeIdx = 0;
    for (int i = 0; i < TextCount + 1; ++i)
    {
        // 반복돌면서 동일한 문자를 찾는다.
        if (_Text[i] == _Old[0])
        {
            ChangeIdx = i;
            // 찾았다면 뒤쪽 문자열도 확인한다. 
            for (int j = 0; j < OldTextCount; ++j)
            {
                if (_Text[i + j] == _Old[j])
                {
                    ++ChangeTextCount;
                }
            }

            // 바꿔줄 문자와 동일한지 확인이 됐기 때문에 for문 종료
            break;
        }
    }

    // 변경할 문자를 넣어준다. 
    // 이 때 변경할 텍스트개수보다 새로운 텍스트의 개수가 작다면 예외처리해야하는데.. 그게 ex인듯
    // 텍스트개수가 몇개 더 작은지 계산해서 바꿔주고 그 이후 인덱스는 한칸씩 땡겨 
    int Value = ChangeTextCount - NewTextCount;

    // 서로 텍스트의 개수가 같다면 이렇게 처리
    if (Value == 0)
    {
       for (int i = 0; i < ChangeTextCount; ++i)
       {
           _Text[ChangeIdx + i] = _New[i];
       }
   
    }
    
    // 그게 아니면 작업이 완료 되고 나면 뒤쪽 인덱스를 앞으로 채워준다. 
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
            
            if (_Text[MoveIdx + i] == 0)
                break;
        }
    }
    
}

void StringChangeEx(char* _Text, const char* _Old, const char* _New)
{
    // 널문자를 뺀 문자열 길이룰 구한다.  
    int TextCount = 0;
    while (0 != _Text[TextCount])
    {
        ++TextCount;
    }

    // 바꿔줄 문자열의 길이를 구한다.
    int OldTextCount = 0;
    while (0 != _Old[OldTextCount])
    {
        ++OldTextCount;
    }

    // 새 문자열의 길이를 구한다.
    int NewTextCount = 0;
    while (0 != _New[NewTextCount])
    {
        ++NewTextCount;
    }

    // 바꿔야할 문자 개수 
    int ChangeTextCount = 0;

    // 바꿔줄 시작 인덱스를 구한다.
    int ChangeIdx = 0;
    for (int i = 0; i < TextCount + 1; ++i)
    {
        // 반복돌면서 동일한 문자를 찾는다.
        if (_Text[i] == _Old[0])
        {
            ChangeIdx = i;
            // 찾았다면 뒤쪽 문자열도 확인한다. 
            for (int j = 0; j < OldTextCount; ++j)
            {
                if (_Text[ChangeIdx + j] == _Old[j])
                {
                    ++ChangeTextCount;
                }
            }

            // 바꿔줄 문자와 동일한지 확인이 됐기 때문에 for문 종료
            break;
        }
    }

    // 넣어줄 문자배열의 Index 값
    int Count = 0;
    // 이어서 붙여줘야할 문자의 시작인덱스 
    int ConnectIdx = ChangeIdx + ChangeTextCount;

    while (0 != _New[Count])
    {
        _Text[ChangeIdx] = _New[Count];

        ++ChangeIdx;
        ++Count;
    }

    while (0 != _Text[ConnectIdx])
    {
        _Text[ChangeIdx] = _Text[ConnectIdx];

        ++ChangeIdx;
        ++ConnectIdx;
    }

    // 코드가 여기까지 내려왔다면 모든 작업이 끝났기 때문에
    // 마지막으로 변경된 인덱스 다음번째에 0을 넣어준다. 
    // 현재 그다음 번째 인덱스 값으로 설정되어 있기 때문에 0 대입 
    _Text[ChangeIdx] = 0;
}
int main()
{
    // StrngChange
    {
        char Arr[20] = "aaa bbb ccc";

        StringChange(Arr, "bbb", "ddd");
        printf("StringChange : %s\n", Arr);
    }
    // --------------------------------------------------- // 

    // StringChangeEx 
    {
        char Arr[20] = "aaa bbb check";
       
        StringChangeEx(Arr, "bbb", "3");
        printf("%s", "============================\n");
        printf("StringChangeEx : %s\n", Arr);
    }

 
    // StringCompair
	char Arr[20] = "잘되나?";
	{
        // true
		bool result = StringCompair(Arr, "잘되나?");

        int a = 0;
	}

	{
        // false
		bool result = StringCompair(Arr, "잘안되나???");

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
