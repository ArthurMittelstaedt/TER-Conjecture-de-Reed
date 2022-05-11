#include "Gen_Graph.c"
#include <stdio.h>

int main(void){
    printf("hii");
    LLG* triangle_free_graphs = newLLG();
    
    triangle_free_graphs =Gen_tf(2);
    printLLG(triangle_free_graphs);

}