#include "List.h"

void TestList1()
{
	List<int> l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);

	List<int>::iterator it = l.begin();
	while (it != l.end()) 
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : l)
	{
		cout << e << " ";
	}
	cout << endl;
}


void TestList2()
{
	List<AA> laa;
	AA aa1 = { 1, 2 };
	laa.PushBack(aa1);
	laa.PushBack({ 3, 4 });

	List<AA>::iterator ita = laa.begin();
	while (ita != laa.end())
	{
		//cout << (*ita)._a1 << ' ' << (*ita)._a2 << endl;
		cout << ita->_a1 << ' ' << ita->_a2 << endl;
		++ita;
	}

	AA* pa = new AA;
	pa->_a1 = 10;
	cout << (*pa)._a1 << endl;

	int* pi = new int;
	cout << *pi << endl;
}


void TestList3()
{
	List<int> l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);

	List<int> copy(l);
	for (auto e : copy)
	{
		cout << e << " ";
	}
	cout << endl;

	cout << l.Size() << endl;
	cout << l.Empty() << endl;
}


int main()
{
	TestList3();

	system("pause");
	return 0;
}
