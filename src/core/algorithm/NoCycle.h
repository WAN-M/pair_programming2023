//
// Created by DELL on 2023/3/8.
//

#ifndef WORDLIST_NOCYCLE_H
#define WORDLIST_NOCYCLE_H


#include "Algorithm.h"

class NoCycle : public Algorithm {
private:
    Graph *buildNewGraph();

    // 0��ʾ��������࣬1��ʾ��ĸ�����
    int longestPath(int type, char *result[]);

public:
    explicit NoCycle(Graph &graph, Parameter &parameter) : Algorithm(graph, parameter) {

    }

    int allWordlist(char *result[]) override;

    int longestWords(char *result[]) override;

    int longestAlphas(char *result[]) override;
};


#endif //WORDLIST_NOCYCLE_H
