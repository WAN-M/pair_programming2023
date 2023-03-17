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
///// 使用vs连续打3个/，自动弹出该注释
///// 单元测试，测试所有函数，每个函数单独写一个测试样例，保证该函数百分百被测到
///// </summary>
///// <param name="NameOfTestFunction">测试函数名</param>
///// <param name="DescriptionOfAssert">渴望得到的测试效果描述</param>
//
//TEST(NameOfTestFunction, DescriptionOfAssert)
//{
//	int res = your_aim_count();
//	EXPECT_EQ(0, res);
//}

/// <summary>
/// 集中测试 gen_chains_all
/// </summary>
/// <param name="NameOfTestFunction">测试函数名</param>
/// <param name="DescriptionOfAssert">渴望得到的测试效果描述</param>

void Low(char** words, int len) {
    //char** newWords = (char**)malloc(sizeof(char*) * len);
    for (int i = 0; i < len; i++) {
        
        int j = 0;
        while (true)
        {
            if (!isalpha(words[i][j])) {
                break;
            }
            j++;
        }
        char* temp = (char*)malloc(sizeof(char) * (j + 1));
        j = 0;
        while (true)
        {
            if (isalpha(words[i][j])) {
                temp[j] = (char)tolower(words[i][j]);
            }
            else {
                break;
            }
            j++;
        }
        temp[j] = 0;
        words[i] = temp;
        //newWords[i] = temp;
    }
    //return newWords;
}

//普通环，不允许
TEST(NCircle, Forbid)
{
	char* words[maxLength];
    int* resNumber = (int*)malloc(sizeof(int));
    int* maxLen = (int*)malloc(sizeof(int));
	int len = getCircle(words, resNumber, maxLen);
	char* res[maxLength];
    int api_res = 0;
    try {
        Low(words, len);
        api_res = gen_chains_all(words, len, res);
    }
    catch (MyError e) {
        // 环必须识别
        EXPECT_EQ(e.reason, DATA_CYCLIC);
    }
    // 结果不能超过上限
    EXPECT_LT(api_res, maxLength);
    // 结果不能低于下限
    EXPECT_GE(api_res, 0);
    printf("NCircle finish! 结果长度: %d\n", api_res);
    //free(words);
    /*for (int i = 0; i < len; i++) {
        free(words[i]);
    }
    free(resNumber);
    free(maxLen);
    for (int i = 0; i < api_res; i++) {
        free(res[i]);
    }*/
    //delete res;
}

// 自身带环，允许
TEST(NSelfCircle, Allow)
{
    char* words[maxLength];
    int* resNumber = (int *)malloc(sizeof(int));
    int* maxLen = (int*)malloc(sizeof(int));
    int len = getSelfCircle(words, resNumber, maxLen);
    char* res[maxLength];

    int api_res = 0;
    try {
        Low(words, len);
        api_res = gen_chains_all(words, len, res);
    }
    catch (MyError e) {
        // 本题不应有异常
        cout << e.reason << " 本题不应有异常!" << endl;
    }
    // 返回全部链数目
    EXPECT_EQ(api_res, *resNumber);
    printf("n self-circle (v) 全部链数 %d\n", api_res);
}

// 自身大写字母带环，允许，需能识别出
TEST(NSelfCircleWithUpperChar, Allow)
{
    char* words[maxLength];
    int* resNumber = (int*)malloc(sizeof(int));
    int* maxLen = (int*)malloc(sizeof(int));
    int len = getSelfCircleWithUpperChar(words, resNumber, maxLen);
    char* res[maxLength];

    int api_res = 0;
    try {
        Low(words, len);
        api_res = gen_chains_all(words, len, res);
    }
    catch (MyError e) {
        // 本题不应有异常
        cout << e.reason << " 本题不应有异常!" << endl;
    }
    // 返回全部链数目
    EXPECT_EQ(api_res, *resNumber);
    //int api_res = gen_chain_char(words, len, res, 0, 0, 0, true);
    //int api_res = gen_chain_word(words, len, res, 0, 0, 0, true);
    printf("n self-circle-with-upper-char (v) %d\n", api_res);
    //EXPECT_EQ(0, api_res);
}

