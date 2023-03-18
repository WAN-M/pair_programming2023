#include <iostream>
#include <fstream>
#include <set>
#include <cstring>
#include "library.h"

using namespace std;

//
// pch.cpp
//

#include <iostream>
#include <fstream>
#include "exception/CommandException.h"
#include "exception/FileException.h"
#include "exception/RuntimeException.h"

#define maxLength 20001
#define release true

using namespace std;

void append(string path, char* str)
{
	ofstream ofs;						//����������
	ofs.open(path, ios::app);		//��д�ķ�ʽ���ļ�
	ofs << str << endl;//д��
	ofs.close();
}

void create(string path)
{
	ofstream ofs;						//����������
	ofs.open(path, ios::in);		//��д�ķ�ʽ���ļ�
	ofs << "";//д��
	ofs.close();
}

void getWord(char* allWords[], int index, char start, char end, int length, bool upper) {
	char* res = (char*)malloc(sizeof(char) * length);
	res[0] = start;
	for (int i = 1; i < length - 2; i++) {
		int up = 0;
		char temp = 'a' + rand() % 26;
		if (upper) {
			up = rand() % 2;
		}
		if (up == 1) {
			temp = temp - 'a' + 'A';
		}
		res[i] = temp;
	}
	res[length - 2] = end;
	res[length - 1] = 0;

	//printf("%s\n", word.c_str());
	allWords[index] = (char*)malloc(sizeof(char) * (length + 5));
	strcpy(allWords[index], res);

	free(res);
	//printf("%s\n", res);
	//*(allWords + index) = res;

	//printf("%s\n", index, allWords[index]);
}

/// <summary>
/// 25����������
/// </summary>
/// <returns></returns>
int get25HeadTailConnectLongWords(char* words[]) {
	int number = 25;
	string path = "./0_25����β����������.txt";
	for (int i = 0; i < number; i++) {
		getWord(words, i, 'a' + i, 'a' + i + 1, 10000, true);
		//printf("%s\n", words[i]);
	}
	//create(path);
	//for (int i = 0; i < number; i++) {
	//	printf("%s\n", words[i]);
	//	append(path, words[i]);
	//}
	return number;
}

/// <summary>
/// a->z,b->z,...
/// ȫ��ͨ����
/// </summary>
/// <param name="words"></param>
/// <returns></returns>
int getFullHeadTailConnectWords(char** words) {
	int number = 26;
	int count = 0;
	string path = "./1_ȫ��ͨ����.txt";
    //cout << "s" << endl;
	for (int i = 0; i < number; i++) {
		for (int j = i; j < number - 1; j++) {
			getWord(words, count, 'a' + j, 'a' + j + 1, 8, true);
            //printf("%s\n", words[count]);
			count += 1;
		}
	}
    for (int i = 0; i < number; i++) {
        getWord(words, count, 'a' + i, 'a' + i, 8, true);
        count += 1;
    }

	//pri
	//create(path);
    //count = 5;
	
    ////int count = 5;
    //words[0] = (char*)"aPqhmab";
    //words[1] = (char*)"bLLDfrc";
    //words[2] = (char*)"cvCgbKd";
    //words[3] = (char*)"cndxFfc";
    //words[4] = (char*)"eZStJrf";
    //words[5] = (char*)"cddd";
     //wordRepeat;
    for (int i = 0; i < count; i++) {
    	printf("word %s\n", words[i]);
    	append(path, words[i]);
        //if(wordRepeat..);
    }
	return count;
}

/// <summary>
/// ���ʴ��ڻ�·
/// </summary>
/// <param name="words"></param>
/// <returns></returns>
int getCircle(char** words, int* resNumber, int* maxLen) {
	words[0] = (char*)"ssstd";
	words[1] = (char*)"dab";
	words[2] = (char*)"bccca";
	words[3] = (char*)"assbd";
	words[4] = (char*)"ssdtb";

	*resNumber = 12;
	*maxLen = 3;

	return 5;
}

