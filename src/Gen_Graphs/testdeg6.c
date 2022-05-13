#include "Gen_tf_deg6.c"
#include <stdio.h>

int main(void) {
    
    LLG* triangle_free_graphs = Gen_tfdeg6(7);
    printLLG(triangle_free_graphs);
}