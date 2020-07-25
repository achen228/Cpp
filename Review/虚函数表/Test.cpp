//虚函数表
#include <iostream>
using namespace std;

class Base
{
public:
    virtual void Func1()
    {
        cout << "Base::Func1()" << endl;
    }
    virtual void Func2()
    {
        cout << "Base::Func2()" << endl;
    }
    void Func3()
    {
        cout << "Base::Func3()" << endl;
    }
private:
    int _b = 1;
};

class Derive : public Base
{
public:
    virtual void Func1()
    {
        cout << "Derive::Func1()" << endl;
    }
private:
    int _d = 2;
};

int main()
{
    Base b;
    Derive d;
    return 0;
}
