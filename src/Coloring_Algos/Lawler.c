#include <stdlib.h>
#include <stdio.h>
//#include "../Data_Structures/c/GraphALL.c" // Arthur : - je crois y'a des erreurs de compilation
// si tu met ça, car tu inclues aussi mis.c (ligne du dessous) et ça inclue deux fois graphALL.C
// j'essaye de résoudre ça en mettent des ifndef sur un commit prochain
#include "../Maximals_Independants_sets/c/mis.c"

typedef enum BOOL BOOL;
enum BOOL { FALSE, TRUE };


int find_int_I(GraphALL* S, LLV* mis) {
    NodeV* cur = S->vertices->head;
    int intmis = 0; // 32 fois zero
    int length = S->vertices->length;
    //LLV* mis = I->head->mis;
    printf("mis %c \n :", mis->head->id);
    printf("taille du mis: %d \n", mis->length);
    int pos = 0;
    while (cur != NULL && pos < length) {
        if (containsV(mis, cur->id) == 1) {
            //je mets 1 dans cette pos (je décale le 1 qui est 2^0 en binaire à la position pos)
            //printf("current vertex : %c \n ", cur->id);
            //printf("intmis avant : %d \n  ", intmis);
            intmis = intmis | (1 << pos);
            //printf("intmis apres : %d \n  ", intmis);
            //printf("avec pos %d \n ", pos);
            cur = cur->next;

        }
        else {
            cur = cur->next;
        }
        //else je laisse 0
        //pass to the next bit , and also to the next vertex
        
        pos++;
    }
    return intmis;
}





Color Lawler(GraphALL* g) {

    int length = g->vertices->length;
    //number of grpahs in g without the empty one
    int nb_sub_graph = 1 << length;

    //the tab where we will coloriate all subgraphs
    // TODO change int for VertexId
    int* X = (int*)malloc(nb_sub_graph * sizeof(int)); //car j'ai choisi les S des int (32 bit)
    // initate X
    // if empty graph then 0
    X[0] = 0;
    // if only one vertex int the graph then 1
    int start_from = 1;
    for (int i = 1; i < nb_sub_graph; i = i << 1) {
        for (int j = start_from; j < i; j++) {
            X[j] = length;
            
        }
        X[i] = 1;
        //printf("cas = 1 X[S]=: %d \n" , X[i]);
        //printf("i correspondant: %d \n" ,i);
        start_from = i + 1;
    }
    for (int j = start_from; j < nb_sub_graph; j++) {
        X[j] = length;
        //printf("length is : %d \n", length);
        //printf("cas >1 X[S]=: %d \n" , X[j]);
        //printf("j correspondant: %d \n" ,j);
    }


    for (int S =0 ; S < nb_sub_graph; S++) {
        GraphALL* Sub_g = copyGraphALL(g);
        NodeV* cur = Sub_g->vertices->head;
        NodeV* next = cur->next;
        int pos = 0;
        while (cur != NULL && pos != 32) {
            if (S & (1 << pos)) {
                // Current bit is set to 1
                 // do nothing ; keep the vertex in the graph
            }
            else {
                // Current bit is set to 0
                // then remove it from Sub_g and remove it from LLneightours of the other vertices
                //printf("before :");
                //printGraphALL(Sub_g); 
                //printf("vetrex to remove : %c \n" , cur->id);
                //printLLN(cur->id);
                removeVertexNodeALL(Sub_g, cur);
                //printf("after :");
                //printGraphALL(Sub_g);
            }
            //pass to the next bit , and also to the next vertex
            cur = next;
            next = cur == NULL ? NULL : cur->next;
            pos++;

        }
        // ones out from the for loop ; we have the subgraph S
        // we compute all the MIS of this subgraph:

        if (Sub_g->vertices->length != 0 && Sub_g->vertices->length != 1) { //already done
            printf("the current subgraph after the if \n ");
            printGraphALL(Sub_g);
            //calculate MIS of Sub_g
            // linked list of all sub-g's maximal independent sets
            LLMIS* I = maximal_independant_sets(Sub_g);
            // the current independant set 
            NodeMIS* curmis = I->head;

            while (curmis != NULL) {
                LLV* incurmis = curmis->mis;
                int intmis = find_int_I(Sub_g, incurmis);
                //printf("X[S] avant le min = %d , \n", X[S]);
                //X[S] = (X[S] <= (X[S & (~intmis)] + 1)) ?  X[S] : X[S & (~intmis)] ;
                if((X[S & (~intmis)] + 1 ) < X[S]){
                    X[S]= (X[S & (~intmis)] + 1 );
                }
                
                //printf("S est = %d \n", S);
                /*printf("S-I est = %d \n",S & (~intmis));
                printf("X[S-I] : %d \n", (X[S & (~intmis)]  ) );
                printf("X[S-I]+1 : %d \n", (X[S & (~intmis)] + 1 ) );*/
                //printf("X[S] apres le min = %d , \n", X[S]);
                /*printf("mis is : %c \n" , incurmis->head->id);
                printf("mis is : %d \n" , incurmis->length);
                printf("S est = %d \n", S);
                printf("I est = %d \n", intmis);
                */
                
                
                curmis = curmis->next; // next mis
            }

            destroyLLMIS(I);
        }
        printf("X[S]= %d \n", X[S]);
        destroyGraphALL(Sub_g);


    }

    //return X[V]   
    return (X[nb_sub_graph - 1]);


}