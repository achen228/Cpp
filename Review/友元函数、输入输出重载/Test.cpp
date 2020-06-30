#include <iostream>
using namespace std;

class Date
{
    //声明友元函数
    friend ostream& operator<<(ostream& out, const Date& d);
    friend istream& operator>>(istream& in, Date& d);
public:
    Date(int year = 1900, int month = 1, int day = 1)
    {
        _year = year;
        _month = month;
        _day = day;
    }

    void Print()
    {
        cout << _year << "-" << _month << "-" << _day << endl;
    }
private:
    int _year;
    int _month;
    int _day;
};

//定义友元函数
ostream& operator<<(ostream& out, const Date& d)
{
    out << d._year << "-" << d._month << "-" << d._day;
    return out;
}

istream& operator>>(istream& in, Date& d)
{
    in >> d._year >> d._month >> d._day;
    return in;
}

int main()
{
    Date d1(2020, 6, 7);
    d1.Print();

    cout << d1 << endl;
    operator<<(cout, d1) << endl;

    Date d2(2020, 6, 8);
    cout << d1 << " " << d2 << endl;

    Date d3;
    cin >> d3;
    cout << d3 << endl;
    return 0;
}
