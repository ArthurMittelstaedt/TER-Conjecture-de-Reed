#include "../../Coloring_Algos/FirstFit.c"
#include "../../Data_Structures/c/GraphCollection.c"

#include <stdio.h>

int main(void) {
    printf("salut\n");
    GraphALL* g = Gortzsch();
    printf("The chromatic number of the Grötzsch graph is %d", FirstFitchromatic_number(g));
    printGraphALL(g);printf("\n");
}