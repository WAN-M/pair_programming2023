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

    void allWordlist(char *result[]) override;

    vector<string> &longestWords(char *result[]) override;

    vector<string> &longestAlphas(char *result[]) override;
};


#endif //WORDLIST_CYCLE_H
