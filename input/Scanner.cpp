//
// Created by DELL on 2023/3/7.
//

#include "Scanner.h"
#include <cctype>
#include <unistd.h>
#include <io.h>
#include <fstream>
#include <iostream>
#include <set>

using namespace std;

Scanner::Scanner(int n, char *paras[]) : n(n) {
    this->paras = paras;
}

char nextChar(const char *const para) {
    if (para == nullptr) {
        // TODO 未指定字符
    } else if (strlen(para) > 1) {
        // TODO 只能指定一个字符
    } else if (!isalpha(para[0])) {
        // TODO 只能指定单词字符
    } else {
        return (char) tolower(para[0]);
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
                c = nextChar(optarg);
                if (c == 0) {
                    // TODO 出错
                } else {
                    parameter.setH(c);
                }
                break;
            case 't':
                c = nextChar(optarg);
                if (c == 0) {
                    // TODO 出错
                } else {
                    parameter.setT(c);
                }
                break;
            case 'j':
                c = nextChar(optarg);
                if (c == 0) {
                    // TODO 出错
                } else {
                    parameter.setJ(c);
                }
                break;
            case '?':
                // TODO 不存在的参数
                break;
            default:
                // TODO 不存在的参数
                break;
        }
    }
}

void readAvailableFile(Solver &solver, const char *const fileName) {
    fstream inFile;
    inFile.open(fileName, ios::in);
    if (!inFile.is_open()) {
        cout << "打开文件失败" << endl;
    }

    set<string> words;
    char *buf = (char *) malloc(sizeof(char) * 50);
    int cnt = 0;
    char c;
    while (!inFile.eof()) {
        c = inFile.get();
//        inFile >> c;
        if (inFile.fail()) {
            break;
        }
        if (isalpha(c)) {
            buf[cnt++] = (char) tolower(c);
        } else {
            if (cnt > 0) {
                buf[cnt] = 0;
                if (words.find(buf) == words.end()) {
                    words.insert(buf);
                    solver.newWord(buf);
                }
            }
            cnt = 0;
        }
    }
    if (cnt > 0) {
        buf[cnt] = 0;
        solver.newWord(buf);
    }
    free(buf);
    inFile.close();
}

void Scanner::readFile(Solver &solver) {
    const char *const fileName = this->paras[this->n - 1];
    // 判读文件是否存在
    if (access(fileName, F_OK) == -1) {
        // TODO 文件不存在
    } else if (access(fileName, R_OK) == -1) {
        // TODO 文件不可读
    } else {
        readAvailableFile(solver, fileName);
    }
}
