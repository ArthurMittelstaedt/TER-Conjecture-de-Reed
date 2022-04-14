#include "../../Data_Structures/c/LLN.c"
#include "../../Data_Structures/c/graphALL.c"
#include "../h/LLmis.h"

MIS* Q;
LLMIS* c_g_mis_list;

LLMIS* maximal_independant_sets(GraphALL* g) {
    c_g_mis_list = newLLMIS(); // comprehensive list of g's mis
    Q = newLLN();
    expand(g, g->vertices);
    return c_g_mis_list;
}

void expand(MIS* SUBG, MIS* CAND) {
    if (isEmptyMIS(SUBG)) {
        addMIS(c_g_mis_list, copyLLN(Q));
    }
    else {
        Nu = ; //TODO
    }
}