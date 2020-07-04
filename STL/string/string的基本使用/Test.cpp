// string类的用法
#include <iostream>
#include <string>
using namespace std;

void test_string1() 
{
	string s1;
	cout << s1 << endl;
	cout << s1.c_str() << endl;

	string s2("hello, wrold");
	cout << s2 << endl;
	cout << s2.c_str() << endl;

	string s3(100, 'x');
	cout << s3 << endl;

	string s4(s3);
	cout << s4 << endl;

	string s5(s2, 0, 5); // 从0开始取5个字符
	cout << s5 << endl;
}


void test_string2()
{
	string s("hello");
	// push_back 只能插入一个字符， append 可以插入字符串
	s.push_back(' ');
	s.append("world");
	cout << s << endl;

	string w("world");
	s += '-';
	s += "change ";
	s += w;
	cout << s << endl;
}


void test_string3() 
{
	//string s("hello");
	//// 一般使用 size
	//cout << s.size() << endl;
	//cout << s.length() << endl;
	//cout << s.max_size() << endl;

	//s += "xxxxxxxxxxxxxxxxxxx";
	//cout << s.size() << endl;
	//cout << s.capacity() << endl;
	//s.clear(); // 清空数据
	//cout << s << endl;
	//cout << s.size() << endl;
	//cout << s.capacity() << endl;


	//resize()，设置大小（size）;
	//reserve()，设置容量（capacity）;
	//size()是分配容器的内存大小，而capacity()只是设置容器容量大小，但并没有真正分配内存。
	//打个比方：正在建造的一辆公交车，车里面可以设置40个座椅（reserve(40); ），这是它的容量，
	//但并不是说它里面就有了40个座椅，只能说明这部车内部空间大小可以放得下40张座椅而已。
	//而车里面安装了40个座椅(resize(40);)，这个时候车里面才真正有了40个座椅，这些座椅就可以使用了


	//string s("hello");
	//s.resize(13);
	//s.resize(20, 'a');
	//cout << s << endl;
	//cout << s.c_str() << endl;
	//cout << s.size() << endl;
	//cout << s.capacity() << endl;


	//string s("hello");
	//s.reserve(10);
	//s.reserve(20);
	//cout << s << endl;
	//cout << s.size() << endl;
	//cout << s.capacity() << endl;


	// capacity 大约以 size 的1.5倍增长
	string s;
	s.reserve(1000);
	s.resize(1000);
	size_t sz = s.capacity();
	cout << "capacity changed: " << sz << '\n';
	cout << "making s grow:\n";
	for (int i = 0; i < 1000; ++i) 
	{
		s += 'c';
		//s[i] = 'c';
		if (sz != s.capacity()) 
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}


void test_string4()
{
	string s1("hello");
	string s2(s1);   // 拷贝构造  
	string s3 = s1;  // 拷贝构造
	string s4("world");
	cout << s2 << endl;
	s1 = s4;  // 赋值 
	cout << s1 << endl;

	s1[4] = 'x'; // 修改字符
	// 遍历字符串中的每一个字符并打印
	for (size_t i = 0; i < s1.size(); ++i)
	{
		cout << s1[i] << " "; // 调用 operator[]
		//cout << s1.at(i) << " ";  // 早期接口at
	}
	cout << endl;

	// 正向迭代器 [)
	string::iterator it1 = s1.begin();
	while (it1 != s1.end()) 
	{
		//++(*it1);  // 可读可写
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;

	// 反向迭代器 (]
	string::reverse_iterator rit1 = s1.rbegin();
	while (rit1 != s1.rend()) 
	{
		cout << *rit1 << " ";
		++rit1;
	}
	cout << endl;

	// const 迭代器
	const string s5("122333");
	string::const_iterator it5 = s5.begin();
	while (it5 != s5.end())
	{
		//++(*it5);  // const 迭代器不可修改内容
		cout << *it5 << " ";
		++it5;
	}
	cout << endl;
	////example:
	////将 str 类型转成 int 类型，需要用 const 迭代器
	//int StrToInt(const string& s) 
	//{}

	// C++11 范围 for 循环
	for (auto ch : s5) 
	{
		cout << ch << " ";
	}
	cout << endl;

	// 使用范围 for 循环改变内容赋值时  要用->引用
	for (auto& ch : s4) 
	{
		ch = 'x';
	}
	cout << s4 << endl;
}


void test_string5()
{
	string s1("world");

	// 插入
	s1.insert(s1.begin(), ' ');
	s1.insert(0, "hello");
	cout << s1 << endl;

	//// 删除
	//s1.erase(++s1.begin(), --s1.end()); // 保留hd
	//cout << s1 << endl;

	// 删除空格（用迭代器）
	// string::iterator it1 = s1.begin(); // 使用繁琐，C++11中可用下面的 auto
	auto it1 = s1.begin();
	while (it1 != s1.end())
	{
		if (*it1 == ' ')
		{
			s1.erase(it1);
		}
		++it1;
	}
	cout << s1 << endl;

	//// 使用 find 找到空格后再删除
	//auto pos = std::find(s1.begin(), s1.end(), ' ');
	//if (pos != s1.end())
	//{
	//	s1.erase(pos);
	//	cout << s1 << endl;
	//}

	string file1("string.cpp.gz");
	// rfind(); 从字符串后向前查找
	size_t pos = file1.rfind('.');
	// substr(); 从pos开始取后面的字符串
	string suffix = file1.substr(pos);
	cout << suffix << endl;

	string url1("http://www.cplusplus.com/reference/string/string/find/");
	size_t start = url1.find("://");
	start += 3;
	size_t finish = url1.find('/', start);
	string address = url1.substr(start, finish - start);
	cout << address << endl;
}


void test_string6()
{
	string str1;
	cin >> str1;
	cout << str1 << endl;

	string str2;
	cin >> str2;
	cout << str2 << endl;

	cout << (str1 < str2) << endl;
	cout << (str1 == str2) << endl;

	cout << str1 + "1111" << endl;
	cout << "1111" + str1 << endl;
}

int main()
{
	test_string1();

	system("pause");
	return 0;
}
