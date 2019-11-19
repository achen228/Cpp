#include <iostream>
#include <queue>
using namespace std;

void test_queue()
{
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	while (!q.empty())
	{
		cout << q.front() << endl;
		q.pop();
	}
}

int main()
{
	test_queue();

	system("pause");
	return 0;
}
