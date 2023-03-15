#include "library.h"
#include "var/Graph.h"
#include "var/Global.h"
#include "algorithm/Solver.h"

static void buildGraph(char *words[], int len) {
    Graph graph = Global::get_instance().getGraph();
    for (int i = 0; i < len; i++) {
        Word word(words[i]);
        graph.addNode(word);
    }
}

static void setParameters(char head, char tail, char reject, bool enable_loop) {
    Parameter parameter = Global::get_instance().getParameter();
    parameter.setH(head);
    parameter.setT(tail);
    parameter.setJ(reject);
    parameter.setR(enable_loop);
}


int gen_chains_all(char *words[], int len, char *result[]) {
    buildGraph(words, len);
    Global::get_instance().getParameter().setN(true);
    Solver::solve(result);

    return 0;
}

int gen_chain_word(char *words[], int len, char *result[], char head, char tail, char reject, bool enable_loop) {
    buildGraph(words, len);
    setParameters(head, tail, reject, enable_loop);
    Global::get_instance().getParameter().setW(true);
    Solver::solve(result);

    return 0;
}

int gen_chain_char(char *words[], int len, char *result[], char head, char tail, char reject, bool enable_loop) {
    buildGraph(words, len);
    setParameters(head, tail, reject, enable_loop);
    Global::get_instance().getParameter().setC(true);
    Solver::solve(result);

    return 0;
}
