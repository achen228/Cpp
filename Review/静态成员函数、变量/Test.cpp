#include <iostream>
using namespace std;

class A
{
public:
    A()
    {
        ++_n;
    }

    A(const A& a)
    {
        ++_n;
    }

    //int GetN()
    //{
    //    return _n;
    //}

    //静态成员函数，没有隐藏的this指针，不能访问任何非静态成员
    //不属于某个具体的对象，而是属于类中所有的对象
    static int GetN() 
    {
        return _n;
    }
private:
    static int _n; //声明静态成员变量
};

int A::_n = 0; //定义静态成员变量

int main()
{
    A a1;
    A a2;
    //cout << a1.GetN() << endl;
    cout << A::GetN() << endl;
    return 0;
}
