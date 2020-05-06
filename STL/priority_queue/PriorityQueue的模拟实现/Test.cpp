#include"PriorityQueue.h"

// 仿函数 函数对象
void TestPriorityQueue1()
{
	Less<int> less;
	Greater<int> greater;

	cout << less(1, 3) << endl;
	cout << less.operator()(1, 3) << endl;
	cout << Less<int>()(1, 3) << endl;
	cout << greater(1, 3) << endl;
}


void TestPriorityQueue2()
{
	PriorityQueue<int, vector<int>, Less<int>> pq1;
	pq1.Push(4);
	pq1.Push(3);
	pq1.Push(1);
	pq1.Push(9);
	pq1.Push(7);
	while (!pq1.Empty())
	{
		cout << pq1.Top() << endl;
		pq1.Pop();
	}
}

int main()
{
	TestPriorityQueue2();

	system("pause");
	return 0;
}
