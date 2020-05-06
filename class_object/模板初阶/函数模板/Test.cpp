// 函数模板
#include <iostream>
using namespace std;

template<class T>
T Add(const T& left, const T& right) 
{
	return left + right;
}

template<class T>
void func() 
{
	T tmp = 1;
	cout << tmp << endl;
}

int main() 
{
	// 隐式实例化
	cout << Add(1, 2) << endl;
	// 显式实例化
	cout << Add<int>(1, 2.2) << endl;
	func<int>();

	system("pause");
	return 0;
}
