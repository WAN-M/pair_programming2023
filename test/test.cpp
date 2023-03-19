#include <gtest/gtest.h>

//#include "library.h"
#include "pch.h"
//#include "error/MyError.h"
//#include "var/Information.h"
#include <fstream>
//#include "forTest.h"

using namespace std;
#define maxLength 20001
#define release true
//#include "your_aim.h"

/// <summary>
/// 集中测试 gen_chains_all
/// </summary>
/// <param name="NameOfTestFunction">测试函数名</param>
/// <param name="DescriptionOfAssert">渴望得到的测试效果描述</param>

//void Low(char** words, int len) {
//    //char** newWords = (char**)malloc(sizeof(char*) * len);
//    for (int i = 0; i < len; i++) {
//        
//        int j = 0;
//        while (true)
//        {
//            if (!isalpha(words[i][j])) {
//                break;
//            }
//            j++;
//        }
//        char* temp = (char*)malloc(sizeof(char) * (j + 1));
//        j = 0;
//        while (true)
//        {
//            if (isalpha(words[i][j])) {
//                temp[j] = (char)tolower(words[i][j]);
//            }
//            else {
//                break;
//            }
//            j++;
//        }
//        temp[j] = 0;
//        words[i] = temp;
//        //newWords[i] = temp;
//    }
//    //return newWords;
//}

void myappend(string path, char* str)
{
    ofstream ofs;						//定义流对象
    ofs.open(path, ios::app);		//以写的方式打开文件
    ofs << str << endl;//写入
    ofs.close();
}

void mycreate(string path)
{
    ofstream ofs;						//定义流对象
    ofs.open(path, ios::out);		//以写的方式打开文件
    ofs << "";//写入
    ofs.close();
}

