//override关键字
#include <iostream>
using namespace std;

class Car
{
public:
    virtual void Drive()
    {}
};

class Benz :public Car
{
public:
    virtual void Drive() override
    { 
        cout << "Benz-舒适" << endl; 
    }
};
