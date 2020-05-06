// 现代写法->实现一个String
#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

class String
{
public:
	typedef char* Iterator;
	typedef const char* ConstIterator;
	
	Iterator Begin() 
	{
		return _str;
	}
	
	Iterator End() 
	{
		return _str + _size;
	}

	ConstIterator Begin() const
	{
		return _str;
	}
	
	ConstIterator End() const
	{
		return _str + _size;
	}

	String(const char* str = "")
		: _str(nullptr)
		, _capacity(0)
	{
		_size = strlen(str);
		Reserve(_size);
		strcpy(_str, str);
	}

	// s2(s1)
	String(const String& s)
		: _str(nullptr)
		, _size(0)
		, _capacity(0)
	{
		String tmp(s._str);  // 构造
		this->Swap(tmp);
	}

	// s1 = s3
	String& operator=(String s)
	{
		this->Swap(s);
		return *this;
	}

	// s1.Swap(s2)
	void Swap(String& s)
	{
		std::swap(_str, s._str);
		std::swap(_size, s._size);
		std::swap(_capacity, s._capacity);
	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}
	}

	void PushBack(char ch)
	{
		if (_size = _capacity)
		{
			Reserve(_capacity * 2);
		}
		_str[_size] = ch;
		++_size;
		_str[_size] = '\0';
	
		//Insert(_size, ch);
	}
	
	void Append(const char* str)
	{
		size_t len = strlen(str);
		if (_size + len > _capacity) 
		{
			Reserve(_size + len);
		}
		strcpy(_str + _size, str);
		_size += len;
	
		//Insert(_size, str);
	}
	
	String& operator+=(char ch) 
	{
		PushBack(ch);
		return *this;
	}
	
	String& operator+=(const char* str)
	{
		Append(str);
		return *this;
	}
	
	String operator+(char ch) const
	{
		String tmp(*this);
		tmp.PushBack(ch);
		return tmp;
	}
	
	String& operator+(const char* str) const
	{
		String tmp(*this);
		tmp.Append(str);
		return tmp;
	}
	
	// 在 pos 前插入一个字符
	void Insert(size_t pos, char ch) 
	{
		assert(pos <= _size);
	
		if (_size = _capacity) 
		{
			Reserve(_capacity * 2);
		}
	
		for (int i = _size; i >= (int)pos; --i)
		{
			_str[i + 1] = _str[i];
		}
	
		_str[pos] = ch;
		_size++;
	}
	
	// 在 pos 前插入字符串
	void Insert(size_t pos, const char* str)
	{
		size_t len = strlen(str);
		if (len + _size > _capacity) 
		{
			Reserve(len + _size);
		}
	
		int end = _size;
		while (end >= (int)pos) 
		{
			_str[end + len] = _str[end];
			--end;
		}
		strncpy(_str + pos, str, len);
		_size += len;

		// 避免去强制转换pos类型
		//size_t end = _size + len;
		//while (end > pos + len - 1) 
		//{
		//	_str[end] = _str[end - len];
		//	--end;
		//}
	}
	
	// 从 pos 开始删除 len 个字符
	void Erase(size_t pos = 0, size_t len = npos)
	{
		if (pos + len >= _size) 
		{
			_size = pos;
			_str[_size] = '\0';
		}
		else 
		{
			size_t start = pos + len;
			strcpy(_str + pos, _str + start);
			_size -= len;
		}
	}
	
	// 查找第 pos 个字符
	size_t Find(char ch, size_t pos = 0) 
	{
		for (size_t i = pos; i < _size; ++i)
		{
			if (_str[i] == ch) 
			{
				return i;
			}
		}
		return npos;
	}
	
	// 从 pos 开始查找字符串
	size_t Find(const char* str, size_t pos = 0) 
	{
		const char* ret = strstr(_str + pos, str);
		if (ret == nullptr) 
		{
			return npos;
		}
		else 
		{
			return ret - _str;
		}
	}
	
	bool operator<(const String& s) const 
	{
		size_t i = 0;
		size_t j = 0;
		while (i < _size && j < s._size)
		{
			if (_str[i] < s[j])
			{
				return true;
			}
			else if (_str[i] > s[j])
			{
				return false;
			}
			else 
			{
				++i;
				++j;
			}
		}
	
		// "hello"  "hello"   false
		// "hello!"  "hello"  false
		// "hello"  "hello!"  true
		if (j < s._size) 
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
	
	bool operator<=(const String& s) const
	{
		return *this < s || *this == s;
	}
	
	bool operator>(const String& s) const 
	{
		return !(*this <= s);
	}
	
	bool operator>=(const String& s) const 
	{
		return !(*this < s);
	}
	
	bool operator==(const String& s) const
	{
		size_t i = 0;
		size_t j = 0;
		while (i < _size && j < s._size) 
		{
			if (_str[i] != s[j]) 
			{
				return false;
			}
			else 
			{
				++i;
				++j;
			}
		}
	
		if (i == _size && j == s._size) 
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
	
	bool operator!=(const String& s) const
	{
		return !(*this == s);
	}

	char& operator[](size_t pos)
	{
		assert(pos < _size);
		return _str[pos];
	}

	const char& operator[](size_t pos) const
	{
		assert(pos < _size);
		return _str[pos];
	}

	char* c_str() const
	{
		return _str;
	}

	size_t Size() const
	{
		return _size;
	}

	size_t Capacity() const
	{
		return _capacity;
	}

	void Reserve(size_t n) 
	{
		if (n == 0 || n > _capacity) 
		{
			//size_t newsize = (n + 7) & (~7);  // 神级写法
	
			size_t newsize = n;
			if (n % 8 != 0) 
			{
				newsize = (n / 8 + 1) * 8;  // 对齐到8的倍数
			}
			else
			{
				newsize = n + 8;
			}
			char* newstr = new char[newsize];
	
			if (_str) 
			{
				strcpy(newstr, _str);
			}
			
			delete[] _str;
			_str = newstr;
			_capacity = newsize - 1;  // 有一个留给\0
		}	
	}
	
	void Resize(size_t n, char ch = '\0') 
	{
		if (n <= _size) 
		{
			_size = n;
			_str[_size] = '\0';
		}
		else 
		{
			Reserve(n);
			for (size_t i = _size; i < n; ++i)
			{
				_str[i] = ch;
				++_size;
			}
			_str[_size] = '\0';
		}
	}
	
private:
	char* _str;
	size_t _size;
	size_t _capacity;
	static size_t npos;
};

size_t String::npos = -1;
