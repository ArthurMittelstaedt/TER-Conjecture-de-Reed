#ifndef LLV_H
#define LLV_H
#include "LLN.h"
// Linked List of vertices :
// A linked list of vertices, each node contains a vertex represented
// by its id and it's neighbours;
// Multiples entries can share their id

// Definition of the type for representing vertex ids
// As we will work on small graphs ~20 vertices, we chose the smallest
// type available.
typedef unsigned char VertexId;
// We don't need more colors than vertices.
typedef VertexId Color;

// Node of a Linked List of vertices
typedef struct NodeV NodeV;
struct NodeV {
    VertexId id;// Id of the vertex
    Color col; // Color of the vertex, value 0 means no color
    struct LLN* neighbours; // List of the vertex's neighbours
    struct NodeV* next; // Next node
    struct NodeV* prev; // previous node
};

typedef struct LLV {
    NodeV* head; // First Node of the list, its prev field is NULL
    int length; // Number of Node in the list
} LLV;


// Allocate the memory for a node for a vertex with id = id,
// empty neighbourhood and no color (col=0)
extern NodeV* newNodeV(VertexId id);

// Frees the memory of a node, including its neigbourhood list
extern void destroyNodeV(NodeV* n, int destroy_neighbour);

// Allocate the memory for an empty linked list of vertices
extern LLV* newLLV();

// Frees the moemory of a linked list of vertices
// including all its nodes.
extern void destroyLLV(LLV* l, int destroy_neighbour);

// Adds a new node at the head, for a vertex with id = id 
// and empty neighbourhood
// A. E. : l != NULL
extern void addV(LLV* l, VertexId id);

// Removes the node n from the list
// A. E. : n is indeed a node of the list
//         && l != NULL
extern void removeV(LLV* l, NodeV* n, int destroy_neighbour);

// Returns 1 if l contains a node with vertex id = id
// 0 otherwise.
// A. E. : l != NULL
extern int containsV(LLV* l, VertexId id);

// Returns the node of l with vertex id = id
// NULL otherwise.
// A. E. : l != NULL
extern NodeV* findV(LLV* l, VertexId id);

// Prints the list l on default output.
// A. E. : != NULL
extern void printV(LLV* l);

extern int isEmptyV(LLV* l);
#endif