//
// Created by DELL on 2023/3/7.
//

#ifndef WORDLIST_SCANNER_H
#define WORDLIST_SCANNER_H

#include "Parameter.h"

class Scanner {
private:
    int n;
    char **paras;
    void readAvailableFile(const char *const fileName);
public:
    int wordNumber = 0;
    char **words = nullptr;
    Scanner(int n, char *paras[]);
    void setParas(Parameter &parameter);
    void readFile();
};

#endif //WORDLIST_SCANNER_H
