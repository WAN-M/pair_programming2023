#include <gtest/gtest.h>
#include <tchar.h>

#include "core/library.h"
#include "pch.h"
#define maxLength 20001
//#include "your_aim.h"

///// <summary>
///// ʹ��vs������3��/���Զ�������ע��
///// ��Ԫ���ԣ��������к�����ÿ����������дһ��������������֤�ú����ٷְٱ��⵽
///// </summary>
///// <param name="NameOfTestFunction">���Ժ�����</param>
///// <param name="DescriptionOfAssert">�����õ��Ĳ���Ч������</param>
//
//TEST(NameOfTestFunction, DescriptionOfAssert)
//{
//	int res = your_aim_count();
//	EXPECT_EQ(0, res);
//}

/// <summary>
/// gen_chains_all
/// </summary>
/// <param name="NameOfTestFunction">���Ժ�����</param>
/// <param name="DescriptionOfAssert">�����õ��Ĳ���Ч������</param>

// ��ͨ����-n��Ӧ��
TEST(CommonCircle, Forbid)
{
	char* words[maxLength];
	int len = getPlentyLinks(words);
	char* res[maxLength];

	int api_res = gen_chains_all(words, len, res);
	//int api_res = gen_chain_char(words, len, res, 0, 0, 0, true);
	//int api_res = gen_chain_word(words, len, res, 0, 0, 0, true);
	printf("%d\n", api_res);
	//EXPECT_EQ(0, api_res);
}

//// �������
//TEST(NameOfTestFunction, DescriptionOfAssert)
//{
//    char** words = (char**)malloc(sizeof(char*) * maxLength);
//    int len = getCircle(words);
//    char** res = (char**)malloc(sizeof(char*) * maxLength);
//
//    int api_res = gen_chains_all(words, len, res);
//    printf("%d\n", api_res);
//    //EXPECT_EQ(0, api_res);
//}
/// <summary>
/// ���������޸�
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
