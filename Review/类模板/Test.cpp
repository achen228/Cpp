#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

template<class T>
class Vector
{
public:
    Vector()
        : _arr(nullptr)
        , _size(0)
        , _capacity(0)
    {}

    ~Vector()
    {
        if (_arr)
        {
            _arr = nullptr;
            _size = _capacity = 0;
        }
    }

    void PushBack(const T& val)
    {
        //扩容
        if (_size == _capacity)
        {
            size_t new_capacity = _capacity == 0 ? 2 : _capacity * 2;
            Reserve(new_capacity);
        }

        _arr[_size++] = val;
    }

    T& operator[](size_t index)
    {
        assert(index < _size);
        return _arr[index];
    }

    const T& operator[](size_t index) const
    {
        assert(index < _size);
        return _arr[index];
    }

    size_t Size()
    {
        return _size;
    }

    size_t Capacity()
    {
        return _capacity;
    }
private:
    void Reserve(size_t new_capacity)
    {
        if (_arr)
        {
            T* tmp = new T[new_capacity];
            memcpy(tmp, _arr, sizeof(T) * _size);
            delete[] _arr;
            _arr = tmp;
        }
        else
        {
            _arr = new T[new_capacity];
        }
    }
private:
    T* _arr;
    size_t _size;
    size_t _capacity;
};

int main()
{
    Vector<int> v;
    v.PushBack(1);
    v.PushBack(2);
    v.PushBack(3);
    v.PushBack(4);

    for (int i = 0; i < v.Size(); ++i)
    {
        v[i] *= 2;
    }

    for (int i = 0; i < v.Size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}
