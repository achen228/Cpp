//继承的定义
#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
	void Print()
	{
		cout << _name << " " << _num << endl;
	}
protected:
	string _name = "胖胖"; //姓名
	int _num = 18060210; //学号
};

class Student : public Person
{
public:
	string _major = "软件工程"; //专业
};

int main()
{
	Student s;
    s.Print();
	return 0;
}
