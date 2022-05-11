#include "../Independants_sets/c/mis.c"
#include <stdio.h>
#include <stdlib.h>


// need a fonction  for forbiden vertices of a graph G
LLV* forbiden_vertices(GraphALL* g, int d) { // ?? want it to return the forbiden vertices 
    //parcourir les sommets du graphes :
    NodeV* curV = g->vertices->head;
    LLV* fb = newLLV();

    if (curV->neighbours->length == d) {
        // add the vertex to the list of forbiden vertices
        addV(fb, curV->id);
    }
    return fb;
}


//return Ture if G is mtf ????

//on cherche le sommet de deg d et on verifit si ces voisins sont tous des mis
BOOL is_mtf(GraphALL* G, int n, int d, int k) {
    LLSG* I = maximal_independant_sets(G);
    int num_mis = I->length;
    if (num_mis == d) {
        NodeV* cur = G->vertices->head;
        while (cur != NULL) {
            if (cur->neighbours->length == d) {
                //je verifie si les voisins de chaque voisin de ce sommet est lié à un stable 


                // si oui
                return TRUE;
            }
            else cur = cur->next;
        }
    }
    return FALSE;

}

GraphALL* Connect_indep_sets(GraphALL* H, int d, int set_order, int set_index, int num_assigned, Color k, int n) {
    if (num_assigned == d) {
        if (is_mtf(H, k, n, d)) {
            return H;
        }
        else {
            LLSG* I = maximal_independant_sets(H);
            int num_mis = I->length;
            NodeSG* curmis = I->head;

            // rajouter le sommet v et les sommets et ces voisins ni
            NodeV* v = newNodeV(v->id);
            addVertexALL(H, v->id);
            // comment créer d sommets 


            for (int j = set_index; j < num_mis; j++) {

                //parcourir la list des forbiden vertices
                // ???? faire une LL des fb ??
                LLV* forbiddenvertices = forbiden_vertices(H, d);
                NodeV* fb_v = forbiddenvertices->head;
                if (!containsSV(curmis, fb_v->id)) {
                    NodeSG* cur = curmis->sg;
                    while (cur != NULL) {
                        addEdgeALL(H, cur, n[num_assigned]);//n_num_assigned : les sommets voisins de v ajoutés 
                        cur = cur->next;
                    }
                    //update forbidden vertices
                    Connect_indep_sets(H, d, set_order, j, num_assigned + 1, k, n);
                    //restore forbidden vertices
                }
            }
            if (set_order > 1) {
                Connect_indep_sets(H, d, set_order - 1, 0, num_assigned, k, n);

            }
        }
    }
}


/*
// j'ai un graphe G (k-1,n-d-1,<=d-1) sur lequel je construit un mtf (en rajoutant un sommet v nd voisins et relier ces voinsins aux mis de H)
GraphALL* ALLmtf(GraphALL* H, Color k , int n , int d){

    //H is a (k-1,n-d-1,<=d-1)-graph
    LLSG* I = maximal_independant_sets(H);
    Connect_indep_sets(H,d,d,0,0,k,n);
}
//si je veux toutes le permutations de qui sont entre le graphe d'origine et le graphe construit je supprime des arêt 
*/