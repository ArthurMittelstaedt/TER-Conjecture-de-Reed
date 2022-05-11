#include "Gen_Graph.c"
#include <stdio.h>

int main(void) {
    LLG* triangle_free_graphs = newLLG();

    triangle_free_graphs = Gen_tf(3);
    printLLG(triangle_free_graphs);

}