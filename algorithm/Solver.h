//
// Created by DELL on 2023/3/7.
//

#ifndef WORDLIST_SOLVER_H
#define WORDLIST_SOLVER_H

#include <vector>
#include "Word.h"
#include "../var/Graph.h"

using namespace std;
class Solver {
private:
    Graph graph;

public:
    void solve();
    void newWord(char *word);
};


#endif //WORDLIST_SOLVER_H
