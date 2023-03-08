//
// Created by DELL on 2023/3/8.
//

#include "NoCycle.h"
#include "../var/Constant.h"
#include "../tools/JudgeChar.h"

#include <cstring>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

static void printPath(vector<string> &path) {
    for (string &s: path) {
        cout << s << " ";
    }
    cout << endl;
}

static void dfs(Graph &graph, int now, int cnt[], vector<string> &path, bool print = false) {
    for (int next: graph.getEdges().at(now)) {
        if (print) {
            path.push_back(graph.getNode(next).getWord());
            printPath(path);
        }
        dfs(graph, next, cnt, path, print);
        if (print) {
            path.pop_back();
        } else if (cnt != nullptr) {
            cnt[now] += cnt[next] + 1;
        }
    }
}

static int wordlistCnt(Graph &graph) {
    int n = graph.getSize();
    int cnt[n + 5];
    memset(cnt, 0, sizeof(cnt));
    vector<string> useless;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (cnt[i] == 0) {
            dfs(graph, i, cnt, useless);
        }
        sum += cnt[i];
    }
    return sum;
}

static void printAllPath(Graph &graph) {
    int n = graph.getSize();

    vector<string> path;
    for (int i = 0; i < n; i++) {
        path.push_back(graph.getNode(i).getWord());
        dfs(graph, i, nullptr, path, true);
        path.pop_back();
    }
}

void NoCycle::allWordlist() {
    cout << wordlistCnt(this->graph) << endl;

    printAllPath(this->graph);
}

/* 求解最长路：
 * 增加两个点n和n+1：
 * n到能作为起点的点之间存在边，权值为作为起点的点权
 * 能作为终点的点到n+1之间存在边，权值为0
 * 因此最长路在引入上述两点并将权值取负后转化为n到n+1的最短路
 * 利用spfa求解
 */
static void spfa(Graph *graph, int start, int pre[], int getWeight(Graph *graph, int u, int v)) {
    queue<int> q;
    int size = graph->getSize();
    int dis[size + 5];
    bool vis[size + 5];
    memset(dis, INF, sizeof(dis));
    memset(vis, 0, sizeof(vis));

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
}

static int weightByWords(Graph *graph, int u, int v) {
    return v == graph->getSize() - 1 ? 0 : -1;
}

static int weightByAlphas(Graph *graph, int u, int v) {
    return v == graph->getSize() - 1 ? 0 : -graph->getNode(v).getLen();
}

void NoCycle::longestPath(int type) {
    Graph *newGraph = buildNewGraph();
    int size = newGraph->getSize();
    int pre[size + 5];
    memset(pre, INF, sizeof(pre));

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
        cout << "不存在满足条件的单词链" << endl;
    } else {
        stack<int> s;
        for (int i = pre[size - 1]; i != size - 2; i = pre[i]) {
            s.push(i);
        }
        while (!s.empty()) {
            cout << newGraph->getNode(s.top()).getWord() << endl;
            s.pop();
        }
    }
    delete newGraph;
}

vector<string> &NoCycle::longestWords() {
    this->longestPath(0);
}

vector<string> &NoCycle::longestAlphas() {
    this->longestPath(1);
}

Graph *NoCycle::buildNewGraph() {
    auto *newGraph = new Graph(this->graph);
//    Graph newGraph(this->graph);
    int preSize = this->graph.getSize();

    // 加入n和n+1两个点
    Word n, n1;
    newGraph->addNode(n, false);
    newGraph->addNode(n1, false);

    // 根据命令行参数创建新边关系
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
