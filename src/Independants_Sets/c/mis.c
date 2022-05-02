#ifndef MIS_C
#define MIS_C

#include "../c/LLmis.c"

NodeV* findMaximalVertex(LLV* SUBG, LLV* CAND);
LLV* LLVinterLLN(LLV* lv, LLN* ln, VertexId vertexToKeep);
LLV* LLVminusLLN(LLV* lv, LLN* ln, VertexId vertexToExclude);
LLMIS* maximal_independant_sets(GraphALL* g);
void expand(LLV* SUBG, LLV* CAND);


typedef LLMIS LL;

LLV* Q;
LLMIS* g_mis_list = NULL;

LLMIS* maximal_independant_sets(GraphALL* g) {
    //destroyLLMIS(g_mis_list);
    g_mis_list = newLLMIS(); // comprehensive list of g's mis
    destroyLLV(Q, 0);
    Q = newLLV();
    LLV* SUBG = copyLLV(g->vertices);
    LLV* CAND = copyLLV(g->vertices);
    expand(SUBG, CAND);
    destroyLLV(SUBG, 0);
    destroyLLV(CAND, 0);
    return g_mis_list;
}

void expand(LLV* SUBG, LLV* CAND) {
    if (isEmptyV(SUBG)) {
        addMIS(g_mis_list, copyLLV(Q));
    }
    else {
        NodeV* u = findMaximalVertex(SUBG, CAND);
        LLV* EXTu = LLVinterLLN(CAND, u->neighbours, u->id);
        while (!isEmptyV(EXTu)) {
            NodeV* q = EXTu->head;
            addV(Q, q->id); free(Q->head->neighbours)/*remove later*/; Q->head->neighbours = q->neighbours;
            NodeV* qinQ = Q->head;

            LLV* SUBGq = LLVminusLLN(SUBG, q->neighbours, q->id);

            LLV* CANDq = LLVminusLLN(CAND, q->neighbours, q->id);

            expand(SUBGq, CANDq);
            destroyLLV(SUBGq, 0);
            destroyLLV(CANDq, 0);
            NodeV* qinCAND = findV(CAND, q->id);
            NodeV* qinCANDinterNU = findV(EXTu, q->id);
            removeV(CAND, qinCAND, 0);
            removeV(EXTu, qinCANDinterNU, 0);
            removeV(Q, qinQ, 0);
        }
    }
}

LLV* LLVinterLLN(LLV* lv, LLN* ln, VertexId vertexToKeep) {
    LLV* intersection = newLLV();
    NodeV* cur = lv->head;
    while (cur != NULL) {
        if (cur->id == vertexToKeep || containsN(ln, cur->id)) {
            addV(intersection, cur->id);
            free(intersection->head->neighbours);// move later
            intersection->head->neighbours = cur->neighbours;
        }
        cur = cur->next;
    }
    return intersection;
}

LLV* LLVminusLLN(LLV* lv, LLN* ln, VertexId vertexToExclude) {
    LLV* difference = newLLV();
    NodeV* cur = lv->head;
    while (cur != NULL) {
        if (vertexToExclude != cur->id && !containsN(ln, cur->id)) {
            addV(difference, cur->id);
            difference->head->neighbours = cur->neighbours;
        }
        cur = cur->next;
    }
    return difference;
}

NodeV* findMaximalVertex(LLV* SUBG, LLV* CAND) {
    NodeV* cur = SUBG->head;
    NodeV* maxU = cur;
    LLV* maxCANDq = LLVminusLLN(CAND, cur->neighbours, cur->id);
    cur = cur->next;
    while (cur != NULL) {
        LLV* curCANDq = LLVminusLLN(CAND, cur->neighbours, cur->id);
        if (curCANDq->length > maxCANDq->length) {
            destroyLLV(maxCANDq, 0);
            maxCANDq = curCANDq;
            maxU = cur;
        }
        else {
            destroyLLV(curCANDq, 0);
        }
        cur = cur->next;
    }
    destroyLLV(maxCANDq, 0);
    return maxU;

}
#endif