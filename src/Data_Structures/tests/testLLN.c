#include <stdio.h>
#include <stdlib.h>
#include "../c/LLN.c"
#include "../c/LLV.c"

int main() {

    LLN* list = newLLN();


    AddNodeN(list, 'a');
    AddNodeN(list, 'b');
    AddNodeN(list, 'c');
    NodeN* na = findN(list, 'a');
    removeN(list, na);
    NodeN* nc = findN(list, 'c');
    removeN(list, nc);
    NodeN* nz = findN(list, 'z');
    //printf("%d\n", (nz == NULL) ? 1 : 0);
    removeN(list, nz);
    printf("%d", containsN(list, 'a'));
    printf("%d", containsN(list, 'z'));
    printLLN(list);
}

