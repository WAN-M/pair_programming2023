#include "library.h"
#include "algorithm/optimize/Global.h"
#include "algorithm/optimize/Solver.h"
#include "tools/Char2Pos.h"
#include "tools/JudgeChar.h"

static list<OPTIMIZE::Edge *> edges;
/*
 * 引入两虚点表示起止点，起点向可以作为起点的点连长度为0的边，可以为终点的点向终点连边。
 * 0-25表示各字母，26,27表示起始点
 */
static void buildGraph_o(char *words[], int len) {
    OPTIMIZE::Graph &graph = OPTIMIZE::Global::get_instance().getGraph();
    for (int i = 0; i < len; i++) {
//        OPTIMIZE::Edge edge(words[i]);
        if (firstRejected(OPTIMIZE::Global::get_instance().getParameter(), words[i][0])) {
            continue;
        }
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
    /*edges.clear();
    printf("edges %d\n\n", edges.size());*/
    for (OPTIMIZE::Edge * edge : edges) {
        delete *edge;
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
    OPTIMIZE::Global::get_instance().reset();
    OPTIMIZE::Global::get_instance().getParameter().setN(true);
    buildGraph_o(words, len);
    int ans = OPTIMIZE::Solver::solve(result);
    releaseEdges();
    return ans;
}

extern "C" __declspec(dllexport) int gen_chain_word(char *words[], int len, char *result[], char head, char tail, char reject, bool enable_loop) {
    OPTIMIZE::Global::get_instance().reset();
    setParameters(head, tail, reject, enable_loop);
    buildGraph_o(words, len);
    OPTIMIZE::Global::get_instance().getParameter().setW(true);
    int ans = OPTIMIZE::Solver::solve(result);
    releaseEdges();
    return ans;
}

extern "C" __declspec(dllexport) int gen_chain_char(char *words[], int len, char *result[], char head, char tail, char reject, bool enable_loop) {
    OPTIMIZE::Global::get_instance().reset();
    setParameters(head, tail, reject, enable_loop);
    buildGraph_o(words, len);
    OPTIMIZE::Global::get_instance().getParameter().setC(true);
    int ans = OPTIMIZE::Solver::solve(result);
    releaseEdges();
    return ans;
}