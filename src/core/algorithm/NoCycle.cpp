//
// Created by DELL on 2023/3/8.
//

#include "NoCycle.h"
#include "../var/Constant.h"
#include "../tools/JudgeChar.h"
#include "../var/Information.h"

#include <cstring>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

static void printPath(vector<string> &path, int &pos, char *result[]) {
    for (string &s: path) {
        strcat(result[pos], s.c_str());
    }
    pos++;
}

static void dfs(Graph &graph, int now, int cnt[], vector<string> &path, int &pos,
                char *result[] = nullptr) {
    for (int next: graph.getEdges().at(now)) {
        if (result != nullptr) {
            path.push_back(graph.getNode(next).getWord());
            printPath(path, pos, result);
        }
        dfs(graph, next, cnt, path, pos);
        if (result != nullptr) {
            path.pop_back();
        } else if (cnt != nullptr) {
            cnt[now] += cnt[next] + 1;
        }
    }
}

static int wordlistCnt(Graph &graph) {
    int n = graph.getSize();
//    int cnt[n + 5];
    int *cnt = (int *) malloc(sizeof(int) * (n + 5));
    memset(cnt, 0, sizeof(int) * (n + 5));
    vector<string> useless;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (cnt[i] == 0) {
            int pos = -1;
            dfs(graph, i, cnt, useless, pos);
        }
        sum += cnt[i];
    }
    free(cnt);
    return sum;
}

static void getAllPath(Graph &graph, char *result[]) {
    int n = graph.getSize();
    int pos = 0;

    vector<string> path;
    for (int i = 0; i < n; i++) {
        path.push_back(graph.getNode(i).getWord());
        dfs(graph, i, nullptr, path, pos, result);
        path.pop_back();
    }
}

void NoCycle::allWordlist(char *result[]) {
    cout << wordlistCnt(this->graph) << endl;

    getAllPath(this->graph, result);
}

/* ����·��
 * ����������n��n+1��
 * n������Ϊ���ĵ�֮����ڱߣ�ȨֵΪ��Ϊ���ĵ�Ȩ
 * ����Ϊ�յ�ĵ㵽n+1֮����ڱߣ�ȨֵΪ0
 * ����·�������������㲢��Ȩֵȡ����ת��Ϊn��n+1�����·
 * ����spfa���
 */
static void spfa(Graph *graph, int start, int pre[], int getWeight(Graph *graph, int u, int v)) {
    queue<int> q;
    int size = graph->getSize();
//    int dis[size + 5];
//    bool vis[size + 5];
    int *dis = (int *) malloc(sizeof(int) * (size + 5));
    bool *vis = (bool *) malloc(sizeof(bool) * (size + 5));
    memset(dis, INF, sizeof(int) * (size + 5));
    memset(vis, 0, sizeof(bool) * (size + 5));

    dis[start] = 0;
    vis[start] = true;
    q.push(start);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        vis[now] = false;
        for (int next: graph->getEdges().at(now)) {
            int w = getWeight(graph, now, next);
            if (dis[next] > dis[now] + w) {
                dis[next] = dis[now] + w;
                pre[next] = now;
                if (!vis[next]) {
                    vis[next] = true;
                    q.push(next);
                }
            }
        }
    }

    free(dis);
    free(vis);
}

static int weightByWords(Graph *graph, int u, int v) {
    return v == graph->getSize() - 1 ? 0 : -1;
}

static int weightByAlphas(Graph *graph, int u, int v) {
    return v == graph->getSize() - 1 ? 0 : -graph->getNode(v).getLen();
}

void NoCycle::longestPath(int type, char *result[]) {
    Graph *newGraph = buildNewGraph();
    int size = newGraph->getSize();
//    int pre[size + 5];
    int *pre = (int *) malloc(sizeof(int) * (size + 5));
    memset(pre, INF, sizeof(int) * (size + 5));

    switch (type) {
        case 0:
            spfa(newGraph, size - 2, pre, weightByWords);
            break;
        case 1:
            spfa(newGraph, size - 2, pre, weightByAlphas);
            break;
        default:
            break;
    }

    if (pre[size - 1] == INF) {
        cout << NO_SATISFYING_WL << endl;
    } else {
        stack<int> s;
        for (int i = pre[size - 1]; i != size - 2; i = pre[i]) {
            s.push(i);
        }
        int pos = 0;
        while (!s.empty()) {
//            cout << newGraph->getNode(s.top()).getWord() << endl;
            strcpy(result[pos++], newGraph->getNode(s.top()).getWord().c_str());
            s.pop();
        }
    }

    free(pre);
    free(newGraph);
}

void NoCycle::longestWords(char *result[]) {
    this->longestPath(0, result);
}

void NoCycle::longestAlphas(char *result[]) {
    this->longestPath(1, result);
}

Graph *NoCycle::buildNewGraph() {
    auto *newGraph = new Graph(this->graph);
//    Graph newGraph(this->graph);
    int preSize = this->graph.getSize();

    // ����n��n+1������
    Word n, n1;
    newGraph->addNode(n, false);
    newGraph->addNode(n1, false);

    // ���������в��������±߹�ϵ
    for (int i = 0; i < preSize; i++) {
        if (firstOk(this->parameter, this->graph.getNode(i).getFirst())) {
            newGraph->addEdge(preSize, i);
        }
    }
    for (int i = 0; i < preSize; i++) {
        if (lastOk(this->parameter, this->graph.getNode(i).getLast())) {
            newGraph->addEdge(i, preSize + 1);
        }
    }
    return newGraph;
}
