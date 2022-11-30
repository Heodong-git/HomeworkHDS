#include <iostream>


// 인자로 들어온 값이 몇자리 수인지 반환
int NumberCount(int _Number)
{
    // 인자로 123이 들어왔다면
    // 자리수가 3자리이기 때문에 
    // 반환값은 3이 나오면 된다. 
    // 자리수를 뭘로 판단하지? 
    // 어떠한 자릿수의 값을 10으로 나눈다. 
    int Count = 0;
    while (0 <= _Number)
    {
        // 계속 나눠진다면 자릿수가 더 길다는 의미, 나눠지지 않는다면
        // ex) 7 이라는 값이 들어왔다면 나눠지지 않기 때문에 Count 의 값이 1만 증가하여
        // 1자리수라는 의미가 된다. 
        _Number = _Number / 10;
        ++Count;

        if (_Number == 0)
        {
            break;
        }

    }
    
    return Count;
}

void NumbertoString(char* _Ptr, int _Size, int _Value)
{
    // 저장해야하는 값 
    int Value = _Value;

    // 자리수 
    int Count = NumberCount(Value);

    // 인자로 들어온 배열의 크기 
    int ArrSize = _Size;

    // 나눌 값 
    int DividValue = 1;

    // ex) 저장해야 하는 값이 1300이라면 Count 의 값은 4가 저장되어 있을 것이고
    // 반복문을 실행하면 결과값으로 1000이 나오게 된다. 
    for (int i = 1; i < Count; ++i)
    {
        // 나눠주어야할 값 
        DividValue *= 10;
    }
    
    // 현재 인덱스 
    int CurIdx = 0;

    // 값의 자리수만큼 반복
    for (CurIdx = 0; CurIdx < Count; ++CurIdx)
    {
        // *아스키코드표 참고
        // 나눗셈하여 나온값을 그냥 저장할 경우 문자 1~9 가 아닌 다른 값이
        // 저장되기 때문에 '0' (48) 의 값을 더하여 문자로 저장될 수 있도록 한다.
        _Ptr[CurIdx] = Value / DividValue + '0';

        // 제일앞쪽 ( 제일큰 ) 자리수는 저장되었기 때문에 그 값을 빼주고
        // 뒤쪽 값들도 동일하게 계산해준다. 
        // 현재값 -= (1300 / 1000) * 1000  
        Value -= ((Value / DividValue) * DividValue);

        // 10으로 나누어 다음자리수를 처리
        DividValue /= 10;
    }

    // 모든 작업이 완료 되었다면 마지막에 널문자 삽입
    _Ptr[CurIdx + 1] = 0;
}

// 코드 간소화해서 다시 만들어보기 
void Myitoa(char* _Text, int _Size, int _Value)
{
    // 숫자의 길이
    int Len = NumberCount(_Value);

    int Div = 1;

    // 자리수확인을 위해 나누어야할 값 
    for (int i = 1; i < Len; ++i)
    {
        Div *= 10;
    }

    // 문자배열에 값 저장 
    for (int i = 0; i < Len; ++i)
    {
        // 정수 1의 값을 저장하게 되면 완전히 다른 문자가 나오기 때문에
        // 아스키코드 '0' 의 값을 더해주면 그 정수에 해당하는 문자를 저장할 수 있게 된다. 
        _Text[i] = _Value / Div + '0';

        // 기존 값에서 저장해주었던 자리수를 빼준다. 
        _Value -= (_Value / Div) * Div;

        // 자리수를 줄여준다. 
        Div /= 10;
    }

    // 마지막 인덱스에 0 을 넣어 문자열의 끝을 알 수 있게 처리해준다. 
    _Text[Len] = 0;
}


int main()
{

    {
        // 인자로 넣어준 정수값의 자리수 확인함수 
        int Count = NumberCount(1232123);
        int Value = 0;
    }

    {
        // 이 배열 안에 문자열로
        // '1300' 이 저장되어 있으면 된다. 
        char Arr[100] = {};
        Myitoa(Arr, 100, 1112330);

        // 이렇게 처리하면 12345가 문자로 나오면 됨. 
        printf_s(Arr);
    }

	return 0;
}