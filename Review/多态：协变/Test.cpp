//协变
#include <iostream>
using namespace std;

class A {};
class B : public A {};

class Person
{
public:
    virtual A* Fun1()
    { 
        return new A; 
    }

    virtual Person* Fun2()
    {
        return nullptr;
    }
};

class Student : public Person
{
public:
    virtual B* Fun1() 
    { 
        return new B; 
    }

    virtual Student* Fun2()
    {
        return nullptr;
    }
};
