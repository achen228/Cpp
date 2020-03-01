//explicit 关键字
#include <iostream>
using namespace std;
class A 
{
public:
	explicit A(int a)
		: _a(a) 
	{}

private:
	int _a;
};

int main() 
{
	A aa1(10);  // 构造

	// 若构造函数前面加上 explicit 关键字，则不允许创建临时对象->下面语句将报错
	//A aa2 = 20;  //  A tmp(20); A aa2 = tmp; 构造+拷贝构造

	A aa3(aa1);  // 拷贝构造
	A aa4 = aa1;  // 拷贝构造

	system("pause");
	return 0;
}


// C++98 具有单参数构造函数类
// C++11 支持多参数构造函数类
#include <iostream>
using namespace std;

class A 
{
public:
	A(int a1, int a2)
		: _a1(a1)
		, _a2(a2)
	{}
private:
	int _a1;
	int _a2;
};

int main() 
{
	A aa1(1, 2);

	// 同样若构造函数前面加上 explicit 关键字，则不允许创建临时对象->下面语句将报错
	A aa2 = { 1, 2 }; 

	system("pasue");
	return 0;
}
