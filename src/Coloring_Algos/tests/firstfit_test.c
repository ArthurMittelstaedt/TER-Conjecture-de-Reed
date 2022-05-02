#include "../../Coloring_Algos/FirstFit.c"
#include "../../Data_Structures/c/GraphCollection.c"
#include <stdio.h>

int main(void) {
    printf("salut\n");
    GraphALL* g = Gortzsch();
    V_perm* p = firstPerm(g);
    printf("chromatic number of this permutation is : %d\n", ((int)FirstFit(p->vertices, 11)));
    printPerm(p);
    destroyPerm(p);
    /*
        LLV* list = newLLV();

        addV(list, 'a');
        addV(list, 'b');
        addV(list, 'c');

        LLN* n_a = newLLN();
        n_a =*/
}