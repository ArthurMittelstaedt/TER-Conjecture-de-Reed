#ifndef LINKEDLIST
#define  LINKEDLIST

#include "../h/Collection.h"
typedef struct Node
{
    void* e;
    struct Node* next;
    struct Node* prev;
} Node;

extern void addLL(void* c, void* e);
extern void removeLL(void* c, void* e);
extern void printLL(void* c);
extern int containsLL(void* c, void* e);
extern void* constructorLL();
extern void destroyLL(void* c);
extern void* findLL(void* c, void*, comparator);
extern void printpLL(void* c, printor);
extern void* startLL(void* c);
extern void* nextLL(void* c);
extern int endLL(void* c);

const struct Collection CollectionForLinkedList = { addLL,
                                    removeLL,
                                    printLL,
                                    containsLL,
                                    constructorLL,
                                    destroyLL,
                                    printpLL,
                                    findLL,
                                    startLL,
                                    nextLL,
                                    endLL
};

typedef struct LinkedList
{
    struct Collection Collection;
    struct Node* head;
    struct Node* curr;
} LinkedList;

extern struct LinkedList* constructorLinkedList();
#endif