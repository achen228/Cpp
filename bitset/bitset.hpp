#pragma once
#include <vector>

namespace BitSet
{
	class bitset
	{
	public:
		bitset(size_t N)
		{
			_bs.resize(N / 32 + 1, 0);
			_num = 0;
		}

		//将某一位设置成1
		void set(size_t x)
		{
			size_t index = x / 32; // 算出映射的位置在第几个整型
			size_t pos = x % 32;   // 算出x在整型的第几个位

			_bs[index] |= (1 << pos); // 第pos个位置成1
		}

		//将某一位设置成0
		void reset(size_t x)
		{
			size_t index = x / 32; // 算出映射的位置在第几个整型
			size_t pos = x % 32;   // 算出x在整型的第几个位

			_bs[index] &= ~(1 << pos); // 第pos个位置成0
		}

		// 判断x在不在(也就是说x映射的位是否为1)
		bool test(size_t x)
		{
			size_t index = x / 32; // 算出映射的位置在第几个整型
			size_t pos = x % 32;   // 算出x在整型的第几个位

			return _bs[index] & (1 << pos);
		}
	private:
		std::vector<int> _bs;
		size_t _num;
	};

	void test_bitset()
	{
		bitset bs(100);
		bs.set(99);
		bs.set(98);
		bs.set(97);
		bs.set(5);
		bs.reset(98);

		for (size_t i = 0; i < 100; ++i)
		{
			printf("[%d]:%d\n", i, bs.test(i));
		}
	}
}