// todo
// 由于大小写字母不同而成环，不允许，应予以识别
TEST(NCircleWithUpperChar, Forbid)
{
    char* words[maxLength];
    int* resNumber = (int*)malloc(sizeof(int));
    int* maxLen = (int*)malloc(sizeof(int));
    int len = getCircleWithUpperChar(words, resNumber, maxLen);
    char* res[maxLength];

    int api_res = 0;
    try {
        Low(words, len);
        api_res = gen_chains_all(words, len, res);
    }
    catch (MyError e) {
        // 本题应有异常
        EXPECT_EQ(e.reason, DATA_CYCLIC);
    }
    // 结果不能超过上限
    EXPECT_LT(api_res, maxLength);
    // 结果不能低于下限
    EXPECT_GE(api_res, 0);
    //int api_res = gen_chain_char(words, len, res, 0, 0, 0, true);
    //int api_res = gen_chain_word(words, len, res, 0, 0, 0, true);
    printf("n circle-with-upper-char (x) %d\n", api_res);
    //EXPECT_EQ(0, api_res);
}

// 重复单词，不允许单词重复
TEST(NRepeat, Forbid)
{
    char* words[maxLength];
    int* resNumber = (int*)malloc(sizeof(int));
    int* maxLen = (int*)malloc(sizeof(int));

    int len = getRepeat(words, resNumber, maxLen);
    char* res[maxLength];

    int api_res = 0;
    try {
        Low(words, len);
        api_res = gen_chains_all(words, len, res);
    }
    catch (MyError e) {
        // 本题应有异常
        //EXPECT_EQ(e.reason, DATA_CYCLIC);
        cout << "没有定义该类异常 " << e.reason << endl;
        EXPECT_EQ(e.reason, FILE_NOT_EXIST);
    }
    // 结果不能超过上限
    EXPECT_LT(api_res, maxLength);
    // 结果不能低于下限
    EXPECT_GE(api_res, 0);
    //int api_res = gen_chain_char(words, len, res, 0, 0, 0, true);
    //int api_res = gen_chain_word(words, len, res, 0, 0, 0, true);
    printf("n repeat (x) %d\n", api_res);
    //EXPECT_EQ(0, api_res);
}

// 因为重复单词导致成环，不允许
TEST(NCircleWithRepeat, Forbid)
{
    char* words[maxLength];
    int* resNumber = (int*)malloc(sizeof(int));
    int* maxLen = (int*)malloc(sizeof(int));

    int len = getCircleWithRepeat(words, resNumber, maxLen);
    char* res[maxLength];

    int api_res = 0;
    try {
        Low(words, len);
        api_res = gen_chains_all(words, len, res);
    }
    catch (MyError e) {
        // 本题应有异常
        
        cout << "没有定义该类异常 " << e.reason << endl;
        EXPECT_EQ(e.reason, DATA_CYCLIC);
        //EXPECT_EQ(e.reason, FILE_NOT_EXIST);
    }
    // 结果不能超过上限
    EXPECT_LT(api_res, maxLength);
    // 结果不能低于下限
    EXPECT_GE(api_res, 0);
    //int api_res = gen_chain_char(words, len, res, 0, 0, 0, true);
    //int api_res = gen_chain_word(words, len, res, 0, 0, 0, true);
    printf("n circle-with-repeat (x) %d\n", api_res);
    //cout << e.reason << " 本题不应有异常!" << endl;
    //EXPECT_EQ(0, api_res);
}

