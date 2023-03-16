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
	ofstream ofs;						//����������
	ofs.open(path, ios::app);		//��д�ķ�ʽ���ļ�
	ofs << str << endl;//д��
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
/// 26����������
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
	char** words = (char**)malloc(sizeof(char*) * 20001);
	int len = getWords(words);
	char** res = (char**)malloc(sizeof(char*) * maxLength);
	for (int i = 0; i < 25; i++) {
		printf("%s\n", *(words + i));
		//append("test.txt", *(words + i));
	}
	int api_res = gen_chains_all(words, len, res);
	printf("%d\n", api_res);
	//ofstr();
	return 0;
}