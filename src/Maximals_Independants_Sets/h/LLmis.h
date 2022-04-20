#ifndef LLMIS_H
#define LLMIS_H

#include "../../Data_Structures/c/graphALL.c"

// mis = maximal independant set
typedef struct NodeMIS NodeMIS;
struct NodeMIS {
    LLV* mis;
    NodeMIS* next;
    NodeMIS* prev;
};

typedef struct LLMIS LLMIS;
struct LLMIS {
    NodeMIS* head;
    int length;
};

// Allocate the memory for a node with given list representing an ipendant set
extern NodeMIS* newNodeMIS(LLV* mis);

// Frees the memory of a node, including its mis
extern void destroyNodeMIS(NodeMIS* n);

// Allocate the memory for an empty linked list of mis
extern LLMIS* newLLMIS();

// Frees the moemory of a linked list of vertices
// including all its nodes and their mis.
extern void destroyLLMIS(LLMIS* l);

// Adds a new node at the head, with given mis
// A. E. : l != NULL
extern void addMIS(LLMIS* l, LLV* mis);

// Removes the node n from the list
// A. E. : n is indeed a node of the list
//         && l != NULL
//extern void removeV(LLV* l, NodeV* n);

// Returns 1 if l contains a node with vertex id = id
// 0 otherwise.
// A. E. : l != NULL
//extern int containsV(LLV* l, VertexId id);

// Returns the node of l with vertex id = id
// NULL otherwise.
// A. E. : l != NULL
//extern NodeV* findV(LLV* l, VertexId id);

// Prints the list l on default output.
// A. E. : != NULL
extern void printMIS(LLMIS* l);

#endif