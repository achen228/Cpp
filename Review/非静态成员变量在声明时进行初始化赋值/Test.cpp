#include <iostream>
using namespace std;

class Date
{
public:
    Date()
    {}

    void Print()
    {
        cout << _year << "-" << _month << "-" << _day << endl;
    }
private:
    //C++11支持非静态成员变量在声明时进行初始化赋值
    //但是这里不是真正意义上的初始化，而是给缺省值
    int _year = 1900;
    int _month = 1;
    int _day = 1;
};

int main()
{
    Date d1;
    d1.Print();
    return 0;
}
