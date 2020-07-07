//字符串最后一个单词的长度
//题目描述
//计算字符串最后一个单词的长度，单词以空格隔开。
//输入描述 :
//一行字符串，非空，长度小于5000。
//输出描述 :
//整数N，最后一个单词的长度。
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    size_t pos = s.rfind(' ');
    cout << s.size() - (pos + 1) << endl;
    return 0;
}
