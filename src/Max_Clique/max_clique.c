#ifndef MAX_CLIQUE_C
#define MAX_CLIQUE_C
#include "../Independants_Sets/c/mis.c"

GraphALL* complement(GraphALL* g) {
    GraphALL* cg = newGraphALL();
    NodeV* cur = g->vertices->head;
    while (cur != NULL) {
        addVertexALL(cg, cur->id);
        cur = cur->next;
    }
    cur = g->vertices->head;
    while (cur != NULL) {
        SG* nbrs = SGFromLLV(cg->vertices);
        NodeN* n = cur->neighbours->head;
        while (n != NULL) {
            NodeSV* nsv = findSV(nbrs, n->id);
            removeSV(nbrs, nsv);
            n = n->next;
        }
        NodeSV* curSV = nbrs->head;
        while (curSV != NULL) {
            if (curSV->v->id > cur->id) {
                addEdgeALL(cg, curSV->v->id, cur->id);
            }
            curSV = curSV->next;
        }
        cur = cur->next;
        destroySG(nbrs);
    }
    return cg;
}

size_t maxClique(GraphALL* g) {
    GraphALL* cg = complement(g);
    LLSG* I = maximal_independant_sets(cg);
    size_t max = 0;
    NodeSG* i = I->head;
    while (i != NULL) {
        max = (max >= i->sg->length) ? max : i->sg->length;
        i = i->next;
    }
    destroyLLSG(I);
    destroyGraphALL(cg);
    return max;
}

#endif