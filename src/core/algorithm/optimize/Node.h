//
// Created by DELL on 2023/3/17.
//

#ifndef CORE_NODE_H
#define CORE_NODE_H

#include "Edge.h"
#include <vector>
#include <list>
#include <set>

namespace OPTIMIZE {
    class Node {
    private:
        int pos;
        vector<list<OPTIMIZE::Edge *>> edges;
//        int edgePos[30];
        list<OPTIMIZE::Edge *>::iterator edgePos[30];
        set<int> next;
    public:
        Node(int pos);

        void addEdge(OPTIMIZE::Edge *e);

        bool hasEdge(int v);

        OPTIMIZE::Edge *nextEdge(int v);

        void resetAll();

        void sortAll();

        const set<int> &getNext() const;

//        int getEdgePos(int v);
//
//        void setEdgePos(int v, int value);

        void increaseItr(int v);

        void decreaseItr(int v);
    };
}



#endif //CORE_NODE_H
