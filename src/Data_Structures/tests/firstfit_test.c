#include "../../Coloring_Algos/FirstFit.c"
#include <stdio.h>

int main(void) {
    printf("salut\n");
    GraphALL* g = newGraphALL();
    addVertexALL(g, 'a'); // 'a'
    addVertexALL(g, 'b'); // 'b'
    addVertexALL(g, 'c'); // 'c'
    addVertexALL(g, 'd'); // 'd'
    addVertexALL(g, 'e'); // 'e'
    addVertexALL(g, 'f'); // 'f'
    addVertexALL(g, 'g'); // 'g'
    addVertexALL(g, 'h'); // 'h'
    addVertexALL(g, 'i'); // 'i'
    addVertexALL(g, 'j'); // 'j'
    addVertexALL(g, 'k'); // 'k'
    // AIcha
    addEdgeALL(g, 'e', 'a'); // 'a'--'b'
    addEdgeALL(g, 'c', 'd'); // 'a'--'b'
    addEdgeALL(g, 'c', 'f'); // 'a'--'b'
    addEdgeALL(g, 'f', 'g'); // 'a'--'b'
    addEdgeALL(g, 'g', 'k'); // 'a'--'b'
    addEdgeALL(g, 'f', 'i'); // 'a'--'b'
    addEdgeALL(g, 'f', 'e'); // 'a'--'b'
    addEdgeALL(g, 'f', 'h'); // 'a'--'b'
    addEdgeALL(g, 'h', 'b'); // 'a'--'b'
    addEdgeALL(g, 'i', 'j'); // 'a'--'b'


    // ARthur
    addEdgeALL(g, 'b', 'a'); // 'a'--'b'
    addEdgeALL(g, 'a', 'd'); // 'a'--'b'
    addEdgeALL(g, 'd', 'k'); // 'a'--'b'
    addEdgeALL(g, 'k', 'j'); // 'a'--'b'
    addEdgeALL(g, 'j', 'b'); // 'a'--'b'

    addEdgeALL(g, 'b', 'c'); // 'a'--'b'
    addEdgeALL(g, 'a', 'g'); // 'a'--'b'
    addEdgeALL(g, 'd', 'i'); // 'a'--'b'
    addEdgeALL(g, 'k', 'h'); // 'a'--'b'
    addEdgeALL(g, 'j', 'e'); // 'a'--'b'

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