#include <gtest/gtest.h>
#include <tchar.h>

#include "core/library.h"
#include "pch.h"
#include <iostream>
#include <core/error/MyError.h>
#include "core/var/Information.h"

using namespace std;
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
/// ���в��� gen_chains_all
/// </summary>
/// <param name="NameOfTestFunction">���Ժ�����</param>
/// <param name="DescriptionOfAssert">�����õ��Ĳ���Ч������</param>

// ��ͨ����������
TEST(NCircle, Forbid)
{
	char* words[maxLength];
    int* resNumber = (int*)malloc(sizeof(int));
    int* maxLen = (int*)malloc(sizeof(int));
	int len = getCircle(words, resNumber, maxLen);
	char* res[maxLength];
    int api_res = 0;
    try {
        api_res = gen_chains_all(words, len, res);
    }
    catch (MyError e) {
        // ������ʶ��
        EXPECT_EQ(e.reason, DATA_CYCLIC);
    }
    // ������ܳ�������
    EXPECT_LT(api_res, maxLength);
    // ������ܵ�������
    EXPECT_GE(api_res, 0);
    printf("NCircle finish! �������: %d\n", api_res);
}

// �������������
TEST(NSelfCircle, Allow)
{
    char* words[maxLength];
    int* resNumber = (int *)malloc(sizeof(int));
    int* maxLen = (int*)malloc(sizeof(int));
    int len = getSelfCircle(words, resNumber, maxLen);
    char* res[maxLength];

    int api_res = 0;
    try {
        api_res = gen_chains_all(words, len, res);
    }
    catch (MyError e) {
        // ���ⲻӦ���쳣
        cout << e.reason << " ���ⲻӦ���쳣!" << endl;
    }
    // ����ȫ������Ŀ
    EXPECT_EQ(api_res, *resNumber);
    printf("n self-circle (v) ȫ������ %d\n", api_res);
}

// �����д��ĸ��������������ʶ���
TEST(NSelfCircleWithUpperChar, Allow)
{
    char* words[maxLength];
    int* resNumber = (int*)malloc(sizeof(int));
    int* maxLen = (int*)malloc(sizeof(int));
    int len = getSelfCircleWithUpperChar(words, resNumber, maxLen);
    char* res[maxLength];

    int api_res = 0;
    try {
        api_res = gen_chains_all(words, len, res);
    }
    catch (MyError e) {
        // ���ⲻӦ���쳣
        cout << e.reason << " ���ⲻӦ���쳣!" << endl;
    }
    // ����ȫ������Ŀ
    EXPECT_EQ(api_res, *resNumber);
    //int api_res = gen_chain_char(words, len, res, 0, 0, 0, true);
    //int api_res = gen_chain_word(words, len, res, 0, 0, 0, true);
    printf("n self-circle-with-upper-char (v) %d\n", api_res);
    //EXPECT_EQ(0, api_res);
}

// todo
// ���ڴ�Сд��ĸ��ͬ���ɻ���������Ӧ����ʶ��
TEST(NCircleWithUpperChar, Forbid)
{
    char* words[maxLength];
    int* resNumber = (int*)malloc(sizeof(int));
    int* maxLen = (int*)malloc(sizeof(int));
    int len = getCircleWithUpperChar(words, resNumber, maxLen);
    char* res[maxLength];

    int api_res = 0;
    try {
        api_res = gen_chains_all(words, len, res);
    }
    catch (MyError e) {
        // ����Ӧ���쳣
        EXPECT_EQ(e.reason, DATA_CYCLIC);
    }
    // ������ܳ�������
    EXPECT_LT(api_res, maxLength);
    // ������ܵ�������
    EXPECT_GE(api_res, 0);
    //int api_res = gen_chain_char(words, len, res, 0, 0, 0, true);
    //int api_res = gen_chain_word(words, len, res, 0, 0, 0, true);
    printf("n circle-with-upper-char (x) %d\n", api_res);
    //EXPECT_EQ(0, api_res);
}

// �ظ����ʣ����������ظ�
TEST(NRepeat, Forbid)
{
    char* words[maxLength];
    int* resNumber = (int*)malloc(sizeof(int));
    int* maxLen = (int*)malloc(sizeof(int));

    int len = getRepeat(words, resNumber, maxLen);
    char* res[maxLength];

    int api_res = 0;
    try {
        api_res = gen_chains_all(words, len, res);
    }
    catch (MyError e) {
        // ����Ӧ���쳣
        //EXPECT_EQ(e.reason, DATA_CYCLIC);
        cout << "û�ж�������쳣 " << e.reason << endl;
        EXPECT_EQ(e.reason, FILE_NOT_EXIST);
    }
    //int api_res = gen_chain_char(words, len, res, 0, 0, 0, true);
    //int api_res = gen_chain_word(words, len, res, 0, 0, 0, true);
    printf("n repeat (x) %d\n", api_res);
    //EXPECT_EQ(0, api_res);
}

// ��Ϊ�ظ����ʵ��³ɻ���������
TEST(NCircleWithRepeat, Forbid)
{
    char* words[maxLength];
    int* resNumber = (int*)malloc(sizeof(int));
    int* maxLen = (int*)malloc(sizeof(int));

    int len = getCircleWithRepeat(words, resNumber, maxLen);
    char* res[maxLength];

    int api_res = 0;
    try {
        api_res = gen_chains_all(words, len, res);
    }
    catch (MyError e) {
        // ����Ӧ���쳣
        //EXPECT_EQ(e.reason, DATA_CYCLIC);
        cout << "û�ж�������쳣 " << e.reason << endl;
        EXPECT_EQ(e.reason, FILE_NOT_EXIST);
    }
    // ������ܳ�������
    EXPECT_LT(api_res, maxLength);
    // ������ܵ�������
    EXPECT_GE(api_res, 0);
    //int api_res = gen_chain_char(words, len, res, 0, 0, 0, true);
    //int api_res = gen_chain_word(words, len, res, 0, 0, 0, true);
    printf("n circle-with-repeat (x) %d\n", api_res);
    cout << e.reason << " ���ⲻӦ���쳣!" << endl;
    //EXPECT_EQ(0, api_res);
}

// todo
// �����ͬ����������
TEST(NDifferentCircle, Forbid)
{
    char* words[maxLength];
    int* resNumber = (int*)malloc(sizeof(int));
    int* maxLen = (int*)malloc(sizeof(int));

    int len = getDifferentCircle(words, resNumber, maxLen);
    char* res[maxLength];

    int api_res = 0;
    try {
        api_res = gen_chains_all(words, len, res);
    }
    catch (MyError e) {
        // ����Ӧ���쳣
        //EXPECT_EQ(e.reason, DATA_CYCLIC);
        cout << "û�ж�������쳣 " << e.reason << endl;
        EXPECT_EQ(e.reason, FILE_NOT_EXIST);
    }
    // ������ܳ�������
    EXPECT_LT(api_res, maxLength);
    // ������ܵ�������
    EXPECT_GE(api_res, 0);
    //int api_res = gen_chain_char(words, len, res, 0, 0, 0, true);
    //int api_res = gen_chain_word(words, len, res, 0, 0, 0, true);
    printf("n different-circle (x) %d\n", api_res);
    //EXPECT_EQ(0, api_res);
}

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
