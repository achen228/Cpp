// priority_queue的使用
#include <iostream>
#include <queue>
using namespace std;

void test_priority_queue()
{
	// 小堆
	priority_queue<int, vector<int>, greater<int>> pq1;  
	pq1.push(4);
	pq1.push(3);
	pq1.push(1);
	pq1.push(9);
	pq1.push(7);
	while (!pq1.empty())
	{
		cout << pq1.top() << endl;
		pq1.pop();
	}

	// 大堆，如果没有说明less或greater，默认less
	priority_queue<int, vector<int>, less<int>> pq2;  
	pq2.push(4);
	pq2.push(3);
	pq2.push(1);
	pq2.push(9);
	pq2.push(7);
	while (!pq2.empty())
	{
		cout << pq2.top() << endl;
		pq2.pop();
	}
}

int main()
{
	test_priority_queue();

	system("pause");
	return 0;
}
