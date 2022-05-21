#include "../Gen_Graphs/Gen_tf_deg6_connected.c"
#include "../Coloring_Algos/Lawler.c"
#include <stdio.h>

void explore(size_t depth, NodeV* v, binarySubG* reached, binarySubG ALLreached) {
    NodeN* curN = v->neighbours->head;
    if (depth > 1) {
        while (curN) {
            *reached = *reached | (1 << (curN->id - 65));
            if (ALLreached == *reached) return;
            explore(depth - 1, curN->pv, reached, ALLreached);
            curN = curN->next;
        }
    }
    else {
        while (curN) {
            if (ALLreached == *reached) return;
            *reached = *reached | (1 << (curN->id - 65));
            curN = curN->next;
        }
    }
}

int h_mtf(GraphALL* g) {
    size_t n = g->vertices->length;
    binarySubG reached = 0;
    binarySubG ALLreached = (1 << n) - 1;
    NodeV* v = g->vertices->head;
    reached = reached | (1 << (v->id - 65));
    explore(2, v, &reached, ALLreached);
    return reached == ALLreached;
}

int main(void) {
    // n=6 tout va bien
    /*
    for (int i=6; i<8; i++){
        LLG* G = Gen_tf(i);
        NodeG* ng = G->head;
        while(ng != NULL){
            GraphALL* g = ng->g;
            //calculer le deg max
            int degmax = 0;
            NodeV* v = g->vertices->head;
            while(v != NULL){
                degmax = (v->neighbours->length >= degmax)? v->neighbours->length :degmax;
                v=v->next;
            }
            //printf("Free Tiangle Graphs with length %d \n", i);
            if(Lawler(g)<= ((degmax +1)/2)+2){
                //printf("oui \n");
            }
            else printf("non \n");

            //printf("The chromatic number of the graph is %d \n", Lawler(g));
            ng=ng->next;

        }
    }*/


    // n=7
    LLG* G = Gen_tfdeg6_connected(8);
    NodeG* ng = G->head;
    size_t nb_skiped = 0;
    while (ng != NULL) {
        GraphALL* g = ng->g;
        //calculer le deg max 
        int degmax = 0;
        NodeV* v = g->vertices->head;
        while (v != NULL) {
            int deg = v->neighbours->length;
            degmax = (deg >= degmax) ? deg : degmax;
            v = v->next;
        }
        //printf("Free Tiangle Graphs with length %d \n", i);
        if (h_mtf(g)) {
            if (Lawler(g) <= ((degmax + 1) / 2) + 2) {
                //printf("oui \n");
            }
            else printf("contre exemple \n");
        }
        else nb_skiped++;

        //printf("The chromatic number of the graph is %d \n", Lawler(g));
        ng = ng->next;

    }
    printf("skiped %d/%d", nb_skiped, G->length);
    destroyLLG(G);
}
