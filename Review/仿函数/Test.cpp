#include <iostream>
using namespace std;
namespace Functional
{
    template <class T>
    struct less
    {
        bool operator()(const T& x, const T& y)
        {
            return x < y;
        }
    };

    template <class T>
    struct greater
    {
        bool operator()(const T& x, const T& y)
        {
            return x > y;
        }
    };
}

int main()
{
    Functional::less<int> lessFun;
    cout << lessFun(1, 2) << endl;

    Functional::greater<int> greaterFun;
    cout << greaterFun(1, 2) << endl;
    return 0;
}
