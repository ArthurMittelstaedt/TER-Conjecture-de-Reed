#include <stdlib.h>
#include <stdio.h>
#include "VertexList.h"
#include "LinkedList.h"

// Adds a vertex at the head of the list
static void addVertex(void* this, unsigned char v)
{
    struct LinkedList* l = this;
    struct Node* oldHead = l->head;
    struct Node newHead =
    {
        v, oldHead, NULL
    };
    l->head = newHead;
    if (oldHead != NULL) {
        oldHead->prev = &newHead;
    }
};

// Returns the first node of the list wich containts v
// returns NULL if v is absent.
struct Node* void findVertex(void* this, unsigned char v) {
    struct LinkedList* l = this;
    Node* n = l->head;
    while (n != NULL && n->v != v) {

    }
    return NULL;
};

// Removes a vertex v if it's present by searching for its node then 
// deconnecting it.
// No effect if v is absent. 
static void removeVertex(void* this, unsigned char v) {
    Node* n = findVertex(this, v);
    if (n != NULL) {
        if (n->prev != NULL) {
            n->prev->next = n->next;
        }
        if (n->next != NULL) {
            n->next->prev = n->prev;
        }
        free(n);
    }
};

static void print(void* this) {
    struct LinkedList* l = this;
    Node* n = findVertex(this, v);
    printf("[");
    while (n != NULL) {
        print("%d, ", n->v);
        n = n->next;
    }
    printf("]%n");
}

struct LinkedList* newLinkedList() {
    LinkedList l = { NULL };
    return  l;
}