/// <summary>
/// ���ʴ��Ի�
/// </summary>
/// <param name="words"></param>
/// <returns></returns>
int getSelfCircle(char** words, int* resNumber, int* maxLen) {
	words[0] = (char*)"abcxde";
	words[1] = (char*)"abxxscdc";
	words[2] = (char*)"abcsssssda";
	words[3] = (char*)"edassssssssssssssat";
	words[4] = (char*)"tckssssssssskk";

	*resNumber = 7;
	*maxLen = 4;

	return 5;
}

/// <summary>
/// ���ʴ��Ի��Ҵ�Сд
/// </summary>
/// <param name="words"></param>
/// <returns></returns>
int getSelfCircleWithUpperChar(char** words, int* resNumber, int* maxLen) {
	words[0] = (char*)"abcde";
	words[1] = (char*)"Abcdc";
	words[2] = (char*)"abcdA";
	words[3] = (char*)"edaat";
	words[4] = (char*)"tckkk";

	*resNumber = 7;
	*maxLen = 4;

	return 5;
}

/// <summary>
/// ���ʴ��ڻ�·�Ҵ�Сд�ɻ�
/// </summary>
/// <param name="words"></param>
/// <returns></returns>
int getCircleWithUpperChar(char** words, int* resNumber, int* maxLen) {
	words[0] = (char*)"abcdE";
	words[1] = (char*)"eccct";
	words[2] = (char*)"tbbaA";
	words[3] = (char*)"Evjju";
	words[4] = (char*)"ubv";

	*resNumber = 12;
	*maxLen = 4;

	return 5;
}

/// <summary>
/// �����ظ�
/// </summary>
/// <param name="words"></param>
/// <returns></returns>
int getRepeat(char** words, int* resNumber, int* maxLen) {
	words[0] = (char*)"abcdE";
	words[1] = (char*)"eccct";
	words[2] = (char*)"tbbab";
	words[3] = (char*)"BaaaB";
	words[4] = (char*)"abcdE";

	*resNumber = 9;
	*maxLen = 4;

	return 5;
}

/// <summary>
/// �����ظ��ҳɻ�
/// </summary>
/// <param name="words"></param>
/// <returns></returns>
int getCircleWithRepeat(char** words, int* resNumber, int* maxLen) {
	words[0] = (char*)"abcdE";
	words[1] = (char*)"eccct";
	words[2] = (char*)"BaaaB";
	words[3] = (char*)"BaaaB";
	words[4] = (char*)"tss";

	*resNumber = 4;
	*maxLen = 3;

	return 5;
}

/// <summary>
/// �൥����
/// </summary>
/// <param name="words"></param>
/// <returns></returns>
int getDifferentCircle(char** words, int* resNumber, int* maxLen) {
	words[0] = (char*)"abcssssddE";
	words[1] = (char*)"eccdct";
	words[2] = (char*)"BaasssssssssaB";
	words[3] = (char*)"bv";
	words[4] = (char*)"vqxs";
	words[5] = (char*)"fss";
	words[6] = (char*)"sbxxbvu";
	words[7] = (char*)"sssso";

	*resNumber = 12;
	*maxLen = 4;

	return 8;
}

/// <summary>
/// �����൥����
/// </summary>
/// <param name="words"></param>
/// <returns></returns>
int getPlentyLinks(char** words) {
	int number = 25;
	int count = 0;
	string path = "./2_���൥����.txt";
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			getWord(words, i * number + j, 'a' + i, 'a' + i + 1, 4 + rand() % (j + 1), true);
			count++;
		}

		//printf("%s\n", words[i]);
	}
	//create(path);
	//for (int i = 0; i < count; i++) {
	//	printf("%s\n", *(words + i));
	//	append(path, *(words + i));
	//}
	return count;
}

