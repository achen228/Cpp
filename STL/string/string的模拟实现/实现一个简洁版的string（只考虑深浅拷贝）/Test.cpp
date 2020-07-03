#include "string.hpp"

void Test()
{
    MakeString::string s1("hello");
    MakeString::string s2(s1);
    MakeString::string s3;
    cout << s1.c_str() << endl;
    cout << s2.c_str() << endl;
    cout << s3.c_str() << endl;

    for (size_t i = 0; i < s1.size(); ++i)
    {
        cout << s1[i] << " ";
    }
    cout << endl;

    for (size_t i = 0; i < s2.size(); ++i)
    {
        s2[i] += 1;
        cout << s2[i] << " ";
    }
    cout << endl;

    MakeString::string s4;
    s4 = s1;
    cout << s4.c_str() << endl;
}
int main()
{
    Test();
    return 0;
}
