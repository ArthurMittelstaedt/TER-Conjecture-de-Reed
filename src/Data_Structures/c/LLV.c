#include "../h/LLV.h"
#include <stdlib.h>
#include <stdio.h>

NodeV* newNodeV(VertexId id) {
    NodeV* nnv = (NodeV*)malloc(sizeof(NodeV));
    nnv->id = id;
    nnv->col = 0;
    nnv->neighbours = newLLN();
    nnv->next = NULL;
    nnv->prev = NULL;
};

void destroyNodeV(NodeV* n, int destroy_neighbour) {
    if (n != NULL) {
        if (destroy_neighbour)
            destroyLLN(n->neighbours);
        free(n);
    }
};

LLV* newLLV() {
    LLV* l = (LLV*)malloc(sizeof(LLV));
    l->length = 0;
    l->head = NULL;
};

void destroyLLV(LLV* l, int destroy_neighbour) {
    if (l != NULL) {
        NodeV* cur = NULL;
        NodeV* next = l->head;
        while (next != NULL) {
            cur = next;
            next = cur->next;
            destroyNodeV(cur, destroy_neighbour);
        }
    }
};

void addV(LLV* l, VertexId id) {
    NodeV* newHead = newNodeV(id);
    NodeV* oldHead = l->head;
    l->head = newHead;
    newHead->next = oldHead;
    if (oldHead != NULL) {
        oldHead->prev = newHead;
    }
    l->length += 1;
};


void removeV(LLV* l, NodeV* n, int destroy_neighbour) {
    if (n != NULL) {
        if (n->prev == NULL) {
            l->head = n->next;
        }
        else {
            n->prev->next = n->next;
        }
        if (n->next != NULL) {
            n->next->prev = n->prev;
        }
        destroyNodeV(n, destroy_neighbour);
        l->length -= 1;
    }
};

int containsV(LLV* l, VertexId id) {
    NodeV* nId = findV(l, id);
    return (nId == NULL) ? 0 : 1;
};

NodeV* findV(LLV* l, VertexId id) {
    NodeV* cur = l->head;
    while (cur != NULL && cur->id != id) {
        cur = cur->next;
    }
    return cur;
};

void printV(LLV* l) {
    printf("[\n");
    NodeV* cur = l->head;
    while (cur != NULL) {
        printf("%c:", cur->id);
        printLLN(cur->neighbours);
        cur = cur->next;
    }
    printf("]\n");
};

int isEmptyV(LLV* l) {
    return l->head == NULL;
}

// copies l but not deep copy
LLV* copyLLV(LLV* l) {
    LLV* clone = newLLV();
    NodeV* cur = l->head;
    while (cur != NULL) {
        addV(clone, cur->id);
        clone->head->neighbours = cur->neighbours;
        cur = cur->next;
    }
    return clone;
}