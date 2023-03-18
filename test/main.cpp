#include <iostream>
#include <fstream>
#include <set>
#include <cstring>
#include "core/library.h"

using namespace std;

int readAvailableFile(char *data[], const char *const fileName) {
    fstream inFile;
    inFile.open(fileName, ios::in);
    if (!inFile.is_open()) {
        cout << "打开文件失败" << endl;
    }

    set<string> words;
    char *buf = (char *) malloc(sizeof(char) * 50);
    int cnt = 0;
    char c;
    int size = 0;
    while (!inFile.eof()) {
        c = (char) inFile.get();
//        inFile >> c;
        if (inFile.fail()) {
            break;
        }
        if (isalpha(c)) {
            buf[cnt++] = (char) tolower(c);
        } else {
            if (cnt > 0) {
                buf[cnt] = 0;
                if (words.find(buf) == words.end()) {
                    words.insert(buf);
                    data[size] = (char *) malloc(sizeof(char) * (cnt + 5));
                    strcpy(data[size++], buf);
                }
            }
            cnt = 0;
        }
    }
    if (cnt > 0) {
        buf[cnt] = 0;
        data[size] = (char *) malloc(sizeof(char) * (cnt + 5));
        strcpy(data[size++], buf);
    }
    free(buf);
    inFile.close();

    return size;
}

//int main() {
//
//    char *words[100];
//    int len = readAvailableFile(words, "D:\\pair_programming2023\\test\\Debug\\test.txt");
//    char *result[200];
//    int reSize = gen_chains_all(words, len, result);
//    cout << reSize << endl;
//    for (int i = 0; i < reSize; i++) {
//        std::cout << result[i] << std::endl;
//    }
//
//    return 0;
//}
