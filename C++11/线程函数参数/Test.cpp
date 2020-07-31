//线程函数参数
#include <iostream>
using namespace std;
#include <thread>
void ThreadFunc1(int& x)
{
    x += 10;
}

void ThreadFunc2(int* x)
{
    *x += 10;
}

int main()
{
    int a = 10;
    // 在线程函数中对a修改，不会影响外部实参，因为：线程函数参数虽然是引用方式，但其实际引用的是线程栈中的拷贝
    thread t1(ThreadFunc1, a);
    t1.join();
    cout << a << endl;

    // 如果想要通过形参改变外部实参时，必须借助std::ref()函数
    thread t2(ThreadFunc1, std::ref(a));
    t2.join();
    cout << a << endl;

    // 地址的拷贝
    thread t3(ThreadFunc2, &a);
    t3.join();
    cout << a << endl;
    return 0;
}
