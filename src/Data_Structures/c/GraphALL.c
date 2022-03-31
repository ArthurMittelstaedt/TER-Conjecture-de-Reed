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
    AddNodeN(nvU->neighbours, v);
    AddNodeN(nvV->neighbours, u);
}

void removeVertexALL(GraphALL* g, VertexId v) {
    NodeV* nvV = findV(g->vertices, v);
    if (nvV == NULL) return;
    NodeN* cur_neighbour = nvV->neighbours->head;
    while (cur_neighbour != NULL) {
        removeN(cur_neighbour->pv->neighbours, cur_neighbour->pn);
        cur_neighbour->next;
    }
    removeV(g->vertices, nvV);
};

void removeEdgeALL(GraphALL* g, VertexId v, VertexId u) {
    NodeV* nvV = findV(g->vertices, v);
    if (nvV == NULL) return;
    NodeN* nnU = findN(nvU->neighbours, u);
    if (nnU == NULL) return;
    NodeV* nvU = nnU->pv;
    removeN(nvV->neighbours, nnU->pn);
    removeN(nvU->neighbours, )

};
























void containsVertexALL(GraphALL* g, VertexId v);
int containsEdgeALL(GraphALL* g, VertexId v, VertexId u) {
    NodeV* cur = findV(g->vertices, v);
    NodeN* vneigh = cur->pv;
    if (conatins)





}