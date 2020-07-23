//子类的默认成员函数
#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    Person(const char* name = "peter")
        : _name(name)
    {
        cout << "Person()" << endl;
    }

    Person(const Person& p)
        : _name(p._name)
    {
        cout << "Person(const Person& p)" << endl;
    }

    Person& operator=(const Person& p)
    {
        if (this != &p)
        {
            _name = p._name;
        }
        cout << "Person operator=(const Person& p)" << endl;
        return *this;
    }

    ~Person()
    {
        cout << "~Person()" << endl;
    }
protected:
    string _name; //姓名
};

class Student : public Person
{
public:
    Student(const char* name, int num)
        : Person(name)
        , _num(num)
    {
        cout << "Student()" << endl;
    }

    Student(const Student& s)
        : Person(s)
        , _num(s._num)
    {
        cout << "Student(const Student& s)" << endl;
    }

    Student& operator=(const Student& s)
    {
        if (this != &s)
        {
            Person::operator =(s);
            _num = s._num;
        }
        cout << "Student& operator= (const Student& s)" << endl;
        return *this;
    }

    ~Student()
    {
        cout << "~Student()" << endl;
    }
protected:
    int _num; //学号
};

void Test()
{
    Student s1("jack", 18);
    Student s2(s1);
    Student s3("rose", 17);
    s1 = s3;
}

int main()
{
    Test();
    return 0;
}
