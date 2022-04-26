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
    if (nvV == NULL) return;
    NodeN* cur_neighbour = nvV->neighbours->head;
    while (cur_neighbour != NULL) {
        removeN(cur_neighbour->pv->neighbours, cur_neighbour->pn);
        cur_neighbour = cur_neighbour->next;
    }
    removeV(g->vertices, nvV, 1);
};

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

GraphALL* copyGraphALL(GraphALL* g){
    GraphALL* clone = newGraphALL();
    clone->vertices = copyLLV(g->vertices)
    NodeV* curClone = clone->head;
    NodeV*
}