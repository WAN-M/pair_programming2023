//
// Created by DELL on 2023/3/8.
//

#include "NoCycle.h"
#include "../var/Graph.h"

#include <cstring>
#include <iostream>

using namespace std;

static void printPath(vector<string> &path) {
    for (string &s: path) {
        cout << s << " ";
    }
    cout << endl;
}

static void dfs(Graph &graph, int now, int cnt[], vector<string> &path, bool print = false) {
    for (int next : graph.getEdges().at(now)) {

    }
}

static int wordlistCnt(Graph &graph) {
    int n = graph.getSize();
    int cnt[n + 5];
    memset(cnt, 0, sizeof(cnt));
}

void NoCycle::allWordlist() {

}

vector<string> NoCycle::longestWords() {
    return;
}

vector<string> &NoCycle::longestAlphas() {
    return;
}
