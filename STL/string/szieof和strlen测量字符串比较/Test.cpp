#include <iostream>
using namespace std;

int main() 
{
	char p1[] = "abcd";
	cout << sizeof(p1) << endl;  // 5
	cout << strlen(p1) << endl;  // 4
	cout << endl;

	char p2[] = "abcd\0";
	cout << sizeof(p2) << endl;  // 6
	cout << strlen(p2) << endl;  // 4
	cout << endl;

	char p3[] = "abcd\\0";  // \\为一个字符
	cout << sizeof(p3) << endl;  // 7
	cout << strlen(p3) << endl;  // 6
	cout << endl;

	char p4[] = "abcd\\\0";
	cout << sizeof(p4) << endl;  // 7
	cout << strlen(p4) << endl;  // 5
	cout << endl;

	char p5[] = "ab\t\ncd\\\0";
	cout << sizeof(p5) << endl;  // 9
	cout << strlen(p5) << endl;  // 7
	cout << endl;

	system("pause");
	return 0;
}
