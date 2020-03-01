//内部类
//如果一个类定义在另一个类的内部，这个内部类就叫做内部类。注意此时这个内部类是一个独立的类，
//   它不属于外部类，更不能通过外部类的对象去调用内部类。外部类对内部类没有任何优越的访问权限。
//注意：内部类就是外部类的友元类。
//注意友元类的定义，内部类可以通过外部类的对象参数来访问外部类中的所有成员。但是外部类不是内部类的友元。
#include <iostream>
using namespace std;

class A 
{
private:    
	static int k;    
	int h; public:    
		class B 
		{
		public:        
			void foo(const A& a) 
			{
				cout << k << endl;          
				cout << a.h << endl;      
			}    
		}; 
};

int A::k = 1;

int main() 
{ 
	A::B b;    
	b.foo(A());    

	system("pause");
	return 0; 
}
