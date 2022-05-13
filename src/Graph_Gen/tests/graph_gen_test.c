#include "../c/graph_gen.c"

int main(void) {
    LLG* graphs = GenGraphs(4);
    NodeG* ng = graphs->head;
    while (ng != NULL) {
        printGraphALL(ng->g);
        ng = ng->next;
    }
}