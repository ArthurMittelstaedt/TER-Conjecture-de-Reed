#ifndef LLN_H
#define LLN_H

#include "Definitions.h"
#include "LLV.h"


// NodeN: (Node neighbour)
// A linked list node (for LLN), containing data about a neighbour vetex.
// Those data are relative to another vertex, we will call the origin.
typedef struct NodeN NodeN;
struct NodeN {
    VertexId id; // id of the neighbour
    struct NodeV* pv; // The NodeV of the neighbour
    struct NodeN* pn; // The NodeN of origin in pv->neighbours
    struct NodeN* next;
    struct NodeN* prev;
};

// LLN: (Linked list of neighbours)
// A linked list of the origin's neighbours.
// Memory of the pointer field of its nodes is up to the user.
typedef struct LLN LLN;
struct LLN
{
    NodeN* head; // Node of the first neighbour
    int length; // number of neighbours (origin's degree)
};

// Returns true if the list is empty.
extern int isEmptyLLN(LLN*);

// Adds a new Node at the head with given id.
// Fields pv and pn are up to the user
extern void addN(LLN*, VertexId);

// Returns the NodeN of the neighbour with given id.
// NULL if it's absent.
extern NodeN* findN(LLN*, VertexId id);

// Removes the neighbour, given directly by its NodeN.
// It's up to the user to only remove nodes that are indeed in the list.
extern void removeN(LLN*, NodeN*);

// Prints the list.
extern void printLLN(LLN*);

// Allocate the memory for an empty list.
extern LLN* newLLN(void);

// Frees the memory of the list, including all its nodes,
// Excluding memory pointed by other NodeN fields.
extern void destroyLLN(LLN*);

// Allocates the memory for a NodeN, with given id, other fields are NULL
extern NodeN* newNodeN(VertexId);

// Frees the memory of a NodeN, excluding memory pointed by its fields.
extern void destroyNodeN(NodeN*);

// Returns TRUE if the list contains a vertex with given id. 
extern int containsN(LLN*, VertexId);

// Copies a list without reversing the order.
extern LLN* copyLLN(LLN*);

#endif