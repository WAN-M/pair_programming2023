//
// Created by DELL on 2023/3/7.
//

#ifndef WORDLIST_SCANNER_H
#define WORDLIST_SCANNER_H
#include "../var/Parameter.h"
#include "../algorithm/Solver.h"


class Scanner {
private:
    int n;
    char **paras;
public:
    Scanner(int n, char *paras[]);
    void setParas(Parameter &parameter);
    void readFile(Solver &solver);
};


#endif //WORDLIST_SCANNER_H
