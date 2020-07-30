//函数对象与lambda表达式
class Rate
{
public:
    Rate(double rate)
        : _rate(rate)
    {}

    double operator()(double money, int year)
    {
        return money * _rate * year;
    }
private:
    double _rate;
};

int main()
{
    // 函数对象
    double rate = 0.49;
    Rate r1(rate);
    r1(10000, 2);

    // lambda
    auto r2 = [=](double monty, int year)->double {return monty * rate * year; };
    r2(10000, 2);
    return 0;
}
