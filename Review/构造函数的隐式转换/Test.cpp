#if 0
class Date
{
public:
    //explicit Date(int year, int month, int day)
    //{
    //    _year = year;
    //    _month = month;
    //    _day = day;
    //}

    Date(int year, int month, int day)
    {
        _year = year;
        _month = month;
        _day = day;
    }
private:
    int _year;
    int _month;
    int _day;
};

int main()
{
    //C++11支持多参构造函数的隐式转换,但是注意要用花括号
    Date d1 = { 1, 2, 3 };
    return 0;
}
#endif


#if 0
class A
{
public:
    //explicit A(int a)
    //{
    //    _a = a;
    //}

    A(int a)
    {
        _a = a;
    }
private:
    int _a;
};

int main()
{
    //隐式类型转换，tmp(2); 在将临时变量拷贝给 x(tmp);
    A x = 2;
    return 0;
}
#endif
