//单继承中虚表的存储
#include <iostream>
using namespace std;

class Base
{
public:
    virtual void func1() { cout << "Base::func1" << endl; }
    virtual void func2() { cout << "Base::func2" << endl; }
private:
    int _a;
};

class Derive :public Base
{
public:
    virtual void func1() { cout << "Derive::func1" << endl; }
    virtual void func3() { cout << "Derive::func3" << endl; }
    virtual void func4() { cout << "Derive::func4" << endl; }
private:
    int _b;
};

//函数指针重定义
typedef void(*VFT_PTR)();

void PrintVFTable(VFT_PTR vftable[])
{
    for (size_t i = 0; vftable[i] != 0; ++i)
    {
        cout << "VFT_PTR:[" << i << "]:" << vftable[i] << "->";
        VFT_PTR f = vftable[i];
        f();
    }
    cout << endl;
}

int main()
{
    Base b;
    //取对象中前四个字节存的虚表指针
    PrintVFTable((VFT_PTR*)(*(int*)&b));

    Derive d;
    PrintVFTable((VFT_PTR*)(*(int*)&d));
    return 0;
}
