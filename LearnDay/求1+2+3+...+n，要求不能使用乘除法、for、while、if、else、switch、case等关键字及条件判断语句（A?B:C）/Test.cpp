#include <iostream>
using namespace std;

class Sum
{
public:
    Sum()
    {
        _sum += _i;
        ++_i;
    }

    static void Init()
    {
        _sum = 0;
        _i = 1;
    }

    static int GetSum()
    {
        return _sum;
    }
private:
    static int _sum;
    static int _i;
};

int Sum::_sum = 0;
int Sum::_i = 1;

class Solution
{
public:
    int Sum_Solution(int n)
    {
        Sum::Init();
        Sum* p = new Sum[n];
        return Sum::GetSum();
    }
};

int main()
{
    Solution so;
    cout << so.Sum_Solution(5) << endl;
    return 0;
}
