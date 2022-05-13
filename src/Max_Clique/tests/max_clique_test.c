#include "../max_clique.c"
#include "../../Data_Structures/c/GraphCollection.c"

int main(void) {
    GraphALL* g = Gortzsch();
    printf("%d", maxClique(g));
    printf("\n");
    destroyGraphALL(g);
    g = Cube();
    printf("%d", maxClique(g));
    destroyGraphALL(g);
    printf("\n");
    g = Independant(10);
    printf("%d", maxClique(g));
    destroyGraphALL(g);
    printf("\n");
}