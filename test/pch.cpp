//
// pch.cpp
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include "core/library.h"
#define maxLength 20001
using namespace std;
 
void append(string path, char* str)
{
	ofstream ofs;						//定义流对象
	ofs.open(path, ios::app);		//以写的方式打开文件
	ofs << str << endl;//写入
	ofs.close();
}

void create(string path)
{
	ofstream ofs;						//定义流对象
	ofs.open(path, ios::in);		//以写的方式打开文件
	ofs << "";//写入
	ofs.close();
}

void getWord(char* allWords[], int index, char start, char end, int length, bool upper) {
    char* res = (char*) malloc(sizeof(char) * length);
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
/// 25连续长单词
/// </summary>
/// <returns></returns>
int get25HeadTailConnectLongWords(char* words[]) {
	int number = 25;
	string path = "./0_25个首尾相连长单词.txt";
	for (int i = 0; i < number; i++) {
		getWord(words, i, 'a' + i, 'a' + i + 1, 8, true);
		//printf("%s\n", words[i]);
	}
	create(path);
	for (int i = 0; i < number; i++) {
		printf("%s\n", words[i]);
		append(path, words[i]);
	}
	return number;
}

/// <summary>
/// a->z,b->z,...
/// 全联通网络
/// </summary>
/// <param name="words"></param>
/// <returns></returns>
int getFullHeadTailConnectWords(char** words) {
	int number = 25;
	int count = 0;
	string path = "./1_全联通网络.txt";
	for (int i = 0; i < number; i++) {
		for (int j = i; j < number - 1; j++) {
			getWord(words, i * number + j, 'a' + j, 'a' + j + 1, 8, true);
			count += 1;
		}
		//printf("%s\n", words[i]);
	}
	create(path);
	for (int i = 0; i < number; i++) {
		printf("%s\n", words[i]);
		append(path, words[i]);
	}
	return count;
}

/// <summary>
/// 单词存在环路
/// </summary>
/// <param name="words"></param>
/// <returns></returns>
int getCircle(char** words, int* resNumber, int* maxLen){
    words[0] = (char *)"ssstd";
    words[1] = (char *)"dab";
    words[2] = (char *)"bccca";
    words[3] = (char *)"assbd";
    words[4] = (char *)"ssdtb";

	*resNumber = 12;
	*maxLen = 3;

    return 5;
}

/// <summary>
/// 单词带自环
/// </summary>
/// <param name="words"></param>
/// <returns></returns>
int getSelfCircle(char** words, int * resNumber, int *maxLen){
    words[0] = (char *)"abcxde";
    words[1] = (char *)"abxxscdc";
    words[2] = (char *)"abcsssssda";
    words[3] = (char *)"edassssssssssssssat";
    words[4] = (char *)"tckssssssssskk";

	*resNumber = 7;
	*maxLen = 4;

    return 5;
}

/// <summary>
/// 单词带自环且大小写
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
/// 单词存在环路且大小写成环
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
/// 单词重复
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
/// 单词重复且成环
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
/// 多单词链
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

	return 5;
}

/// <summary>
/// 超级多单词链
/// </summary>
/// <param name="words"></param>
/// <returns></returns>
int getPlentyLinks(char** words) {
	int number = 25;
	string path = "tooManyLinks.txt";
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			getWord(words, i * number + j, 'a' + i, 'a' + i + 1, 4 + rand() % (j + 1), true);
		}
		
		//printf("%s\n", words[i]);
	}
	create(path);
	for (int i = 0; i < number * number; i++) {
		printf("%s\n", *(words + i));
		append(path, *(words + i));
	}
	return number;
}

/// <summary>
/// 超级多单词环
/// </summary>
/// <param name="words"></param>
/// <returns></returns>
int getPlentyCircles(char** words) {
	int number = 26;
	string path = "./3_超多单词环.txt";
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			if (i != 25) {
				getWord(words, i * number + j, 'a' + i, 'a' + i + 1, 4 + rand() % (j + 1), true);
			}
			else
			{
				getWord(words, i * number + j, 'a' + i, 'a', 4 + rand() % (j + 1), true);
			}
		}
		//printf("%s\n", words[i]);
	}
	create(path);
	for (int i = 0; i < number; i++) {
		printf("%s\n", *(words + i));
		append(path, *(words + i));
	}
	return number;
}

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