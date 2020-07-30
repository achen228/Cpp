//lambda表达式之间不能相互赋值
void (*PF)();
int main()
{
    auto f1 = [] {cout << "hello world" << endl; };
    auto f2 = [] {cout << "hello world" << endl; };
    //f1 = f2; // 编译失败--->提示找不到operator=()
    //允许使用一个lambda表达式拷贝构造一个新的副本
    auto f3(f2);
    f3();
    //可以将lambda表达式赋值给相同类型的函数指针
    PF = f2;
    PF();
    return 0;
}
