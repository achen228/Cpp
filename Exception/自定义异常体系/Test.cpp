//自定义异常体系
class Exception
{
public:
    Exception(const char* errmsg, int errid)
        : _errmsg(errmsg)
        , _errid(errid)
    {}

    virtual string what() = 0;
protected:
    int _errid;       // 错误码
    string _errmsg;   // 错误描述
};

class SqlException : public Exception
{
public:
    SqlException(const char* errmsg, int errid)
        : Exception(errmsg, errid)
    {}

    virtual string what()
    {
        return "数据库错误:" + _errmsg;
    }
};

class NetworkException : public Exception
{
public:
    NetworkException(const char* errmsg, int errid)
        : Exception(errmsg, errid)
    {}

    virtual string what()
    {
        return "网络错误:" + _errmsg;
    }
};

void ServerStart()
{
    // 模拟一下出现问题抛异常报错
    if (rand() % 11 == 0)
    {
        throw SqlException("数据库启动失败", 1);
    }       

    if (rand() % 7 == 0)
    {
        throw NetworkException("网络连接失败", 3);
    }
   
    cout << "正常运行" << endl;
}

int main()
{
    for (size_t i = 0; i < 100; i++)
    {
        try
        {
            ServerStart();
        }
        catch (Exception& e)
        {
            cout << e.what() << endl;
        }
        catch (...)
        {
            cout << "未知异常" << endl;
        }
    }
    return 0;
}
