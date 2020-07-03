#include "string.hpp"

void Test1()
{
	MakeString::string s1("hello");
	MakeString::string s2(s1);
	cout << s1.c_str() << endl;
	cout << s2.c_str() << endl;

	MakeString::string s3("world");
	s1 = s3;
	cout << s1.c_str() << endl;
}

void Test2()
{
	MakeString::string s1("hello");
	for (size_t i = 0; i < s1.size(); ++i)
	{
		s1[i] += 1;
		cout << s1[i] << " ";
	}
	cout << endl;

	MakeString::string::iterator it1 = s1.begin();
	while (it1 != s1.end())
	{
		--(*it1);
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;

	const MakeString::string s2("world");
	for (size_t i = 0; i < s2.size(); ++i)
	{
		cout << s2[i] << " ";
	}
	cout << endl;

	MakeString::string::const_iterator it2 = s2.begin();
	while (it2 != s2.end())
	{
		cout << *it2 << " ";
		++it2;
	}
	cout << endl;

	for (auto ch : s1)
	{
		cout << ch << " ";
	}
	cout << endl;

	for (auto& ch : s1)
	{
		ch += 1;
		cout << ch << " ";
	}
	cout << endl;
}

void Test3()
{
	MakeString::string s1("hello");
	s1.push_back('-');
	cout << s1.c_str() << endl;

	s1.append("world");
	cout << s1.c_str() << endl;

	s1 += '!';
	s1 += "nihao world!";
	cout << s1.c_str() << endl;
}

void Test4()
{
	MakeString::string s1("hello");
	s1.insert(5, "world");
	cout << s1.c_str() << endl;
	s1.insert(5, '-');
	cout << s1.c_str() << endl;

	s1.erase(5, 6);
	cout << s1 << endl;

	cout << s1.find('e') << endl;
	cout << s1.find("ll") << endl;
}

void Test5()
{
	MakeString::string s1("hello");
	cout << s1 << endl;
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;

	s1.reserve(15);
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;

	s1.resize(20);
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
}

void Test6()
{
	MakeString::string s1("hello");
	MakeString::string s2("hello!");
	MakeString::string s3("hello");
	cout << (s1 < s2) << endl;
	cout << (s1 < s3) << endl;
	cout << (s1 == s2) << endl;
	cout << (s1 == s3) << endl;
}

int main()
{
	Test5();
	return 0;
}
