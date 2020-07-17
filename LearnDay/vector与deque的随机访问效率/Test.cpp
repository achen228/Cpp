#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
using namespace std;

int main()
{
    vector<int> v;
    deque<int> d;
    const int n = 1000000;
    srand((unsigned int)time(0));
    for (int i = 0; i < n; ++i)
    {
        int val = rand();
        v.push_back(val);
        d.push_back(val);
    }

    int begin1 = clock();
    sort(v.begin(), v.end());
    int end1 = clock();

    int begin2 = clock();
    sort(d.begin(), d.end());
    int end2 = clock();

    cout << end1 - begin1 << endl;
    cout << end2 - begin2 << endl;
    return 0;
}
