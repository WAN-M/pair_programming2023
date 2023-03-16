//
// pch.cpp
//

#include "pch.h"
#include <iostream>
#include<fstream>
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

void getWord(char** allWords, int index, char start, char end, int length, bool upper) {
    char* res = (char*) malloc(sizeof (char ) * (length + 1));
	res[0] = start;
	for (int i = 1; i < length - 1; i++) {
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
    res[length - 1] = end;
	res[length] = '\0';

	//printf("%s\n", word.c_str());


	//printf("%s\n", res);
	*(allWords + index) = res;

	//printf("%s\n", index, allWords[index]);
}

/// <summary>
/// 26连续长单词
/// </summary>
/// <returns></returns>
int getWords(char** words) {
	for (int i = 0; i < 25; i++) {
		getWord(words, i, 'a' + i, 'a' + i + 1, 5, true);
		//printf("%s\n", words[i]);
	}
	/*for (int i = 0; i < 25; i++) {
		printf("%s\n", *(words + i));
		append("test.txt", *(words + i));
	}*/
	return 25;
}

int main() {
	/*getWords();*/
	//char** words = (char**)malloc(sizeof(char*) * 20001);
	//int len = getWords(words);

	char* words[] = {
		"aPqhb",
        "bmaLc",
        "cLDfd",
        "drvCe",
        "egbKf",
        "fndxg",
        "gFfZh",
        "hStJi",
        "irpGj",
        "jRNvk",
        "kSmcl",
        "lsyQm",
        "mEiEn",
        "nfZio",
        "okavp",
        "pSEzq",
        "qyXXr",
        "rlgps",
        "sfDot",
        "tEXbu",
        "uojVv",
        "vvbyw",
        "wpeLx",
        "xPNLy",
        "yVvpz",
	};

	char** res = (char**)malloc(sizeof(char*) * maxLength);
	for (int i = 0; i < 25; i++) {
		printf("%s\n", *(words + i));
		//append("test.txt", *(words + i));
	}
    try{
        int api_res = gen_chains_all(words, 25, res);
//		free(words);
		free(res);
        printf("%d\n", api_res);
    }
	catch (exception &e){
        cout<< e.what() <<endl;
    }

	//ofstr();
	return 0;
}