//
// Created by DELL on 2023/3/7.
//

#include "Solver.h"
#include "Algorithm.h"
#include "NoCycle.h"
#include "Cycle.h"
#include <cstring>
#include <queue>

void Solver::newWord(char *word) {
    Word wordObj(word);
    this->graph.addNode(wordObj);
}

// 先利用拓扑排序，判断图中是否有环
static bool hasCycle(Graph &graph) {
    int n = graph.getSize();

    // 1. 求得各点的入度
    int in[n + 5];
    memset(in, 0, sizeof(in));
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

    return cnt != n;
}

void Solver::solve() {
    Algorithm *algorithm;
    if (!hasCycle(this->graph)) {
        // 无环图
        algorithm = new NoCycle();
    } else {
        if (!this->parameter.isR()) {
            // TODO 未指定-r但有环
        }
        algorithm = new Cycle();
    }

    if (this->parameter.isN()) {
        algorithm->allWordlist();
    } else if (this->parameter.isW()) {
        algorithm->longestWords();
    } else if (this->parameter.isC()) {
        algorithm->longestAlphas();
    }

    delete algorithm;
}

Solver::Solver(const Parameter &parameter) : parameter(parameter) {}
