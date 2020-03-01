#pragma once
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Date
{
public:
	inline int GetMonthDay(int year, int month) const
	{
		static int monthArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if ((month == 2) &&(year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) 
		{
			return 29;
		}
		return monthArray[month];
	}

	// 构造函数
	Date(int year, int month, int day) 
	{
		if (year >= 1900
			&& month > 0 && month < 13
			&& day > 0 && day <= GetMonthDay(year, month)) 
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else 
		{
			cout << "非法日期" << endl;
		}
	}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	 //1.
	 //不加引用的话，str则被复制一份，函数中对str的操作实质上是对其复制品的操作，
	 //所以即使在函数中修改了str，调用层的原str并不会被改变。

	 //加了引用的话，传入的str即是调用层的实际参数，这样省却了复制过程，效率会有提高。
	 //但如果函数中修改了str，则原str也会改变，因为其实是同一个东西。

	 //有时候为了追求效率，又希望避免改变原来的str，则可在引用的基础上加const修饰，
	 //这样函数中就不能再修改str的内容（否则会编译出错）。

	 //2.
	 //在函数后面是否加上 const 
	 //如果函数的实现不想改变私有成员变量，则加上 const； 反之不加 const

	bool operator > (const Date& d) const;
	bool operator >= (const Date& d) const;
	bool operator < (const Date& d) const;
	bool operator <= (const Date& d) const;
	bool operator == (const Date& d) const;
	bool operator != (const Date& d) const;

	Date& operator++();    // 前置++
	Date operator++(int); // 后置++

	Date& operator--();    // 前置--
	Date operator--(int); // 后置--

	Date operator+(int day) const;
	Date operator-(int day) const;

	Date& operator+=(int day);
	Date& operator-=(int day);

	int operator-(const Date& d)const;

private:
	int _year;
	int _month;
	int _day;
};
