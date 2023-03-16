//
// Created by DELL on 2023/3/7.
//

#include "Scanner.h"
#include "../error/Error.h"
#include "Parameter.h"

#include <cctype>
#include <unistd.h>
#include <io.h>
#include <fstream>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

Scanner::Scanner(int n, char *paras[]) : n(n) {
    this->paras = paras;
}

char nextChar(const char *const alpha, const char *const para) {
    if (alpha == nullptr) {
        Error::wrongSpecificAlpha(para, 0);
    } else if (strlen(alpha) > 1) {
        Error::wrongSpecificAlpha(para, 1);
    } else if (!isalpha(alpha[0])) {
        Error::wrongSpecificAlpha(para, 2);
    } else {
        return (char) tolower(alpha[0]);
    }
    return 0;
}

void Scanner::setParas(Parameter &parameter) {
    char o;
    const char *const optStr = "nwch:t:j:r";
    char c;
    while ((o = (char) getopt(this->n, this->paras, optStr)) != -1) {
        switch (o) {
            case 'n':
                parameter.setN(true);
                break;
            case 'w':
                parameter.setW(true);
                break;
            case 'c':
                parameter.setC(true);
                break;
            case 'h':
                c = nextChar(optarg, "-h");
                if (c != 0) {
                    parameter.setH(c);
                }
                break;
            case 't':
                c = nextChar(optarg, "-t");
                if (c != 0) {
                    parameter.setT(c);
                }
                break;
            case 'j':
                c = nextChar(optarg, "-j");
                if (c != 0) {
                    parameter.setJ(c);
                }
                break;
            case 'r':
                parameter.setR(true);
                break;
            default:
                Error::wrongParameter();
                break;
        }
    }

    Error::checkParas(parameter);
}

vector<string> readAvailableFile(const char *const fileName) {
    fstream inFile;
    inFile.open(fileName, ios::in);
    if (!inFile.is_open()) {
        cout << "打开文件失败" << endl;
    }

//    set<string> words;
    vector<string> allWords = {};
    string word;

//    char *buf = (char *) malloc(sizeof(char) * 50);
//    int cnt = 0;
    char c;
    while (!inFile.eof()) {
        c = (char) inFile.get();
//        inFile >> c;
        if (inFile.fail()) {
            break;
        }
        if (isalpha(c)) {
//            buf[cnt++] = (char) tolower(c);
            word.append(1, (char) tolower(c));
        } else {
            if (word.length() > 0){
                allWords.push_back(word);
                word = "";
            }
//            if (cnt > 0) {
//                buf[cnt] = 0;
//                if (words.find(buf) == words.end()) {
//                    words.insert(buf);
//                    solver.newWord(buf);
//                }
//            }
//            cnt = 0;
        }
    }
    if (word.length() > 0){
        allWords.push_back(word);
        word = "";
    }
//    if (cnt > 0) {
//        buf[cnt] = 0;
//        solver.newWord(buf);
//    }
//    free(buf);
    inFile.close();
    return allWords;
}

char** Scanner::readFile() {
    // todo 确定读入参数一定按顺序吗
    char *const fileName = this->paras[this->n - 1];
    // 判断文件是否是.txt后缀
    char *fileType = fileName + strlen(fileName) - 4;
    if (fileType < fileName || strcmp(fileType, ".txt") != 0) {
        Error::wrongFileStatus(2);
    }

    // 判断文件是否存在
    if (access(fileName, F_OK) == -1) {
        Error::wrongFileStatus(0);
    } else if (access(fileName, R_OK) == -1) {
        Error::wrongFileStatus(1);
    } else {
        vector<string> allWords = readAvailableFile(fileName);
        char** res = (char **) malloc(sizeof (char *) * allWords.size());
        for (int i = 0; i < allWords.size(); i++){
//            char* pointer = (char *) malloc(sizeof (char ) * allWords[i].length());
            char* pointer = (char *)allWords[i].c_str();
            *(res + i) = pointer;
//            printf("%s\n", pointer);
        }
        this->wordNumber = (int) allWords.size();
        return res;
    }
    return nullptr;
}
