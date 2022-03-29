#ifndef LINKEDLIST
#define  LINKEDLIST

#include "../h/SetOfVertices.h"
typedef struct NodeV NodeV;
struct NodeV
{
    vertexId id;
    struct NodeV* next;
    struct NodeV* prev;
};

typedef struct LinkedListOfV LinkedListOfV;
struct LinkedListOfV
{
    struct SetOfV super;
    NodeV* head;
    NodeV* curr;
};

extern void addLLV(LinkedListOfV* c, vertexId v);
extern void removeLLV(LinkedListOfV* c, vertexId v);
extern void printLLV(LinkedListOfV* c);
extern int containsLLV(LinkedListOfV* c, vertexId v);
extern LinkedListOfV* constructorLLV();
extern void destroyLLV(LinkedListOfV* c);
extern vertexId startLLV(LinkedListOfV* c);
extern vertexId nextLLV(LinkedListOfV* c);
extern int endLLV(LinkedListOfV* c);
extern LinkedListOfV* constructorLinkedList();

const SetOfV SetOfVForLinkedList = { (void (*)(SetOfV*, vertexId)) addLLV,
                                    (void (*)(SetOfV*, vertexId)) removeLLV,
                                    (void (*)(SetOfV*)) printLLV,
                                    (int (*)(SetOfV*, vertexId))containsLLV,
                                    (SetOfV * (*)(void))constructorLLV,
                                    (void (*)(SetOfV*))destroyLLV,
                                    (vertexId(*)(SetOfV*))startLLV,
                                    (vertexId(*)(SetOfV*))nextLLV,
                                    (int(*)(SetOfV*))endLLV
};
#endif