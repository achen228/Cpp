//线程安全
#include <iostream>
using namespace std;
#include <thread>

unsigned long sum = 0L;

void fun(size_t num)
{
    for (size_t i = 0; i < num; ++i)
    {
        sum++;
    }    
}

int main()
{
    cout << "Before joining,sum = " << sum << std::endl;
    thread t1(fun, 10000000);
    thread t2(fun, 10000000);
    t1.join();
    t2.join();
    cout << "After joining,sum = " << sum << std::endl;
    return 0;
}
