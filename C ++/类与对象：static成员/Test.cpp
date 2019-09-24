// static成员 
// 静态的成员变量在类外进行初始化
// 即静态成员变量必须在类外定义，定义时不添加static关键字
// 静态成员函数没有隐藏的this指针，不能访问任何非静态成员

// static有什么作用？
// 1.修饰局部变量，改变生命周期
// 2.修饰全局函数，全局变量，改变链接属性
// 3.修饰成员函数，成员函数没有this指针，成员函数属于整个类，使用类名就可以调用
// 4.修饰成员变量，属于整个类，使用类名就可以访问

// 设计一个类，统计出一个程序中创建了多少个这个类型的对象
#include <iostream>
using namespace std;

int n = 0;
class A 
{
public:
	A(int a = 10)
		: _a(a) 
	{
		++_n;
	}

	A(const A& a) 
	{
		++_n;
	}

	static int GetN() 
	{
		return _n;
	}

private:
	int _a;
	static int _n;  // 静态成员变量声明
};

int A::_n = 0;  // 静态成员变量必须在类外定义

A f(A a) 
{
	return a;
}

int main()
{
	A aa1(1);
	A aa2 = 10;
	A aa3 = f(aa1);

	cout << n << endl;

	A();  // 匿名对象
	cout << A().GetN() << endl;  // 使用GetN()接口时，必须有对象

	cout << A::GetN() << endl;  // 或者 给GetN函数前加上static

	system("pause");
	return 0;
}


//C++11支持非静态成员变量在声明时进行初始化赋值，但是要注意这里不是初始化，这里是给声明的成员变量缺省值。
#include <iostream>
using namespace std;

class B 
{
public:
	B(int b = 0)
		: _b(b) 
	{}

	int _b;
};

class A 
{
public:
	A()
		: _a2(10)
	{}

private:
	int _a1;
	int _a2 = 2;  // 声明->给缺省值
	//static int _n = 20; 静态不能这样写

	int* _p = new int;
	B _b = 10;  // 声明->给缺省值
};

int main() 
{
	A aa;

	system("pause");
	return 0;
}
