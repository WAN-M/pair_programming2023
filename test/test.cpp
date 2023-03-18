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

//��ͨ����������
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
        // ������ʶ��
        EXPECT_EQ(e.reason, DATA_CYCLIC);
    }
    // ������ܳ�������
    EXPECT_LT(api_res, maxLength);
    // ������ܵ�������
    EXPECT_GE(api_res, 0);
    printf("NCircle finish! �������: %d\n", api_res);
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
        Low(words, len);
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
        Low(words, len);
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
        Low(words, len);
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
        Low(words, len);
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
        Low(words, len);
        api_res = gen_chains_all(words, len, res);
    }
    catch (MyError e) {
        // ����Ӧ���쳣
        
        cout << "û�ж�������쳣 " << e.reason << endl;
        EXPECT_EQ(e.reason, DATA_CYCLIC);
        //EXPECT_EQ(e.reason, FILE_NOT_EXIST);
    }
    // ������ܳ�������
    EXPECT_LT(api_res, maxLength);
    // ������ܵ�������
    EXPECT_GE(api_res, 0);
    //int api_res = gen_chain_char(words, len, res, 0, 0, 0, true);
    //int api_res = gen_chain_word(words, len, res, 0, 0, 0, true);
    printf("n circle-with-repeat (x) %d\n", api_res);
    //cout << e.reason << " ���ⲻӦ���쳣!" << endl;
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
        Low(words, len);
        api_res = gen_chains_all(words, len, res);
    }
    catch (MyError e) {
        // ����Ӧ���쳣
        EXPECT_EQ(e.reason, DATA_CYCLIC);
        //cout << "û�ж�������쳣 " << e.reason << endl;
        //EXPECT_EQ(e.reason, FILE_NOT_EXIST);
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
/// ���в��� gen_chain_word
/// </summary>
/// <param name="NameOfTestFunction">���Ժ�����</param>
/// <param name="DescriptionOfAssert">�����õ��Ĳ���Ч������</param>

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

////��ͨ��
TEST(WCircle, Forbid)
{
    int api_res = 0;
    //// ������
    //try {
    //    api_res = wCircle(0, 0, 0, false);
    //}
    //catch (MyError e) {
    //    // ������ʶ��
    //    EXPECT_EQ(e.reason, DATA_CYCLIC);
    //}
    //// ������ܳ�������
    //EXPECT_LT(api_res, maxLength);
    //// ������ܵ�������
    //EXPECT_GE(api_res, 0);
    //printf("NCircle finish! �������: %d\n", api_res);
    
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
            // ������ʶ��
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
            // ������ʶ��
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
            // ������ʶ��
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
            // ������ʶ��
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
            // ������ʶ��
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
            // ������ʶ��
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



////��ͨ����������
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
//        // ������ʶ��
//        EXPECT_EQ(e.reason, DATA_CYCLIC);
//    }
//    // ������ܳ�������
//    EXPECT_LT(api_res, maxLength);
//    // ������ܵ�������
//    EXPECT_GE(api_res, 0);
//    printf("NCircle finish! �������: %d\n", api_res);
//}
//
//
//// �������������
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
//        // ���ⲻӦ���쳣
//        cout << e.reason << " ���ⲻӦ���쳣!" << endl;
//    }
//    // ����ȫ������Ŀ
//    EXPECT_EQ(api_res, *resNumber);
//    printf("n self-circle (v) ȫ������ %d\n", api_res);
//}
//
//// �����д��ĸ��������������ʶ���
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
//        // ���ⲻӦ���쳣
//        cout << e.reason << " ���ⲻӦ���쳣!" << endl;
//    }
//    // ����ȫ������Ŀ
//    EXPECT_EQ(api_res, *resNumber);
//    //int api_res = gen_chain_char(words, len, res, 0, 0, 0, true);
//    //int api_res = gen_chain_word(words, len, res, 0, 0, 0, true);
//    printf("n self-circle-with-upper-char (v) %d\n", api_res);
//    //EXPECT_EQ(0, api_res);
//}
//
//// todo
//// ���ڴ�Сд��ĸ��ͬ���ɻ���������Ӧ����ʶ��
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
//        // ����Ӧ���쳣
//        EXPECT_EQ(e.reason, DATA_CYCLIC);
//    }
//    // ������ܳ�������
//    EXPECT_LT(api_res, maxLength);
//    // ������ܵ�������
//    EXPECT_GE(api_res, 0);
//    //int api_res = gen_chain_char(words, len, res, 0, 0, 0, true);
//    //int api_res = gen_chain_word(words, len, res, 0, 0, 0, true);
//    printf("n circle-with-upper-char (x) %d\n", api_res);
//    //EXPECT_EQ(0, api_res);
//}
//
//// �ظ����ʣ����������ظ�
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
//        // ����Ӧ���쳣
//        //EXPECT_EQ(e.reason, DATA_CYCLIC);
//        cout << "û�ж�������쳣 " << e.reason << endl;
//        EXPECT_EQ(e.reason, FILE_NOT_EXIST);
//    }
//    // ������ܳ�������
//    EXPECT_LT(api_res, maxLength);
//    // ������ܵ�������
//    EXPECT_GE(api_res, 0);
//    //int api_res = gen_chain_char(words, len, res, 0, 0, 0, true);
//    //int api_res = gen_chain_word(words, len, res, 0, 0, 0, true);
//    printf("n repeat (x) %d\n", api_res);
//    //EXPECT_EQ(0, api_res);
//}
//
//// ��Ϊ�ظ����ʵ��³ɻ���������
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
//        // ����Ӧ���쳣
//        //EXPECT_EQ(e.reason, DATA_CYCLIC);
//        cout << "û�ж�������쳣 " << e.reason << endl;
//        EXPECT_EQ(e.reason, FILE_NOT_EXIST);
//    }
//    // ������ܳ�������
//    EXPECT_LT(api_res, maxLength);
//    // ������ܵ�������
//    EXPECT_GE(api_res, 0);
//    //int api_res = gen_chain_char(words, len, res, 0, 0, 0, true);
//    //int api_res = gen_chain_word(words, len, res, 0, 0, 0, true);
//    printf("n circle-with-repeat (x) %d\n", api_res);
//    //cout << e.reason << " ���ⲻӦ���쳣!" << endl;
//    //EXPECT_EQ(0, api_res);
//}
//
//// todo
//// �����ͬ����������
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
//        // ����Ӧ���쳣
//        EXPECT_EQ(e.reason, DATA_CYCLIC);
//        //cout << "û�ж�������쳣 " << e.reason << endl;
//        //EXPECT_EQ(e.reason, FILE_NOT_EXIST);
//    }
//    // ������ܳ�������
//    EXPECT_LT(api_res, maxLength);
//    // ������ܵ�������
//    EXPECT_GE(api_res, 0);
//    //int api_res = gen_chain_char(words, len, res, 0, 0, 0, true);
//    //int api_res = gen_chain_word(words, len, res, 0, 0, 0, true);
//    printf("n different-circle (x) %d\n", api_res);
//    //EXPECT_EQ(0, api_res);
//}
/// <summary>
/// ���������޸�
/// </summary>
/// <param name="argc"></param>
/// <param name="argv"></param>
/// <returns></returns>


/// <summary>
/// ���в��� gen_chain_word
/// </summary>
/// <param name="NameOfTestFunction">���Ժ�����</param>
/// <param name="DescriptionOfAssert">�����õ��Ĳ���Ч������</param>

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

////��ͨ��
TEST(CCircle, Forbid)
{
    int api_res = 0;
    //// ������
    //try {
    //    api_res = wCircle(0, 0, 0, false);
    //}
    //catch (MyError e) {
    //    // ������ʶ��
    //    EXPECT_EQ(e.reason, DATA_CYCLIC);
    //}
    //// ������ܳ�������
    //EXPECT_LT(api_res, maxLength);
    //// ������ܵ�������
    //EXPECT_GE(api_res, 0);
    //printf("NCircle finish! �������: %d\n", api_res);

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
            // ������ʶ��
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
            // ������ʶ��
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
            // ������ʶ��
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
            // ������ʶ��
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
            // ������ʶ��
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
            // ������ʶ��
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