// todo
// 多个不同环，不允许
TEST(NDifferentCircle, Forbid)
{
    char* words[maxLength];
    int* resNumber = (int*)malloc(sizeof(int));
    int* maxLen = (int*)malloc(sizeof(int));

    int len = getDifferentCircle(words, resNumber, maxLen);
    char* res[maxLength];

    int api_res = 0;
    try {
        Low(words, len);
        api_res = gen_chains_all(words, len, res);
    }
    catch (MyError e) {
        // 本题应有异常
        EXPECT_EQ(e.reason, DATA_CYCLIC);
        //cout << "没有定义该类异常 " << e.reason << endl;
        //EXPECT_EQ(e.reason, FILE_NOT_EXIST);
    }
    // 结果不能超过上限
    EXPECT_LT(api_res, maxLength);
    // 结果不能低于下限
    EXPECT_GE(api_res, 0);
    //int api_res = gen_chain_char(words, len, res, 0, 0, 0, true);
    //int api_res = gen_chain_word(words, len, res, 0, 0, 0, true);
    printf("n different-circle (x) %d\n", api_res);
    //EXPECT_EQ(0, api_res);
}












/// <summary>
/// 集中测试 gen_chain_word
/// </summary>
/// <param name="NameOfTestFunction">测试函数名</param>
/// <param name="DescriptionOfAssert">渴望得到的测试效果描述</param>

int wCircleCommon(char head, char tail, char reject, bool loop) {
    char* words[maxLength];
    int* resNumber = (int*)malloc(sizeof(int));
    int* maxLen = (int*)malloc(sizeof(int));
    int len = getCircle(words, resNumber, maxLen);
    char* res[maxLength];
    int api_res = 0;
    Low(words, len);
    api_res = gen_chain_word(words, len, res, head, tail, reject, loop);
    return api_res;
}

int wCircleDifferent(char head, char tail, char reject, bool loop) {
    char* words[maxLength];
    int* resNumber = (int*)malloc(sizeof(int));
    int* maxLen = (int*)malloc(sizeof(int));
    int len = getDifferentCircle(words, resNumber, maxLen);
    char* res[maxLength];
    int api_res = 0;
    Low(words, len);
    api_res = gen_chain_word(words, len, res, head, tail, reject, loop);
    return api_res;
}

int wLinks(char head, char tail, char reject, bool loop) {
    char* words[maxLength];
    int* resNumber = (int*)malloc(sizeof(int));
    int* maxLen = (int*)malloc(sizeof(int));
    int len = get25HeadTailConnectLongWords(words);
    char* res[maxLength];
    int api_res = 0;
    Low(words, len);
    api_res = gen_chain_word(words, len, res, head, tail, reject, loop);
    return api_res;
}

int wCircleRepeat(char head, char tail, char reject, bool loop) {
    char* words[maxLength];
    int* resNumber = (int*)malloc(sizeof(int));
    int* maxLen = (int*)malloc(sizeof(int));
    int len = getCircleWithRepeat(words, resNumber, maxLen);
    char* res[maxLength];
    int api_res = 0;
    Low(words, len);
    api_res = gen_chain_word(words, len, res, head, tail, reject, loop);
    return api_res;
}

int wPlentyCircle(char head, char tail, char reject, bool loop) {
    char* words[maxLength];
    int* resNumber = (int*)malloc(sizeof(int));
    int* maxLen = (int*)malloc(sizeof(int));
    int len = getPlentyCircles(words);
    char* res[maxLength];
    int api_res = 0;
    Low(words, len);
    api_res = gen_chain_word(words, len, res, head, tail, reject, loop);
    return api_res;
}

int wPlentyLinks(char head, char tail, char reject, bool loop) {
    char* words[maxLength];
    int* resNumber = (int*)malloc(sizeof(int));
    int* maxLen = (int*)malloc(sizeof(int));
    int len = getPlentyLinks(words);
    char* res[maxLength];
    int api_res = 0;
    Low(words, len);
    api_res = gen_chain_word(words, len, res, head, tail, reject, loop);
    return api_res;
}

