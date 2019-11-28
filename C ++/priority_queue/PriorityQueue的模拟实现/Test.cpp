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
