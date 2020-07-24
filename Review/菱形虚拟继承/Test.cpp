//菱形虚拟继承
#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    string _name; // 姓名
};

class Student : virtual public Person
{
protected:
    int _num; //学号
};

class Teacher : virtual public Person
{
protected:
    int _id; // 职工编号
};

class Assistant : public Student, public Teacher
{
protected:
    string _majorCourse; // 主修课程
};

void Test()
{
    Assistant a;
    a._name = "peter";
}

int main()
{
    Test();
    return 0;
}
