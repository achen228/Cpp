#include <iostream>
using namespace std;

class Time
{
    //声明日期类为时间类的友元类
    friend class Date;
public:
    Time(int hour = 0, int minute = 0, int second = 0)
    {
        _hour = hour;
        _minute = minute;
        _second = second;
    }
private:
    int _hour;
    int _minute;
    int _second;
};

class Date
{
public:
    Date(int year = 1900, int month = 1, int day = 1)
    {
        _year = year;
        _month = month;
        _day = day;
    }

    void SetTime(int hour, int minute, int second)
    {
        _t._hour = hour;
        _t._minute = minute;
        _t._second = second;
    }

    void Print()
    {
        cout << _year << "-" << _month << "-" << _day << endl;
        cout << _t._hour << "-" << _t._minute << "-" << _t._second << endl;
    }
private:
    int _year;
    int _month;
    int _day;
    Time _t;
};

int main()
{
    Date d1(2020, 6, 7);
    d1.Print();

    d1.SetTime(12, 44, 0);
    d1.Print();
    return 0;
}
