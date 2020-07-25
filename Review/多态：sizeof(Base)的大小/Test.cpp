//sizeof(Base)的大小
#include <iostream>
using namespace std;

class Base
{
public:
    virtual void Func1()
    {
        cout << "Func1()" << endl;
    }

    virtual void Func2()
    {
        cout << "Func2()" << endl;
    }
private:
    int _b = 1;
};

int main()
{
    cout << sizeof(Base) << endl;
    return 0;
}
