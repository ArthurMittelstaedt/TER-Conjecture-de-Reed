#ifndef LINKED_LIST
#define  LINKED_LIST

#include "../h/Set.h"
#include <stdlib.h>
typedef struct Node Node;
struct Node
{
    void* e;
    struct Node* next;
    struct Node* prev;
};

typedef struct LinkedList LinkedList;
struct LinkedList {
    struct Set* super;
    struct Node* head;
    struct Node* curr;
    struct Node* next;
};

int (*comparatorLL)(void*, void*);
void (*printorLL)(void*);
extern int addLL(LinkedList* l, void* e);
extern int removeLL(LinkedList* l, void* e);
extern void printLL(LinkedList* l);
extern int containsLL(LinkedList* l, void* e);
extern LinkedList* constructorLL(comparator c, printor f);
extern void destroyLL(LinkedList* l);
extern void* findLL(LinkedList* l, void*);
extern void* findCompLL(LinkedList* l, void*, int (*comp)(void*, void*));
extern void* startLL(LinkedList* l);
extern void* nextLL(LinkedList* l);
extern int endLL(LinkedList* l);

struct Set SetForLinkedList = { (int (*)(Set*, void*))addLL,
                                    (int (*)(Set*, void*))removeLL,
                                    (void (*)(Set*)) printLL,
                                    (int (*)(Set*, void*)) containsLL,
                                    (Set * (*)(void))constructorLL,
                                    (void (*)(Set*))destroyLL,
                                    (void* (*)(Set*, void*))findLL,
                                    (void* (*)(Set*, void*, int (*)(void*, void*)))findCompLL,
                                    (void* (*)(Set*))startLL,
                                    (void* (*)(Set*))nextLL,
                                    (int (*)(Set*))endLL,
                                    NULL,
                                    NULL,
};


extern struct LinkedList* constructorLL();
#endif