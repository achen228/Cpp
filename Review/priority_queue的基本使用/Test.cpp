#include <iostream>
#include <queue>
#include <functional>
using namespace std;

void Test()
{
    priority_queue<int> pq;
    pq.push(9);
    pq.push(5);
    pq.push(2);
    pq.push(7);
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

void Test2()
{
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(9);
    pq.push(5);
    pq.push(2);
    pq.push(7);
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

int main()
{
    Test2();
    return 0;
}
