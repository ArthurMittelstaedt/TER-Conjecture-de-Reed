#include "../c/is.c"

GraphALL* buildCubeGraph();


int main(void) {
    GraphALL* g = buildCubeGraph();
    LLSG* m = independant_sets(g);
    printLLSG(m);
}


// From wikipedia : The graph of the cube has six different maximal independent 
// sets
GraphALL* buildCubeGraph() {
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