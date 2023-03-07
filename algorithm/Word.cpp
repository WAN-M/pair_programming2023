//
// Created by DELL on 2023/3/7.
//

#include "Word.h"
#include <cstring>

Word::Word(char *word) {
    this->word = word;
    this->first = word[0];
    this->len = (int) strlen(word);
    this->last = word[len - 1];
}

const string &Word::getWord() const {
    return word;
}

char Word::getFirst() const {
    return first;
}

char Word::getLast() const {
    return last;
}

int Word::getLen() const {
    return len;
}
