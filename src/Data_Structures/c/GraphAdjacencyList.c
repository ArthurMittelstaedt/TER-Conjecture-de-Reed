#include "../h/GraphAL.h"
#include "../h/Set.h"
#include <stdlib.h>

static struct VertexAL* constructorVertexAL(struct GraphAL* g, unsigned char v) {
    VertexAL* newV = (VertexAL*)malloc(sizeof(VertexAL));
    newV->id = v;
    newV->neighbours = g->ALconstructor();
    return newV;
}

// adds a vertex to g with id=v
// No effect if g already contains a vertex with id=v
void addVertex(struct GraphAL* g, unsigned char v) {
    struct VertexAL* newVertex = constructorVertexAL(g, v);
    g->vertices->add(g->vertices, (void*)newVertex);
};

static comparator idcomp(void* U, unsigned char idV) {
    if (U == NULL) {
        return 0;
    }
    else {
        VertexAL* vertU = (VertexAL*)U;
        return vertU->id == idV;
    }
}

void addEdge(struct GraphAL* g, unsigned char u, unsigned char v) {
    struct VertexAL* vertU = g->vertices->find(g->vertices, (void*)u, idcomp);
    if (vertU == NULL)
        return;
    struct VertexAL* vertV = g->vertices->find(g->vertices, (void*)v, idcomp);
    if (vertV == NULL)
        return;
    vertU->neighbours->add(vertU->neighbours, v);
    vertV->neighbours->add(vertU->neighbours, u);
};

void removeVetex(struct GraphAL* g, unsigned char v) {
    struct VertexAL* vertV = g->vertices->find(g->vertices, (void*)v, idcomp);
    if (vertV == NULL)
        return;
    Collection* Ng = vertV->neighbours;
    for (void* e = Ng->start(Ng); e = Ng->next(Ng); !Ng->end(Ng)) {
        VertexAL* vertE = g->vertices->find(g->vertices, e, idcomp);
        vertE->neighbours->remove(vertE->neighbours, v);
    }
}

void removeEdge(struct GraphAL* g, unsigned char u, unsigned char v) {
    struct VertexAL* vertU = g->vertices->find(g->vertices, (void*)u, idcomp);
    if (vertU == NULL)
        return;
    struct VertexAL* vertV = g->vertices->find(g->vertices, (void*)v, idcomp);
    if (vertV == NULL)
        return;
    vertU->neighbours->remove(vertU->neighbours, v);
    vertV->neighbours->remove(vertU->neighbours, u);
};

GraphAL* constructorGraphAL(void* (*vertexCollectionConstructor)(void),
    void* (*adjacencyListConstructor)(void)) {
    GraphAL* g = (GraphAL*)malloc(sizeof(GraphAL));
    g->constructor = adjacencyListConstructor;
    g->vertices = (Collection*)vertexCollectionConstructor();
}

void destroyGraphAL(GraphAL* g) {
    Collection* vertices = g->vertices;
    for (void* e = vertices->start(vertices); e = vertices->next(vertices); !vertices->end(vertices)) {
        VertexAL* v = (VertexAL*)e;
        v->neighbours->destroy(v->neighbours);
    }
    vertices->destroy(vertices);
    free(g);
}

static printor vertexPrinter(void* e) {
    printf("%d", *((int*)e));
}

void printGraphAl(GraphAL* g) {
    printf("[\n");
    Collection* vertices = g->vertices;
    for (void* e = vertices->start(vertices); e = vertices->next(vertices); !vertices->end(vertices)) {
        VertexAL* v = (VertexAL*)e;
        v->neighbours->printp(v->neighbours, vertexPrinter);
        printf("\n");
    }
    printf("]\n");
}