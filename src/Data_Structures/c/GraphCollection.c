#ifndef GRAPH_COLLECTION_C
#define GRAPH_COLLECTION_C

#include "GraphALL.c"

GraphALL* Gortzsch() {
    GraphALL* g = newGraphALL();
    addVertexALL(g, 'a');
    addVertexALL(g, 'b');
    addVertexALL(g, 'c');
    addVertexALL(g, 'd');
    addVertexALL(g, 'e');
    addVertexALL(g, 'f');
    addVertexALL(g, 'g');
    addVertexALL(g, 'h');
    addVertexALL(g, 'i');
    addVertexALL(g, 'j');
    addVertexALL(g, 'k');
    // grey
    addEdgeALL(g, 'e', 'a');
    addEdgeALL(g, 'c', 'd');
    addEdgeALL(g, 'c', 'f');
    addEdgeALL(g, 'f', 'g');
    addEdgeALL(g, 'g', 'k');
    addEdgeALL(g, 'f', 'i');
    addEdgeALL(g, 'f', 'e');
    addEdgeALL(g, 'f', 'h');
    addEdgeALL(g, 'h', 'b');
    addEdgeALL(g, 'i', 'j');
    //blue
    addEdgeALL(g, 'b', 'a');
    addEdgeALL(g, 'a', 'd');
    addEdgeALL(g, 'd', 'k');
    addEdgeALL(g, 'k', 'j');
    addEdgeALL(g, 'j', 'b');
    addEdgeALL(g, 'b', 'c');
    addEdgeALL(g, 'a', 'g');
    addEdgeALL(g, 'd', 'i');
    addEdgeALL(g, 'k', 'h');
    addEdgeALL(g, 'j', 'e');
    return g;
}

#endif