#include "Queue.h"

void TestQueue()
{
	//Queue<int, vector<int>> q; vector不支持头删
	Queue<int, list<int>> q1;
	q1.Push(1);
	q1.Push(2);
	q1.Push(3);
	q1.Push(4);
	while (!q1.Empty())
	{
		cout << q1.Front() << endl;
		q1.Pop();
	}

	Queue<int> q2;
	q2.Push(1);
	q2.Push(2);
	q2.Push(3);
	q2.Push(4);
	while (!q2.Empty())
	{
		cout << q2.Front() << endl;
		q2.Pop();
	}
}

int main()
{
	TestQueue();

	system("pause");
	return 0;
}
