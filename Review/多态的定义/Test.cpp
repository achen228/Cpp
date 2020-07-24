//多态的定义
#include <iostream>
using namespace std;

class Person
{
public:
    virtual void BuyTicket()
    { 
        cout << "Person::买票-全价" << endl;
    }
};

class Student : public Person
{
public:
    virtual void BuyTicket()
    { 
        cout << "Student::买票-半价" << endl; 
    }
};

void Func(Person& p)
{
    p.BuyTicket();
}

int main()
{
    Person Mike;    
    Func(Mike);

    Student Johnson;
    Func(Johnson);
    return 0;
}