int wFullLinks(char head, char tail, char reject, bool loop) {
    char* words[maxLength];
    int* resNumber = (int*)malloc(sizeof(int));
    int* maxLen = (int*)malloc(sizeof(int));
    int len = getFullHeadTailConnectWords(words);
    char* res[maxLength];
    int api_res = 0;
    //Low(words, len);
    api_res = gen_chain_word(words, len, res, head, tail, reject, loop);
    return api_res;
}

////普通环
TEST(WCircle, Forbid)
{
    int api_res = 0;
    //// 不允许环
    //try {
    //    api_res = wCircle(0, 0, 0, false);
    //}
    //catch (MyError e) {
    //    // 环必须识别
    //    EXPECT_EQ(e.reason, DATA_CYCLIC);
    //}
    //// 结果不能超过上限
    //EXPECT_LT(api_res, maxLength);
    //// 结果不能低于下限
    //EXPECT_GE(api_res, 0);
    //printf("NCircle finish! 结果长度: %d\n", api_res);
    
    char head = 's';
    char tail = 'b';
    char reject = 'b';
    int code = 0b0000;
    while (code <= 0b1111) {
        try {
            api_res = wCircleCommon((code & 0b1000) == 0b1000 ? head : 0,
                (code & 0b0100) == 0b0100 ? tail : 0,
                (code & 0b0010) == 0b0010 ? reject : 0, 
                (code & 0b0001) == 0b0001 ? true : false);
        }
        catch (MyError e) {
            // 环必须识别
            EXPECT_EQ(e.reason, DATA_CYCLIC);
        }
        catch (exception& e) {
            cout << e.what() << endl;
        }
        code += 1;
    }

    code = 0b0000;
    while (code <= 0b1111) {
        try {
            api_res = wCircleDifferent((code & 0b1000) == 0b1000 ? head : 0,
                (code & 0b0100) == 0b0100 ? tail : 0,
                (code & 0b0010) == 0b0010 ? reject : 0,
                (code & 0b0001) == 0b0001 ? true : false);
        }
        catch (MyError e) {
            // 环必须识别
            EXPECT_EQ(e.reason, DATA_CYCLIC);
        }
        catch (exception& e) {
            cout << e.what() << endl;
        }
        code += 1;
    }

    code = 0b0000;
    while (code <= 0b1111) {
        try {
            api_res = wLinks((code & 0b1000) == 0b1000 ? head : 0,
                (code & 0b0100) == 0b0100 ? tail : 0,
                (code & 0b0010) == 0b0010 ? reject : 0,
                (code & 0b0001) == 0b0001 ? true : false);
        }
        catch (MyError e) {
            // 环必须识别
            EXPECT_EQ(e.reason, DATA_CYCLIC);
        }
        catch (exception& e) {
            cout << e.what() << endl;
        }
        code += 1;
    }

    code = 0b0000;
    while (code <= 0b1111) {
        try {
            api_res = wCircleRepeat((code & 0b1000) == 0b1000 ? head : 0,
                (code & 0b0100) == 0b0100 ? tail : 0,
                (code & 0b0010) == 0b0010 ? reject : 0,
                (code & 0b0001) == 0b0001 ? true : false);
        }
        catch (MyError e) {
            // 环必须识别
            EXPECT_EQ(e.reason, DATA_CYCLIC);
        }
        catch (exception& e) {
            cout << e.what() << endl;
        }
        code += 1;
    }

    code = 0b0000;
    while (code <= 0b1111) {
        try {
            api_res = wPlentyCircle((code & 0b1000) == 0b1000 ? head : 0,
                (code & 0b0100) == 0b0100 ? tail : 0,
                (code & 0b0010) == 0b0010 ? reject : 0,
                (code & 0b0001) == 0b0001 ? true : false);
        }
        catch (MyError e) {
            // 环必须识别
            EXPECT_EQ(e.reason, DATA_CYCLIC);
        }
        catch (exception& e) {
            cout << e.what() << endl;
        }
        code += 1;
    }

    code = 0b0000;
    while (code <= 0b1111) {
        try {
            api_res = wPlentyLinks((code & 0b1000) == 0b1000 ? head : 0,
                (code & 0b0100) == 0b0100 ? tail : 0,
                (code & 0b0010) == 0b0010 ? reject : 0,
                (code & 0b0001) == 0b0001 ? true : false);
        }
        catch (MyError e) {
            // 环必须识别
            EXPECT_EQ(e.reason, DATA_CYCLIC);
        }
        catch (exception& e) {
            cout << e.what() << endl;
        }
        code += 1;
    }
    //wPlentyCircle(0, 0, 0, true);
    //wPlentyLinks(0, 0, 0, true);
    //wFullLinks(0, 0, 0, true);
}



