#include "Stack.h"

void TestStack()
{
	Stack<int, vector<int>> s1;
	s1.Push(1);
	s1.Push(2);
	s1.Push(3);
	s1.Push(4);
	while (!s1.Empty())
	{
		cout << s1.Top() << endl;
		s1.Pop();
	}

	Stack<int, list<int>> s2;
	s2.Push(1);
	s2.Push(2);
	s2.Push(3);
	s2.Push(4);
	while (!s2.Empty())
	{
		cout << s2.Top() << endl;
		s2.Pop();
	}

	Stack<int> s3;
	s3.Push(1);
	s3.Push(2);
	s3.Push(3);
	s3.Push(4);
	while (!s3.Empty())
	{
		cout << s3.Top() << endl;
		s3.Pop();
	}

	Stack<int, deque<int>> s;
	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(4);
	while (!s.Empty())
	{
		cout << s.Top() << endl;
		s.Pop();
	}
}

int main()
{
	TestStack();

	system("pause");
	return 0;
}