/// <summary>
/// �����൥�ʻ�
/// </summary>
/// <param name="words"></param>
/// <returns></returns>
int getPlentyCircles(char** words) {
	int number = 26;
	int count = 0;
	string path = "./3_���൥�ʻ�.txt";
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			if (i != 25) {
				getWord(words, i * number + j, 'a' + i, 'a' + i + 1, 4 + rand() % (j + 1), true);
			}
			else
			{
				getWord(words, i * number + j, 'a' + i, 'a', 4 + rand() % (j + 1), true);
			}
			count++;
		}
		//printf("%s\n", words[i]);
	}
	//create(path);
	//for (int i = 0; i < count; i++) {
	//	printf("%s\n", *(words + i));
	//	append(path, *(words + i));
	//}
	return count;
}


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

void myappend(string path, char* str)
{
    ofstream ofs;						//����������
    ofs.open(path, ios::app);		//��д�ķ�ʽ���ļ�
    ofs << str << endl;//д��
    ofs.close();
}

void mycreate(string path)
{
    ofstream ofs;						//����������
    ofs.open(path, ios::in);		//��д�ķ�ʽ���ļ�
    ofs << "";//д��
    ofs.close();
}

//��ͨ����������
void NCircle()
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
    catch (CommandException e) {
        cout << e.getInfomation() << endl;
    }
    catch (FileException e) {
        cout << e.getInfomation() << endl;
    }
    catch (RuntimeException e) {
        cout << e.getInfomation() << endl;
    }
    catch (exception e) {
        cout << "unknown exception" << endl;
    }
    //// ������ܳ�������
    //EXPECT_LT(api_res, maxLength);
    //// ������ܵ�������
    //EXPECT_GE(api_res, 0);
    printf("NCircle finish! �������: %d\n", api_res);
    //free(words);
    /*for (int i = 0; i < len; i++) {
        free(words[i]);
    }
    free(resNumber);
    free(maxLen);*/

    //string path;
    //if (release) {
    //    path = "reNCircle.txt";
    //}
    //else
    //{
    //    path = "deNCircle.txt";
    //}
    //mycreate(path);
    //for (int i = 0; i < api_res; i++) {
    //    printf("%s\n", res[i]);
    //    myappend(path, res[i]);
    //}

    //delete res;
}

// �������������
void NSelfCircle()
{
    char* words[maxLength];
    int* resNumber = (int*)malloc(sizeof(int));
    int* maxLen = (int*)malloc(sizeof(int));
    int len = getSelfCircle(words, resNumber, maxLen);
    char* res[maxLength];

    int api_res = 0;
    try {
        Low(words, len);
        api_res = gen_chains_all(words, len, res);
    }
    catch (CommandException e) {
        cout << e.getInfomation() << endl;
    }
    catch (FileException e) {
        cout << e.getInfomation() << endl;
    }
    catch (RuntimeException e) {
        cout << e.getInfomation() << endl;
    }
    catch (exception e) {
        cout << "unknown exception" << endl;
    }
    // ����ȫ������Ŀ
    //EXPECT_EQ(api_res, *resNumber);
    printf("n self-circle (v) ȫ������ %d\n", api_res);

    /*string path;
    if (release) {
        path = "reNSelfCircle.txt";
    }
    else
    {
        path = "deNSelfCircle.txt";
    }
    mycreate(path);
    for (int i = 0; i < api_res; i++) {
        printf("%s\n", res[i]);
        myappend(path, res[i]);
    }*/
}

