#include "../c/connected_gen.c"

int main(void) {
    LLG* graphs = GenConnected(4);
    NodeG* ng = graphs->head;
    while (ng != NULL) {
        printGraphALL(ng->g);
        ng = ng->next;
    }
}