#ifndef LINKED_LIST_OF_V
#define  LINKED_LIST_OF_V

#include "../h/SetOfVAL.h"
typedef struct NodeVAL NodeVAL;

struct NodeVAL
{
    VertexAL* VAL;
    struct NodeVAL* next;
    struct NodeVAL* prev;
};

typedef struct LinkedListOfVAL LinkedListOfVAL;
struct LinkedListOfVAL
{
    struct SetOfVAL super;
    NodeVAL* head;
    NodeVAL* curr;

};

extern int addLLVAL(LinkedListOfVAL* l, vertexId v);
extern int removeLLVAL(LinkedListOfVAL* l, vertexId v);
extern void printLLVAL(LinkedListOfVAL* l);
extern int containsLLVAL(LinkedListOfVAL* l, vertexId v);
extern VertexAL* findLLVAL(LinkedListOfVAL*, vertexId v);
extern LinkedListOfVAL* constructorLLVAL();
extern void destroyLLVAL(LinkedListOfVAL* l);
extern VertexAL* startLLVAL(LinkedListOfVAL* l);
extern VertexAL* nextLLVAL(LinkedListOfVAL* l);
extern int endLLVAL(LinkedListOfVAL* l);
extern LinkedListOfVAL* constructorLinkedList();

SetOfVAL SetOfVALForLinkedList = { (int (*)(SetOfVAL*, vertexId)) addLLVAL,
                                    (int (*)(SetOfVAL*, vertexId)) removeLLVAL,
                                    (void (*)(SetOfVAL*)) printLLVAL,
                                    (int (*)(SetOfVAL*, vertexId))containsLLVAL,
                                    (VertexAL * (*)(SetOfVAL*, vertexId))findLLVAL,
                                    (SetOfVAL * (*)(void))constructorLLVAL,
                                    (void (*)(SetOfVAL*))destroyLLVAL,
                                    (VertexAL * (*)(SetOfVAL*))startLLVAL,
                                    (VertexAL * (*)(SetOfVAL*))nextLLVAL,
                                    (int(*)(SetOfVAL*))endLLVAL,
                                    NULL
};
#endif