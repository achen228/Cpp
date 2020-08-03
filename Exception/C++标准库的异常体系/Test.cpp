//C++标准库的异常体系
int main()
{
    try
    {
        vector<int> v(10, 5);
        // 这里如果系统内存不够也会抛异常
        v.reserve(1000000000);

        // 这里越界会抛异常
        v.at(10) = 100;
    }
    catch (const exception& e) // 这里捕获父类对象就可以
    {
        cout << e.what() << endl;
    }
    catch (...)
    {
        cout << "Unkown Exception" << endl;
    }
    return 0;
}
