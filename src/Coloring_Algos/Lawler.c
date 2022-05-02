#include <stdlib.h>
#include <stdio.h>
//#include "../Data_Structures/c/GraphALL.c" // Arthur : - je crois y'a des erreurs de compilation
// si tu met ça, car tu inclues aussi mis.c (ligne du dessous) et ça inclue deux fois graphALL.C
// j'essaye de résoudre ça en mettent des ifndef sur un commit prochain
#include "../Independants_sets/c/mis.c"

typedef enum BOOL BOOL;
enum BOOL { FALSE, TRUE };


void affichage_binaire(int n)
{
    int i;
    for (i = 31; i >= 0; i--)
        printf("%d", (n >> i) & 1);
    printf("\n");
}

Color Lawler(GraphALL* g) {
    VertexId idPosMap[256] = {};
    NodeV* curV = g->vertices->head;
    int w = 0;
    while (curV != NULL) {
        idPosMap[curV->id] = w;
        w++;
        curV = curV->next;
    }

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
            X[j] = length * 4;

        }
        X[i] = 1;
        //printf("cas = 1 X[S]=: %d \n" , X[i]);
        //printf("i correspondant: %d \n" ,i);
        start_from = i + 1;
    }
    for (int j = start_from; j < nb_sub_graph; j++) {
        X[j] = length * 4;
        //printf("length is : %d \n", length);
        //printf("cas >1 X[S]=: %d \n" , X[j]);
        //printf("j correspondant: %d \n" ,j);
    }
    /*
    // debugage afficher X
    printf("X : ");
    for (int i = 0; i < nb_sub_graph; i++) {
        printf("%d, ", X[i]);
    }
    printf("\n");
    //*/
    int nextPow = 4;
    for (int S = 2; S < nb_sub_graph; S++) {
        if (S != nextPow) {
            GraphALL* Sub_g = subGraphALL(g, S);


            //printf("the current subgraph after the if \n ");
            //printGraphALL(Sub_g);
            //calculate MIS of Sub_g
            // linked list of all sub-g's maximal independent sets
            LLMIS* I = maximal_independant_sets(Sub_g);
            // the current independant set 
            NodeMIS* curmis = I->head;

            while (curmis != NULL) {
                LLV* incurmis = curmis->mis;

                int intmis = 0;
                for (NodeV* cur = incurmis->head; cur != NULL; cur = cur->next) {
                    intmis = intmis | (1 << (int)idPosMap[cur->id]);
                }

                //printf("X[S] avant le min = %d , \n", X[S]);
                //X[S] = (X[S] <= (X[S & (~intmis)] + 1)) ?  X[S] : X[S & (~intmis)] ;
                if ((X[S & (~intmis)] + 1) < X[S]) {
                    X[S] = (X[S & (~intmis)]) + 1;
                }
                /*
                printf("S est   = ");
                affichage_binaire(S);
                printf("I est   = ");
                affichage_binaire(intmis);
                printf("S-I est = ");
                affichage_binaire(S & (~intmis));
                printf("I avant traduction binaire:");
                printV(incurmis);
                //printf("X[S-I] : %d \n", (X[S & (~intmis)]  ) );
                printf("X[S-I]+1 : %d \n", (X[S & (~intmis)] + 1));
                printf("X[S] apres le min = %d , \n", X[S]);
                /*printf("mis is : %c \n" , incurmis->head->id);
                printf("mis is : %d \n" , incurmis->length);
                printf("S est = %d \n", S);
                printf("I est = %d \n", intmis);
                */


                curmis = curmis->next; // next mis
            }

            destroyLLMIS(I);
            //printf("X[S]= %d \n", X[S]);
            destroyGraphALL(Sub_g);
        }
        else {
            nextPow = nextPow << 1;
        }

    }

    //return X[V]
    int chromatic_number = X[nb_sub_graph - 1];
    free(X);
    return (chromatic_number);


}