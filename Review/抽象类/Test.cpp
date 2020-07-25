//抽象类
#include <iostream>
using namespace std;

class Car
{
public:
    virtual void Drive() = 0;
};

class Benz :public Car
{
public:
    virtual void Drive()
    {
        cout << "Benz-舒适" << endl;
    }
};

class BMW :public Car
{
public:
    virtual void Drive()
    {
        cout << "BMW-操控" << endl;
    }
};

void Test()
{
    Car* pBenz = new Benz;
    pBenz->Drive();

    Car* pBMW = new BMW;
    pBMW->Drive();
}

int main()
{
    Test();
    return 0;
}
