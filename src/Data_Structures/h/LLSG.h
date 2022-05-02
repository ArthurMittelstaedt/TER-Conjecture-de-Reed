#ifndef LLSG_H
#define LLSG_H

#include "SG.h"

typedef struct NodeSG NodeSG;
struct NodeSG {
    SG* sg;
    NodeSG* next;
    NodeSG* prev;
};

typedef struct LLSG LLSG;
struct LLSG {
    NodeSG* head;
    int length;
};

extern NodeSG* newNodeSG(SG* sg);

extern void destroyNodeSG(NodeSG* n);

extern LLSG* newLLSG();

extern void destroyLLSG(LLSG* l);

extern void addSG(LLSG* l, SG* sg);

extern void printLLSG(LLSG* l);

#endif