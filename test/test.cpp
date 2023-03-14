#include <gtest/gtest.h>
#include <tchar.h>

#include "your_aim.h"

/// <summary>
/// 使用vs连续打3个/，自动弹出该注释
/// 单元测试，测试所有函数，每个函数单独写一个测试样例，保证该函数百分百被测到
/// </summary>
/// <param name="NameOfTestFunction">测试函数名</param>
/// <param name="DescriptionOfAssert">渴望得到的测试效果描述</param>

TEST(NameOfTestFunction, DescriptionOfAssert)
{
	int res = your_aim_count();
	EXPECT_EQ(0, res);
}

/// <summary>
/// 以下请勿修改
/// </summary>
/// <param name="argc"></param>
/// <param name="argv"></param>
/// <returns></returns>

int _tmain(int argc, _TCHAR* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	testing::GTEST_FLAG(output) = "xml:";
	return RUN_ALL_TESTS();
}
