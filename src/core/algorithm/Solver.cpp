//
// Created by DELL on 2023/3/7.
//

#include "Solver.h"
#include "Algorithm.h"
#include "NoCycle.h"
#include "Cycle.h"
#include "../error/Error.h"
#include "../var/Global.h"
#include <cstring>
#include <queue>

// 先利用拓扑排序，判断图中是否有环
static bool hasCycle(Graph &graph) {
    int n = graph.getSize();

    // 1. 求得各点的入度
//    int in[n + 5];
    int *in = (int *) malloc(sizeof(int) * (n + 5));
    memset(in, 0, sizeof(int) * (n + 5));
    for (int i = 0; i < n; i++) {
        vector<int> now = graph.getEdges().at(i);
        for (int &v: now) {
            in[v]++;
        }
    }

    // 2. 将初始入度为0的点入队
    queue<int> q;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (in[i] == 0) {
            q.push(i);
            cnt++;
        }
    }

    // 3. 不断减少图中的点
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int v: graph.getEdges().at(now)) {
            in[v]--;
            if (in[v] == 0) {
                q.push(v);
                cnt++;
            }
        }
    }

    free(in);
    return cnt != n;
}

int Solver::solve(char *result[]) {
    Graph &graph = Global::get_instance().getGraph();
    Parameter &parameter = Global::get_instance().getParameter();

    Algorithm *algorithm;
    if (!hasCycle(graph)) {
        // 无环图
        algorithm = new NoCycle(graph, parameter);
    } else {
        if (!parameter.isR()) {
            Error::dataCyclicWithoutR();
        }
        algorithm = new Cycle(graph, parameter);
    }

    int ans = 0;
    if (parameter.isN()) {
        ans = algorithm->allWordlist(result);
    } else if (parameter.isW()) {
        ans = algorithm->longestWords(result);
    } else if (parameter.isC()) {
        ans = algorithm->longestAlphas(result);
    }

    delete algorithm;

    return ans;
}
