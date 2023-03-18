//
// Created by DELL on 2023/3/17.
//

#include "Solver.h"
#include "Graph.h"
#include "Global.h"
#include "../../tools/Char2Pos.h"
#include "../../tools/JudgeChar.h"
#include "../../exception/RuntimeException.h"
#include "../../var/Information.h"
#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

static bool hasCycle() {
    int n = NODE_SIZE;

    // 1. 求得各点的入度
    int in[NODE_SIZE + 5];
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


void dfs(int now, int nowWeight, string &nowPath, int &longestWeight, string &longestPath, int nowLen, int &sumLen,
         int getWeight(const string &path)) {
    // 遍历到终点
    if (now == TARGET) {
        if (nowWeight > longestWeight) {
            longestPath = nowPath;
            longestWeight = nowWeight;
            sumLen = nowLen;
        }
        return;
    }

    OPTIMIZE::Graph &graph = OPTIMIZE::Global::get_instance().getGraph();
    OPTIMIZE::Node &node = graph.getNode(now);

    const set<int> &nexts = node.getNext();
    // 根据贪心原则，先将自环加入
    int selfCnt = 0;
    if (nexts.find(now) != nexts.end()) {
        while (node.hasEdge(now)) {
            selfCnt++;
            OPTIMIZE::Edge *edge = node.nextEdge(now);
            node.increaseItr(now);
            if (edge->getLen() > 0) {
                nowPath += " ";
                nowPath += edge->getWord();
                nowWeight += getWeight(edge->getWord());
                nowLen += edge->getLen();
            }
        }
    }

    for (int next: node.getNext()) {
        if (!node.hasEdge(next)) {
            continue;
        }
        // 开始遍历下一条边
        OPTIMIZE::Edge *edge = node.nextEdge(next);
        if (edge->getLen() > 0) {
            nowPath += " ";
            nowPath += edge->getWord();
            nowWeight += getWeight(edge->getWord());
            nowLen += edge->getLen();
        }

        // 将下一条边标记为以遍历
        node.increaseItr(next);
        dfs(next, nowWeight, nowPath, longestWeight, longestPath, nowLen, sumLen, getWeight);
        node.decreaseItr(next);

        if (edge->getLen() != 0) {
            nowPath.erase(nowPath.end() - edge->getLen() - 1, nowPath.end());
            nowWeight -= getWeight(edge->getWord());
            nowLen -= edge->getLen();
        }
    }

    while (selfCnt--) {
        node.decreaseItr(now);
    }
}

static int copyPath(const string &path, char *result[], bool copy) {
    vector<string> split;
    splitByBlank(path, split);
    if (copy) {
        int pos = 0;
        for (string &str: split) {
//        cout << str << endl;
            result[pos] = (char *) malloc(sizeof(char) * (str.length() + 5));
            strcpy(result[pos++], str.c_str());
        }
        return pos;
    } else {
        return split.size();
    }
}

static void newPath(string &path, int &pos, char *result[]) {
    int len = path.length();
    result[pos] = (char *) malloc(sizeof(char) * (len + 5));
    strcpy(result[pos++], path.c_str());
}

void getAllWordlist(int now, int nowLen, int &sumLen, string &path, int &pos, char *result[], int wordCnt) {
    OPTIMIZE::Node &node = OPTIMIZE::Global::get_instance().getGraph().getNode(now);
    for (int i: node.getNext()) {
        if (i == TARGET) {
            continue;
        }
        int cnt = 0;
        while (node.hasEdge(i)) {
            cnt++;
            OPTIMIZE::Edge *edge = node.nextEdge(i);
            node.increaseItr(i);
            int len = strlen(edge->getWord());
            nowLen += len;
            if (wordCnt >= 1) {
                path += " ";
                len++;
            }
            path += edge->getWord();
            if (wordCnt >= 1) {
                sumLen += nowLen;
                if (sumLen <= MAX_ANS_LEN) {
                    newPath(path, pos, result);
                }
            }
            getAllWordlist(i, nowLen, sumLen, path, pos, result, wordCnt + 1);
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
    int sumLen = 0;
    for (int i = 0; i < ALPHA_SIZE; i++) {
        OPTIMIZE::Global::get_instance().getGraph().resetAll();
        getAllWordlist(i, 0, sumLen, path, pos, result, 0);
    }

    if (sumLen > MAX_ANS_LEN) {
        throw RuntimeException(RESULT_TOO_LONG);
    }
    return pos;
}

int OPTIMIZE::Solver::longestWords(char **result) {
    string longestPath;
    string nowPath;
    int longestWeight = 0;
    int sumLen = 0;
    dfs(SOURCE, 0, nowPath, longestWeight, longestPath, 0, sumLen, weightByWords);

    if (sumLen > MAX_ANS_LEN) {
        throw RuntimeException(RESULT_TOO_LONG);
    }
    return copyPath(longestPath, result, sumLen <= MAX_ANS_LEN);
}

int OPTIMIZE::Solver::longestAlphas(char **result) {
    string longestPath;
    string nowPath;
    int longestWeight = 0;
    int sumLen = 0;
    dfs(SOURCE, 0, nowPath, longestWeight, longestPath, 0, sumLen, weightByWords);

    if (sumLen > MAX_ANS_LEN) {
        throw RuntimeException(RESULT_TOO_LONG);
    }
    return copyPath(longestPath, result, sumLen <= MAX_ANS_LEN);
}

int OPTIMIZE::Solver::solve(char **result) {
    Graph &graph = Global::get_instance().getGraph();
    Parameter &parameter = Global::get_instance().getParameter();

    if (hasCycle() && !parameter.isR()) {
        throw RuntimeException(DATA_CYCLIC);
    }

    int ans = 0;
    if (parameter.isN()) {
        ans = allWordlist(result);
    } else if (parameter.isW()) {
        ans = longestWords(result);
    } else if (parameter.isC()) {
        ans = longestAlphas(result);
    }

    if (ans == 0) {
        throw RuntimeException(NO_SATISFYING_WL);
    }

    return ans;
}
