// string类的用法
#include <iostream>
#include <string>
using namespace std;

void test_string1() 
{
	string s1;
	cout << s1 << endl;
	cout << s1.c_str() << endl;

	string s2("hello, wrold");
	cout << s2 << endl;
	cout << s2.c_str() << endl;

	string s3(100, 'x');
	cout << s3 << endl;

	string s4(s3);
	cout << s4 << endl;

	string s5(s2, 0, 5); // 从0开始取5个字符
	cout << s5 << endl;
}


void test_string2()
{
	string s("hello");
	// push_back 只能插入一个字符， append 可以插入字符串
	s.push_back(' ');
	s.append("world");
	cout << s << endl;

	string w("world");
	s += '-';
	s += "change ";
	s += w;
	cout << s << endl;
}
