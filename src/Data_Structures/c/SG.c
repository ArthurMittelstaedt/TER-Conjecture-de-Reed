#ifndef SG_C
#define SG_C

#include "../h/SG.h"
#include <stdlib.h>
#include <stdio.h>

NodeSV* newNodeSV(NodeV* v) {
    NodeSV* nnv = (NodeSV*)malloc(sizeof(NodeSV));
    nnv->v = v;
    nnv->next = NULL;
    nnv->prev = NULL;
};

void destroyNodeSV(NodeSV* n) {
    free(n);
};

SG* newSG() {
    SG* l = (SG*)malloc(sizeof(SG));
    l->length = 0;
    l->head = NULL;
};

void destroySG(SG* l) {
    if (l != NULL) {
        NodeSV* cur = NULL;
        NodeSV* next = l->head;
        while (next != NULL) {
            cur = next;
            next = cur->next;
            destroyNodeSV(cur);
        }
    }
};

void addSV(SG* l, NodeV* v) {
    NodeSV* newHead = newNodeSV(v);
    NodeSV* oldHead = l->head;
    l->head = newHead;
    newHead->next = oldHead;
    if (oldHead != NULL) {
        oldHead->prev = newHead;
    }
    l->length += 1;
};


void removeSV(SG* l, NodeSV* v) {
    if (v != NULL) {
        if (v->prev == NULL) {
            l->head = v->next;
        }
        else {
            v->prev->next = v->next;
        }
        if (v->next != NULL) {
            v->next->prev = v->prev;
        }
        destroyNodeSV(v);
        l->length -= 1;
    }
};

int containsSV(SG* l, VertexId id) {
    NodeV* nId = findV(l, id);
    return (nId == NULL) ? 0 : 1;
};

NodeSV* findV(LLV* l, VertexId id) {
    NodeSV* cur = l->head;
    while (cur != NULL && cur->v->id != id) {
        cur = cur->next;
    }
    return cur;
};

void printSV(LLV* l) {
    printf("[\n");
    NodeSV* cur = l->head;
    while (cur != NULL) {
        printf("%c:", cur->v->id);
        printLLN(cur->v->neighbours);
        cur = cur->next;
    }
    printf("]\n");
};

int isEmptySG(SG* l) {
    return l->head == NULL;
}

#endif