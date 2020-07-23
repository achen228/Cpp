//子类和父类有同名成员时，子类隐藏父类的成员
#include <iostream>
#include <string>
using namespace std;

class A
{
public:
    void fun()
    {
        cout << "func()" << endl;
    }
};

class B : public A
{
public:
    void fun(int i)
    {
        A::fun();
        cout << "func(int i)->" << i << endl;
    }
};

void Test()
{
    B b;
    b.fun(10);
};

int main()
{
    Test();
    return 0;
}
