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
    void longestPath(int type, char *result[]);

public:
    explicit NoCycle(Graph &graph, Parameter &parameter) : Algorithm(graph, parameter) {

    }

    void allWordlist(char *result[]) override;

    void longestWords(char *result[]) override;

    void longestAlphas(char *result[]) override;
};


#endif //WORDLIST_NOCYCLE_H
