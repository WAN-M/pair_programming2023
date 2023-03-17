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

static void printPath(string &path, int &pos, char *result[]) {
    int len = path.length();
    result[pos] = (char *) malloc(sizeof(char) * (len + 5));
    strcpy(result[pos++], path.c_str());
}

static void dfs(Graph &graph, int now, int cnt[], string &path, int &pos,
                char *result[] = nullptr) {
    //cout << now << endl;
    for (int next: graph.getEdges().at(now)) {
        //cout << "next: " << next << endl;
        int len = 0;
        if (result != nullptr) {
            len = graph.getNode(next).getWord().length() + 1;
            path += " " + graph.getNode(next).getWord();
            printPath(path, pos, result);
        }
        dfs(graph, next, cnt, path, pos, result);
        if (result != nullptr) {
            path.erase(path.end() - len, path.end());
        }/* else if (cnt != nullptr) {
            cnt[now] += cnt[next] + 1;
        }*/
    }
}

static int wordlistCnt(Graph &graph) {
    int n = graph.getSize();
//    int cnt[n + 5];
    int *cnt = (int *) malloc(sizeof(int) * (n + 5));
    memset(cnt, 0, sizeof(int) * (n + 5));
    string useless;
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

static int getAllPath(Graph &graph, char *result[]) {
    int n = graph.getSize();
    int pos = 0;

    string path;
    for (int i = 0; i < n; i++) {
        path = graph.getNode(i).getWord();
        dfs(graph, i, nullptr, path, pos, result);
        path = "";
    }

    return pos;
}

int NoCycle::allWordlist(char *result[]) {
//    cout << wordlistCnt(this->graph) << endl;

    return getAllPath(this->graph, result);
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

int NoCycle::longestPath(int type, char *result[]) {
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

    int pos = 0;
    if (pre[size - 1] == INF) {
        cout << NO_SATISFYING_WL << endl;
    } else {
        stack<int> s;
        for (int i = pre[size - 1]; i != size - 2; i = pre[i]) {
            s.push(i);
        }
        while (!s.empty()) {
//            cout << newGraph->getNode(s.top()).getWord() << endl;
            result[pos] = (char *) malloc(sizeof(char) * (newGraph->getNode(s.top()).getWord().length() + 5));
            strcpy(result[pos++], newGraph->getNode(s.top()).getWord().c_str());
            s.pop();
        }
    }

    free(pre);
    free(newGraph);

    return pos;
}

int NoCycle::longestWords(char *result[]) {
    return this->longestPath(0, result);
}

int NoCycle::longestAlphas(char *result[]) {
    return this->longestPath(1, result);
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
