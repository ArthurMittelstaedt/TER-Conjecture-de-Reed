#include <stdlib.h>
#include "GraphALL.h"
GraphALL* newGraphALL() {
    GraphALL* g = (GraphALL*)malloc(sizeof(GraphALL));
    g->vertices = newLLV();
};

void destroyGraphALL(GraphALL* g) {
    destroyLLV(g->vertices);
    free(g);
};

void addVertexALL(GraphALL* g, VertexId v) {
    addV(g->vertices, v);
};

void addEdgeALL(GraphALL* g, VertexId v, VertexId u) {
    NodeV* nvV = findV(g->vertices, v);
    if (nvV == NULL) return;
    NodeV* nvU = findV(g->vertices, v);
    if (nvV == NULL) return;
    AddNodeN(nvU->neighbours, v);            //                     this line            
    NodeN* NNVinNVU = nvU->neighbours->head; // <- this line must floow ↑
    AddNodeN(nvV->neighbours, u);            //                     this line  
    NodeN* NNUinNVV = nvV->neighbours->head; // <- this line must floow ↑
    NNVinNVU->pn = NNUinNVV;
    NNVinNVU->pv = nvU;
    NNUinNVV->pn = NNVinNVU;
    NNUinNVV->pv = nvV;
}

void removeVertexALL(GraphALL* g, VertexId v) {
    NodeV* nvV = findV(g->vertices, v);
    if (nvV == NULL) return;
    NodeN* cur_neighbour = nvV->neighbours->head;
    while (cur_neighbour != NULL) {
        removeN(cur_neighbour->pv->neighbours, cur_neighbour->pn);
        cur_neighbour = cur_neighbour->next;
    }
    removeV(g->vertices, nvV);
};

void removeEdgeALL(GraphALL* g, VertexId v, VertexId u) {
    NodeV* nvV = findV(g->vertices, v);
    if (nvV == NULL) return;
    NodeN* nnU = findN(nvV->neighbours, u);
    if (nnU == NULL) return;
    NodeV* nvU = nnU->pv;
    NodeN* NNUinNVV = nnU->pn;
    NodeN* NNVinNVU = nnU->pn->pn;
    removeN(nvV->neighbours, NNUinNVV);
    removeN(nvU->neighbours, NNVinNVU);
};

int containsVertexALL(GraphALL* g, VertexId v) {
    return containsV(g->vertices, v);
};

int containsEdgeALL(GraphALL* g, VertexId v, VertexId u) {
    NodeV* nvV = findV(g->vertices, v);
    if (nvV != NULL) {
        return containN(nvV->neighbours, u);
    }
    else return 0;
}