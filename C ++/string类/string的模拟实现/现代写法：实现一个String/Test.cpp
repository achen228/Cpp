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


int main() 
{
	Test1();

	system("pause");
	return 0;
}
