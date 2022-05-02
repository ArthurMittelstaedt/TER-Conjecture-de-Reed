#ifndef GRAPHALL_H
#define GRAPHALL_H

#include "LLV.h"

typedef struct GraphALL GraphALL;
struct GraphALL {
    LLV* vertices;
};

extern GraphALL* newGraphALL();
extern void destroyGraphALL(GraphALL* g);
extern void addVertexALL(GraphALL* g, VertexId v);
extern void addEdgeALL(GraphALL* g, VertexId v, VertexId u);
extern void removeVertexALL(GraphALL* g, VertexId v);
extern void removeEdgeALL(GraphALL* g, VertexId v, VertexId u);
extern int containsVertexALL(GraphALL* g, VertexId v);
extern int containsEdgeALL(GraphALL* g, VertexId v, VertexId u);
extern void printGraphALL(GraphALL* g);
extern void resetColALL(GraphALL* g);
extern void removeVertexNodeALL(GraphALL* g, NodeV* nvV);
extern GraphALL* subGraphALL(GraphALL* g, binarySubG subgBits);

#endif