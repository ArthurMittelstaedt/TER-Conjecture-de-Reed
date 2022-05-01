#include <stdlib.h>
#include "../h/GraphALL.h"
#include "LLN.c"
#include "LLV.c"

GraphALL* newGraphALL() {
    GraphALL* g = (GraphALL*)malloc(sizeof(GraphALL));
    g->vertices = newLLV();
};

void destroyGraphALL(GraphALL* g) {
    destroyLLV(g->vertices, 1);
    free(g);
};

void addVertexALL(GraphALL* g, VertexId v) {
    addV(g->vertices, v);
};

void addEdgeALL(GraphALL* g, VertexId v, VertexId u) {
    NodeV* nvV = findV(g->vertices, v);
    if (nvV == NULL) return;
    NodeV* nvU = findV(g->vertices, u);
    if (nvU == NULL) return;
    AddNodeN(nvU->neighbours, v);            //                    this line            
    NodeN* NNVinNVU = nvU->neighbours->head; // <- this line must flow ↑
    AddNodeN(nvV->neighbours, u);            //                    this line  
    NodeN* NNUinNVV = nvV->neighbours->head; // <- this line must flow ↑
    NNVinNVU->pn = NNUinNVV;
    NNVinNVU->pv = nvV;
    NNUinNVV->pn = NNVinNVU;
    NNUinNVV->pv = nvU;
};

void removeVertexALL(GraphALL* g, VertexId v) {
    NodeV* nvV = findV(g->vertices, v);
    removeVertexNodeALL(g, nvV);
};

void removeVertexNodeALL(GraphALL* g, NodeV* nvV) {
    if (nvV == NULL) return;
    NodeN* cur_neighbour = nvV->neighbours->head;
    while (cur_neighbour != NULL) {
        removeN(cur_neighbour->pv->neighbours, cur_neighbour->pn);
        cur_neighbour = cur_neighbour->next;
    }
    removeV(g->vertices, nvV, 1);
}

void removeEdgeALL(GraphALL* g, VertexId v, VertexId u) {
    NodeV* nvV = findV(g->vertices, v);
    if (nvV == NULL) return;
    NodeN* nnU = findN(nvV->neighbours, u);
    if (nnU == NULL) return;
    NodeV* nvU = nnU->pv;
    NodeN* NNUinNVV = nnU->pn->pn;
    NodeN* NNVinNVU = nnU->pn;
    removeN(nvV->neighbours, NNUinNVV);
    removeN(nvU->neighbours, NNVinNVU);
};

int containsVertexALL(GraphALL* g, VertexId v) {
    return containsV(g->vertices, v);
};

int containsEdgeALL(GraphALL* g, VertexId v, VertexId u) {
    NodeV* nvV = findV(g->vertices, v);
    if (nvV != NULL) {
        return containsN(nvV->neighbours, u);
    }
    else return 0;
}

void printGraphALL(GraphALL* g) {
    printV(g->vertices);
}

void resetColALL(GraphALL* g) {
    NodeV* cur = g->vertices->head;
    while (cur != NULL) {
        cur->col = 0;
        cur = cur->next;
    }
}

GraphALL* copyGraphALL(GraphALL* g) {
    GraphALL* clone = newGraphALL();
    NodeV* curVG = g->vertices->head;
    if (curVG != NULL) {
        // Copy of the vertices in the right order
        NodeV* curVC = newNodeV(curVG->id);
        clone->vertices->head = curVC;
        curVG = curVG->next;
        while (curVG != NULL) {
            NodeV* nextVC = newNodeV(curVG->id);
            nextVC->prev = curVC;
            curVC->next = nextVC;
            curVC = nextVC;
            curVG = curVG->next;
        }
        clone->vertices->length = g->vertices->length;
        // Adding edge
        curVG = g->vertices->head;
        curVC = clone->vertices->head;
        while (curVG != NULL) {
            NodeN* curNG = curVG->neighbours->head;
            while (curNG != NULL) {
                // printf("adding edge %c to %c", curVG->id, curNG->id);
                // adding directed edge
                AddNodeN(curVC->neighbours, curNG->id);
                NodeV* nV = findV(clone->vertices, curNG->id);
                curVC->neighbours->head->pv = nV;
                NodeN* nN = findN(nV->neighbours, curVC->id);
                if (nN != NULL) {
                    curVC->neighbours->head->pn = nN;
                    nN->pn = curVC->neighbours->head;
                }
                //
                curNG = curNG->next;
            }
            curVG = curVG->next;
            curVC = curVC->next;
        }

    }
    return clone;
}

/*
GraphALL* copyGraphALL(GraphALL* g) {
    GraphALL* clone = newGraphALL();
    clone->vertices = copyLLV(g->vertices);
    NodeV* curVClone = clone->vertices->head;
    NodeV* curVG = g->vertices->head;
    while (curVClone != NULL) {
        curVClone->neighbours = copyLLN(curVG->neighbours);
        NodeN* curNClone = curVClone->neighbours->head;
        NodeN* curNG = curVG->neighbours->head;
        while (curNClone != NULL) {
            curNClone->pv;
            curNClone->pn;
        }
        curVClone = curVClone->next;
        curVG = curVG->next;
    }
}*/