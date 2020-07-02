#include <iostream>
using namespace std;

class A
{
public:
    A(int x = 1, int y = 2)
    {
        _x = x;
        _y = y;
    }

    //B类天生就是A类的友元类
    class B
    {
    public:
        void Print(const A& a)
        {
            cout << a._x << " " << a._y << endl;
        }
    };
private:
    int _x;
    int _y;
};

int main()
{
    A::B b; //定义B类的对象时必须指定它的作用域是在A类
    b.Print(A());
    return 0;
}
