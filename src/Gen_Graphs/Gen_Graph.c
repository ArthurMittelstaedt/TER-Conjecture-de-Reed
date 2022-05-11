#include "../Independants_sets/c/is.c"
#include <stdio.h>
#include <stdlib.h>
#include "../Data_Structures/c/LLG.c"

LLSG* is_n (int n , GraphALL* G){ // return indep sets with length n
    LLSG* isn = newLLSG();
    LLSG* I = independant_sets(G); // je parcours les indep sets de G
    NodeSG* curis = I->head;
    while (curis!= NULL){
        if(curis->sg->length == n){
            addSG(isn,curis->sg);
            curis = curis->next;
        }
        curis = curis->next;
    }
    return isn;
}

LLG* Gen_tf(int n){
    LLG* graphs  = newLLG();
    printf("hi");
    if (n == 0 ) {
        GraphALL* empty_graph = newGraphALL();
        addG(graphs, empty_graph);
        return graphs;
    }
    else {
        
        LLG* smaller =newLLG();
        smaller = Gen_tf(n-1);
        GraphALL* G = smaller->head->g;
        while(G != NULL){
            LLSG* I = newLLSG();
            I = is_n(n,G);
            NodeSG* curInode = I->head; // je parcours les node de I
            while (curInode != NULL){
                // je parcours le is du current node de I
                SG* is = curInode->sg;
                NodeSV* iscur = is->head;
                while (iscur != NULL){
                   // for(int m =0; m<7; m++){
                        // relier le sommet v ax sommet de ce stable de taille n
                        // je crée le v 
                    NodeV* v = newNodeV(v->id);
                    NodeV* u = iscur->v;
                    addEdgeALL(G,v->id, u->id);
                   // }
                    iscur = iscur->next;
                }
                curInode = curInode->next;
            }
            addG(graphs,G);//faut init grpahs
            destroyLLSG(I);
        }
        return graphs;
    }

}