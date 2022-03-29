#include "../h/GraphAdjacencyList.h"
#include "../h/LinkedList.h"
#include "../h/Collection.h"
#include <stdlib.h>

static struct VertexAdjacencyList* constructorVertexAdjacencyList(struct GraphAdjacencyList* g, unsigned char v) {
    VertexAdjacencyList* newV = (VertexAdjacencyList*)malloc(sizeof(VertexAdjacencyList));
    newV->id = v;
    newV->neighbours = (struct Collection*)g->constructor();
    return newV;
}

// adds a vertex to g with id=v
// No effect if g already contains a vertex with id=v
void addVertex(struct GraphAdjacencyList* g, unsigned char v) {
    if (!g->vertices->contains(g->vertices, (void*)v)) {
        struct VertexAdjacencyList* newVertex = constructorVertexAdjacencyList(g, v);
        g->vertices->add(g->vertices, (void*)newVertex);
    }
};

static comparator idcomp(void* U, unsigned char idV) {
    if (U == NULL) {
        return 0;
    }
    else {
        VertexAdjacencyList* vertU = (VertexAdjacencyList*)U;
        return vertU->id == idV;
    }
}

void addEdge(struct GraphAdjacencyList* g, unsigned char u, unsigned char v) {
    struct VertexAdjacencyList* vertU = g->vertices->find(g->vertices, (void*)u, idcomp);
    if (vertU == NULL)
        return;
    struct VertexAdjacencyList* vertV = g->vertices->find(g->vertices, (void*)v, idcomp);
    if (vertV == NULL)
        return;
    vertU->neighbours->add(vertU->neighbours, v);
    vertV->neighbours->add(vertU->neighbours, u);
};

void removeVetex(struct GraphAdjacencyList* g, unsigned char v) {
    struct VertexAdjacencyList* vertV = g->vertices->find(g->vertices, (void*)v, idcomp);
    if (vertV == NULL)
        return;
    Collection* Ng = vertV->neighbours;
    for (void* e = Ng->start(Ng); e = Ng->next(Ng); !Ng->end(Ng)) {
        VertexAdjacencyList* vertE = g->vertices->find(g->vertices, e, idcomp);
        vertE->neighbours->remove(vertE->neighbours, v);
    }
}

void removeEdge(struct GraphAdjacencyList* g, unsigned char u, unsigned char v) {
    struct VertexAdjacencyList* vertU = g->vertices->find(g->vertices, (void*)u, idcomp);
    if (vertU == NULL)
        return;
    struct VertexAdjacencyList* vertV = g->vertices->find(g->vertices, (void*)v, idcomp);
    if (vertV == NULL)
        return;
    vertU->neighbours->remove(vertU->neighbours, v);
    vertV->neighbours->remove(vertU->neighbours, u);
};

GraphAdjacencyList* constructorGraphAL(void* (*vertexCollectionConstructor)(void),
    void* (*adjacencyListConstructor)(void)) {
    GraphAdjacencyList* g = (GraphAdjacencyList*)malloc(sizeof(GraphAdjacencyList));
    g->constructor = adjacencyListConstructor;
    g->vertices = (Collection*)vertexCollectionConstructor();
}

void destroyGraphAL(GraphAdjacencyList* g) {
    Collection* vertices = g->vertices;
    for (void* e = vertices->start(vertices); e = vertices->next(vertices); !vertices->end(vertices)) {
        VertexAdjacencyList* v = (VertexAdjacencyList*)e;
        v->neighbours->destroy(v->neighbours);
    }
    vertices->destroy(vertices);
    free(g);
}

static printor vertexPrinter(void* e) {
    printf("%d", *((int*)e));
}

void printGraphAl(GraphAdjacencyList* g) {
    printf("[\n");
    Collection* vertices = g->vertices;
    for (void* e = vertices->start(vertices); e = vertices->next(vertices); !vertices->end(vertices)) {
        VertexAdjacencyList* v = (VertexAdjacencyList*)e;
        v->neighbours->printp(v->neighbours, vertexPrinter);
        printf("\n");
    }
    printf("]\n");
}