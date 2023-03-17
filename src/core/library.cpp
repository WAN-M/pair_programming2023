#include "library.h"
#include "algorithm/optimize/Global.h"
#include "algorithm/optimize/Solver.h"
#include "algorithm/Solver.h"
#include "var/Global.h"
#include "tools/Char2Pos.h"

static void buildGraph(char *words[], int len) {
//    Graph &graph = Global::get_instance().getGraph();
    for (int i = 0; i < len; i++) {
        Word word(words[i]);
//        graph.addNode(word);
    }
}

static list<OPTIMIZE::Edge *> edges;
static void buildGraph_o(char *words[], int len) {
    OPTIMIZE::Graph &graph = OPTIMIZE::Global::get_instance().getGraph();
    for (int i = 0; i < len; i++) {
//        OPTIMIZE::Edge edge(words[i]);
        OPTIMIZE::Edge *edge = new OPTIMIZE::Edge(words[i]);
        edges.push_back(edge);
        graph.getNode(char2pos(words[i][0])).addEdge(edge);
    }
    graph.sortAll();
}

static void releaseEdges() {
    for (OPTIMIZE::Edge * edge : edges) {
        free(edge);
    }
}

static void setParameters(char head, char tail, char reject, bool enable_loop) {
    Parameter &parameter = OPTIMIZE::Global::get_instance().getParameter();
    parameter.setH(head);
    parameter.setT(tail);
    parameter.setJ(reject);
    parameter.setR(enable_loop);
}


extern "C" __declspec(dllexport) int gen_chains_all(char *words[], int len, char *result[]) {
    buildGraph_o(words, len);
    OPTIMIZE::Global::get_instance().getParameter().setN(true);
    return OPTIMIZE::Solver::solve(result);
}

extern "C" __declspec(dllexport) int gen_chain_word(char *words[], int len, char *result[], char head, char tail, char reject, bool enable_loop) {
    buildGraph_o(words, len);
    setParameters(head, tail, reject, enable_loop);
    OPTIMIZE::Global::get_instance().getParameter().setW(true);
    int ans = OPTIMIZE::Solver::solve(result);
    releaseEdges();
    return ans;
}

extern "C" __declspec(dllexport) int gen_chain_char(char *words[], int len, char *result[], char head, char tail, char reject, bool enable_loop) {
    buildGraph_o(words, len);
    setParameters(head, tail, reject, enable_loop);
    OPTIMIZE::Global::get_instance().getParameter().setC(true);
    int ans = OPTIMIZE::Solver::solve(result);
    return ans;
}