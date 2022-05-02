#ifndef SG_H
#define SG_H

#include "Definitions.h"
#include "GraphALL.h"

typedef struct NodeSV NodeSV;
struct NodeSV {
    NodeV* v;
    struct NodeSV* next;
    struct NodeSV* prev;
};

typedef struct SG {
    NodeSV* head;
    int length;
} SG;

extern NodeSV* newNodeSV(NodeV* v);

extern void destroyNodeSV(NodeSV* n);

extern SG* newSG();

extern void destroySG(SG* sg);

extern void addSV(SG* l, NodeV* v);

extern void removeSV(SG* l, NodeSV* n);

extern int containsSV(SG* l, VertexId id);

extern NodeSV* findSV(SG* l, VertexId id);

extern void printSG(SG* l);

extern int isEmptySV(SG* l);

extern SG* copySG(SG* sg);

extern SG* SGFromLLV(LLV* l);
#endif