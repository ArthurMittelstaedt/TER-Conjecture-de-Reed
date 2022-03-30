#ifndef GRAPH_ADJACENCY_LIST
#define  GRAPH_ADJACENCY_LIST

#include "Set.h"
#include "SetOfVertices.h"
typedef SetOfV* (*AdjacencyListConstructor)(void);

typedef struct VertexAL VertexAL;

struct VertexAL
{
    // vertex's identifier, unique among the graph
    unsigned char id;
    // adjacency list
    struct SetOfV* neighbours;
};
typedef struct GraphAL GraphAL;
struct GraphAL
{
    // List of the graph's vertices
    struct Set* vertices;
    AdjacencyListConstructor ALconstructor;
};

extern void addVertex(struct GraphAL* g, unsigned char v);
extern void addEdge(struct GraphAL* g, unsigned char u, unsigned char v);
extern void removeVetex(struct GraphAL* g, unsigned char v);
extern void removeEdge(struct GraphAL* g, unsigned char u, unsigned char v);
extern GraphAL* constructorGraphAL(Set* (*vertexALSetConstructor)(void), AdjacencyListConstructor);
extern void destroyGraphAL(GraphAL* g);
extern void printGraphAl(GraphAL* g);
#endif