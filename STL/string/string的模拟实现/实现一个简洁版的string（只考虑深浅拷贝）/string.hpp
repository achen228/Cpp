#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

namespace MakeString
{
	class string
	{
	public:
		string(const char* str = "")
			: _str(new char[strlen(str) + 1])
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
		//	: _str(nullptr)
		//{
		//	_str = new char[strlen(s._str) + 1];
		//	strcpy(_str, s._str);
		//}

		//拷贝构造现代写法
		string(const string& s)
			: _str(nullptr)
		{
			string tmp(s._str);
			std::swap(_str, tmp._str);
		}

		//赋值运算符传统写法
		//string& operator=(const string& s)
		//{
		//	if (this != &s)
		//	{
		//		delete[] _str;
		//		_str = new char[strlen(s._str) + 1];
		//		strcpy(_str, s._str);
		//		return *this;
		//	}
		//}

		//赋值运算符现代写法
		string& operator=(string s)
		{
			std::swap(_str, s._str);
			return *this;
		}

		char& operator[](size_t index)
		{
			return _str[index];
		}

		const char& operator[](size_t index) const
		{
			return _str[index];
		}

		const char* c_str() const
		{
			return _str;
		}

		const size_t size() const
		{
			return strlen(_str);
		}
	private:
		char* _str;
	};
}