////普通环，不允许
//TEST(NCircle, Forbid)
//{
//    char* words[maxLength];
//    int* resNumber = (int*)malloc(sizeof(int));
//    int* maxLen = (int*)malloc(sizeof(int));
//    int len = getCircle(words, resNumber, maxLen);
//    char* res[maxLength];
//    int api_res = 0;
//    try {
//        api_res = gen_chain_word(words, len, res);
//    }
//    catch (MyError e) {
//        // 环必须识别
//        EXPECT_EQ(e.reason, DATA_CYCLIC);
//    }
//    // 结果不能超过上限
//    EXPECT_LT(api_res, maxLength);
//    // 结果不能低于下限
//    EXPECT_GE(api_res, 0);
//    printf("NCircle finish! 结果长度: %d\n", api_res);
//}
//
//
//// 自身带环，允许
//TEST(NSelfCircle, Allow)
//{
//    char* words[maxLength];
//    int* resNumber = (int*)malloc(sizeof(int));
//    int* maxLen = (int*)malloc(sizeof(int));
//    int len = getSelfCircle(words, resNumber, maxLen);
//    char* res[maxLength];
//
//    int api_res = 0;
//    try {
//        api_res = gen_chains_all(words, len, res);
//    }
//    catch (MyError e) {
//        // 本题不应有异常
//        cout << e.reason << " 本题不应有异常!" << endl;
//    }
//    // 返回全部链数目
//    EXPECT_EQ(api_res, *resNumber);
//    printf("n self-circle (v) 全部链数 %d\n", api_res);
//}
//
//// 自身大写字母带环，允许，需能识别出
//TEST(NSelfCircleWithUpperChar, Allow)
//{
//    char* words[maxLength];
//    int* resNumber = (int*)malloc(sizeof(int));
//    int* maxLen = (int*)malloc(sizeof(int));
//    int len = getSelfCircleWithUpperChar(words, resNumber, maxLen);
//    char* res[maxLength];
//
//    int api_res = 0;
//    try {
//        api_res = gen_chains_all(words, len, res);
//    }
//    catch (MyError e) {
//        // 本题不应有异常
//        cout << e.reason << " 本题不应有异常!" << endl;
//    }
//    // 返回全部链数目
//    EXPECT_EQ(api_res, *resNumber);
//    //int api_res = gen_chain_char(words, len, res, 0, 0, 0, true);
//    //int api_res = gen_chain_word(words, len, res, 0, 0, 0, true);
//    printf("n self-circle-with-upper-char (v) %d\n", api_res);
//    //EXPECT_EQ(0, api_res);
//}
//
//// todo
//// 由于大小写字母不同而成环，不允许，应予以识别
//TEST(NCircleWithUpperChar, Forbid)
//{
//    char* words[maxLength];
//    int* resNumber = (int*)malloc(sizeof(int));
//    int* maxLen = (int*)malloc(sizeof(int));
//    int len = getCircleWithUpperChar(words, resNumber, maxLen);
//    char* res[maxLength];
//
//    int api_res = 0;
//    try {
//        api_res = gen_chains_all(words, len, res);
//    }
//    catch (MyError e) {
//        // 本题应有异常
//        EXPECT_EQ(e.reason, DATA_CYCLIC);
//    }
//    // 结果不能超过上限
//    EXPECT_LT(api_res, maxLength);
//    // 结果不能低于下限
//    EXPECT_GE(api_res, 0);
//    //int api_res = gen_chain_char(words, len, res, 0, 0, 0, true);
//    //int api_res = gen_chain_word(words, len, res, 0, 0, 0, true);
//    printf("n circle-with-upper-char (x) %d\n", api_res);
//    //EXPECT_EQ(0, api_res);
//}
//
//// 重复单词，不允许单词重复
//TEST(NRepeat, Forbid)
//{
//    char* words[maxLength];
//    int* resNumber = (int*)malloc(sizeof(int));
//    int* maxLen = (int*)malloc(sizeof(int));
//
//    int len = getRepeat(words, resNumber, maxLen);
//    char* res[maxLength];
//
//    int api_res = 0;
//    try {
//        api_res = gen_chains_all(words, len, res);
//    }
//    catch (MyError e) {
//        // 本题应有异常
//        //EXPECT_EQ(e.reason, DATA_CYCLIC);
//        cout << "没有定义该类异常 " << e.reason << endl;
//        EXPECT_EQ(e.reason, FILE_NOT_EXIST);
//    }
//    // 结果不能超过上限
//    EXPECT_LT(api_res, maxLength);
//    // 结果不能低于下限
//    EXPECT_GE(api_res, 0);
//    //int api_res = gen_chain_char(words, len, res, 0, 0, 0, true);
//    //int api_res = gen_chain_word(words, len, res, 0, 0, 0, true);
//    printf("n repeat (x) %d\n", api_res);
//    //EXPECT_EQ(0, api_res);
//}
//
//// 因为重复单词导致成环，不允许
//TEST(NCircleWithRepeat, Forbid)
//{
//    char* words[maxLength];
//    int* resNumber = (int*)malloc(sizeof(int));
//    int* maxLen = (int*)malloc(sizeof(int));
//
//    int len = getCircleWithRepeat(words, resNumber, maxLen);
//    char* res[maxLength];
//
//    int api_res = 0;
//    try {
//        api_res = gen_chains_all(words, len, res);
//    }
//    catch (MyError e) {
//        // 本题应有异常
//        //EXPECT_EQ(e.reason, DATA_CYCLIC);
//        cout << "没有定义该类异常 " << e.reason << endl;
//        EXPECT_EQ(e.reason, FILE_NOT_EXIST);
//    }
//    // 结果不能超过上限
//    EXPECT_LT(api_res, maxLength);
//    // 结果不能低于下限
//    EXPECT_GE(api_res, 0);
//    //int api_res = gen_chain_char(words, len, res, 0, 0, 0, true);
//    //int api_res = gen_chain_word(words, len, res, 0, 0, 0, true);
//    printf("n circle-with-repeat (x) %d\n", api_res);
//    //cout << e.reason << " 本题不应有异常!" << endl;
//    //EXPECT_EQ(0, api_res);
//}
//
//// todo
//// 多个不同环，不允许
//TEST(NDifferentCircle, Forbid)
//{
//    char* words[maxLength];
//    int* resNumber = (int*)malloc(sizeof(int));
//    int* maxLen = (int*)malloc(sizeof(int));
//
//    int len = getDifferentCircle(words, resNumber, maxLen);
//    char* res[maxLength];
//
//    int api_res = 0;
//    try {
//        api_res = gen_chains_all(words, len, res);
//    }
//    catch (MyError e) {
//        // 本题应有异常
//        EXPECT_EQ(e.reason, DATA_CYCLIC);
//        //cout << "没有定义该类异常 " << e.reason << endl;
//        //EXPECT_EQ(e.reason, FILE_NOT_EXIST);
//    }
//    // 结果不能超过上限
//    EXPECT_LT(api_res, maxLength);
//    // 结果不能低于下限
//    EXPECT_GE(api_res, 0);
//    //int api_res = gen_chain_char(words, len, res, 0, 0, 0, true);
//    //int api_res = gen_chain_word(words, len, res, 0, 0, 0, true);
//    printf("n different-circle (x) %d\n", api_res);
//    //EXPECT_EQ(0, api_res);
//}
/// <summary>
/// 以下请勿修改
/// </summary>
/// <param name="argc"></param>
/// <param name="argv"></param>
/// <returns></returns>


