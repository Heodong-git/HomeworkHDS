// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


class Parent
{
public:
    Parent() :
        c(0),
        a(100),
        b(10)
    {

    }

    virtual ~Parent()
    {

    }

    virtual void Test()
    {

    }

public:
    int a;
    int b;
    int c;

    // 생성자에서 값을 초기화 할때 변수가 선언된 순서대로 값이 초기화되는 부분을
    // 확인했고 a b c 의 순서대로 변수를 선언한 이후에 
    // 생성자에서 초기화시에 순서를 c b a 와 같은 순서로 바꿔서 입력하더라도 
    // 가장 먼저 선언되어 있는 변수부터 초기화가 되는 것을 볼 수 있다. 
    // 그렇기 때문에 클래스 생성시 초기화 순서를 확인해보면 vfptr 이 가장먼저
    // 초기화 되어 가상함수의 주소가 입력되는 것을 확인이 가능하다. 

};

class Child : public Parent
{
public:
    Child()
    {

    }
    ~Child()
    {

    }

    void Test() override
    {

    }

};

int main()
{
    Parent* NewParent = new Parent;
    Child* NewChild = new Child;

    NewChild->Test();

    delete NewParent;
    delete NewChild;

    std::cout << sizeof(NewParent) << std::endl;
}

