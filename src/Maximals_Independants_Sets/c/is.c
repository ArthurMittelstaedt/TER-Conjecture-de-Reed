#include "../c/mis.c"

void addToAll(LLMIS* is_with_u, NodeV* u);
void addList(LLMIS* is_with_u, LLMIS* is_without_u);
LLMIS* independant_sets_r(LLV* V);

LLMIS* independant_sets(GraphALL* g) {
    LLV* VG = copyLLV(g->vertices);
    LLMIS* res = independant_sets_r(VG);
    return res;
}

LLMIS* independant_sets_r(LLV* V) {
    if (isEmptyV(V)) {
        LLMIS* is = newLLMIS();
        addMIS(is, newLLV());
        return is;
    }
    else {
        NodeV* u = V->head;
        LLV* Vminusu = copyLLV(V);
        NodeV* nodeU = findV(Vminusu, u->id);
        removeV(Vminusu, nodeU, 0);
        LLMIS* is_without_u = independant_sets_r(Vminusu);

        LLV* VminusNGu = copyLLV(Vminusu);
        NodeN* curN = u->neighbours->head;
        while (curN != NULL) {
            NodeV* nodeNeighbour = findV(VminusNGu, curN->id);
            removeV(VminusNGu, nodeNeighbour, 0);
            curN = curN->next;
        }
        LLMIS* is_with_u = independant_sets_r(VminusNGu);
        addToAll(is_with_u, u);
        addList(is_with_u, is_without_u);
        destroyLLV(VminusNGu, 0);
        destroyLLV(Vminusu, 0);
        free(is_without_u);
        return is_with_u;
    }

};

void addToAll(LLMIS* is_with_u, NodeV* u) {
    NodeMIS* cur = is_with_u->head;
    while (cur != NULL) {
        addV(cur->mis, u->id);
        cur->mis->head->neighbours = u->neighbours;
        cur = cur->next;
    }
}

void addList(LLMIS* is_with_u, LLMIS* is_without_u) {
    NodeMIS* prec = NULL;
    NodeMIS* cur = is_with_u->head;
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