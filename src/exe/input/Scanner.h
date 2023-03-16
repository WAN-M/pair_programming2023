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
public:
    int wordNumber = 0;
    Scanner(int n, char *paras[]);
    void setParas(Parameter &parameter);
    char** readFile();
};

#endif //WORDLIST_SCANNER_H
