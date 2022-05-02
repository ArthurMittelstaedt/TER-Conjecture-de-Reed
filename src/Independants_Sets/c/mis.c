#ifndef MIS_C
#define MIS_C

#include "../../Data_Structures/c/LLSG.c"

NodeSV* findMaximalVertex(SG* SUBG, SG* CAND);
SG* SGinterLLN(SG* lv, LLN* ln, VertexId vertexToKeep);
SG* SGminusLLN(SG* lv, LLN* ln, VertexId vertexToExclude);
LLSG* maximal_independant_sets(GraphALL* g);
void expand(SG* SUBG, SG* CAND);

SG* Q;
LLSG* g_mis_list = NULL;

LLSG* maximal_independant_sets(GraphALL* g) {
    g_mis_list = newLLSG(); // comprehensive list of g's mis
    destroySG(Q);
    Q = newSG();
    SG* SUBG = SGFromLLV(g->vertices);
    SG* CAND = SGFromLLV(g->vertices);
    expand(SUBG, CAND);
    destroySG(SUBG);
    destroySG(CAND);
    return g_mis_list;
}

void expand(SG* SUBG, SG* CAND) {
    if (isEmptySV(SUBG)) {
        addSG(g_mis_list, copySG(Q));
    }
    else {
        NodeSV* u = findMaximalVertex(SUBG, CAND);
        SG* EXTu = SGinterLLN(CAND, u->v->neighbours, u->v->id);
        while (!isEmptySV(EXTu)) {
            NodeSV* q = EXTu->head;
            addSV(Q, q->v);
            NodeSV* qinQ = Q->head;

            SG* SUBGq = SGminusLLN(SUBG, q->v->neighbours, q->v->id);

            SG* CANDq = SGminusLLN(CAND, q->v->neighbours, q->v->id);

            expand(SUBGq, CANDq);
            destroySG(SUBGq);
            destroySG(CANDq);
            NodeSV* qinCAND = findSV(CAND, q->v->id);
            NodeSV* qinCANDinterNU = findSV(EXTu, q->v->id);
            removeSV(CAND, qinCAND);
            removeSV(EXTu, qinCANDinterNU);
            removeSV(Q, qinQ);
        }
    }
}

SG* SGinterLLN(SG* lv, LLN* ln, VertexId vertexToKeep) {
    SG* intersection = newSG();
    NodeSV* cur = lv->head;
    while (cur != NULL) {
        if (cur->v->id == vertexToKeep || containsN(ln, cur->v->id)) {
            addSV(intersection, cur->v);
        }
        cur = cur->next;
    }
    return intersection;
}

SG* SGminusLLN(SG* lv, LLN* ln, VertexId vertexToExclude) {
    SG* difference = newSG();
    NodeSV* cur = lv->head;
    while (cur != NULL) {
        if (vertexToExclude != cur->v->id && !containsN(ln, cur->v->id)) {
            addSV(difference, cur->v);
            difference->head->v->neighbours = cur->v->neighbours;//----------------??
        }
        cur = cur->next;
    }
    return difference;
}

NodeSV* findMaximalVertex(SG* SUBG, SG* CAND) {
    NodeSV* cur = SUBG->head;
    NodeSV* maxU = cur;
    SG* maxCANDq = SGminusLLN(CAND, cur->v->neighbours, cur->v->id);
    cur = cur->next;
    while (cur != NULL) {
        SG* curCANDq = SGminusLLN(CAND, cur->v->neighbours, cur->v->id);
        if (curCANDq->length > maxCANDq->length) {
            destroySG(maxCANDq);
            maxCANDq = curCANDq;
            maxU = cur;
        }
        else {
            destroySG(curCANDq);
        }
        cur = cur->next;
    }
    destroySG(maxCANDq);
    return maxU;

}
#endif