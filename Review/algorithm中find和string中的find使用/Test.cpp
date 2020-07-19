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
    auto pos = find(v.begin(), v.end(), 5);
    if (pos != v.end())
    {
        cout << *pos << endl;
    }
}

void Test2()
{
    string s("hello world");
    auto pos = find(s.begin(), s.end(), ' ');
    if (pos != s.end())
    {
        s.erase(pos);
        cout << *pos << endl;
    }
    cout << s << endl;
}

void Test3()
{
    string s("hello world");
    //此处find为string类中的接口
    size_t pos = s.find("world");
    for (; pos < s.size(); ++pos)
    {
        cout << s[pos];
    }
    cout << endl;
}

int main()
{
    Test();
    Test2();
    Test3();
    return 0;
}
