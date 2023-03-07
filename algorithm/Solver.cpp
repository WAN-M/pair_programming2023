//
// Created by DELL on 2023/3/7.
//

#include "Solver.h"

void Solver::solve() {

}

void Solver::newWord(char *word) {
    Word wordObj(word);
    this->graph.addNode(wordObj);
}