void saveData(string path, char** words, int length) {
    mycreate(path);
    for (int i = 0; i < length; i++) {
        myappend(path, words[i]);
    }
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

    saveData("NCircle.txt", words, len);
    // exe -n nc.txt
    //char* argv[3] = { "exe.exe", "-n", "NCircle.txt" };
    //mainTest(3, argv);
    //try {
    //    Low(words, len);
    //    api_res = gen_chains_all(words, len, res);
    //}
    //catch (MyError e) {
    //    // 环必须识别
    //    EXPECT_EQ(e.reason, DATA_CYCLIC);
    //    cout << e.reason << endl;
    //}
    //catch (exception& e) {
    //    cout << e.what() << endl;
    //}
    //// 结果不能超过上限
    //EXPECT_LT(api_res, maxLength);
    //// 结果不能低于下限
    //EXPECT_GE(api_res, 0);
    //printf("NCircle finish! 结果长度: %d\n", api_res);
    //free(words);
    /*for (int i = 0; i < len; i++) {
        free(words[i]);
    }
    free(resNumber);
    free(maxLen);*/
    /*string path;
    if (release) {
        path = "reNCircle.txt";
    }
    else
    {
        path = "deNCircle.txt";
    }
    mycreate(path);
    for (int i = 0; i < api_res; i++) {
    	printf("%s\n", res[i]);
        myappend(path, res[i]);
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

    saveData("NSelfCircle.txt", words, len);
    // exe -n nc.txt
    //char* argv[3] = { "exe.exe", "-n", "NSelfCircle.txt" };
    //mainTest(3, argv);

    //int api_res = 0;
    //try {
    //    Low(words, len);
    //    api_res = gen_chains_all(words, len, res);
    //}
    //catch (MyError e) {
    //    // 本题不应有异常
    //    cout << e.reason << " 本题不应有异常!" << endl;
    //}
    //// 返回全部链数目
    //EXPECT_EQ(api_res, *resNumber);
    //printf("n self-circle (v) 全部链数 %d\n", api_res);

    //string path;
    //if (release) {
    //    path = "reNSelfCircle.txt";
    //}
    //else
    //{
    //    path = "deNSelfCircle.txt";
    //}
    //mycreate(path);
    //for (int i = 0; i < api_res; i++) {
    //    printf("%s\n", res[i]);
    //    myappend(path, res[i]);
    //}
}

// 自身大写字母带环，允许，需能识别出
TEST(NSelfCircleWithUpperChar, Allow)
{
    char* words[maxLength];
    int* resNumber = (int*)malloc(sizeof(int));
    int* maxLen = (int*)malloc(sizeof(int));
    int len = getSelfCircleWithUpperChar(words, resNumber, maxLen);
    char* res[maxLength];

    saveData("NSelfCircleWithUpperChar.txt", words, len);
    // exe -n nc.txt
    //char* argv[3] = { "exe.exe", "-n", "NSelfCircleWithUpperChar.txt" };
    //mainTest(3, argv);

    //int api_res = 0;
    //try {
    //    Low(words, len);
    //    api_res = gen_chains_all(words, len, res);
    //}
    //catch (MyError e) {
    //    // 本题不应有异常
    //    cout << e.reason << " 本题不应有异常!" << endl;
    //}
    //// 返回全部链数目
    //EXPECT_EQ(api_res, *resNumber);
    ////int api_res = gen_chain_char(words, len, res, 0, 0, 0, true);
    ////int api_res = gen_chain_word(words, len, res, 0, 0, 0, true);
    //printf("n self-circle-with-upper-char (v) %d\n", api_res);
    ////EXPECT_EQ(0, api_res);
    //string path;
    //if (release) {
    //    path = "reNSelfCircleWithUpperChar.txt";
    //}
    //else
    //{
    //    path = "deNSelfCircleWithUpperChar.txt";
    //}
    ////string path = mode + "NSelfCircleWithUpperChar.txt";
    //mycreate(path);
    //for (int i = 0; i < api_res; i++) {
    //    printf("%s\n", res[i]);
    //    myappend(path, res[i]);
    //}
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

    saveData("NCircleWithUpperChar.txt", words, len);
    // exe -n nc.txt
    //char* argv[3] = { "exe.exe", "-n", "NCircleWithUpperChar.txt" };
    //mainTest(3, argv);


    //int api_res = 0;
    //try {
    //    Low(words, len);
    //    api_res = gen_chains_all(words, len, res);
    //}
    //catch (MyError e) {
    //    // 本题应有异常
    //    EXPECT_EQ(e.reason, DATA_CYCLIC);
    //}
    //// 结果不能超过上限
    //EXPECT_LT(api_res, maxLength);
    //// 结果不能低于下限
    //EXPECT_GE(api_res, 0);
    ////int api_res = gen_chain_char(words, len, res, 0, 0, 0, true);
    ////int api_res = gen_chain_word(words, len, res, 0, 0, 0, true);
    //printf("n circle-with-upper-char (x) %d\n", api_res);
    ////EXPECT_EQ(0, api_res);
    //string path;
    //if (release) {
    //    path = "reNCircleWithUpperChar.txt";
    //}
    //else
    //{
    //    path = "deNCircleWithUpperChar.txt";
    //}
    ////string path = mode + "NCircleWithUpperChar.txt";
    //mycreate(path);
    //for (int i = 0; i < api_res; i++) {
    //    printf("%s\n", res[i]);
    //    myappend(path, res[i]);
    //}
}

// 重复单词，不允许单词重复
TEST(NRepeat, Forbid)
{
    char* words[maxLength];
    int* resNumber = (int*)malloc(sizeof(int));
    int* maxLen = (int*)malloc(sizeof(int));

    int len = getRepeat(words, resNumber, maxLen);
    char* res[maxLength];

    saveData("NRepeat.txt", words, len);
    // exe -n nc.txt
    //char* argv[3] = { "exe.exe", "-n", "NRepeat.txt" };
    //mainTest(3, argv);

    //int api_res = 0;
    //try {
    //    Low(words, len);
    //    api_res = gen_chains_all(words, len, res);
    //}
    //catch (MyError e) {
    //    // 本题应有异常
    //    //EXPECT_EQ(e.reason, DATA_CYCLIC);
    //    cout << "没有定义该类异常 " << e.reason << endl;
    //    EXPECT_EQ(e.reason, FILE_NOT_EXIST);
    //}
    //// 结果不能超过上限
    //EXPECT_LT(api_res, maxLength);
    //// 结果不能低于下限
    //EXPECT_GE(api_res, 0);
    ////int api_res = gen_chain_char(words, len, res, 0, 0, 0, true);
    ////int api_res = gen_chain_word(words, len, res, 0, 0, 0, true);
    //printf("n repeat (x) %d\n", api_res);
    ////EXPECT_EQ(0, api_res);
    //string path;
    //if (release) {
    //    path = "reNRepeat.txt";
    //}
    //else
    //{
    //    path = "deNRepeat.txt";
    //}
    ////string path = mode + "NRepeat.txt";
    //mycreate(path);
    //for (int i = 0; i < api_res; i++) {
    //    printf("%s\n", res[i]);
    //    myappend(path, res[i]);
    //}
}

// 因为重复单词导致成环，不允许
TEST(NCircleWithRepeat, Forbid)
{
    char* words[maxLength];
    int* resNumber = (int*)malloc(sizeof(int));
    int* maxLen = (int*)malloc(sizeof(int));

    int len = getCircleWithRepeat(words, resNumber, maxLen);
    char* res[maxLength];

    saveData("NCircleWithRepeat.txt", words, len);
    // exe -n nc.txt
    //char* argv[3] = { "exe.exe", "-n", "NCircleWithRepeat.txt" };
    //mainTest(3, argv);
    //mainTest(3, argv);
    //int api_res = 0;
    //try {
    //    Low(words, len);
    //    api_res = gen_chains_all(words, len, res);
    //}
    //catch (MyError e) {
    //    // 本题应有异常
    //    
    //    cout << "没有定义该类异常 " << e.reason << endl;
    //    EXPECT_EQ(e.reason, DATA_CYCLIC);
    //    //EXPECT_EQ(e.reason, FILE_NOT_EXIST);
    //}
    //// 结果不能超过上限
    //EXPECT_LT(api_res, maxLength);
    //// 结果不能低于下限
    //EXPECT_GE(api_res, 0);
    ////int api_res = gen_chain_char(words, len, res, 0, 0, 0, true);
    ////int api_res = gen_chain_word(words, len, res, 0, 0, 0, true);
    //printf("n circle-with-repeat (x) %d\n", api_res);
    ////cout << e.reason << " 本题不应有异常!" << endl;
    ////EXPECT_EQ(0, api_res);
    //string path;
    //if (release) {
    //    path = "reNCircleWithRepeat.txt";
    //}
    //else
    //{
    //    path = "deNCircleWithRepeat.txt";
    //}
    ////string path = mode + "NCircleWithRepeat.txt";
    //mycreate(path);
    //for (int i = 0; i < api_res; i++) {
    //    printf("%s\n", res[i]);
    //    myappend(path, res[i]);
    //}
}

void myPrint(char** words, int len) {
    for (int i = 0; i < len; i++) {
        printf("check %s\n", words[i]);
    }
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

    saveData("NDifferentCircle.txt", words, len);
    // exe -n nc.txt
    //char* argv[3] = { "exe.exe", "-n", "NDifferentCircle.txt" };
    //mainTest(3, argv);

    //int api_res = 0;
    ////try {
    //Low(words, len);
    ////myPrint(words, len);
    //api_res = gen_chains_all(words, len, res);
    ////}
    ////catch (MyError e) {
    ////    // 本题应有异常
    ////    EXPECT_EQ(e.reason, DATA_CYCLIC);
    ////    //cout << "没有定义该类异常 " << e.reason << endl;
    ////    //EXPECT_EQ(e.reason, FILE_NOT_EXIST);
    ////}
    ////// 结果不能超过上限
    ////EXPECT_LT(api_res, maxLength);
    ////// 结果不能低于下限
    ////EXPECT_GE(api_res, 0);
    //EXPECT_EQ(api_res, *resNumber);
    ////int api_res = gen_chain_char(words, len, res, 0, 0, 0, true);
    ////int api_res = gen_chain_word(words, len, res, 0, 0, 0, true);
    //printf("n different-circle (x) %d\n", api_res);
    ////EXPECT_EQ(0, api_res);
    //string path;
    //if (release) {
    //    path = "reNDifferentCircle.txt";
    //}
    //else
    //{
    //    path = "deNDifferentCircle.txt";
    //}
    ////string path = mode + "NDifferentCircle.txt";
    //mycreate(path);
    //for (int i = 0; i < api_res; i++) {
    //    printf("%s\n", res[i]);
    //    myappend(path, res[i]);
    //}
}

//// todo
//// 多个不同环，不允许
TEST(NFullLinks, Forbid)
{
    char* words[maxLength];
    int* resNumber = (int*)malloc(sizeof(int));
    int* maxLen = (int*)malloc(sizeof(int));

    int len = getFullHeadTailConnectWords(words);
    char* res[maxLength];

    saveData("NDifferentCircle.txt", words, len);

    //int api_res = 0;
    //try {
    //    Low(words, len);
    //    api_res = gen_chains_all(words, len, res);
    //}
    //catch (MyError e) {
    //    // 本题应有异常
    //    EXPECT_EQ(e.reason, DATA_CYCLIC);
    //    //cout << "没有定义该类异常 " << e.reason << endl;
    //    //EXPECT_EQ(e.reason, FILE_NOT_EXIST);
    //}
    //// 结果不能超过上限
    //EXPECT_LT(api_res, maxLength);
    //// 结果不能低于下限
    //EXPECT_GE(api_res, 0);
    ////int api_res = gen_chain_char(words, len, res, 0, 0, 0, true);
    ////int api_res = gen_chain_word(words, len, res, 0, 0, 0, true);
    //printf("n different-circle (x) %d\n", api_res);
    ////EXPECT_EQ(0, api_res);
    //string path;
    //if (release) {
    //    path = "reNFullLinks.txt";
    //}
    //else
    //{
    //    path = "deNFullLinks.txt";
    //}
    ////string path = mode + "NDifferentCircle.txt";
    //mycreate(path);
    //for (int i = 0; i < api_res; i++) {
    //    printf("%s\n", words[i]);
    //    myappend(path, words[i]);
    //}
}











///// <summary>
///// 集中测试 gen_chain_word
///// </summary>
///// <param name="NameOfTestFunction">测试函数名</param>
///// <param name="DescriptionOfAssert">渴望得到的测试效果描述</param>
//
int wCircleCommon(char head, char tail, char reject, bool loop, string path) {
    char* words[maxLength];
    int* resNumber = (int*)malloc(sizeof(int));
    int* maxLen = (int*)malloc(sizeof(int));
    int len = getCircle(words, resNumber, maxLen);
    char* res[maxLength];

    saveData(path, words, len);
    // exe -n nc.txt
    //char* argv[3] = { "exe.exe", 
    //    (head == 0) ? "" : "-h", (head == 0) ? "" : &head,
    //    (tail == 0) ? "" : "-t", (tail == 0) ? "" : &tail,
    //    (reject == 0) ? "" : "-j", (reject == 0) ? "" : &reject,
    //    ()
    //    "-n", "NDifferentCircle.txt"};
    //mainTest(3, argv);


    //Low(words, len);
    //api_res = gen_chain_word(words, len, res, head, tail, reject, loop);
    return 0;
}

int wCircleDifferent(char head, char tail, char reject, bool loop, string path) {
    char* words[maxLength];
    int* resNumber = (int*)malloc(sizeof(int));
    int* maxLen = (int*)malloc(sizeof(int));
    int len = getDifferentCircle(words, resNumber, maxLen);
    char* res[maxLength];

    saveData(path, words, len);

    //int api_res = 0;
    //Low(words, len);
    //api_res = gen_chain_word(words, len, res, head, tail, reject, loop);
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

//////普通环
//TEST(WCircle, Forbid)
//{
//    int api_res = 0;
//    //// 不允许环
//    //try {
//    //    api_res = wCircle(0, 0, 0, false);
//    //}
//    //catch (MyError e) {
//    //    // 环必须识别
//    //    EXPECT_EQ(e.reason, DATA_CYCLIC);
//    //}
//    //// 结果不能超过上限
//    //EXPECT_LT(api_res, maxLength);
//    //// 结果不能低于下限
//    //EXPECT_GE(api_res, 0);
//    //printf("NCircle finish! 结果长度: %d\n", api_res);
//    
//    char head = 'a';
//    char tail = 'z';
//    char reject = 'x';
//    int code = 0b0000;
//    //while (code <= 0b1111) {
//    //    try {
//    //        api_res = wCircleCommon((code & 0b1000) == 0b1000 ? head : 0,
//    //            (code & 0b0100) == 0b0100 ? tail : 0,
//    //            (code & 0b0010) == 0b0010 ? reject : 0, 
//    //            (code & 0b0001) == 0b0001 ? true : false);
//    //    }
//    //    catch (MyError e) {
//    //        // 环必须识别
//    //        EXPECT_EQ(e.reason, DATA_CYCLIC);
//    //    }
//    //    catch (exception& e) {
//    //        cout << e.what() << endl;
//    //    }
//    //    code += 1;
//    //}
//
//    //code = 0b0000;
//    //while (code <= 0b1111) {
//    //    try {
//    //        api_res = wCircleDifferent((code & 0b1000) == 0b1000 ? head : 0,
//    //            (code & 0b0100) == 0b0100 ? tail : 0,
//    //            (code & 0b0010) == 0b0010 ? reject : 0,
//    //            (code & 0b0001) == 0b0001 ? true : false);
//    //    }
//    //    catch (MyError e) {
//    //        // 环必须识别
//    //        EXPECT_EQ(e.reason, DATA_CYCLIC);
//    //    }
//    //    catch (exception& e) {
//    //        cout << e.what() << endl;
//    //    }
//    //    code += 1;
//    //}
//
//    //code = 0b0000;
//    //while (code <= 0b1111) {
//    //    try {
//    //        api_res = wLinks((code & 0b1000) == 0b1000 ? head : 0,
//    //            (code & 0b0100) == 0b0100 ? tail : 0,
//    //            (code & 0b0010) == 0b0010 ? reject : 0,
//    //            (code & 0b0001) == 0b0001 ? true : false);
//    //    }
//    //    catch (MyError e) {
//    //        // 环必须识别
//    //        EXPECT_EQ(e.reason, DATA_CYCLIC);
//    //    }
//    //    catch (exception& e) {
//    //        cout << e.what() << endl;
//    //    }
//    //    code += 1;
//    //}
//
//    //code = 0b0000;
//    //while (code <= 0b1111) {
//    //    try {
//    //        api_res = wCircleRepeat((code & 0b1000) == 0b1000 ? head : 0,
//    //            (code & 0b0100) == 0b0100 ? tail : 0,
//    //            (code & 0b0010) == 0b0010 ? reject : 0,
//    //            (code & 0b0001) == 0b0001 ? true : false);
//    //    }
//    //    catch (MyError e) {
//    //        // 环必须识别
//    //        EXPECT_EQ(e.reason, DATA_CYCLIC);
//    //    }
//    //    catch (exception& e) {
//    //        cout << e.what() << endl;
//    //    }
//    //    code += 1;
//    //}
//
//    //code = 0b0000;
//    //while (code <= 0b1111) {
//    //    try {
//    //        api_res = wPlentyCircle((code & 0b1000) == 0b1000 ? head : 0,
//    //            (code & 0b0100) == 0b0100 ? tail : 0,
//    //            (code & 0b0010) == 0b0010 ? reject : 0,
//    //            (code & 0b0001) == 0b0001 ? true : false);
//    //    }
//    //    catch (MyError e) {
//    //        // 环必须识别
//    //        EXPECT_EQ(e.reason, DATA_CYCLIC);
//    //    }
//    //    catch (exception& e) {
//    //        cout << e.what() << endl;
//    //    }
//    //    code += 1;
//    //}
//
//    code = 0b0000;
//    while (code <= 0b1111) {
//        try {
//            api_res = wPlentyLinks((code & 0b1000) == 0b1000 ? head : 0,
//                (code & 0b0100) == 0b0100 ? tail : 0,
//                (code & 0b0010) == 0b0010 ? reject : 0,
//                (code & 0b0001) == 0b0001 ? true : false);
//        }
//        catch (MyError e) {
//            // 环必须识别
//            EXPECT_EQ(e.reason, DATA_CYCLIC);
//        }
//        catch (exception& e) {
//            cout << e.what() << endl;
//        }
//        code += 1;
//    }
//
//    //code = 0b0000;
//    //while (code <= 0b1111) {
//    //    try {
//    //        api_res = wFullLinks((code & 0b1000) == 0b1000 ? head : 0,
//    //            (code & 0b0100) == 0b0100 ? tail : 0,
//    //            (code & 0b0010) == 0b0010 ? reject : 0,
//    //            (code & 0b0001) == 0b0001 ? true : false);
//    //    }
//    //    catch (MyError e) {
//    //        // 环必须识别
//    //        EXPECT_EQ(e.reason, DATA_CYCLIC);
//    //    }
//    //    catch (exception& e) {
//    //        cout << e.what() << endl;
//    //    }
//    //    code += 1;
//    //}
//    //wPlentyCircle(0, 0, 0, true);
//    //wPlentyLinks(0, 0, 0, true);
//    //wFullLinks(0, 0, 0, true);
//}
//
//
///// <summary>
///// 集中测试 gen_chain_word
///// </summary>
///// <param name="NameOfTestFunction">测试函数名</param>
///// <param name="DescriptionOfAssert">渴望得到的测试效果描述</param>
//
//int cCircle(char head, char tail, char reject, bool loop) {
//    char* words[maxLength];
//    int* resNumber = (int*)malloc(sizeof(int));
//    int* maxLen = (int*)malloc(sizeof(int));
//    int len = getDifferentCircle(words, resNumber, maxLen);
//    char* res[maxLength];
//    int api_res = 0;
//    Low(words, len);
//    api_res = gen_chain_char(words, len, res, head, tail, reject, loop);
//    return api_res;
//}
//
//int cCircleDifferent(char head, char tail, char reject, bool loop) {
//    char* words[maxLength];
//    int* resNumber = (int*)malloc(sizeof(int));
//    int* maxLen = (int*)malloc(sizeof(int));
//    int len = getDifferentCircle(words, resNumber, maxLen);
//    char* res[maxLength];
//    int api_res = 0;
//    Low(words, len);
//    api_res = gen_chain_char(words, len, res, head, tail, reject, loop);
//    return api_res;
//}
//
//int cLinks(char head, char tail, char reject, bool loop) {
//    char* words[maxLength];
//    int* resNumber = (int*)malloc(sizeof(int));
//    int* maxLen = (int*)malloc(sizeof(int));
//    int len = get25HeadTailConnectLongWords(words);
//    char* res[maxLength];
//    int api_res = 0;
//    Low(words, len);
//    api_res = gen_chain_char(words, len, res, head, tail, reject, loop);
//    return api_res;
//}
//
//int cCircleRepeat(char head, char tail, char reject, bool loop) {
//    char* words[maxLength];
//    int* resNumber = (int*)malloc(sizeof(int));
//    int* maxLen = (int*)malloc(sizeof(int));
//    int len = getCircleWithRepeat(words, resNumber, maxLen);
//    char* res[maxLength];
//    int api_res = 0;
//    Low(words, len);
//    api_res = gen_chain_char(words, len, res, head, tail, reject, loop);
//    return api_res;
//}
//
//int cPlentyCircle(char head, char tail, char reject, bool loop) {
//    char* words[maxLength];
//    int* resNumber = (int*)malloc(sizeof(int));
//    int* maxLen = (int*)malloc(sizeof(int));
//    int len = getPlentyCircles(words);
//    char* res[maxLength];
//    int api_res = 0;
//    Low(words, len);
//    api_res = gen_chain_char(words, len, res, head, tail, reject, loop);
//    return api_res;
//}
//
//int cPlentyLinks(char head, char tail, char reject, bool loop) {
//    char* words[maxLength];
//    int* resNumber = (int*)malloc(sizeof(int));
//    int* maxLen = (int*)malloc(sizeof(int));
//    int len = getPlentyLinks(words);
//    char* res[maxLength];
//    int api_res = 0;
//    Low(words, len);
//    api_res = gen_chain_char(words, len, res, head, tail, reject, loop);
//    return api_res;
//}
//
//int cFullLinks(char head, char tail, char reject, bool loop) {
//    char* words[maxLength];
//    int* resNumber = (int*)malloc(sizeof(int));
//    int* maxLen = (int*)malloc(sizeof(int));
//    int len = getFullHeadTailConnectWords(words);
//    char* res[maxLength];
//    int api_res = 0;
//    Low(words, len);
//    api_res = gen_chain_char(words, len, res, head, tail, reject, loop);
//    return api_res;
//}
//
//////普通环
//TEST(CCircle, Forbid)
//{
//    int api_res = 0;
//    //// 不允许环
//    //try {
//    //    api_res = wCircle(0, 0, 0, false);
//    //}
//    //catch (MyError e) {
//    //    // 环必须识别
//    //    EXPECT_EQ(e.reason, DATA_CYCLIC);
//    //}
//    //// 结果不能超过上限
//    //EXPECT_LT(api_res, maxLength);
//    //// 结果不能低于下限
//    //EXPECT_GE(api_res, 0);
//    //printf("NCircle finish! 结果长度: %d\n", api_res);
//
//    char head = 's';
//    char tail = 'b';
//    char reject = 's';
//    int code = 0b0000;
//    while (code <= 0b1111) {
//        try {
//            api_res = cCircle((code & 0b1000) == 0b1000 ? head : 0,
//                (code & 0b0100) == 0b0100 ? tail : 0,
//                (code & 0b0010) == 0b0010 ? reject : 0,
//                (code & 0b0001) == 0b0001 ? true : false);
//        }
//        catch (MyError e) {
//            // 环必须识别
//            EXPECT_EQ(e.reason, DATA_CYCLIC);
//        }
//        catch (exception& e) {
//            cout << e.what() << endl;
//        }
//        code += 1;
//    }
//
//    code = 0b0000;
//    while (code <= 0b1111) {
//        try {
//            api_res = cCircleDifferent((code & 0b1000) == 0b1000 ? head : 0,
//                (code & 0b0100) == 0b0100 ? tail : 0,
//                (code & 0b0010) == 0b0010 ? reject : 0,
//                (code & 0b0001) == 0b0001 ? true : false);
//        }
//        catch (MyError e) {
//            // 环必须识别
//            EXPECT_EQ(e.reason, DATA_CYCLIC);
//        }
//        catch (exception& e) {
//            cout << e.what() << endl;
//        }
//        code += 1;
//    }
//
//    code = 0b0000;
//    while (code <= 0b1111) {
//        try {
//            api_res = cLinks((code & 0b1000) == 0b1000 ? head : 0,
//                (code & 0b0100) == 0b0100 ? tail : 0,
//                (code & 0b0010) == 0b0010 ? reject : 0,
//                (code & 0b0001) == 0b0001 ? true : false);
//        }
//        catch (MyError e) {
//            // 环必须识别
//            EXPECT_EQ(e.reason, DATA_CYCLIC);
//        }
//        catch (exception& e) {
//            cout << e.what() << endl;
//        }
//        code += 1;
//    }
//
//    code = 0b0000;
//    while (code <= 0b1111) {
//        try {
//            api_res = cCircleRepeat((code & 0b1000) == 0b1000 ? head : 0,
//                (code & 0b0100) == 0b0100 ? tail : 0,
//                (code & 0b0010) == 0b0010 ? reject : 0,
//                (code & 0b0001) == 0b0001 ? true : false);
//        }
//        catch (MyError e) {
//            // 环必须识别
//            EXPECT_EQ(e.reason, DATA_CYCLIC);
//        }
//        catch (exception& e) {
//            cout << e.what() << endl;
//        }
//        code += 1;
//    }
//
//    code = 0b0000;
//    while (code <= 0b1111) {
//        try {
//            api_res = cPlentyCircle((code & 0b1000) == 0b1000 ? head : 0,
//                (code & 0b0100) == 0b0100 ? tail : 0,
//                (code & 0b0010) == 0b0010 ? reject : 0,
//                (code & 0b0001) == 0b0001 ? true : false);
//        }
//        catch (MyError e) {
//            // 环必须识别
//            EXPECT_EQ(e.reason, DATA_CYCLIC);
//        }
//        catch (exception& e) {
//            cout << e.what() << endl;
//        }
//        code += 1;
//    }
//
//    code = 0b0000;
//    while (code <= 0b1111) {
//        try {
//            api_res = cPlentyLinks((code & 0b1000) == 0b1000 ? head : 0,
//                (code & 0b0100) == 0b0100 ? tail : 0,
//                (code & 0b0010) == 0b0010 ? reject : 0,
//                (code & 0b0001) == 0b0001 ? true : false);
//        }
//        catch (MyError e) {
//            // 环必须识别
//            EXPECT_EQ(e.reason, DATA_CYCLIC);
//        }
//        catch (exception& e) {
//            cout << e.what() << endl;
//        }
//        code += 1;
//    }
//
//    code = 0b0000;
//    while (code <= 0b1111) {
//        try {
//            api_res = cFullLinks((code & 0b1000) == 0b1000 ? head : 0,
//                (code & 0b0100) == 0b0100 ? tail : 0,
//                (code & 0b0010) == 0b0010 ? reject : 0,
//                (code & 0b0001) == 0b0001 ? true : false);
//        }
//        catch (MyError e) {
//            // 环必须识别
//            EXPECT_EQ(e.reason, DATA_CYCLIC);
//        }
//        catch (exception& e) {
//            cout << e.what() << endl;
//        }
//        code += 1;
//    }
//    //cPlentyCircle(0, 0, 0, true);
//    //cPlentyLinks(0, 0, 0, true);
//}
//
////int _tmain(int argc, _TCHAR* argv[])
////{
////	testing::InitGoogleTest(&argc, argv);
////	testing::GTEST_FLAG(output) = "xml:";
////	return RUN_ALL_TESTS();
////}
