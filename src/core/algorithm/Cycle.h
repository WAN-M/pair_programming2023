//
// Created by DELL on 2023/3/8.
//

#ifndef WORDLIST_CYCLE_H
#define WORDLIST_CYCLE_H


#include "Algorithm.h"

class Cycle : public Algorithm {
private:
    void longestPath(int getWeight(const string &path), char *result[]);

public:
    explicit Cycle(Graph &graph, Parameter &parameter) : Algorithm(graph, parameter) {

    }

    int allWordlist(char *result[]) override;

    int longestWords(char *result[]) override;

    int longestAlphas(char *result[]) override;
};


#endif //WORDLIST_CYCLE_H
