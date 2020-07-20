#include <iostream>
#include <string>
using namespace std;

template<class T>
bool IsEqual(T& left, T& right)
{
    return left == right;
}

template<>
bool IsEqual<char*>(char*& left, char*& right)
{
    return strcmp(left, right) == 0;
}

void Test()
{
    char str1[] = "hello";
    char str2[] = "hello";
    char* p1 = str1;
    char* p2 = str2;
    if (IsEqual(p1, p2))
    {
        cout << "equal" << endl;
    }
}

int main()
{
    Test();
    return 0;
}
