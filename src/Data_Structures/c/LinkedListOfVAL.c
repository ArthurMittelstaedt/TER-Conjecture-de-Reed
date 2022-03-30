#include <stdlib.h>
#include <stdio.h>
#include "../h/LinkedListOfVAL.h"

VertexAL* constructorVertexAL(SetOfV* (*ALconstructor)(void), vertexId v) {
    VertexAL* newV = (VertexAL*)malloc(sizeof(VertexAL));
    newV->id = v;
    newV->neighbours = ALconstructor();
    return newV;
}

void destroyVertexAL(VertexAL* v) {
    if (v != NULL) {
        v->neighbours->destroy(v->neighbours);
        free(v);
    }
}

// Adds a vertex at the head of the list
// No effect if a vertex already has this id
int addLLVAL(LinkedListOfVAL* l, vertexId v) {
    if (!containsLLVAL(l, v)) {
        NodeVAL* oldHead = l->head;
        NodeVAL* newHead = (NodeVAL*)malloc(sizeof(NodeVAL));
        VertexAL* newVAL = constructorVertexAL(l->super.ALconstructor, v);
        newHead->VAL = newVAL;
        newHead->next = oldHead;
        newHead->prev = NULL;
        l->head = newHead;
        if (oldHead != NULL) {
            oldHead->prev = newHead;
        }
        return TRUE;
    } return FALSE;
};

// Returns the NodeVAL of the list wich containts v
// returns NULL if v is absent.
static NodeVAL* findNodeVAL(struct LinkedListOfVAL* l, vertexId v) {
    NodeVAL* n = l->head;
    while (n != NULL && n->VAL->id != v) {
        n = n->next;
    }
    return n;
};

void destroyNodeVAL(NodeVAL* n) {
    destroyVertexAL(n->VAL);
    free(n);
}

// Removes a vertex v if it's present by searching for its NodeVAL then 
// deconnecting it.
// No effect if v is absent. 
int removeLLVAL(LinkedListOfVAL* l, vertexId v) {
    NodeVAL* n = findNodeVAL(l, v);
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
        destroyNodeVAL(n);
        return TRUE;
    } return FALSE;
};

void printLLVAL(LinkedListOfVAL* l) {
    printf("[");
    NodeVAL* n = l->head;
    while (n != NULL) {
        if (n->next != NULL) {
            printf("%d:", n->VAL->id);
            n->VAL->neighbours->print(n->VAL->neighbours);
            printf(", ");
        }
        else {
            printf("%d:", n->VAL->id);
            n->VAL->neighbours->print(n->VAL->neighbours);
        }
        n = n->next;
    }
    printf("]\n");
}

int containsLLVAL(LinkedListOfVAL* l, vertexId e) {
    NodeVAL* n = findNodeVAL(l, e);
    return (n == NULL) ? FALSE : TRUE;
}

LinkedListOfVAL* constructorLLVAL() {
    LinkedListOfVAL* l = (LinkedListOfVAL*)malloc(sizeof(struct LinkedListOfVAL));
    l->super = SetOfVALForLinkedList;
    l->head = NULL;
    l->curr = NULL;
    return l;
}

void destroyLLVAL(LinkedListOfVAL* l) {
    NodeVAL* n = l->head;
    NodeVAL* prev = n;
    while (n != NULL) {
        n = n->next;
        free(prev);
        prev = n;
    }
    free(l);
}

extern VertexAL* startLLVAL(LinkedListOfVAL* l) {
    l->curr = l->head;
    return l->curr->VAL;
}

// Faiblaisse remove en cours de parcours!!!!!
extern VertexAL* nextLLVAL(LinkedListOfVAL* l) {
    l->curr = l->curr->next;
    return l->curr->VAL;
}

extern int endLLVAL(LinkedListOfVAL* l) {
    return l->curr->next == NULL;
}