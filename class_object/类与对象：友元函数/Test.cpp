//友元函数

//友元函数可访问类的私有成员，但不是类的成员函数 
//友元函数不能用const修饰 
//友元函数可以在类定义的任何地方声明，不受类访问限定符限制 
//一个函数可以是多个类的友元函数 
//友元函数的调用与普通函数的调用和原理相同
#include <iostream>
using namespace std;

class Date 
{
	// 友元函数的声明
	friend ostream& operator<<(ostream& _cout, const Date& d);
	friend istream& operator>>(istream& _cin, Date& d);
public:
	Date(int year = 1900, int month = 1, int day = 1) 
		: _year(year)
		, _month(month)
		, _day(day)	
	{}

	//void operator<<(ostream& _cout) {
	//	_cout << _year << "-" << _month << "-" << _day << endl;
	//}

private:
	int _year;
	int _month;
	int _day;
};

// 此时_year, _month, _day为私有的，不能够访问，因此定义友元函数->突破封装的一种特例
ostream& operator<<(ostream& _cout, const Date& d) 
{
	_cout << d._year << "-" << d._month << "-" << d._day << endl;
	return _cout;
}

istream& operator>>(istream& _cin, Date& d)
{
	_cin >> d._year;
	_cin >> d._month;
	_cin >> d._day;
	return _cin;
}

int main() 
{
	Date d1(2019, 5, 21);
	Date d2(2019, 5, 22);
	//cout << d1; 使用错误，若重载定义在类外则正确, 但在类外不能用私有成员变量，则需要友元函数
	//d1 << cout;

	cout << d1;
	operator<<(cout, d1);

	cout << d1 << d2 << endl;

	system("pause");
	return 0;
}
