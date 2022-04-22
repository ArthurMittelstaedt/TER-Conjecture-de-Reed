#include <stdlib.h>
#include <stdio.h>
#include "../Data_Structures/c/GraphALL.c"


typedef enum BOOL BOOL;
enum BOOL { FALSE, TRUE };





//given a integer k un a size n of vetercies, it returns the binary number ok k in n bits
GraphALL* int_bin_subg(int k,GraphALL* g ){
    int length = g->vertices->length;
    BOOL* binary_version = (BOOL*)malloc(length* sizeof(BOOL));
    //int to binary
    for(int i=0; k>0; i++){
        binary_version[i]= k%2;
        k=k/2;
    }
    //binary to subg
    NodeV* cur = g->vertices->head;
    GraphALL* Sub_g = newGraphALL();
    //make coy of the original graph 
    Sub_g=g;
    // parcourir les sommets du nv graphe
    NodeV* cur = Sub_g->vertices->head;
    //if i eme bit ==0 then remove the vertex corresponding 
    for(int i =0; i<length ; i++){
        if(binary_version[i]==0){
            //remove it from the sub graph
            // it removes the vertex from the other vertices's neighbors also
            removeVertexALL(Sub_g, cur);
        }
        cur =cur-> next;
    }
    return Sub_g;
}


GraphALL* S_I(GraphALL* S,NodeV* I ){
    NodeV* cur = S->vertices->head;
    while(cur != NULL){
        removeVertexALL(S, cur);
        cur=cur->next;
    }
    return S;

}

Color Lawler (GraphALL* g){
    
    int length = g->vertices->length;
    //number of grpahs in g without the empty one
    int nb_sub_graph=pow(2,length) - 1;

    //the tab where we will coloriate all subgraphs
    Color* X = (Color*)malloc(nb_sub_graph * sizeof(Color)); //How to do : X[subgraph]  not X[Color]
    // initate X
    //for (int i=0; i<length; i++){
        //=0 if S is empty  ... done
        //=1 if S->vertices->length ==1
        //=length else
    //}
    
    // je parcours les sommets du graphe g
    NodeV* cur = g->vertices->head;
    while (cur != NULL) {
        for (int S = 0 ; S < nb_sub_graph ; S++) {
            GraphALL* Sub_g = newGraphALL();
            Sub_g = int_bin_subg(S, g );
            if (Sub_g->vertices->length !=0){
                //calculate MIS of Sub_g
                NodeV* I = NULL;
                while(I!=NULL){
                    I = findMaximalVertex(Sub_g, LLV* CAND);// CAND?? and is Sub_g LLV* or Sub_g->vertices->head???
                     while(I!=NULL){
                     //S_I(Sub_g,I)=S\I
                     // should I put X[S] or X[Sub_g]
                        X[Sub_g]=(X[Sub_g]> X[S_I(Sub_g,I)])? X[S_I(Sub_g,I)]:X[S];// ?????
                        I=I->next;
                     }
                

                }
            }
            else X[S]=0;
            
            
        destroyGraphALL(Sub_g);
        cur=cur->next;
    }
    }
    //return le max des X : X[V] // je m'en occupe une fois réglé le problème de l'instance   
    return X;
    




  
}