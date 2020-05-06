#include "Date.h"

void TestDate() 
{
	Date d1(2019, 1, 1);
	d1 += 2000;
	d1.Print();

	d1 -= 2000;
	d1.Print();

	Date d2 = d1 + 2000;
	cout << d2 - d1 << endl;
	cout << d1 - d2 << endl;
	
}

int main() 
{
	TestDate();
	system("pause");
	return 0;
}
