#ifndef IS_C
#define IS_C

#include "../../Data_Structures/c/LLSG.c"
#include "../../Data_Structures/c/GraphALL.c"

void addToAll(LLSG* is_with_u, NodeV* u);
void addList(LLSG* is_with_u, LLSG* is_without_u);

LLSG* independant_sets_r(SG* V);

LLSG* independant_sets(GraphALL* g) {
    SG* VG = SGFromLLV(g->vertices);
    LLSG* res = independant_sets_r(VG);
    return res;
}

LLSG* independant_sets_r(SG* V) {
    if (isEmptySV(V)) {
        LLSG* is = newLLSG();
        addSG(is, newSG());
        return is;
    }
    else {
        NodeSV* u = V->head;
        SG* Vminusu = copySG(V);
        NodeSV* nodeU = findSV(Vminusu, u->v->id);
        removeSV(Vminusu, nodeU);
        LLSG* is_without_u = independant_sets_r(Vminusu);

        SG* VminusNGu = copySG(Vminusu);
        NodeN* curN = u->v->neighbours->head;
        while (curN != NULL) {
            NodeSV* nodeNeighbour = findSV(VminusNGu, curN->id);
            removeSV(VminusNGu, nodeNeighbour);
            curN = curN->next;
        }
        LLSG* is_with_u = independant_sets_r(VminusNGu);
        addToAll(is_with_u, u->v);
        addList(is_with_u, is_without_u);
        destroySG(VminusNGu);
        destroySG(Vminusu);
        free(is_without_u);
        return is_with_u;
    }

};

void addToAll(LLSG* is_with_u, NodeV* u) {
    NodeSG* cur = is_with_u->head;
    while (cur != NULL) {
        addSV(cur->sg, u);
        cur = cur->next;
    }
}

void addList(LLSG* is_with_u, LLSG* is_without_u) {
    NodeSG* prec = NULL;
    NodeSG* cur = is_with_u->head;
    while (cur != NULL) {
        prec = cur;
        cur = cur->next;
    }
    if (prec != NULL) {
        prec->next = is_without_u->head;
        if (is_with_u->head != NULL) {
            is_with_u->head->prev = prec;
        }
    }
    else {
        is_with_u->head = is_without_u->head;
    }
    is_with_u->length += is_without_u->length;
}
#endif