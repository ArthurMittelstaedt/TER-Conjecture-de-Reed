#include <stdio.h>
#include <stdlib.h>
#include "../c/LLN.c"
#include "../c/LLV.c"

int main() {

    LLN* list = newLLN();


    AddNodeN(list, 101);
    AddNodeN(list, 102);
    AddNodeN(list, 103);
    printLLN(list);


}

