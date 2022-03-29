#include "VertexList.h"

typedef struct VertexAdjacencyList
{
    // vertex's identifier, unique among the graph
    unsigned char id;
    // adjacency list
    struct VertexList *neighbours;
};

typedef struct GraphAdjacencyList
{
    // List of the graph's vertices
    struct VertexList *vertices;
};
