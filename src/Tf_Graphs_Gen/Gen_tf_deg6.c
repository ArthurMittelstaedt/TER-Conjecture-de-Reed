#include "../Independants_sets/c/is.c"
#include <stdio.h>
#include <stdlib.h>
#include "../Data_Structures/c/LLG.c"


int degmax(SG* sg, GraphALL* G) {
    int degmax = 0;
    NodeSV* nsv = sg->head;
    while (nsv != NULL) {
        int deg = nsv->v->neighbours->length;
        degmax = (deg >= degmax) ? deg : degmax;
        nsv = nsv->next;
    }
    return degmax;
}

LLG* Gen_tfdeg6(int n) {
    LLG* graphs = newLLG();


    // if n=0 return empty graph
    if (n == 0) {
        GraphALL* empty_graph = newGraphALL();
        addG(graphs, empty_graph);
    }
    // sinon je crée le graphe à n sommmet à partir de la liste des graphes à n-1 sommets
    else {
        // smaller = liste graphs des graphes de tailles n-1
        LLG* smaller = Gen_tfdeg6(n - 1);
        // je parcours les graphes de la liste graphs smaller
        NodeG* G = smaller->head;
        // tant que smaller nest pas finis
        while (G != NULL) {
            // je copie G dans G1
            GraphALL* G1 = G->g;
            LLSG* I = independant_sets(G1); // je prends une liste I de is de taille i de G1 
            NodeSG* curInode = I->head; // je parcours les node de cette liste I

                // dans la je fais les calculs sur newG1


                //tant que jai pas finis la liste I :
            while (curInode != NULL) {
                if (curInode->sg->length <= 6 && degmax(curInode->sg, G1) <= 5) {
                    GraphALL* newG1 = copyGraphALL(G1);  //newG1<- G1
                    // je crée un sommet n
                    VertexId v = n + 64;
                    // je le rajoute dans les sommet de la copie de G1
                    addV(newG1->vertices, v);
                    // je parcours le is du current node de I
                    // je prend le is 
                    SG* is = curInode->sg;
                    // je parcour les sommets de ce is
                    NodeSV* iscur = is->head;
                    //tant que le is nest pas finis je continu
                    while (iscur != NULL) {
                        // je nomme u le sommet du is curant 
                        NodeV* u = iscur->v;
                        //je rajoute une arête entre u et v dans la copie de G1
                        addEdgeALL(newG1, v, u->id);
                        //je passe au sommet suivant dans le is courant
                        iscur = iscur->next;
                    }
                    // quand je fini de relierle sommetv aus sommets du is 
                    // je rajoute ce nouveau graphe dans graphs 
                    addG(graphs, newG1);
                }
                // et je passe au 2emme is de taille i du même graphe G1 pas de newG1
                // car je viens de le changer 
                curInode = curInode->next;
            }
            destroyLLSG(I);
            G = G->next;
        }

    }
    return graphs;

}