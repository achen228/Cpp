// 类模板引入  C->C++变化
#include <iostream>
using namespace std;

// C
typedef int DataType;
struct Seqlist 
{
	DataType* _array;
	size_t _size;
	size_t _capacity;
};

void SeqlistPushBack(Seqlist* ps, DataType x);
void SeqlistPopBack(Seqlist* ps);

// C++
class Seqlist 
{
public:
	void PushBack(DataType x);
	void PopBack();

private:
	DataType* _array;
	size_t _size;
	size_t _capacity;
};
