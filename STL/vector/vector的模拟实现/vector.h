#include <iostream>
#include <cassert>
using namespace std;

namespace MakeVector
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
	public:
		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin() const
		{
			return _start;
		}

		const_iterator end() const
		{
			return _finish;
		}

		vector()
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}

		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endofstorage = nullptr;
			}
		}

		//拷贝构造传统写法
		//vector(const vector<T>& v)
		//	: _start(nullptr)
		//	, _finish(nullptr)
		//	, _endofstorage(nullptr)
		//{
		//	_start = new T[v.capacity()];
		//	_finish = _start;
		//	_endofstorage = _start + v.capacity();
		//	for (size_t i = 0; i < v.size(); ++i)
		//	{
		//		*_finish = v[i];
		//		++_finish;
		//	}
		//}

		//拷贝构造现代写法
		vector(const vector<T>& v)
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			reserve(v.capacity());
			for (auto e : v)
			{
				push_back(e);
			}
		}

		//赋值运算符传统写法
		//vector<T>& operator=(const vector<T>& v)
		//{
		//	if (this != &v)
		//	{
		//		delete[] _start;
		//		_start = new T[v.capacity()];
		//		_finish = _start;
		//		_endofstorage = _start + v.capacity();
		//		for (size_t i = 0; i < v.size(); ++i)
		//		{
		//			*_finish = v[i];
		//			++_finish;
		//		}
		//	}
		//	return *this;
		//}

		//赋值运算符现代写法
		vector<T>& operator=(vector<T> v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstorage, v._endofstorage);
			return *this;
		}

		void reserve(size_t new_capacity)
		{
			if (new_capacity > capacity())
			{
				size_t sz = size();
				T* tmp = new T[new_capacity];
				if (_start)
				{
					//memcpy对于内置类型和自定义类型都是浅拷贝
					//memcpy(tmp, _start, sizeof(T) * sz);

					for (size_t i = 0; i < sz; ++i)
					{
						tmp[i] = _start[i];
					}
					delete[] _start;
				}
				_start = tmp;
				_finish = _start + sz;
				_endofstorage = _start + new_capacity;
			}
		}

		void resize(size_t n, const T& val = T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				if (n > capacity())
				{
					reserve(n);
				}

				while (_finish < _start + n)
				{
					*_finish = val;
					++_finish;
				}			
			}
		}

		void push_back(const T& val)
		{
			//扩容
			if (_finish == _endofstorage)
			{
				size_t new_capacity = capacity() == 0 ? 2 : capacity() * 2;
				reserve(new_capacity);
			}

			*_finish = val;
			++_finish;
		}

		void pop_back()
		{
			assert(_start < _finish);
			--_finish;
		}

		iterator insert(iterator pos, const T& val)
		{
			assert(pos <= _finish);
			//扩容
			if (_finish == _endofstorage)
			{
				size_t len = pos - _start;
				size_t new_capacity = capacity() == 0 ? 2 : capacity() * 2;
				reserve(new_capacity);
				pos = _start + len;
			}

			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = val;
			++_finish;
			return pos;
		}

		iterator erase(iterator pos)
		{
			assert(pos < _finish);
			iterator begin = pos;
			while (begin < _finish)
			{
				*(begin) = *(begin + 1);
				++begin;
			}
			--_finish;
			return pos;
		}

		T& operator[](size_t index)
		{
			assert(index < size());
			return _start[index];
		}

		const T& operator[](size_t index) const
		{
			assert(index < size());
			return _start[index];
		}

		const size_t size() const
		{
			return _finish - _start;
		}

		const size_t capacity() const
		{
			return _endofstorage - _start;
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};
}
