
#include "gtest/gtest.h"

#include <map>
#include <iterator>
#include <limits>
#include <iostream>

#include "../Map.hpp"

using mCon =    ft::Map<int, int>;
using sCon =    std::map<int, int>;

class TestQueue : public ::testing::Test
{
public:
	sCon sEmpty;
	sCon sTen;
	sCon sRandom;

	mCon mEmpty;
	mCon mTen;
	mCon mRandom;

protected:
	void SetUp()
	{
		int test_value;

		srand(static_cast<unsigned int>(time(nullptr)));
		for (int i = 0; i < 10; ++i)
		{
			test_value = rand();
			sTen.insert(std::make_pair(test_value, test_value));
			mTen.insert(std::make_pair(test_value, test_value));
		}

		for (int i = 0; i < rand() % 100 + 1; ++i)
		{
			test_value = rand();
			sRandom.insert(std::make_pair(test_value, test_value));
			mRandom.insert(std::make_pair(test_value, test_value));
		}
	}

public:
	static void 	mapComparison(const mCon & mC, const sCon & sC)
	{
		ASSERT_EQ(mC.size(), sC.size());

		mCon::const_iterator    mBegin = mC.begin();
		mCon::const_iterator    mEnd = mC.end();

		sCon::const_iterator    sBegin = sC.begin();
		sCon::const_iterator    sEnd = sC.end();

		if (!mC.empty())
			ASSERT_EQ(*sBegin, *mBegin);
//		ASSERT_EQ(sBegin, sEnd);
		ASSERT_EQ(sBegin == sEnd, mBegin == mEnd);

		ASSERT_EQ(sBegin == sEnd, mBegin == mEnd);
		while (sBegin != sEnd)
		{
			EXPECT_EQ(*sBegin, *mBegin);
			++sBegin;
			++mBegin;
		}
		ASSERT_EQ(sBegin == sEnd, mBegin == mEnd);
	}
};

TEST_F(TestQueue, equalTen)
{
	mapComparison(mTen, sTen);
}

TEST_F(TestQueue, equalRandom)
{
	mapComparison(mRandom, sRandom);
}