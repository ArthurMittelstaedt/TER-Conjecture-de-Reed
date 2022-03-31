#include <stdio.h>
#include <stdlib.h>
#include "../c/LLN.c"
#include "../c/LLV.c"

int main() {
    LLV* list = newLLV();

    addV(list, 101);
    addV(list, 102);
    addV(list, 103);
    NodeV* n101 = findV(list, 101);
    NodeV* n102 = findV(list, 102);
    NodeV* n105 = findV(list, 105);

    removeV(list, n101);
    removeV(list, n102);
    printf("%d\n", (n105 == NULL) ? 1 : 0);
    removeV(list, n105);
    printV(list);



}