// �����д��ĸ��������������ʶ���
void NSelfCircleWithUpperChar()
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
    catch (CommandException e) {
        cout << e.getInfomation() << endl;
    }
    catch (FileException e) {
        cout << e.getInfomation() << endl;
    }
    catch (RuntimeException e) {
        cout << e.getInfomation() << endl;
    }
    catch (exception e) {
        cout << "unknown exception" << endl;
    }
    // ����ȫ������Ŀ
    //EXPECT_EQ(api_res, *resNumber);
    //int api_res = gen_chain_char(words, len, res, 0, 0, 0, true);
    //int api_res = gen_chain_word(words, len, res, 0, 0, 0, true);
    printf("n self-circle-with-upper-char (v) %d\n", api_res);
    //EXPECT_EQ(0, api_res);
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
// ���ڴ�Сд��ĸ��ͬ���ɻ���������Ӧ����ʶ��
void NCircleWithUpperChar()
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
    catch (CommandException e) {
        cout << e.getInfomation() << endl;
    }
    catch (FileException e) {
        cout << e.getInfomation() << endl;
    }
    catch (RuntimeException e) {
        cout << e.getInfomation() << endl;
    }
    catch (exception e) {
        cout << "unknown exception" << endl;
    }
    // ������ܳ�������
    //EXPECT_LT(api_res, maxLength);
    //// ������ܵ�������
    //EXPECT_GE(api_res, 0);
    //int api_res = gen_chain_char(words, len, res, 0, 0, 0, true);
    //int api_res = gen_chain_word(words, len, res, 0, 0, 0, true);
    printf("n circle-with-upper-char (x) %d\n", api_res);
    //EXPECT_EQ(0, api_res);
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

// �ظ����ʣ����������ظ�
void NRepeat()
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
    catch (CommandException e) {
        cout << e.getInfomation() << endl;
    }
    catch (FileException e) {
        cout << e.getInfomation() << endl;
    }
    catch (RuntimeException e) {
        cout << e.getInfomation() << endl;
    }
    catch (exception e) {
        cout << "unknown exception" << endl;
    }
    //// ������ܳ�������
    //EXPECT_LT(api_res, maxLength);
    //// ������ܵ�������
    //EXPECT_GE(api_res, 0);
    //int api_res = gen_chain_char(words, len, res, 0, 0, 0, true);
    //int api_res = gen_chain_word(words, len, res, 0, 0, 0, true);
    printf("n repeat (x) %d\n", api_res);
    //EXPECT_EQ(0, api_res);
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

// ��Ϊ�ظ����ʵ��³ɻ���������
void NCircleWithRepeat()
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
    catch (CommandException e) {
        cout << e.getInfomation() << endl;
    }
    catch (FileException e) {
        cout << e.getInfomation() << endl;
    }
    catch (RuntimeException e) {
        cout << e.getInfomation() << endl;
    }
    catch (exception e) {
        cout << "unknown exception" << endl;
    }
    // ������ܳ�������
    //EXPECT_LT(api_res, maxLength);
    //// ������ܵ�������
    //EXPECT_GE(api_res, 0);
    //int api_res = gen_chain_char(words, len, res, 0, 0, 0, true);
    //int api_res = gen_chain_word(words, len, res, 0, 0, 0, true);
    printf("n circle-with-repeat (x) %d\n", api_res);
    //cout << e.reason << " ���ⲻӦ���쳣!" << endl;
    //EXPECT_EQ(0, api_res);
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

// todo
// �����ͬ��������
void NDifferentCircle()
{
    char* words[maxLength];
    int* resNumber = (int*)malloc(sizeof(int));
    int* maxLen = (int*)malloc(sizeof(int));

    int len = getDifferentCircle(words, resNumber, maxLen);
    char* res[maxLength];

    int api_res = 0;
    //try {
        Low(words, len);
        api_res = gen_chains_all(words, len, res);
    //}
    //catch (MyError e) {
    //    // ����Ӧ���쳣
    //    //EXPECT_EQ(e.reason, DATA_CYCLIC);
    //    cout << e.reason << endl;
    //    //EXPECT_EQ(e.reason, FILE_NOT_EXIST);
    //}
    //// ������ܳ�������
    //EXPECT_LT(api_res, maxLength);
    //// ������ܵ�������
    //EXPECT_GE(api_res, 0);
    //int api_res = gen_chain_char(words, len, res, 0, 0, 0, true);
    //int api_res = gen_chain_word(words, len, res, 0, 0, 0, true);
    printf("n different-circle (x) %d\n", api_res);
    //EXPECT_EQ(0, api_res);
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
    for (int i = 0; i < api_res; i++) {
        printf("%s\n", res[i]);
        //myappend(path, words[i]);
    }
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
    //api_res = gen_chains_all(words, len, res);
    return api_res;
}

