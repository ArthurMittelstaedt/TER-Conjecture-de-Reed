#ifndef LINKEDLIST
#define  LINKEDLIST

#include "../h/Collection.h"
typedef struct Node
{
    void* e;
    struct Node* next;
    struct Node* prev;
} Node;

extern void addLL(Collection* c, void* e);
extern void removeLL(Collection* c, void* e);
extern void printLL(Collection* c);
extern int containsLL(Collection* this, void* e);
extern Collection* constructorLL();
extern void destroyLL(Collection* c);
extern void* findLL(Collection* c, void*, comparator);
extern void printpLL(Collection* c, printor);
extern void* startLL(Collection* c);
extern void* nextLL(Collection* c);
extern int endLL(Collection* c);

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