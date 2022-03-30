#include "../c/GraphAdjacencyList.c"
#include "../c/LinkedListOfV.c"
#include "../c/LinkedList.c"
#include <stdio.h>

int main(void) {
    printf("\tWWWWWWWWWWWWWWW\tWWWWWW\n");
    GraphAL* g = constructorGraphAL((Set * (*)(void))constructorLL, (SetOfV * (*)(void))constructorLLV);
    printGraphAl(g);
    addVertex(g, 1); // 1 
    printGraphAl(g);
    addVertex(g, 2); // 1  2
    printGraphAl(g);
    addVertex(g, 2); // 1  2
    printGraphAl(g);
    addEdge(g, 2, 1); // 1--2
    printGraphAl(g);
    addEdge(g, 1, 2); // 1--2
    printGraphAl(g);
    addEdge(g, 1, 3); // 1--2
    printGraphAl(g);
    addVertex(g, 3); // 1--2  3
    printGraphAl(g);
    addEdge(g, 2, 3);// 1--2--3
    printGraphAl(g);
    addEdge(g, 1, 2);// 1  2--3
    printGraphAl(g);
    addEdge(g, 2, 1); // 1--2--3
    printGraphAl(g);
    removeVetex(g, 2); // 1  3
    printGraphAl(g);
    return 0;
}