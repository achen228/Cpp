// 类模板
// 类名：SeqList
// 类型：SeqList<T>
#include <iostream>
#include <assert.h>
using namespace std;

template<class T>
class SeqList 
{
public:
	SeqList() 
	{
		_array = new T[10];
		_size = 0;
		_capacity = 10;
	}

	// 可不写，编译器会默认生成
	//SeqList(const SeqList<T>& s);  // 拷贝构造函数
	//SeqList<T>& operator=(const SeqList<T>& s);  // 赋值运算符重载

	~SeqList();

	// 尾插
	void PushBack(const T& data) 
	{
		if (_size >= _capacity) 
		{
			// 增容
		}

		_array[_size] = data;
		++_size;
	}

	// 尾删
	void PopBack() 
	{
		if (_size > 0)
		{
			--_size;
		}
	}

	T& operator[](size_t index)
	{
		assert(index < _size);
		return _array[index];
	}

	//const T& operator[](size_t index) const
	//{
	//	assert(index < _size);
	//	return _array[index];
	//}

	size_t Size() const 
	{
		return _size;
	}

	void Print() const 
	{
		for (size_t i = 0; i < _size; ++i)
		{
			cout << _array[i] << " ";
		}
		cout << endl;
	}

private:
	T* _array;
	size_t _size;
	size_t _capacity;
};

// 类外面定义成员的写法
template<class T>
SeqList<T>::~SeqList()  // 需要指定类型 SeqList<T>
{
	delete[] _array;
}

int main() 
{
	SeqList<int> s1;
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);
	s1.PushBack(4);

	for (size_t i = 0; i < s1.Size(); ++i) 
	{
		if (s1[i] % 2 == 0)
		{
			s1[i] *= 2;
		}
	}

	//s1.Print();

	for (size_t i = 0; i < s1.Size(); ++i)
	{
		cout << s1[i] << " ";
		cout << s1.operator[](i) << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
