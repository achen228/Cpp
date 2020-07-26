//多继承中虚表的存储
#include <iostream>
using namespace std;

class Base1
{
public:
    virtual void func1() { cout << "Base1::func1" << endl; }
    virtual void func2() { cout << "Base1::func2" << endl; }
private:
    int b1;
};

class Base2
{
public:
    virtual void func1() { cout << "Base2::func1" << endl; }
    virtual void func2() { cout << "Base2::func2" << endl; }
private:
    int b2;
}; 

class Derive : public Base1, public Base2
{
public:
    virtual void func1() { cout << "Derive::func1" << endl; }
    virtual void func3() { cout << "Derive::func3" << endl; }
private:
    int d1;
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
    Derive d;
    //Base1虚表
    PrintVFTable((VFT_PTR*)(*(int*)&d));
    //Base2虚表
    PrintVFTable((VFT_PTR*)(*(int*)((char*)&d + sizeof(Base1))));
    return 0;
}
