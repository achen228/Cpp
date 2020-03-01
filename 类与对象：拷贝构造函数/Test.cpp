//拷贝构造函数也是特殊的成员函数
//1. 拷贝构造函数是构造函数的一个重载形式
//2. 拷贝构造函数的参数只有一个且必须使用引用传参且一般加上const，使用传值方式会引发无穷递归调用
//3. 若未显示定义，系统生成默认的拷贝构造函数。默认的拷贝构造函数对象按内存存储按字节序完成拷贝，这种拷贝叫做浅拷贝，或者值拷贝

// 拷贝构造函数
#include <iostream>
using namespace std;

class A
{
public:
	A() 
	{
		cout << "A()" << endl;
	}
};

class Date 
{
public:
	// 构造函数
	Date(int year = 1900, int month = 1, int day = 1) 
	{
		cout << "Date()" << endl;
		_year = year;
		_month = month;
		_day = day;
	}

	// Date copy(d1)
	// 拷贝构造函数是构造函数的一个重载形式
	// 拷贝构造函数的参数只有一个且必须使用引用传参，使用传值方式会引发无穷递归调用
	Date(const Date& d) 
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	void Print() 
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	~Date()
	{
		cout << "~Date()" << endl;
	}

private:
	int _year;  // 内置类型/基本类型
	int _month;
	int _day;

	//A _a;  // 自定义类型->初始化==调用A的构造函数
};

int main() 
{
	Date d1;
	Date d2;
	Date d3(2019, 5, 12);
	Date copy(d1);
	d1.Print();
	d2.Print();
	d3.Print();
	copy.Print();
	system("pause");
	return 0;
}
