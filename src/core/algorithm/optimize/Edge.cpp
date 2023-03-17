//
// Created by DELL on 2023/3/17.
//

#include "Edge.h"
#include <cstring>
#include "../../tools/Char2Pos.h"

const char *const OPTIMIZE::Edge::getWord() const {
    return word;
}

/*
 * 再根据单词长度从大到小排序。
 */
// TODO 检验排序规则正确性
bool operator<(const OPTIMIZE::Edge &a, const OPTIMIZE::Edge &b) {
    return a.getLen() > b.getLen();
}

int OPTIMIZE::Edge::getLen() const {
    return len;
}

int OPTIMIZE::Edge::getU() const {
    return u;
}

int OPTIMIZE::Edge::getV() const {
    return v;
}

OPTIMIZE::Edge::Edge(char *word) {
    this->word = word;
    this->len = strlen(word);
    this->u = char2pos(word[0]);
    this->v = char2pos(word[len - 1]);
}
