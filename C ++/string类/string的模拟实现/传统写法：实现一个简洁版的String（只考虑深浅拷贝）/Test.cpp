// 传统写法
// 面试：实现一个简洁版的String->只考虑深浅拷贝
// String的深浅拷贝问题
#include <iostream>
using namespace std;

class String 
{
public:
	//String()
	//	: _str(new char[1]) 
	//{
	//	_str = '\0';
	//}

	//String(char* str)
	//	: _str(new char[strlen(str) + 1]) 
	//{
	//	strcpy(_str, str);
	//}

	// 把前两种写法合二为一：带缺省的构造函数
	String(const char* str = "")  // 空字符串，但带有\0
	{
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	// 深拷贝  copy(s2)
	String(const String& s) 
	{
		_str = new char[strlen(s._str) + 1];
		strcpy(_str, s._str);
	}

	// 赋值重载  s1 = copy
	String& operator=(const String& s) 
	{
		if (this != &s) 
		{
			delete[] _str; // 干掉_str的空间
			_str = new char[strlen(s._str) + 1]; // 重新开辟和s._str一样大的空间
			strcpy(_str, s._str);
		}

		return *this;
	}

	~String() 
	{
		if (_str) 
		{
			delete[] _str;
			_str = nullptr;
		}
	}
		
	char& operator[](size_t index) 
	{
		return _str[index];
	}

	const char* c_str()
	{
		return _str;
	}

private:
	char* _str;
};

int main() 
{
	String s1;
	String s2("hello");
	s2[0] = 'x';

	cout << s1.c_str() << endl;
	cout << s2.c_str() << endl;

	String copy(s2);
	copy[0] = 'h';
	cout << copy.c_str() << endl;

	s1 = copy; // 如果不写好赋值函数，会发生s2的内存泄露，s2有自己的空间
	cout << s1.c_str() << endl;

	s1 = s1; // 如果赋值重载中不添加 this != &s 将出错，释放自己的空间后，再拷贝会出现随机值
	cout << s1.c_str() << endl;

	system("pause");
	return 0;
}
