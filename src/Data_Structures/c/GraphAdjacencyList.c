#include "../h/GraphAdjacencyList.h"
#include "../h/Set.h"
#include <stdlib.h>
#include <stdio.h>

static VertexAL* constructorVertexAL(GraphAL* g, vertexId v) {
    VertexAL* newV = (VertexAL*)malloc(sizeof(VertexAL));
    newV->id = v;
    newV->neighbours = g->ALconstructor();
    return newV;
}

static void destroyVertexAL(VertexAL* v) {
    if (v != NULL) {
        v->neighbours->destroy(v->neighbours);
        free(v);
    }
}

// adds a vertex to g with id=v
// No effect if g already contains a vertex with id=v
void addVertex(struct GraphAL* g, vertexId v) {
    struct VertexAL* newVertex = constructorVertexAL(g, v);
    if (!g->vertices->add(g->vertices, (void*)newVertex)) {
        destroyVertexAL(newVertex);
    }
};

static int VertexALComparator(VertexAL* U, VertexAL* V) {
    if (U == V) {
        return TRUE;
    }
    if (U == NULL || V == NULL) {
        return FALSE;
    }
    else {
        return U->id == V->id;
    }
}
static void VertexALPrintor(VertexAL* U) {
    if (U != NULL) {
        printf("%d : ", U->id);
        U->neighbours->print(U->neighbours);
    }
}



static int VertexALIdComparator(VertexAL* U, vertexId* v) {
    if (U == NULL) {
        return FALSE;
    }
    else {
        return U->id == *v;
    }
}

void addEdge(struct GraphAL* g, vertexId u, vertexId v) {
    struct VertexAL* vertU = g->vertices->findComp(g->vertices, (void*)&u, (comparator)VertexALIdComparator);
    if (vertU == NULL)
        return;
    struct VertexAL* vertV = g->vertices->findComp(g->vertices, (void*)&v, (comparator)VertexALIdComparator);
    if (vertV == NULL)
        return;
    vertU->neighbours->add(vertU->neighbours, v);
    vertV->neighbours->add(vertU->neighbours, u);
};

void removeVetex(struct GraphAL* g, vertexId v) {
    struct VertexAL* vertV = g->vertices->findComp(g->vertices, (void*)&v, (comparator)VertexALIdComparator);
    if (vertV == NULL)
        return;
    SetOfV* Ng = vertV->neighbours;
    for (vertexId e = Ng->start(Ng); !Ng->end(Ng); e = Ng->next(Ng)) {
        VertexAL* vertE = g->vertices->findComp(g->vertices, (void*)&e, (comparator)VertexALIdComparator);
        vertE->neighbours->remove(vertE->neighbours, v);
    }
    g->vertices->remove(g->vertices, vertV);
    destroyVertexAL(vertV);
}

void removeEdge(struct GraphAL* g, vertexId u, vertexId v) {
    struct VertexAL* vertU = g->vertices->findComp(g->vertices, (void*)&u, (comparator)VertexALIdComparator);
    if (vertU == NULL)
        return;
    struct VertexAL* vertV = g->vertices->findComp(g->vertices, (void*)&v, (comparator)VertexALIdComparator);
    if (vertV == NULL)
        return;
    vertU->neighbours->remove(vertU->neighbours, v);
    vertV->neighbours->remove(vertU->neighbours, u);
};

GraphAL* constructorGraphAL(Set* (*vertexSetConstructor)(void),
    SetOfV* (*adjacencyListConstructor)(void)) {
    GraphAL* g = (GraphAL*)malloc(sizeof(GraphAL));
    g->ALconstructor = adjacencyListConstructor;
    g->vertices = (Set*)vertexSetConstructor();
    g->vertices->comparator = (comparator)VertexALComparator;
}

void destroyGraphAL(GraphAL* g) {
    Set* vertices = g->vertices;
    for (void* e = vertices->start(vertices); !(vertices->end(vertices)); e = vertices->next(vertices)) {
        VertexAL* v = (VertexAL*)e;
        destroyVertexAL(v);
    }
    vertices->destroy(vertices);
    free(g);
}

void printGraphAl(GraphAL* g) {
    printf("[\n");
    Set* vertices = g->vertices;
    for (void* e = vertices->start(vertices); !(vertices->end(vertices)); (e = vertices->next(vertices))) {
        VertexAL* v = (VertexAL*)e;
        VertexALPrintor(v);
        printf("\n");
    }
    printf("]\n");
}