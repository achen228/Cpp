#include <iostream>
#include <stack>
using namespace std;

void test_stack()
{
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	
	while (!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}
}

int main()
{
	test_stack();

	system("pause");
	return 0;
}
