// join()的误用一
void ThreadFunc()
{ 
    cout << "ThreadFunc()" << endl;
}

bool DoSomething()
{ 
    return false;
}

int main()
{
    std::thread t(ThreadFunc);
    if (!DoSomething())
        return -1;

    t.join();
    return 0;
}
//说明：如果DoSomething()函数返回false,主线程将会结束，join()没有调用，线程资源没有回收，造成资源泄漏。


// join()的误用二
void ThreadFunc()
{ 
    cout << "ThreadFunc()" << endl;
}

void Test1()
{ 
    throw 1;
}

void Test2()
{
    int* p = new int[10];
    std::thread t(ThreadFunc);
    try
    {
        Test1();
    }
    catch (...)
    {
        delete[] p;
        throw;
    }

    t.join();
}
