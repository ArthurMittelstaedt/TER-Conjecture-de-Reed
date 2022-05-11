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

GraphALL* Cube() {
    GraphALL* g = newGraphALL();

    addVertexALL(g, '1');
    addVertexALL(g, '2');
    addVertexALL(g, '3');
    addVertexALL(g, '4');
    addVertexALL(g, '5');
    addVertexALL(g, '6');
    addVertexALL(g, '7');
    addVertexALL(g, '8');

    addEdgeALL(g, '1', '2');
    addEdgeALL(g, '1', '3');
    addEdgeALL(g, '1', '7');
    addEdgeALL(g, '2', '4');
    addEdgeALL(g, '2', '8');
    addEdgeALL(g, '3', '4');
    addEdgeALL(g, '3', '5');
    addEdgeALL(g, '4', '6');
    addEdgeALL(g, '5', '7');
    addEdgeALL(g, '5', '6');
    addEdgeALL(g, '6', '8');
    addEdgeALL(g, '7', '8');
    return g;
}

GraphALL* Independant(size_t n) {
    GraphALL* g = newGraphALL();
    for (VertexId i = 65; i < 65 + n; i++) {
        addVertexALL(g, i);
    }
    return g;
}

#endif