// String 迭代器
#include <iostream>
using namespace std;

class String 
{
public:
	typedef char* Iterator;
	Iterator begin() 
	{
		return _str;
	}

	Iterator end() 
	{
		return _str + _size;
	}

	String(const char* str = "") 
	{
		_size = _capacity = strlen(str);
		_str = new char[_capacity + 1];
		strcpy(_str, str);
	}

	~String() 
	{
		if (_str) 
		{
			delete[] _str;
			_str = nullptr;
		}
	}

private:
	char* _str;
	size_t _size;
	size_t _capacity;
};

int main() 
{
	String s1;
	String s2("hello");
	String::Iterator it = s2.begin();
	while (it != s2.end()) 
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// 范围for的支持源自于迭代器
	for (auto ch : s2) 
	{
		cout << ch << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
