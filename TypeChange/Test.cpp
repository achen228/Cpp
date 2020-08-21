#include <iostream>
using namespace std;

void Test1()
{
	int i = 1;
	double d = 8.88;
	//c语言支持相近类型的隐式类型转换(相近类型，也就是意义相似的类型)
	i = d;
	cout << i << endl;

	int* p = nullptr;
	//c语言支持不相近类型的强制类型转换(不相近类型，也就是意义差别很大的类型)
	p = (int*)i;
	cout << p << endl;
}

void Test2()
{
	//C++兼容C语言留下来的隐式类型转换和显示类型转换，但是C++觉得C语言做得不规范，C++想规范一下
	//C++标准为了加强类型转换的可视性，引入了四种命名的强制类型转换操作符
	//static_cast、reinterpret_cast、const_cast、dynamic_cast

	int i = 1;
	double d = 8.88;
	//对应c语言的隐式类型转换(相近类型)
	i = static_cast<double>(d);
	cout << i << endl;

	int* p = nullptr;
	//对应c语言大部分强制类型转换(不相近类型)
	p = reinterpret_cast<int*>(i);
	cout << p << endl;
}

void Test3()
{
	const int ci1 = 10;
	//对应c语言强制类型转换中去掉const属性(不相近类型)
	//int* pi1 = (int*)&ci1;
	int* pi1 = const_cast<int*>(&ci1);
	*pi1 = 20;

	//打印20
	cout << *pi1 << endl;
	//打印10，因为ci存储的内存被改了，但是ci是常量被放进了寄存器，这里去寄存器中取，还是10。
	//本质这是由于编译器对const对象存取优化机制导致。
	cout << ci1 << endl;

	cout << endl;

	//想要禁止编译器做这个优化，每次都到内存中去取值，就把关键字volatile加上
	volatile const int ci2 = 10;
	int* pi2 = const_cast<int*>(&ci2);
	*pi2 = 20;
	cout << *pi2 << endl;
	cout << ci2 << endl;
}


class A
{
public:
	virtual void Func()
	{}

	int _a;
};

class B : public A
{
public:
	int _b;
};

void FCast(A* pa)
{
	//怎么来区分 pa是指向父类对象还是子类对象？
	//如果pa是指向子类对象，则转换成功，
	//如果pa指向父类对象则转换失败返回nullptr 
	B* pb = dynamic_cast<B*>(pa);
	if (pb != nullptr)
	{
		cout << "转换成功：pa指向子类对象" << endl;
		pb->_a = 1;
		pb->_b = 2;
	}
	else
	{
		cout << "转换失败：pa指向父类对象" << endl;
	}
}

void Test4()
{
	//C++中子类对象可以赋值给父类的对象、指针、引用，这个过程中会发生切片，	
	//这个过程是语法天然支持的，叫向上转换，都可以成功。

	//如果是父类的指针或者引用，传给子类的指针，这个过程叫向下转换，这个过程有可能能成功，要看具体情况。
	//最后需要注意的是：dynamic_cast向下转换只能针对继承中的多态类型(父类必须包含虚函数)

	//dynamic_cast如何识别父类的指针是指向父类对象还是子类对象的呢？即dynamic_cast的原理？
	//dynamic_cast通过去虚表的上方找到存储的标识信息，来判断指向父类对象还是子类对象。

	A a;
	B b;

	//pa指向父类对象
	A* pa = &a;
	FCast(pa);

	//pa指向子类对象
	pa = &b;
	FCast(pa);
}

int main()
{
	//Test1();
	//Test2();
	//Test3();
	Test4();
	return 0;
}


//总结：尽量少用类型转换，如果要用尽量规范一点，且知道转换后会有什么影响
