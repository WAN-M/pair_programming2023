//
// Created by DELL on 2023/3/17.
//

#ifndef CORE_EDGE_H
#define CORE_EDGE_H

#include <string>

using namespace std;

namespace OPTIMIZE {
    class Edge {
    private:
        char *word;
        int len;
        int u;
        int v;
    public:
        explicit Edge(char *word);

        friend bool operator<(const Edge &a, const Edge &b);

        const char *const getWord() const;

        int getU() const;

        int getV() const;

        int getLen() const;
    };
}


#endif //CORE_EDGE_H
