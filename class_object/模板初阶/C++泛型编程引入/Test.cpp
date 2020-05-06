// C++泛型编程引入
#include <iostream>
using namespace std;

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1) 
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void Print() 
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};                                                                        

namespace my 
{
	template<class T>
	void swap(T& x1, T& x2) 
	{
		T x = x1;
		x1 = x2;
		x2 = x;
	}
}

int main() 
{
	int a = 0, b = 1;
	my::swap(a, b);
	cout << a << endl;
	cout << b << endl;

	double c = 0.11, d = 0.22;
	std::swap(c, d);
	cout << c << endl;
	cout << d << endl;

	Date d1(2019, 5, 14);
	Date d2(2018, 5, 14);
	std::swap(d1, d2);
	d1.Print();
	d2.Print();

	system("pause");
	return 0;
}
