#include <iostream>
#include <deque>
using std::deque;
using std::cout;
using std::endl;

namespace MakeSTLStack
{
    template <class T, class Container = deque<T>>
    class stack
    {
    public:
        void push(const T& val)
        {
            _con.push_back(val);
        }

        void pop()
        {
            _con.pop_back();
        }

        T& top()
        {
            return _con.back();
        }

        const T& top() const
        {
            return _con.back();
        }

        bool empty()
        {
            return _con.empty();
        }

        size_t size()
        {
            return _con.size();
        }
    private:
        Container _con;
    };
}

int main()
{
    MakeSTLStack::stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    return 0;
}
