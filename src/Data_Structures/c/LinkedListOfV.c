#include <stdlib.h>
#include <stdio.h>
#include "../h/LinkedListOfV.h"

// Adds a vertex at the head of the list
// No effect if a vertex already has this id
void addLLV(LinkedListOfV* l, vertexId v)
{
    if (!containsLLV(l, v)) {
        NodeV* oldHead = l->head;
        NodeV* newHead = (NodeV*)malloc(sizeof(NodeV));
        newHead->id = v;
        newHead->next = oldHead;
        newHead->prev = NULL;
        l->head = newHead;
        if (oldHead != NULL) {
            oldHead->prev = newHead;
        }
    }
};

// Returns the NodeV of the list wich containts v
// returns NULL if v is absent.
static NodeV* findNode(struct LinkedListOfV* l, vertexId v) {
    NodeV* n = l->head;
    while (n != NULL && n->id != v) {
        n = n->next;
    }
    return n;
};

// Removes a vertex v if it's present by searching for its NodeV then 
// deconnecting it.
// No effect if v is absent. 
void removeLLV(LinkedListOfV* l, vertexId v) {
    NodeV* n = findNode(l, v);
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

void printLLV(LinkedListOfV* l) {
    printf("[");
    NodeV* n = l->head;
    while (n != NULL) {
        if (n->next != NULL) {
            printf("%d, ", n->id);
        }
        else {
            printf("%d", n->id);
        }
        n = n->next;
    }
    printf("]\n");
}

int containsLLV(LinkedListOfV* l, vertexId e) {
    NodeV* n = findNode(l, e);
    return (n == NULL) ? FALSE : TRUE;
}

LinkedListOfV* constructorLLV() {
    LinkedListOfV* l = (LinkedListOfV*)malloc(sizeof(struct LinkedListOfV));
    l->super = SetOfVForLinkedList;
    l->head = NULL;
    l->curr = NULL;
    return l;
}

void destroyLLV(LinkedListOfV* l) {
    NodeV* n = l->head;
    NodeV* prev = n;
    while (n != NULL) {
        n = n->next;
        free(prev);
        prev = n;
    }
    free(l);
}

extern vertexId startLLV(LinkedListOfV* l) {
    l->curr = l->head;
    return l->curr->id;
}

// Faiblaisse remove en cours de parcours!!!!!
extern vertexId nextLLV(LinkedListOfV* l) {
    l->curr = l->curr->next;
    return l->curr->id;
}
extern int endLLV(LinkedListOfV* l) {
    return l->curr->next == NULL;
}