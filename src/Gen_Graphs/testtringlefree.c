#include "Gen_tf_Graphs.c"
#include <stdio.h>

int main(void) {
    
    LLG* triangle_free_graphs = Gen_tf(8);
    printLLG(triangle_free_graphs);
}