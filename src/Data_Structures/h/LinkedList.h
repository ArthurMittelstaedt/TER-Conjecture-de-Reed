#ifndef LINKED_LIST
#define  LINKED_LIST

#include "../h/Set.h"
typedef struct Node Node;
struct Node
{
    void* e;
    struct Node* next;
    struct Node* prev;
};

typedef struct LinkedList LinkedList;
struct LinkedList {
    struct Set super;
    struct Node* head;
    struct Node* curr;
    int (*comparator)(void*, void*);
    void (*printor)(void*);
};

int (*comparatorLL)(void*, void*);
void (*printorLL)(void*);
extern void addLL(LinkedList* l, void* e);
extern void removeLL(LinkedList* l, void* e);
extern void printLL(LinkedList* l);
extern int containsLL(LinkedList* l, void* e);
extern LinkedList* constructorLL();
extern void destroyLL(LinkedList* l);
extern void* findLL(LinkedList* l, void*);
extern void* startLL(LinkedList* l);
extern void* nextLL(LinkedList* l);
extern int endLL(LinkedList* l);

const struct Set SetForLinkedList = { addLL,
                                    removeLL,
                                    printLL,
                                    containsLL,
                                    constructorLL,
                                    destroyLL,
                                    findLL,
                                    startLL,
                                    nextLL,
                                    endLL
};


extern struct LinkedList* constructorLinkedList();
#endif