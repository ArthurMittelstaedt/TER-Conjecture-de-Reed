#ifndef GRAPHADJACENCYLIST
#define  GRAPHADJACENCYLIST

#include "Collection.h"

typedef struct VertexAdjacencyList
{
    // vertex's identifier, unique among the graph
    unsigned char id;
    // adjacency list
    struct Collection* neighbours;
} VertexAdjacencyList;

extern void addVertex(struct GraphAdjacencyList* g, unsigned char v);
extern void addEdge(struct GraphAdjacencyList* g, unsigned char u, unsigned char v);
extern void removeVetex(struct GraphAdjacencyList* g, unsigned char v);
extern void removeEdge(struct GraphAdjacencyList* g, unsigned char u, unsigned char v);

typedef void* (*AdjacencyListConstructor)(void);

typedef struct GraphAdjacencyList
{
    // List of the graph's vertices
    struct Collection* vertices;
    AdjacencyListConstructor constructor;
} GraphAdjacencyList;
#endif