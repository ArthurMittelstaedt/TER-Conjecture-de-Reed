#ifndef LLG_C
#define LLG_C
#include "../h/LLG.h"
#include <stdio.h>

NodeG* newNodeG(GraphALL* g) {
    NodeG* newNode = malloc(sizeof(NodeG));
    newNode->g = g;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
};

void destroyNodeG(NodeG* n) {
    destroyGraphALL(n->g);
    free(n);
};

LLG* newLLG() {
    LLG* newList = malloc(sizeof(LLG));
    newList->head = NULL;
    newList->length = 0;
    return newList;
};

void destroyLLG(LLG* l) {
    if (l != NULL) {
        NodeG* cur = NULL;
        NodeG* next = l->head;
        while (next != NULL) {
            cur = next;
            next = cur->next;
            destroyNodeG(cur);
        }
    }

};

void addG(LLG* l, GraphALL* g) {
    NodeG* newHead = newNodeG(g);
    NodeG* oldHead = l->head;
    l->head = newHead;
    newHead->next = oldHead;
    if (oldHead != NULL) {
        oldHead->prev = newHead;
    }
    l->length += 1;
};

void printLLG(LLG* g) {
    printf("[\n");
    NodeG* cur = g->head;
    while (cur != NULL) {
        printGraphALL(cur->g);
        cur = cur->next;
    }
    printf("]\n");
};

#endif