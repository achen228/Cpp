#include<memory>
class A
{
public:
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a1;
	int _a2;
};

template<class T>
struct DeleteArry
{
	void operator()(T* pa)
	{
		delete[] pa;
	}
};

struct Free
{
	void operator()(void* p)
	{
		cout << "free(p)" << endl;

		free(p);
	}
};

int main()
{
	std::shared_ptr<A> sp1(new A);
	std::shared_ptr<A> sp2(new A[2], DeleteArry<A>());
	std::shared_ptr<A> sp3((A*)malloc(sizeof(A)), Free());

	return 0;
}
