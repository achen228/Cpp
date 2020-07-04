#include <iostream>
using namespace std;

template<typename T>
void Swap(T& x, T& y)
{
    T tmp = x;
    x = y;
    y = tmp;
}

int main()
{
    double a = 1.0, b = 2.2;
    Swap<double>(a, b);
    cout << a << " " << b << endl;
    return 0;
}
