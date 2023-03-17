//
// Created by DELL on 2023/3/17.
//

#include "Solver.h"
#include "Graph.h"
#include "Global.h"
#include "../../tools/Char2Pos.h"
#include "../../tools/JudgeChar.h"
#include "../../error/MyError.h"
#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

static bool hasCycle() {
    int n = 26;

    // 1. 求得各点的入度
    int in[n + 5];
    memset(in, 0, sizeof(in));
    for (int i = 0; i < n; i++) {
        for (int v: OPTIMIZE::Global::get_instance().getGraph().getNode(i).getNext()) {
            // 不计算自环
            if (i != v) {
                in[v]++;
            }
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
        for (int v: OPTIMIZE::Global::get_instance().getGraph().getNode(now).getNext()) {
            in[v]--;
            if (in[v] == 0) {
                q.push(v);
                cnt++;
            }
        }
    }

    return cnt != n;
}

static void splitByBlank(const string &str, vector<string> &split) {
    int i = 0;
    while (i < str.length() && str.at(i) == ' ') {
        i++;
    }
    for (int j = i + 1; j < str.length(); j++) {
        if (str.at(j) == ' ') {
            split.push_back(str.substr(i, j - i));
            i = j + 1;
            j++;
        }
    }
    if (i < str.length()) {
        split.push_back(str.substr(i, str.length() - i));
    }
}

static int weightByWords(const string &path) {
    vector<string> split;
    splitByBlank(path, split);
    return (int) split.size();
}

static int weightByAlphas(const string &path) {
    vector<string> split;
    splitByBlank(path, split);
    return (int) path.length() - (int) split.size() + 1;
}


void dfs(int now, const string &nowPath, string &longestPath, int getWeight(const string &path)) {
    OPTIMIZE::Graph &graph = OPTIMIZE::Global::get_instance().getGraph();
    Parameter &parameter = OPTIMIZE::Global::get_instance().getParameter();

    OPTIMIZE::Node &node = graph.getNode(now);

    const set<int> &nexts = node.getNext();
    // 根据贪心原则，先将自环加入
    int selfCnt = 0;
    string newPath = nowPath;
    if (nexts.find(now) != nexts.end()) {
        while (node.hasEdge(now)) {
            selfCnt++;
            OPTIMIZE::Edge *edge = node.nextEdge(now);
            node.increaseItr(now);
            newPath += " ";
            newPath += edge->getWord();
        }

        if (lastOk(parameter, pos2char(now))) {
            if (getWeight(nowPath) > getWeight(longestPath)) {
                longestPath = newPath;
            }
        }
    }

    for (int next: node.getNext()) {
        if (!node.hasEdge(next)) {
            continue;
        }
        // 开始遍历下一条边
        OPTIMIZE::Edge *edge = node.nextEdge(next);

        string newStr = newPath + " " + edge->getWord();
        if (lastOk(parameter, pos2char(edge->getV()))) {
            if (getWeight(newStr) > getWeight(longestPath)) {
                longestPath = newStr;
            }
        }

        // 将下一条边标记为以遍历
//        int edgePos = node.getEdgePos(next);
//        node.setEdgePos(next, edgePos + 1);
        node.increaseItr(next);

        dfs(next, newStr, longestPath, getWeight);

//        node.setEdgePos(next, edgePos);
        node.decreaseItr(next);
    }

    while (selfCnt--) {
        node.decreaseItr(now);
    }
//    return longestPath;
}

static int copyPath(const string &path, char *result[]) {
    vector<string> split;
    splitByBlank(path, split);
    int pos = 0;
    for (string &str: split) {
//        cout << str << endl;
        result[pos] = (char *) malloc(sizeof(char) * (str.length() + 5));
        strcpy(result[pos++], str.c_str());
    }
    return pos;
}

static void newPath(string &path, int &pos, char *result[]) {
    int len = path.length();
    result[pos] = (char *) malloc(sizeof(char) * (len + 5));
    strcpy(result[pos++], path.c_str());
}

void getAllWordlist(int now, string &path, int &pos, char *result[], bool canAns = false) {
    OPTIMIZE::Node &node = OPTIMIZE::Global::get_instance().getGraph().getNode(now);
    for (int i : node.getNext()) {
        int cnt = 0;
        while (node.hasEdge(i)) {
            cnt++;
            OPTIMIZE::Edge *edge = node.nextEdge(i);
            node.increaseItr(i);
            int len = strlen(edge->getWord());
            if (canAns) {
                path += " ";
                len++;
            }
            path += edge->getWord();
            if (canAns) {
                newPath(path, pos, result);
            }
            getAllWordlist(i, path, pos, result, true);
            path.erase(path.end() - len, path.end());
        }

        while (cnt--) {
            node.decreaseItr(i);
        }
    }
}

int OPTIMIZE::Solver::allWordlist(char **result) {
    int pos = 0;
    string path;
    for (int i = 0; i < 26; i++) {
        OPTIMIZE::Global::get_instance().getGraph().resetAll();
        getAllWordlist(i, path, pos, result);
    }
    return pos;
}

int OPTIMIZE::Solver::longestWords(char **result) {
    string longestPath;
    string nowPath;
    for (int i = 0; i < 26; i++) {
        if (firstOk(Global::get_instance().getParameter(), pos2char(i))) {
            Global::get_instance().getGraph().resetAll();
            dfs(i, nowPath, longestPath, weightByWords);
        }
    }

    return copyPath(longestPath, result);
}

int OPTIMIZE::Solver::longestAlphas(char **result) {
    string longestPath;
    string nowPath;
    for (int i = 0; i < 26; i++) {
        if (firstOk(Global::get_instance().getParameter(), pos2char(i))) {
            Global::get_instance().getGraph().resetAll();
            dfs(i, nowPath, longestPath, weightByAlphas);
        }
    }

    return copyPath(longestPath, result);
}

int OPTIMIZE::Solver::solve(char **result) {
    Graph &graph = Global::get_instance().getGraph();
    Parameter &parameter = Global::get_instance().getParameter();

    if (hasCycle() && !parameter.isR()) {
        MyError::dataCyclicWithoutR();
    }

    int ans = 0;
    if (parameter.isN()) {
        ans = allWordlist(result);
    } else if (parameter.isW()) {
        ans = longestWords(result);
    } else if (parameter.isC()) {
        ans = longestAlphas(result);
    }

    return ans;
}
