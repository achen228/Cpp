//继承与静态成员变量
//子类可以继承基类的静态成员变量，但整个继承体系里面只有一个这样的成员（即静态成员变量的地址不会改变）
#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    Person()
    { 
        ++_count; 
    }
protected:
    string _name; //姓名
public:
    static int _count; //统计人的个数
};

int Person::_count = 0;

class Student : public Person
{
protected:
    int _stuNum; //学号
};

class Graduate : public Student
{
protected:
    string _seminarCourse; //研究科目
};

void TestPerson()
{
    Student s1;
    Student s2;
    Student s3;
    Graduate s4;
    cout << " 人数 :" << Person::_count << endl;

    Student::_count = 0;
    cout << " 人数 :" << Person::_count << endl;
}

int main()
{
    TestPerson();
    return 0;
}
