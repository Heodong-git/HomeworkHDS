#include <iostream>


// 널문자 제외 문자열 길이 체크 함수
int MyStringCount(const char* _String)
{
    // 개수를 체크할 변수
    int Count = 0;

    const char* StringCheck = _String;
    
    // 반복문을 사용하여 0이 나올때 까지 검사 
    for (int i = 0; i < INT_MAX; ++i)
    {
        // 0이 아니라면 변수의 값을 증가
        if (StringCheck[i] != 0)
        {
            ++Count;
        }

        // 0을 만날 경우 문자열의 끝이라는 의미
        else if (StringCheck[i] == 0)
        {
            // 반복문 종료 
            break;
        }
    }

    // 문자열의 길이가 체크 되었기 때문에 그 값을 반환
    return Count;
}

int main()
{
    // 순서대로 5, 11, 8, 6 이 나오면 된다. 
    int Len0 = MyStringCount("aaaaa");
    int Len1 = MyStringCount("fasdjklfasd");
    int Len2 = MyStringCount("wew00000");   
    int Len3 = MyStringCount("gnvmkv");

    printf_s("Len0 변수의 문자열 길이 : %d", Len0);
    printf_s("\n");
    printf_s("Len1 변수의 문자열 길이 : %d", Len1);
    printf_s("\n");
    printf_s("Len2 변수의 문자열 길이 : %d", Len2);
    printf_s("\n");
    printf_s("Len3 변수의 문자열 길이 : %d", Len3);
    printf_s("\n");

    int Test = MyStringCount("으어으아한국어문자열개수테스트으억꾸에엑");
    printf_s("%d", Test);
    printf_s("\n");

    Test = MyStringCount("아무거나넣어보자adsf");
    printf_s("%d", Test);

    return 0;
}
