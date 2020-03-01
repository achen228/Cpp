//友元类
//友元类的所有成员函数都可以是另一个类的友元函数，都可以访问另一个类中的非公有成员。
//友元关系是单向的，不具有交换性。 
//比如上述Time类和Date类，在Time类中声明Date类为其友元类，那么可以在Date类中直接访问Time类的私有成员变量，但想在Time类中访问Date类中私有的成员变量则不行。 
//友元关系不能传递 
//如果B是A的友元，C是B的友元，则不能说明C时A的友元
#include <iostream>
using namespace std;

class Date;  // 前置声明 
class Time 
{   
	friend class Date;  // 声明日期类为时间类的友元类，则在日期类中就直接访问Time类中的私有成员变量 
public:   
	Time(int hour = 1, int minute = 1, int second = 1)       
		: _hour(hour)       
		, _minute(minute)       
		, _second(second)   
	{}   
private:   
	int _hour;   
	int _minute;   
	int _second; 
};

class Date 
{
public:   
	Date(int year = 1900, int month = 1, int day = 1) 
		: _year(year)
		, _month(month)
		, _day(day) 
	{}      

	// 直接访问时间类私有的成员变量
	void SetTimeOfDate(int hour, int minute, int second) 
	{           
	_t._hour = hour;       
	_t._minute = minute;       
	_t._second = second;   
	}   
private:   
	int _year;   
	int _month;   
	int _day;   
	Time _t; 
};
