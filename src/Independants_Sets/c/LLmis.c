#include "../h/LLmis.h"

// Allocate the memory for a node with given list representing an ipendant set
NodeMIS* newNodeMIS(LLV* mis) {
    NodeMIS* newNode = malloc(sizeof(NodeMIS));
    newNode->mis = mis;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
};

// Frees the memory of a node, including its mis
void destroyNodeMIS(NodeMIS* n) {
    destroyLLV(n->mis, 0);
    free(n);
};

// Allocate the memory for an empty linked list of mis
LLMIS* newLLMIS() {
    LLMIS* newList = malloc(sizeof(LLMIS));
    newList->head = NULL;
    newList->length = 0;
    return newList;
};

// Frees the moemory of a linked list of vertices
// including all its nodes and their mis.
void destroyLLMIS(LLMIS* l) {
    if (l != NULL) {
        NodeMIS* cur = NULL;
        NodeMIS* next = l->head;
        while (next != NULL) {
            cur = next;
            next = cur->next;
            destroyNodeMIS(cur);
        }
    }
};

// Adds a new node at the head, with given mis
// A. E. : l != NULL
void addMIS(LLMIS* l, LLV* mis) {
    NodeMIS* newHead = newNodeMIS(mis);
    NodeMIS* oldHead = l->head;
    l->head = newHead;
    newHead->next = oldHead;
    if (oldHead != NULL) {
        oldHead->prev = newHead;
    }
    l->length += 1;
};

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
void printMIS(LLMIS* l) {
    printf("[\n");
    NodeMIS* cur = l->head;
    while (cur != NULL) {
        printV(cur->mis);
        cur = cur->next;
    }
    printf("]\n");
};