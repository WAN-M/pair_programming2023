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

// ���������������ж�ͼ���Ƿ��л�
static bool hasCycle(Graph &graph) {
    int n = graph.getSize();

    // 1. ��ø�������
    int in[n + 5];
    memset(in, 0, sizeof(in));
    for (int i = 0; i < n; i++) {
        vector<int> now = graph.getEdges().at(i);
        for (int &v: now) {
            in[v]++;
        }
    }

    // 2. ����ʼ���Ϊ0�ĵ����
    queue<int> q;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (in[i] == 0) {
            q.push(i);
            cnt++;
        }
    }

    // 3. ���ϼ���ͼ�еĵ�
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

void Solver::solve(char *result[]) {
    Graph &graph = Global::get_instance().getGraph();
    Parameter &parameter = Global::get_instance().getParameter();

    Algorithm *algorithm;
    if (!hasCycle(graph)) {
        // �޻�ͼ
        algorithm = new NoCycle(graph, parameter);
    } else {
        if (parameter.isR()) {
            Error::dataCyclicWithoutR();
        }
        algorithm = new Cycle(graph, parameter);
    }

    if (parameter.isN()) {
        algorithm->allWordlist(result);
    } else if (parameter.isW()) {
        algorithm->longestWords(result);
    } else if (parameter.isC()) {
        algorithm->longestAlphas(result);
    }

    delete algorithm;
}
