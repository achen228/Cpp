#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

void Test()
{
    vector<int> v;
    v.push_back(9);
    v.push_back(5);
    v.push_back(2);
    v.push_back(7);
    sort(v.begin(), v.end());
    for (auto e : v)
    {
        cout << e << " ";
    }
    cout << endl;
}

void Test2()
{
    vector<int> v;
    v.push_back(9);
    v.push_back(5);
    v.push_back(2);
    v.push_back(7);
    sort(v.begin(), v.end(), greater<int>());
    for (auto e : v)
    {
        cout << e << " ";
    }
    cout << endl;
}

int main()
{
    Test();
    Test2();
    return 0;
}
