#include "../c/mis.c"
#include "../../Data_Structures/c/GraphCollection.c"
GraphALL* buildCubeGraph();


int main(void) {
    // From wikipedia : The graph of the cube has six different maximal independent 
    GraphALL* g = Cube();
    //GraphALL* g = buildCubeGraph();
    LLSG* m = maximal_independant_sets(g);
    printLLSG(m);
}