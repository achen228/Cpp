#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void Test()
{
    vector<int> v;
    v.push_back(9);
    v.push_back(5);
    v.push_back(2);
    v.push_back(7);
    reverse(v.begin(), v.end());
    for (auto e : v)
    {
        cout << e << " ";
    }
    cout << endl;
}

void Test2()
{
    string s("hello world");
    reverse(s.begin() + 6, s.end());
    cout << s << endl;
}

int main()
{
    Test();
    Test2();
    return 0;
}
