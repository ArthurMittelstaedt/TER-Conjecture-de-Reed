#include "../Gen_Graphs/Gen_tf_deg6.c"
#include "../Coloring_Algos/Lawler.c"
#include <stdio.h>

int main(void){
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


    int n=12;
    LLG* G = Gen_tfdeg6(n);
    printf("n = %d \n" , n );
    NodeG* ng = G->head;
    while(ng != NULL){
        GraphALL* g = ng->g;
        //calculer le deg max 
        int degmax = 0;
        NodeV* v = g->vertices->head;
        while(v != NULL){
            int deg = v->neighbours->length ;
            degmax = (deg>= degmax)? deg :degmax;
            v=v->next;
        }
        //printf("Free Tiangle Graphs with length %d \n", i);
        if(Lawler(g)<= ((degmax +1)/2)+2){
            //printf("oui \n");
        }
        else printf("contre exemple \n");
            
        //printf("The chromatic number of the graph is %d \n", Lawler(g));
        ng=ng->next;

        }

}
