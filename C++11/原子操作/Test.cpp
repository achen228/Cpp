//原子操作
#include <atomic>
int main()
{
    atomic<int> a1(0);
    //atomic<int> a2(a1); // 编译失败
    atomic<int> a2(0);
    //a2 = a1; // 编译失败
    return 0;
}
