#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    bool IsChar(char ch)
    {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            return true;
        }
        return false;
    }

    string reverseOnlyLetters(string S)
    {
        int begin = 0;
        int end = S.size() - 1;
        while (begin < end)
        {
            while (begin < end && !IsChar(S[begin]))
            {
                ++begin;
            }

            while (begin < end && !IsChar(S[end]))
            {
                --end;
            }

            swap(S[begin], S[end]);
            ++begin;
            --end;
        }
        return S;
    }
};
