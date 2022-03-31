#include "../h/LLV.h"
#include <stdlib.h>
#include <stdio.h>

NodeV* newNodeV(VertexId id) {
    NodeV* nnv = (NodeV*)malloc(sizeof(NodeV));
    nnv->id = id;
    nnv->neighbours = newLLN();
    nnv->next = NULL;
    nnv->prev = NULL;
};

void destroyNodeV(NodeV* n) {
    if (n != NULL) {
        destroyLLN(n->neighbours);
        free(n);
    }
};

LLV* newLLV() {
    LLV* l = (LLV*)malloc(sizeof(LLV));
    l->length = 0;
    l->head = NULL;
};

void destroyLLV(LLV* l) {
    if (l != NULL) {
        NodeV* cur = NULL;
        NodeV* next = l->head;
        while (next != NULL) {
            cur = next;
            next = cur->next;
            destroyNodeV(cur);
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


void removeV(LLV* l, NodeV* n) {
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
        destroyNodeV(n);
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