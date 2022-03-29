#include <stdlib.h>
#include <stdio.h>
#include "../h/LinkedList.h"

// Adds a vertex at the head of the list
void addLL(void* c, void* e)
{
    struct LinkedList* l = (struct LinkedList*)c;
    struct Node* oldHead = l->head;
    struct Node* newHead = (struct Node*)malloc(sizeof(struct Node));
    newHead->e = e;
    newHead->next = oldHead;
    newHead->prev = NULL;
    l->head = newHead;
    if (oldHead != NULL) {
        oldHead->prev = newHead;
    }
};

// Returns the first node of the list wich containts v
// returns NULL if v is absent.
static struct Node* findVertex(struct LinkedList* c, void* e) {
    struct LinkedList* l = c;
    Node* n = l->head;
    while (n != NULL && n->e != e) {
        n = n->next;
    }
    return n;
};

// Removes a vertex v if it's present by searching for its node then 
// deconnecting it.
// No effect if v is absent. 
void removeLL(void* c, void* e) {
    struct LinkedList* l = (struct LinkedList*)c;
    Node* n = findVertex(l, e);
    if (n != NULL) {
        if (n->prev != NULL) {
            n->prev->next = n->next;
        }
        else {
            l->head = n->next;
        }
        if (n->next != NULL) {
            n->next->prev = n->prev;
        }
        free(n);
    }
};

void printLL(void* c) {
    struct LinkedList* l = (struct LinkedList*)c;
    printf("[");
    struct Node* n = l->head;
    while (n != NULL) {
        if (n->next != NULL) {
            printf("%d, ", n->e);
        }
        else {
            printf("%d", n->e);
        }
        n = n->next;
    }
    printf("]\n");
}

#define TRUE 1
#define FALSE 0
int containsLL(void* c, void* e) {
    struct LinkedList* l = (LinkedList*)c;
    Node* n = findVertex(l, e);
    return (n == NULL) ? FALSE : TRUE;
}

void* constructorLL() {
    LinkedList* l = (LinkedList*)malloc(sizeof(struct LinkedList));
    l->Collection = CollectionForLinkedList;
    l->head = NULL;
    l->curr = NULL;
    return  (void*)l;
}

void destroyLL(void* c) {
    LinkedList* l = (LinkedList*)c;
    struct Node* n = l->head;
    struct Node* prev = n;
    while (n != NULL) {
        n = n->next;
        free(prev);
        prev = n;
    }
    free(l);
}

void* findLL(void* c, void* e, comparator comp) {
    struct LinkedList* l = (struct LinkedList*)c;
    Node* n = l->head;
    while (n != NULL && !comp(n->e, e)) {
        n = n->next;
    }
    return (n == NULL) ? NULL : n->e;
}

extern void printpLL(void* c, printor p) {
    struct LinkedList* l = (struct LinkedList*)c;
    printf("[");
    struct Node* n = l->head;
    while (n != NULL) {
        if (n->next != NULL) {
            p(n->e);
            printf(", ");
        }
        else {
            p(n->e);
        }
        n = n->next;
    }
    printf("]\n");
};

extern void* startLL(void* c) {
    LinkedList* l = (LinkedList*)c;
    l->curr = l->head;
    return l->curr->e;
}

extern void* nextLL(void* c) {
    LinkedList* l = (LinkedList*)c;
    l->curr = l->curr->next;
    return l->curr->e;
}
extern int endLL(void* c) {
    LinkedList* l = (LinkedList*)c;
    return l->curr->next == NULL;
}