int printWFullLink(char head, char tail, char reject, bool loop) {
    char* words[maxLength];
    int* resNumber = (int*)malloc(sizeof(int));
    int* maxLen = (int*)malloc(sizeof(int));
    int len = getFullHeadTailConnectWords(words);
    char* res[maxLength];
    int api_res = 0;
    //Low(words, len);
    try {
        api_res = gen_chain_word(words, len, res, head, tail, reject, loop);
    }
    catch (CommandException e) {
        cout << e.getInfomation() << endl;
    }
    catch (FileException e) {
        cout << e.getInfomation() << endl;
    }
    catch (RuntimeException e) {
        cout << e.getInfomation() << endl;
    }
    catch (exception e) {
        cout << "unknown exception" << endl;
    }
    //api_res = gen_chains_all(words, len, res);

    //string path;
    //if (release) {
    //    path = "reNDifferentCircle.txt";
    //}
    //else
    //{
    //    path = "deNDifferentCircle.txt";
    //}
    //mycreate(path);
    //for (int i = 0; i < len; i++) {
    //    //printf("%s\n", words[i]);
    //    myappend(path, words[i]);
    //}

    for (int i = 0; i < api_res; i++) {
        printf("res %s\n", res[i]);
        //myappend(path, res[i]);
    }

    cout << api_res << endl;
    return api_res;
}

