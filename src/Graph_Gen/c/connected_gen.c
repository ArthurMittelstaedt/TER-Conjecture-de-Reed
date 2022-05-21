#ifndef GEN_CONNECTED_C
#define GEN_CONNECTED_C

#include "../../Data_Structures/c/LLG.c"
#include "../../Data_Structures/c/GraphALL.c"
#include "Odometer.c"

LLG* GenConnected(size_t n) {
    LLG* Graphs = newLLG();
    if (n == 0) {
        GraphALL* emptyG = newGraphALL();
        addG(Graphs, emptyG);
        return Graphs;
    }
    if (n == 1) {
        GraphALL* smallG = newGraphALL();
        addVertexALL(smallG, n + 64);
        addG(Graphs, smallG);
        return Graphs;
    }
    LLG* smaller = GenConnected(n - 1);
    NodeG* curG = smaller->head;
    binarySubG allNodes = (1 << (n - 1)) - 1;
    while (curG != NULL) {
        size_t last_bit = 1;
        for (binarySubG bNgbr = 1;bNgbr <= allNodes;bNgbr++) {
            GraphALL* g = subGraphALL(curG->g, allNodes);
            VertexId v = n + 64;
            addVertexALL(g, v);
            if (bNgbr >= (1 << last_bit)) {
                last_bit++;
            }
            for (size_t u = 0; u < last_bit; u++) {
                if (bNgbr >> u & 1) {
                    addEdgeALL(g, v, u + 65);
                }
            }
            addG(Graphs, g);
        }


        curG = curG->next;
    }
    destroyLLG(smaller);
    return Graphs;
}

#endif