/// <summary>
/// 集中测试 gen_chain_word
/// </summary>
/// <param name="NameOfTestFunction">测试函数名</param>
/// <param name="DescriptionOfAssert">渴望得到的测试效果描述</param>

int cCircle(char head, char tail, char reject, bool loop) {
    char* words[maxLength];
    int* resNumber = (int*)malloc(sizeof(int));
    int* maxLen = (int*)malloc(sizeof(int));
    int len = getDifferentCircle(words, resNumber, maxLen);
    char* res[maxLength];
    int api_res = 0;
    Low(words, len);
    api_res = gen_chain_char(words, len, res, head, tail, reject, loop);
    return api_res;
}

int cCircleDifferent(char head, char tail, char reject, bool loop) {
    char* words[maxLength];
    int* resNumber = (int*)malloc(sizeof(int));
    int* maxLen = (int*)malloc(sizeof(int));
    int len = getDifferentCircle(words, resNumber, maxLen);
    char* res[maxLength];
    int api_res = 0;
    Low(words, len);
    api_res = gen_chain_char(words, len, res, head, tail, reject, loop);
    return api_res;
}

int cLinks(char head, char tail, char reject, bool loop) {
    char* words[maxLength];
    int* resNumber = (int*)malloc(sizeof(int));
    int* maxLen = (int*)malloc(sizeof(int));
    int len = get25HeadTailConnectLongWords(words);
    char* res[maxLength];
    int api_res = 0;
    Low(words, len);
    api_res = gen_chain_char(words, len, res, head, tail, reject, loop);
    return api_res;
}