////��ͨ��
void WCircle()
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
        catch (CommandException e) {
            cout << e.getInfomation() << endl;
        }
        catch (FileException e) {
            cout << e.getInfomation() << endl;
        }
        catch (RuntimeException e) {
            cout << e.getInfomation() << endl;
        }
        catch (exception e) {
            cout << "unknown exception" << endl;
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
        catch (CommandException e) {
            cout << e.getInfomation() << endl;
        }
        catch (FileException e) {
            cout << e.getInfomation() << endl;
        }
        catch (RuntimeException e) {
            cout << e.getInfomation() << endl;
        }
        catch (exception e) {
            cout << "unknown exception" << endl;
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
        catch (CommandException e) {
            cout << e.getInfomation() << endl;
        }
        catch (FileException e) {
            cout << e.getInfomation() << endl;
        }
        catch (RuntimeException e) {
            cout << e.getInfomation() << endl;
        }
        catch (exception e) {
            cout << "unknown exception" << endl;
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
        catch (CommandException e) {
            cout << e.getInfomation() << endl;
        }
        catch (FileException e) {
            cout << e.getInfomation() << endl;
        }
        catch (RuntimeException e) {
            cout << e.getInfomation() << endl;
        }
        catch (exception e) {
            cout << "unknown exception" << endl;
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
        catch (CommandException e) {
            cout << e.getInfomation() << endl;
        }
        catch (FileException e) {
            cout << e.getInfomation() << endl;
        }
        catch (RuntimeException e) {
            cout << e.getInfomation() << endl;
        }
        catch (exception e) {
            cout << "unknown exception" << endl;
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
        catch (CommandException e) {
            cout << e.getInfomation() << endl;
        }
        catch (FileException e) {
            cout << e.getInfomation() << endl;
        }
        catch (RuntimeException e) {
            cout << e.getInfomation() << endl;
        }
        catch (exception e) {
            cout << "unknown exception" << endl;
        }
        code += 1;
    }

    code = 0b0000;
    while (code <= 0b1111) {
        try {
            api_res = wFullLinks((code & 0b1000) == 0b1000 ? head : 0,
                (code & 0b0100) == 0b0100 ? tail : 0,
                (code & 0b0010) == 0b0010 ? reject : 0,
                (code & 0b0001) == 0b0001 ? true : false);
        }
        catch (CommandException e) {
            cout << e.getInfomation() << endl;
        }
        catch (FileException e) {
            cout << e.getInfomation() << endl;
        }
        catch (RuntimeException e) {
            cout << e.getInfomation() << endl;
        }
        catch (exception e) {
            cout << "unknown exception" << endl;
        }
        code += 1;
    }
    //wPlentyCircle(0, 0, 0, true);
    //wPlentyLinks(0, 0, 0, true);
    //wFullLinks(0, 0, 0, true);
}


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

int cFullLinks(char head, char tail, char reject, bool loop) {
    char* words[maxLength];
    int* resNumber = (int*)malloc(sizeof(int));
    int* maxLen = (int*)malloc(sizeof(int));
    int len = getFullHeadTailConnectWords(words);
    char* res[maxLength];
    int api_res = 0;
    Low(words, len);
    api_res = gen_chain_char(words, len, res, head, tail, reject, loop);
    return api_res;
}

////��ͨ��
void CCircle()
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
        catch (CommandException e) {
            cout << e.getInfomation() << endl;
        }
        catch (FileException e) {
            cout << e.getInfomation() << endl;
        }
        catch (RuntimeException e) {
            cout << e.getInfomation() << endl;
        }
        catch (exception e) {
            cout << "unknown exception" << endl;
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
        catch (CommandException e) {
            cout << e.getInfomation() << endl;
        }
        catch (FileException e) {
            cout << e.getInfomation() << endl;
        }
        catch (RuntimeException e) {
            cout << e.getInfomation() << endl;
        }
        catch (exception e) {
            cout << "unknown exception" << endl;
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
        catch (CommandException e) {
            cout << e.getInfomation() << endl;
        }
        catch (FileException e) {
            cout << e.getInfomation() << endl;
        }
        catch (RuntimeException e) {
            cout << e.getInfomation() << endl;
        }
        catch (exception e) {
            cout << "unknown exception" << endl;
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
        catch (CommandException e) {
            cout << e.getInfomation() << endl;
        }
        catch (FileException e) {
            cout << e.getInfomation() << endl;
        }
        catch (RuntimeException e) {
            cout << e.getInfomation() << endl;
        }
        catch (exception e) {
            cout << "unknown exception" << endl;
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
        catch (CommandException e) {
            cout << e.getInfomation() << endl;
        }
        catch (FileException e) {
            cout << e.getInfomation() << endl;
        }
        catch (RuntimeException e) {
            cout << e.getInfomation() << endl;
        }
        catch (exception e) {
            cout << "unknown exception" << endl;
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
        catch (CommandException e) {
            cout << e.getInfomation() << endl;
        }
        catch (FileException e) {
            cout << e.getInfomation() << endl;
        }
        catch (RuntimeException e) {
            cout << e.getInfomation() << endl;
        }
        catch (exception e) {
            cout << "unknown exception" << endl;
        }
        code += 1;
    }

    code = 0b0000;
    while (code <= 0b1111) {
        try {
            api_res = cFullLinks((code & 0b1000) == 0b1000 ? head : 0,
                (code & 0b0100) == 0b0100 ? tail : 0,
                (code & 0b0010) == 0b0010 ? reject : 0,
                (code & 0b0001) == 0b0001 ? true : false);
        }
        catch (CommandException e) {
            cout << e.getInfomation() << endl;
        }
        catch (FileException e) {
            cout << e.getInfomation() << endl;
        }
        catch (RuntimeException e) {
            cout << e.getInfomation() << endl;
        }
        catch (exception e) {
            cout << "unknown exception" << endl;
        }
        code += 1;
    }
    //cPlentyCircle(0, 0, 0, true);
    //cPlentyLinks(0, 0, 0, true);
}

//// todo
//// �����ͬ����������
//TEST(NFullLinks, Forbid)
//{
//    char* words[maxLength];
//    int* resNumber = (int*)malloc(sizeof(int));
//    int* maxLen = (int*)malloc(sizeof(int));
//
//    int len = getFullHeadTailConnectWords(words);
//    char* res[maxLength];
//
//    int api_res = 0;
//    try {
//        Low(words, len);
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
//    string path;
//    if (release) {
//        path = "reNFullLinks.txt";
//    }
//    else
//    {
//        path = "deNFullLinks.txt";
//    }
//    //string path = mode + "NDifferentCircle.txt";
//    mycreate(path);
//    for (int i = 0; i < api_res; i++) {
//        printf("%s\n", words[i]);
//        myappend(path, words[i]);
//    }
//}

//int other() {
//	/*getWords();*/
//	//char** words = (char**)malloc(sizeof(char*) * 20001);
//	//int len = getWords(words);
//
//	char* words[] = {
//		"aPqhb",
//		"bmaLc",
//		"cLDfd",
//		"drvCe",
//		"egbKf",
//		"fndxg",
//		"gFfZh",
//		"hStJi",
//		"irpGj",
//		"jRNvk",
//		"kSmcl",
//		"lsyQm",
//		"mEiEn",
//		"nfZio",
//		"okavp",
//		"pSEzq",
//		"qyXXr",
//		"rlgps",
//		"sfDot",
//		"tEXbu",
//		"uojVv",
//		"vvbyw",
//		"wpeLx",
//		"xPNLy",
//		"yVvpz",
//	};
//
//	char** res = (char**)malloc(sizeof(char*) * maxLength);
//	for (int i = 0; i < 25; i++) {
//		printf("%s\n", *(words + i));
//		//append("test.txt", *(words + i));
//	}
//	try {
//		int api_res = gen_chains_all(words, 25, res);
//		//		free(words);
//		for (int i = 0; i < maxLength; i++) {
//			free(res[i]);
//		}
//		free(res);
//		printf("%d\n", api_res);
//	}
//	catch (exception& e) {
//		cout << e.what() << endl;
//	}
//
//	//ofstr();
//	return 0;
//}

//#undef main
//int main() {
//	char* words1[maxLength];
//	get25HeadTailConnectLongWords(words1);
//	char* words2[maxLength];
//	getPlentyCircles(words2);
//	char* words3[maxLength];
//	getPlentyLinks(words3);
//	char* words4[maxLength];
//	getFullHeadTailConnectWords(words4);
//}

//int readAvailableFile(char *data[], const char *const fileName) {
//    fstream inFile;
//    inFile.open(fileName, ios::in);
//    if (!inFile.is_open()) {
//        cout << "���ļ�ʧ��" << endl;
//    }
//
//    set<string> words;
//    char *buf = (char *) malloc(sizeof(char) * 50);
//    int cnt = 0;
//    char c;
//    int size = 0;
//    while (!inFile.eof()) {
//        c = (char) inFile.get();
////        inFile >> c;
//        if (inFile.fail()) {
//            break;
//        }
//        if (isalpha(c)) {
//            buf[cnt++] = (char) tolower(c);
//        } else {
//            if (cnt > 0) {
//                buf[cnt] = 0;
//                if (words.find(buf) == words.end()) {
//                    words.insert(buf);
//                    data[size] = (char *) malloc(sizeof(char) * (cnt + 5));
//                    strcpy(data[size++], buf);
//                }
//            }
//            cnt = 0;
//        }
//    }
//    if (cnt > 0) {
//        buf[cnt] = 0;
//        data[size] = (char *) malloc(sizeof(char) * (cnt + 5));
//        strcpy(data[size++], buf);
//    }
//    free(buf);
//    inFile.close();
//
//    return size;
//}
////

void run() {
    NCircle();
    NSelfCircle();
    NSelfCircleWithUpperChar();
    NCircleWithUpperChar();
    NRepeat();
    NCircleWithRepeat();
    NDifferentCircle();

    //WCircle();
    //CCircle();
}

int main() {

    /*char *words[100];
    int len = readAvailableFile(words, "D:\\pair_programming2023\\src\\exe\\cmake-build-debug\\test.txt");
    char *result[200];
    int reSize = gen_chains_all(words, len, result);
    cout << reSize << endl;
    for (int i = 0; i < reSize; i++) {
        std::cout << result[i] << std::endl;
    }*/

    //run();
    //cout << "s" << endl;

    printWFullLink(0, 'c', 'd', true);

    return 0;
}
