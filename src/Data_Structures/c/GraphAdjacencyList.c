#include "../h/GraphAdjacencyList.h"
#include "../h/SetOfVAL.h"
#include <stdlib.h>
#include <stdio.h>

// adds a vertex to g with id=v
// No effect if g already contains a vertex with id=v
void addVertex(struct GraphAL* g, vertexId v) {
    g->vertices->add(g->vertices, v);
};

static void VertexALPrintor(VertexAL* U) {
    if (U != NULL) {
        printf("%d : ", U->id);
        U->neighbours->print(U->neighbours);
    }
}

void addEdge(struct GraphAL* g, vertexId u, vertexId v) {
    struct VertexAL* vertU = g->vertices->find(g->vertices, u);
    if (vertU == NULL)
        return;
    struct VertexAL* vertV = g->vertices->find(g->vertices, v);
    if (vertV == NULL)
        return;
    vertU->neighbours->add(vertU->neighbours, v);
    vertV->neighbours->add(vertU->neighbours, u);
};

void removeVetex(struct GraphAL* g, vertexId v) {
    struct VertexAL* vertV = g->vertices->find(g->vertices, v);
    if (vertV == NULL)
        return;
    SetOfV* Ng = vertV->neighbours;
    for (vertexId e = Ng->start(Ng); !Ng->end(Ng); e = Ng->next(Ng)) {
        VertexAL* vertE = g->vertices->find(g->vertices, e);
        vertE->neighbours->remove(vertE->neighbours, v);
    }
    g->vertices->remove(g->vertices, v);
    destroyVertexAL(vertV);
}

void removeEdge(struct GraphAL* g, vertexId u, vertexId v) {
    struct VertexAL* vertU = g->vertices->find(g->vertices, u);
    if (vertU == NULL)
        return;
    struct VertexAL* vertV = g->vertices->find(g->vertices, v);
    if (vertV == NULL)
        return;
    vertU->neighbours->remove(vertU->neighbours, v);
    vertV->neighbours->remove(vertU->neighbours, u);
};

GraphAL* constructorGraphAL(SetOfVAL* (*vertexSetConstructor)(void),
    SetOfV* (*adjacencyListConstructor)(void)) {
    GraphAL* g = (GraphAL*)malloc(sizeof(GraphAL));
    g->ALconstructor = adjacencyListConstructor;
    g->vertices = (SetOfVAL*)vertexSetConstructor();
}

void destroyGraphAL(GraphAL* g) {
    SetOfVAL* vertices = g->vertices;
    for (void* e = vertices->start(vertices); !(vertices->end(vertices)); e = vertices->next(vertices)) {
        VertexAL* v = (VertexAL*)e;
        destroyVertexAL(v);
    }
    vertices->destroy(vertices);
    free(g);
}

void printGraphAl(GraphAL* g) {
    printf("[\n");
    SetOfVAL* vertices = g->vertices;
    for (void* e = vertices->start(vertices); !(vertices->end(vertices)); (e = vertices->next(vertices))) {
        VertexAL* v = (VertexAL*)e;
        VertexALPrintor(v);
        printf("\n");
    }
    printf("]\n");
}