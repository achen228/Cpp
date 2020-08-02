//一个线程对变量number进行加一100次，另外一个减一100次，每次操作加一或者减一之后，输出number的结果。
#include <iostream>
using namespace std;
#include <thread>
#include <mutex>

int number = 0;
mutex g_lock;

int ThreadProc1()
{
    for (int i = 0; i < 100; i++)
    {
        g_lock.lock();
        ++number;
        cout << "thread 1 :" << number << endl;
        g_lock.unlock();
    }
    return 0;
}

int ThreadProc2()
{
    for (int i = 0; i < 100; i++)
    {
        g_lock.lock();
        --number;
        cout << "thread 2 :" << number << endl;
        g_lock.unlock();
    }
    return 0;
}

int main()
{
    thread t1(ThreadProc1);
    thread t2(ThreadProc2);
    t1.join();
    t2.join();
    cout << "number:" << number << endl;
    return 0;
}
