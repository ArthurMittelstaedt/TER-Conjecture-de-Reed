
#ifndef LLSG_C
#define LLSG_C

#include "../h/LLSG.h"

NodeSG* newNodeSG(SG* sg) {
    NodeSG* newNode = malloc(sizeof(NodeSG));
    newNode->sg = sg;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
};

void destroyNodeSG(NodeSG* n) {
    free(n);
};

LLSG* newLLSG() {
    LLSG* newList = malloc(sizeof(LLSG));
    newList->head = NULL;
    newList->length = 0;
    return newList;
};

void destroyLLSG(LLSG* l) {
    if (l != NULL) {
        NodeSG* cur = NULL;
        NodeSG* next = l->head;
        while (next != NULL) {
            cur = next;
            next = cur->next;
            destroyNodeSG(cur);
        }
    }
};

void addSG(LLSG* l, SG* sg) {
    NodeSG* newHead = newNodeMIS(sg);
    NodeSG* oldHead = l->head;
    l->head = newHead;
    newHead->next = oldHead;
    if (oldHead != NULL) {
        oldHead->prev = newHead;
    }
    l->length += 1;
};

// A. E. : != NULL
void printSG(LLSG* l) {
    printf("[\n");
    NodeSG* cur = l->head;
    while (cur != NULL) {
        printSG(cur->sg);
        cur = cur->next;
    }
    printf("]\n");
};
#endif