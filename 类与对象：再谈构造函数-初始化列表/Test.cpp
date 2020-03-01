// 再谈构造函数->初始化列表
#include <iostream>
using namespace std;

class Date 
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)  // 成员定义在初始化列表
		, _month(month)
		, _day(day)
		, _n(10) 
	{}
	// 每个成员变量在初始化列表中有且只能初始化一次
	// 类中包含以下成员，必须放在初始化列表位置进行初始化：
	//	引用成员变量、const成员变量、类类型成员（该类没有默认构造函数）

private:
	int _year;
	int _month;
	int _day; // 声明

	const int _n;
};

int main()
{
	Date d;  // 对象的定义

	system("pause");
	return 0;
}


// 成员变量在类中声明次序就是其在初始化列表中的初始化顺序，与其在初始化列表中的先后次序无关
#include <iostream>
using namespace std;

class A
{
public:
	A()
		:_a2(10)	// 声明顺序为 _a1, _a2
		,_a1(_a2)   // 则先初始化 _a1,此时_a2还是随机值，则_a1也为随机值
	{}             
private:
	int _a1;
	int _a2;
};

int main()
{
	A a;

	system("pause");
	return 0;
}
