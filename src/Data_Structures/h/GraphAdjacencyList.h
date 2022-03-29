#ifndef GRAPH_ADJACENCY_LIST
#define  GRAPH_ADJACENCY_LIST

#include "Set.h"
typedef void* (*AdjacencyListConstructor)(void);

typedef struct VertexAL VertexAL;

struct VertexAL
{
    // vertex's identifier, unique among the graph
    unsigned char id;
    // adjacency list
    struct SetOfVertices* neighbours;
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
extern GraphAL* constructorGraphAL(void* (*vertexALSetConstructor)(void), AdjacencyListConstructor);
extern void destroyGraphAL(GraphAL* g);
extern static printor vertexPrinter(void* e);
extern void printGraphAl(GraphAL* g);
#endif