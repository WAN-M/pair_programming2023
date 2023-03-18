#include "library.h"
#include "algorithm/optimize/Global.h"
#include "algorithm/optimize/Solver.h"
#include "algorithm/Solver.h"
#include "var/Global.h"
#include "tools/Char2Pos.h"
#include "tools/JudgeChar.h"

static void buildGraph(char *words[], int len) {
//    Graph &graph = Global::get_instance().getGraph();
    for (int i = 0; i < len; i++) {
        Word word(words[i]);
//        graph.addNode(word);
    }
}

static list<OPTIMIZE::Edge *> edges;
/*
 * 引入两虚点表示起止点，起点向可以作为起点的点连长度为0的边，可以为终点的点向终点连边。
 * 0-25表示各字母，26,27表示起始点
 */
static void buildGraph_o(char *words[], int len) {
    OPTIMIZE::Graph &graph = OPTIMIZE::Global::get_instance().getGraph();
    for (int i = 0; i < len; i++) {
//        OPTIMIZE::Edge edge(words[i]);
        auto *edge = new OPTIMIZE::Edge(words[i]);
        edges.push_back(edge);
        graph.getNode(char2pos(words[i][0])).addEdge(edge);
    }

    // 建立虚点的边
    for (int i = 0; i < ALPHA_SIZE; i++) {
        if (firstOk(OPTIMIZE::Global::get_instance().getParameter(), pos2char(i))) {
            auto *edge1 = new OPTIMIZE::Edge(i);
            edges.push_back(edge1);
            graph.getNode(SOURCE).addEdge(edge1);
        }
        if (lastOk(OPTIMIZE::Global::get_instance().getParameter(), pos2char(i))) {
            auto *edge1 = new OPTIMIZE::Edge(TARGET);
            edges.push_back(edge1);
            graph.getNode(i).addEdge(edge1);
        }
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
    OPTIMIZE::Global::get_instance().getParameter().setN(true);
    buildGraph_o(words, len);
    return OPTIMIZE::Solver::solve(result);
}

extern "C" __declspec(dllexport) int gen_chain_word(char *words[], int len, char *result[], char head, char tail, char reject, bool enable_loop) {
    setParameters(head, tail, reject, enable_loop);
    buildGraph_o(words, len);
    OPTIMIZE::Global::get_instance().getParameter().setW(true);
    int ans = OPTIMIZE::Solver::solve(result);
    releaseEdges();
    return ans;
}

extern "C" __declspec(dllexport) int gen_chain_char(char *words[], int len, char *result[], char head, char tail, char reject, bool enable_loop) {
    setParameters(head, tail, reject, enable_loop);
    buildGraph_o(words, len);
    OPTIMIZE::Global::get_instance().getParameter().setC(true);
    int ans = OPTIMIZE::Solver::solve(result);
    return ans;
}