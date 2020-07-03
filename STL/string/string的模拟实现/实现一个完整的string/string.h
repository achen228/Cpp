#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

namespace MakeString
{
    class string
    {
        friend ostream& operator<<(ostream& out, const string& s);
    public:
        typedef char* iterator;
        typedef const char* const_iterator;
    public:
        iterator begin()
        {
            return _str;
        }

        iterator end()
        {
            return _str + _size;
        }

        const iterator begin() const
        {
            return _str;
        }

        const iterator end() const
        {
            return _str + _size;
        }

        string(const char* str = "")
            : _str(new char[strlen(str) + 1])
            , _size(strlen(str))
            , _capacity(_size)
        {
            strcpy(_str, str);
        }

        ~string()
        {
            delete[] _str;
            _str = nullptr;
        }

        //拷贝构造传统写法
        //string(const string& s)
        //    : _str(nullptr)
        //    , _size(0)
        //    , _capacity(0)
        //{
        //    _size = s._size;
        //    _capacity = s._capacity;
        //    _str = new char[s._capacity + 1];
        //    strcpy(_str, s._str);
        //}

        //赋值运算符传统写法
        //string& operator=(const string& s)
        //{
        //    if (this != &s)
        //    {
        //        delete[] _str;
        //        _size = s._size;
        //        _capacity = s._capacity;
        //        _str = new char[s._capacity + 1];
        //        strcpy(_str, s._str);
        //        return *this;
        //    }
        //}

        //拷贝构造现代写法
        string(const string& s)
            : _str(nullptr)
            , _size(0)
            , _capacity(0)
        {
            string tmp(s._str); //调用构造函数
            this->Swap(tmp);
        }

        //赋值运算符现代写法
        string& operator=(string s)
        {
            this->Swap(s);
            return *this;
        }

        void reserve(size_t new_capacity)
        {
            char* tmp = new char[new_capacity + 1];
            if (_str)
            {
                strcpy(tmp, _str);
            }
            delete[] _str;
            _str = tmp;
            _capacity = new_capacity;
        }

        void resize(size_t n, char c = '\0')
        {
            if (n < _size)
            {
                _size = n;
                _str[_size] = '\0';              
            }
            else
            {
                if (n > _capacity)
                {
                    reserve(n);
                }
                for (size_t i = _size; i < n; ++i)
                {
                    _str[i] = c;
                }
                _size = n;
                _str[_size] = '\0';
            }
        }

        void push_back(char c)
        {
            //扩容
            if (_size == _capacity)
            {
                size_t new_capacity = _capacity == 0 ? 2 : _capacity * 2;
                reserve(new_capacity);
            }

            _str[_size++] = c;
            _str[_size] = '\0'; //注意不能忘记 \0
        }

        string& append(const char* s)
        {
            //扩容
            size_t len = strlen(s);
            if (_size + len > _capacity)
            {
                size_t new_capacity = _size + len;
                reserve(new_capacity);
            }

            //for (size_t i = 0; i < len; ++i)
            //{
            //    _str[_size++] = s[i];
            //}
            //_str[_size] = '\0';

            strcpy(_str + _size, s);
            _size += len;

            return *this;
        }

        string& operator+=(char c)
        {
            //扩容
            //if (_size == _capacity)
            //{
            //    size_t new_capacity = _capacity == 0 ? 2 : _capacity * 2;
            //    reserve(new_capacity);
            //}

            //_str[_size++] = c;
            //_str[_size] = '\0';

            push_back(c);

            return *this;
        }

        string& operator+=(const char* s)
        {
            //扩容
            //size_t len = strlen(s);
            //if (_size + len > _capacity)
            //{
            //    size_t new_capacity = _size + len;
            //    reserve(new_capacity);
            //}

            //for (size_t i = 0; i < len; ++i)
            //{
            //    _str[_size++] = s[i];
            //}
            //_str[_size] = '\0';

            //strcpy(_str + _size, s);
            //_size += len;

            append(s);

            return *this;
        }

        string& insert(size_t pos, char c)
        {
            assert(pos <= _size);
            //扩容
            if (_size == _capacity)
            {
                size_t new_capacity = _capacity == 0 ? 2 : _capacity * 2;
                reserve(new_capacity);
            }

            for (int i = _size; i >= (int)pos; --i)
            {
                _str[i + 1] = _str[i];
            }
            _str[pos] = c;
            ++_size;
            return *this;
        }

        string& insert(size_t pos, const char* s)
        {
            assert(pos <= _size);
            //扩容
            size_t len = strlen(s);
            if (_size + len > _capacity)
            {
                size_t new_capacity = _size + len;
                reserve(new_capacity);
            }

            for (int i = _size; i >= (int)pos; --i)
            {
                _str[i + len] = _str[i];
            }

            strncpy(_str + pos, s, len);
            _size += len;
            return *this;
        }

        //从pos位置开始删除len个字符
        string& erase(size_t pos = 0, size_t len = npos)
        {
            assert(pos <= _size);
            if (len >= _size - pos)
            {
                _size = pos;
                _str[_size] = '\0';
            }
            else
            {
                size_t i = pos + len;
                //while (i <= _size)
                //{
                //    _str[i - len] = _str[i];
                //    ++i;
                //}
                strcpy(_str + pos, _str + i);
                _size -= len;
            }
            return *this;
        }

        size_t find(char c, size_t pos = 0)
        {
            assert(pos <= _size);
            for (size_t i = pos; i < _size; ++i)
            {
                if (_str[i] == c)
                {
                    return i;
                }
            }
            return npos;
        }

        size_t find(const char* s, size_t pos = 0)
        {
            assert(pos <= _size);
            char* p = strstr(_str + pos, s);
            if (p == nullptr)
            {
                return npos;
            }
            else
            {
                return p - _str;
            }
        }

        bool operator==(const string& s)
        {
            return strcmp(_str, s._str) == 0;
        }

        bool operator!=(const string& s)
        {
            return !(*this == s);
        }

        bool operator>(const string& s)
        {
            return strcmp(_str, s._str) > 0;
        }

        bool operator>=(const string& s)
        {
            return *this > s || *this == s;
        }

        bool operator<(const string& s)
        {
            return !(*this >= s);
        }

        bool operator<=(const string& s)
        {
            return !(*this > s);
        }

        char& operator[](size_t index)
        {
            assert(index < _size);
            return _str[index];
        }

        const char& operator[](size_t index) const
        {
            assert(index < _size);
            return _str[index];
        }

        const char* c_str() const
        {
            return _str;
        }

        const size_t size() const
        {
            return _size;
        }

        const size_t capacity() const
        {
            return _capacity;
        }
    private:
        void Swap(string& tmp)
        {
            std::swap(_str, tmp._str);
            std::swap(_size, tmp._size);
            std::swap(_capacity, tmp._capacity);
        }
    private:
        char* _str;
        size_t _size;
        size_t _capacity;
        static size_t npos;
    };

    size_t string::npos = -1;

    ostream& operator<<(ostream& out, const string& s)
    {
        for (size_t i = 0; i < s.size(); ++i)
        {
            out << s[i];
        }
        return out;
    }
}
