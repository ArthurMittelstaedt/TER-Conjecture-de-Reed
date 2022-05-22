#include "../Gen_tf_deg6_connected.c"
#include <stdio.h>

int main(void) {
    int n = 8;
    LLG* triangle_free_graphs = Gen_tfdeg6_connected(n);
    if (n < 7)
        printLLG(triangle_free_graphs);
    printf("generated %d tf connected graphs with Delta <= 6 for n = %d", triangle_free_graphs->length, n);
    destroyLLG(triangle_free_graphs);
}