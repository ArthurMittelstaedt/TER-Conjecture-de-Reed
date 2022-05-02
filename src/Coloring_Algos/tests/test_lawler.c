#include "../Lawler.c"
#include "../../Data_Structures/c/GraphCollection.c"
#include <stdio.h>

int main() {
    printf("hi");
    GraphALL* g = Gortzsch();
    printGraphALL(g);
    printf("The chromatic number of the Grötzsch graph is %d", Lawler(g));
}