int cCircleRepeat(char head, char tail, char reject, bool loop) {
    char* words[maxLength];
    int* resNumber = (int*)malloc(sizeof(int));
    int* maxLen = (int*)malloc(sizeof(int));
    int len = getCircleWithRepeat(words, resNumber, maxLen);
    char* res[maxLength];
    int api_res = 0;
    Low(words, len);
    api_res = gen_chain_char(words, len, res, head, tail, reject, loop);
    return api_res;
}

int cPlentyCircle(char head, char tail, char reject, bool loop) {
    char* words[maxLength];
    int* resNumber = (int*)malloc(sizeof(int));
    int* maxLen = (int*)malloc(sizeof(int));
    int len = getPlentyCircles(words);
    char* res[maxLength];
    int api_res = 0;
    Low(words, len);
    api_res = gen_chain_char(words, len, res, head, tail, reject, loop);
    return api_res;
}

int cPlentyLinks(char head, char tail, char reject, bool loop) {
    char* words[maxLength];
    int* resNumber = (int*)malloc(sizeof(int));
    int* maxLen = (int*)malloc(sizeof(int));
    int len = getPlentyLinks(words);
    char* res[maxLength];
    int api_res = 0;
    Low(words, len);
    api_res = gen_chain_char(words, len, res, head, tail, reject, loop);
    return api_res;
}

