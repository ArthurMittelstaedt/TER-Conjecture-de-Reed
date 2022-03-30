#include <stdlib.h>
#include <stdio.h>
#include "../h/LinkedList.h"

// Adds a vertex at the head of the list
int addLL(LinkedList* l, void* e)
{
    if (!containsLL(l, e)) {
        struct Node* oldHead = l->head;
        struct Node* newHead = (struct Node*)malloc(sizeof(struct Node));
        newHead->e = e;
        newHead->next = oldHead;
        newHead->prev = NULL;
        l->head = newHead;
        if (oldHead != NULL) {
            oldHead->prev = newHead;
        }
        return TRUE;
    } return FALSE;
};

// Returns the first node of the list wich containts v
// returns NULL if v is absent.
static struct Node* findNode(LinkedList* l, void* e) {
    Node* n = l->head;
    while (n != NULL && !l->super->comparator(n->e, e)) {
        n = n->next;
    }
    return n;
};

// Removes a vertex v if it's present by searching for its node then 
// deconnecting it.
// No effect if v is absent. 
int removeLL(LinkedList* l, void* e) {
    Node* n = findNode(l, e);
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
        return TRUE;
    } return FALSE;
};

void printLL(LinkedList* l) {
    printf("[");
    struct Node* n = l->head;
    while (n != NULL) {
        if (n->next != NULL) {
            l->super->printor(n->e);
            printf(", ", n->e);
        }
        else {
            l->super->printor(n->e);
        }
        n = n->next;
    }
    printf("]\n");
}

int containsLL(LinkedList* l, void* e) {
    Node* n = findNode(l, e);
    return (n == NULL) ? FALSE : TRUE;
}

LinkedList* constructorLL(comparator c, printor f) {
    LinkedList* l = (LinkedList*)malloc(sizeof(struct LinkedList));
    l->super = &SetForLinkedList;
    l->head = NULL;
    l->curr = NULL;
    l->next = NULL;
    return  l;
}

void destroyLL(LinkedList* l) {
    struct Node* n = l->head;
    struct Node* prev = n;
    while (n != NULL) {
        n = n->next;
        free(prev);
        prev = n;
    }
    free(l);
}

void* findLL(LinkedList* l, void* e) {
    Node* n = l->head;
    while (n != NULL && !l->super->comparator(n->e, e)) {
        n = n->next;
    }
    return (n == NULL) ? NULL : n->e;
}

void* findCompLL(LinkedList* l, void* e, int (*comp)(void*, void*)) {
    Node* n = l->head;
    while (n != NULL && !comp(n->e, e)) {
        n = n->next;
    }
    return (n == NULL) ? NULL : n->e;
}

extern void* startLL(LinkedList* l) {
    l->curr = l->head;
    if (l->next != NULL) {
        l->next = l->curr->next;
    }
    else {
        l->next = NULL;
    }
    return l->curr->e;
}

extern void* nextLL(LinkedList* l) {
    l->curr = l->next;
    l->next = l->curr->next;
    return l->curr->e;
}
extern int endLL(LinkedList* l) {
    return l->next == NULL;
}