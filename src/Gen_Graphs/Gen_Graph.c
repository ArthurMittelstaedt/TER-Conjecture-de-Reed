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
            //curis = curis->next;
        }
        curis = curis->next;
    }
    return isn;
}

LLG* Gen_tf(int n){
    //initiat graphs :
    LLG* graphs  = newLLG();
    

    // if n=0 return empty graph
    if (n == 0 ) {
        GraphALL* empty_graph = newGraphALL();
        addG(graphs, empty_graph);
    }
    // sinon je crée le grpahe à n sommmet à partir de la liste des graphes à n-1 sommets
    else {
        // smaller = liste graphs des graphes de tailles n-1
        LLG* smaller = Gen_tf(n-1);
        // je parcours les graphes de la liste graphs smaller
        NodeG* G = smaller->head;
        // tant que smaller nest pas finis
        while(G != NULL){
            // je copie G dans G1
            GraphALL* G1 = G->g;
            GraphALL* newG1 = copyGraphALL(G1);  //newG1<- G1
            // dans la je fais les calculs sur newG1
            

            for(int i=0 ; i<=n; i++){
                LLSG* I = is_n(i,G1); // je prend une liste I de is de taille i de G1 
                NodeSG* curInode = I->head; // je parcours les node de cette liste I
                //tant que jai pas finis la liste I :
                while (curInode != NULL){
                    // je parcours le is du current node de I
                    // je prend le is 
                    SG* is = curInode->sg;
                    // je parcour les sommets de ce is
                    NodeSV* iscur = is->head;
                    //tant que le is nest pas finis je continu
                    while (iscur != NULL){
                        // je crée un sommet n
                        VertexId v =n+42;
                        // je le rajoute dans les sommet de la copie de G1
                        addV(newG1->vertices,v);
                        // je nomme u le sommet du is curant 
                        NodeV* u = iscur->v;
                        //je rajoute une arête entre u et v dans la copie de G1
                        addEdgeALL(newG1,v, u->id);
                        //je passe au sommet suivant dans le is courant
                        iscur = iscur->next;
                    }
                    // quand je fini de relierle sommetv aus sommets du is 
                    // je rajoute ce nouveau graphe dans graphs 
                    addG(graphs,newG1); 
                    // et je passe au 2emme is de taille i du même graphe G1 pas de newG1
                    // car je viens de le changer 
                    curInode = curInode->next;
                }
                destroyLLSG(I);
            
            }
            G=G->next;
        }
        
    }
    return graphs;

}