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
extern void containsVertexALL(GraphALL* g, VertexId v);
extern void containsEdgeALL(GraphALL* g, VertexId v, VertexId u);

#endif