#include "Gen_tf_Graphs.c"
#include <stdio.h>

int main(void) {
<<<<<<< HEAD
    
    LLG* triangle_free_graphs = Gen_tf(8);
=======
    LLG* triangle_free_graphs = newLLG();

    triangle_free_graphs = Gen_tf(4);
>>>>>>> 05409f224506e9d09414b21a9cd988fba42b6b33
    printLLG(triangle_free_graphs);
}