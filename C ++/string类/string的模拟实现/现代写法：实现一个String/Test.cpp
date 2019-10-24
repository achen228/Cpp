#include "String.h"

void Test1()
{
	String s1("hello");
	String s2(s1);
	cout << s1.c_str() << endl;
	cout << s2.c_str() << endl;

	String s3("world");
	s1 = s3;
	cout << s1.c_str() << endl;
}


void Test2()
{
	String s1("hello");
	for (size_t i = 0; i < s1.Size(); ++i) 
	{
		cout << s1[i] << " ";
	}
	cout << endl;

	String::Iterator it1 = s1.Begin();
	while (it1 != s1.End())
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;

	const String s2("world");
	String::ConstIterator it2 = s2.Begin();
	while (it2 != s2.End()) 
	{
		cout << *it2 << " ";
		++it2;
	}
	cout << endl;
	cout << s2.c_str() << endl;
}


int main() 
{
	Test1();

	system("pause");
	return 0;
}
