#include <iostream>
using namespace std;

template<class T1, class T2>
class Data
{
public:
    Data() { cout << "原模板类:Data<T1, T2>" << endl; }
private:
    T1 _d1;
    T2 _d2;
};

template<>
class Data<int, char>
{
public:
    Data() { cout << "全特化:Data<int, char>" << endl; }
private:
};

template<class T2>
class Data<int, T2>
{
public:
    Data() { cout << "偏特化:Data<int, T2>" << endl; }
private:
};

template<class T1, class T2>
class Data<T1*, T2*>
{
public:
    Data() { cout << "偏特化:Data<T1*, T2*>" << endl; }
private:
};

template<class T1, class T2>
class Data<T1&, T2&>
{
public:
    Data() { cout << "偏特化:Data<T1&, T2&>" << endl; }
private:
};

int main()
{
    Data<int, int> d1; //偏特化Data<int, T2>
    Data<int, char> d2; //全特化Data<int, char>
    Data<double, double> d3; //原模板类Data<T1, T2>

    Data<char*, char*> d4; //偏特化Data<T1*, T2*>
    Data<int*, char*> d5; //偏特化Data<T1*, T2*>

    Data<char&, char&> d6; //偏特化Data<T1&, T2&>
    Data<int&, char&> d7; //偏特化Data<T1&, T2&>
    return 0;
}
