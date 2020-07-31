//RAII的方式对线程对象进行封装
#include <thread>
class mythread
{
public:
    explicit mythread(std::thread& t)
        : m_t(t)
    {}

    ~mythread()
    {
        if (m_t.joinable())
        {
            m_t.join();
        }        
    }

    mythread(const mythread&) = delete;
    mythread& operator=(const mythread&) = delete;
private:
    std::thread& m_t;
};

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
    thread t(ThreadFunc);
    mythread q(t);
    if (DoSomething())
    {
        return -1;
    }     
    return 0;
}
