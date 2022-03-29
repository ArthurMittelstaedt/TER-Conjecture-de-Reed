#ifndef LINKED_LIST_OF_V
#define  LINKED_LIST_OF_V

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

extern void addLLV(LinkedListOfV* l, vertexId v);
extern void removeLLV(LinkedListOfV* l, vertexId v);
extern void printLLV(LinkedListOfV* l);
extern int containsLLV(LinkedListOfV* l, vertexId v);
extern LinkedListOfV* constructorLLV();
extern void destroyLLV(LinkedListOfV* l);
extern vertexId startLLV(LinkedListOfV* l);
extern vertexId nextLLV(LinkedListOfV* l);
extern int endLLV(LinkedListOfV* l);
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