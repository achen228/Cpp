//继承与友元
//父类的友元不能被子类继承
#include <iostream>
#include <string>
using namespace std;

class Student;

class Person
{
public:
    friend void Display(const Person& p, const Student& s);
protected:
    string _name; //姓名
};

class Student : public Person
{
protected:
    int _stuNum; //学号
};

void Display(const Person& p, const Student& s)
{
    cout << p._name << endl;
    cout << s._stuNum << endl;
}

int main()
{
    Person p;
    Student s;
    Display(p, s);
    return 0;
}
