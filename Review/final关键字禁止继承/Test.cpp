//C++11 final关键字禁止继承
#include <iostream>
#include <string>
using namespace std;

class A final
{
public:
	A()
	{}
};

class B : public A
{

};

int main()
{
	return 0;
}
