//计算日期到天数的转换
//根据输入的日期，计算是这一年的第几天。
//详细描述：
//输入某年某月某日，判断这一天是这一年的第几天？
#include <iostream>
using namespace std;

int main()
{
    int year, month, day;
    int monthDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31,31, 30, 31, 30, 31 };
    while (cin >> year >> month >> day)
    {
        int n = 0;
        for (int i = 0; i < month; ++i)
        {
            n += monthDay[i];
        }

        n += day;

        if (month > 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
        {
            n += 1;
        }
        cout << n << endl;
    }
    return 0;
}