////普通环
TEST(CCircle, Forbid)
{
    int api_res = 0;
    //// 不允许环
    //try {
    //    api_res = wCircle(0, 0, 0, false);
    //}
    //catch (MyError e) {
    //    // 环必须识别
    //    EXPECT_EQ(e.reason, DATA_CYCLIC);
    //}
    //// 结果不能超过上限
    //EXPECT_LT(api_res, maxLength);
    //// 结果不能低于下限
    //EXPECT_GE(api_res, 0);
    //printf("NCircle finish! 结果长度: %d\n", api_res);

    char head = 's';
    char tail = 'b';
    char reject = 's';
    int code = 0b0000;
    while (code <= 0b1111) {
        try {
            api_res = cCircle((code & 0b1000) == 0b1000 ? head : 0,
                (code & 0b0100) == 0b0100 ? tail : 0,
                (code & 0b0010) == 0b0010 ? reject : 0,
                (code & 0b0001) == 0b0001 ? true : false);
        }
        catch (MyError e) {
            // 环必须识别
            EXPECT_EQ(e.reason, DATA_CYCLIC);
        }
        catch (exception& e) {
            cout << e.what() << endl;
        }
        code += 1;
    }

    code = 0b0000;
    while (code <= 0b1111) {
        try {
            api_res = cCircleDifferent((code & 0b1000) == 0b1000 ? head : 0,
                (code & 0b0100) == 0b0100 ? tail : 0,
                (code & 0b0010) == 0b0010 ? reject : 0,
                (code & 0b0001) == 0b0001 ? true : false);
        }
        catch (MyError e) {
            // 环必须识别
            EXPECT_EQ(e.reason, DATA_CYCLIC);
        }
        catch (exception& e) {
            cout << e.what() << endl;
        }
        code += 1;
    }

    code = 0b0000;
    while (code <= 0b1111) {
        try {
            api_res = cLinks((code & 0b1000) == 0b1000 ? head : 0,
                (code & 0b0100) == 0b0100 ? tail : 0,
                (code & 0b0010) == 0b0010 ? reject : 0,
                (code & 0b0001) == 0b0001 ? true : false);
        }
        catch (MyError e) {
            // 环必须识别
            EXPECT_EQ(e.reason, DATA_CYCLIC);
        }
        catch (exception& e) {
            cout << e.what() << endl;
        }
        code += 1;
    }

    code = 0b0000;
    while (code <= 0b1111) {
        try {
            api_res = cCircleRepeat((code & 0b1000) == 0b1000 ? head : 0,
                (code & 0b0100) == 0b0100 ? tail : 0,
                (code & 0b0010) == 0b0010 ? reject : 0,
                (code & 0b0001) == 0b0001 ? true : false);
        }
        catch (MyError e) {
            // 环必须识别
            EXPECT_EQ(e.reason, DATA_CYCLIC);
        }
        catch (exception& e) {
            cout << e.what() << endl;
        }
        code += 1;
    }

    code = 0b0000;
    while (code <= 0b1111) {
        try {
            api_res = cPlentyCircle((code & 0b1000) == 0b1000 ? head : 0,
                (code & 0b0100) == 0b0100 ? tail : 0,
                (code & 0b0010) == 0b0010 ? reject : 0,
                (code & 0b0001) == 0b0001 ? true : false);
        }
        catch (MyError e) {
            // 环必须识别
            EXPECT_EQ(e.reason, DATA_CYCLIC);
        }
        catch (exception& e) {
            cout << e.what() << endl;
        }
        code += 1;
    }

    code = 0b0000;
    while (code <= 0b1111) {
        try {
            api_res = cPlentyLinks((code & 0b1000) == 0b1000 ? head : 0,
                (code & 0b0100) == 0b0100 ? tail : 0,
                (code & 0b0010) == 0b0010 ? reject : 0,
                (code & 0b0001) == 0b0001 ? true : false);
        }
        catch (MyError e) {
            // 环必须识别
            EXPECT_EQ(e.reason, DATA_CYCLIC);
        }
        catch (exception& e) {
            cout << e.what() << endl;
        }
        code += 1;
    }
    //cPlentyCircle(0, 0, 0, true);
    //cPlentyLinks(0, 0, 0, true);
}

int _tmain(int argc, _TCHAR* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	testing::GTEST_FLAG(output) = "xml:";
	return RUN_ALL_TESTS();
}
