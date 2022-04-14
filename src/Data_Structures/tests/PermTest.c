#include "../../Coloring_Algos/FirstFit.c"
//#include "../Data_Structures/c/GraphALL.c"
#include <stdio.h>

int main(void) {
    printf("salut\n");
    GraphALL* g = newGraphALL();
    addVertexALL(g, 'a'); // 'a'
    addVertexALL(g, 'b'); // 'b'
    addVertexALL(g, 'c'); // 'c'
    printGraphALL(g);printf("\n");

    V_perm* p = firstPerm(g);
    printPerm(p);
    while (nextPerm(p)) {
        printf("\n");
        printPerm(p);
    }

}