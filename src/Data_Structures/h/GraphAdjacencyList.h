#ifndef GRAPH_ADJACENCY_LIST
#define  GRAPH_ADJACENCY_LIST

#include "SetOfVAL.h"
#include "SetOfVertices.h"

typedef struct GraphAL GraphAL;
struct GraphAL
{
    // List of the graph's vertices
    struct SetOfVAL* vertices;
    SetOfV* (*ALconstructor)(void);
};

extern void addVertex(struct GraphAL* g, unsigned char v);
extern void addEdge(struct GraphAL* g, unsigned char u, unsigned char v);
extern void removeVetex(struct GraphAL* g, unsigned char v);
extern void removeEdge(struct GraphAL* g, unsigned char u, unsigned char v);
extern GraphAL* constructorGraphAL(SetOfVAL* (*vertexALSetConstructor)(void), SetOfV* (*ALconstructor)(void));
extern void destroyGraphAL(GraphAL* g);
extern void printGraphAl(GraphAL* g);
#endif