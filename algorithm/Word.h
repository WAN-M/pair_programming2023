//
// Created by DELL on 2023/3/7.
//

#ifndef WORDLIST_WORD_H
#define WORDLIST_WORD_H

#include <string>

using namespace std;

class Word {
private:
    string word;
    char first;
    char last;
    int len;
public:
    Word(char *word);

    const string &getWord() const;

    char getFirst() const;

    char getLast() const;

    int getLen() const;
};


#endif //WORDLIST_WORD_H
