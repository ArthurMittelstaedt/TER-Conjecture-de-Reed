#ifndef GRAPHALL_H
#define GRAPHALL_H

#include "LLV.h"
#include "LLN.h"

// GraphALL: (Graph adjacency linked list)
// Graphs implemented with a linked list of adjacency linked lists.
// It's up to the user to avoid redundant vertices and edges.
// Memory of contained pointer fields, is up to the structure.
typedef struct GraphALL GraphALL;
struct GraphALL {
    LLV* vertices; // Linked list of the graph's vertices
};

// Allocate the memory for an empty graph.
extern GraphALL* newGraphALL();

// Frees the memory of a graphALL including all the adjacency lists.
extern void destroyGraphALL(GraphALL* g);

// Adds a vertex at the head of g->vertices, with empty neighbourhood and id=v.
// No verification of the presence of vertices with same id.
extern void addVertexALL(GraphALL* g, VertexId v);

// Adds an edge between the vertices of id v and u.
// If at least one of the ids is absent, no effect.
extern void addEdgeALL(GraphALL* g, VertexId v, VertexId u);

// Removes the vertex v from g, including incident edges.
// If no vertex with id = v, no effect.
extern void removeVertexALL(GraphALL* g, VertexId v);

// Removes the edge between v and u.
// If at least one of the ids is absent, no effect.
extern void removeEdgeALL(GraphALL* g, VertexId v, VertexId u);

// Returns TRUE if g contains a vertex with id v.
extern BOOL containsVertexALL(GraphALL* g, VertexId v);

// Returns TRUE if g contains an edge with extremities v and u.
extern BOOL containsEdgeALL(GraphALL* g, VertexId v, VertexId u);

// Prints g.
extern void printGraphALL(GraphALL* g);

// Sets all the colours of g's vertices to 0.
extern void resetColALL(GraphALL* g);

// Removes a vertex from g given directly by its Node.
extern void removeVertexNodeALL(GraphALL* g, NodeV* nvV);

// return a the sub graph of g corresponding to the given binary descrition.
extern GraphALL* subGraphALL(GraphALL* g, binarySubG subgBits);

#endif