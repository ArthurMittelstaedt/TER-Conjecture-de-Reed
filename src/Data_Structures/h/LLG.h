#ifndef LLG_H
#define LLG_H

#include "GraphALL.h"

typedef struct NodeG NodeG;
struct NodeG {
    GraphALL* g;
    NodeG* next;
    NodeG* prev;
};

typedef struct LLG LLG;
struct LLG {
    NodeG* head;
    int length;
};

extern NodeG* newNodeG(GraphALL* g);

extern void destroyNodeG(NodeG* n);

extern LLG* newLLG();

extern void destroyLLG(LLG* l);

extern void addG(LLG* l, GraphALL* g);

extern void printLLG(LLG* l);



















#endif