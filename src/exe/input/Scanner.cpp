//
// Created by DELL on 2023/3/7.
//

#include "Scanner.h"
#include "Parameter.h"
#include "../exception/CommandException.h"
#include "../exception/FileException.h"
#include "../exception/Information.h"

#include <cctype>
#include <unistd.h>
#include <io.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <set>
#include <vector>

using namespace std;

Scanner::Scanner(int n, char *paras[]) : n(n) {
    this->paras = paras;
}

static void checkParas(Parameter parameter) {
    if (parameter.isN() && (parameter.isC() || parameter.isW() || parameter.isR() ||
                            parameter.getT() != 0 || parameter.getJ() != 0 || parameter.getH() != 0)) {
        throw CommandException(PARAMETERS_CRUSH);
    }
    if (parameter.isW() && parameter.isC()) {
        throw CommandException(PARAMETERS_CRUSH);
    }
    if (!(parameter.isN() || parameter.isW() || parameter.isC())) {
        throw CommandException(PARAMETERS_CRUSH);
    }
}

static char nextChar(char *para, char *next) {
    // para长度不可能为0，没指定字符则para为下一个参数
    if (next == nullptr || next[0] == '-') {
        string information = para;
        information += NO_ALPHA;
        throw CommandException(information);
    } else if (strlen(next) > 1) {
        string information = para;
        information += MORE_THAN_ONE_ALPHA;
        throw CommandException(information);
    } else if (!isalpha(next[0])) {
        string information = para;
        information += NOT_ALPHA;
        throw CommandException(information);
    }
    return next[0];
}

void Scanner::setParas(Parameter &parameter) {
    // 未指定任何参数
    if (n == 1) {
        throw CommandException(NO_PARA);
    }

    // 第一个参数是exe路径，最后一个参数默认是文件路径，因此应先判断最后一个参数的正确性

    // 判断文件是否是.txt后缀
    char *fileType = paras[n - 1] + strlen(paras[n - 1]) - 4;
    if (fileType < paras[n - 1] || strcmp(fileType, ".txt") != 0) {
        throw FileException(FILE_NOT_TXT);
    }

    set<char> nwcr{'n', 'w', 'c', 'r'};
    set<char> htj{'h', 't', 'j'};
    for (int i = 1; i < n - 1; i++) {
        if (paras[i][0] == '-') {
            if (strlen(paras[i]) != 2 ||
                nwcr.find(paras[i][1]) == nwcr.end() && htj.find(paras[i][1]) == htj.end()) {
                string information = paras[i];
                information += WRONG_PARAMETER;
                throw CommandException(information);
            }

            switch (paras[i][1]) {
                case 'n':
                    parameter.setN(true);
                    break;
                case 'w':
                    parameter.setW(true);
                    break;
                case 'c':
                    parameter.setC(true);
                    break;
                case 'r':
                    parameter.setR(true);
                    break;
                case 'h':
                    parameter.setH(nextChar(paras[i], i + 1 < n - 1 ? paras[i + 1] : nullptr));
                    break;
                case 't':
                    parameter.setT(nextChar(paras[i], i + 1 < n - 1 ? paras[i + 1] : nullptr));
                    break;
                case 'j':
                    parameter.setJ(nextChar(paras[i], i + 1 < n - 1 ? paras[i + 1] : nullptr));
                    break;
                default:
                    break;
            }
        } else {
            if (paras[i - 1][0] != '-') {
                string information = paras[i];
                information += WRONG_PARAMETER;
                throw CommandException(information);
            }
        }
    }

    checkParas(parameter);
}

void Scanner::readAvailableFile(const char *const fileName) {
    fstream inFile;
    inFile.open(fileName, ios::in);
    if (!inFile.is_open()) {
        throw FileException(FILE_NOT_EXIST);
    }

    set<string> allWords;
//    vector<string> allWords = {};
//    stringbuf word;
//    vector<char *> pointers;
    vector<char> word;

//    string word;

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
            word.push_back((char) tolower(c));
        } else {
            if (!word.empty()) {
                word.push_back(0);
                char *temp = (char *) malloc(sizeof(char) * word.size());
                for (int j = 0; j < word.size(); j++) {
                    *(temp + j) = word[j];
                }
                word.clear();

                if (allWords.find(temp) == allWords.end()) {
                    allWords.insert(temp);
                }
            }
        }
    }
    if (!word.empty()) {
        word.push_back(0);
        char *temp = (char *) malloc(sizeof(char) * word.size());
        for (int j = 0; j < word.size(); j++) {
            *(temp + j) = word[j];
        }
        word.clear();

        if (allWords.find(temp) == allWords.end()) {
            allWords.insert(temp);
        }
    }
//    if (cnt > 0) {
//        buf[cnt] = 0;
//        solver.newWord(buf);
//    }
//    free(buf);
    inFile.close();

    this->words = (char **) malloc(sizeof(char *) * allWords.size());
//    for (int i = 0; i < allWords.size(); i++) {
//        *((this->words) + i) = allWords.;
//    }
    int index = 0;
    for (string pointer: allWords) {
        *((this->words) + index) = (char *) malloc(sizeof(char) * (pointer.size() + 5));
        strcpy((this->words)[index++], pointer.c_str());
    }
    this->wordNumber = (int) allWords.size();

//    for(int i = 0; i < allWords.size(); i++){
//        printf("raf %s\n", allWords[i]);
//    }

    allWords.clear();
}

void Scanner::readFile() {
    char *const fileName = this->paras[this->n - 1];

    // 判断文件是否存在
    if (access(fileName, F_OK) == -1) {
        throw FileException(FILE_NOT_EXIST);
    } else if (access(fileName, R_OK) == -1) {
        throw FileException(FILE_UNREADABLE);
    } else {
        readAvailableFile(fileName);
    }
}