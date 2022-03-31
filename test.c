#include <stdio.h>
#include <stdlib.h>
#include "Liste_chainee.h"
#include "Liste_chainee.c"

int main(void){
    AdjNodes *list = EmptyList();
    printf("here\n");
    list = AddNodeAt(list,20,0);
    printAdjNodes(list);
    list = AddNodeAt(list,10,0);
    printAdjNodes(list);
    list = AddNodeAt(list,5,0);
    printAdjNodes(list);
    list = AddNodeAt(list,60,0);
    printAdjNodes(list);
    SortAL (list );
    printAdjNodes(list);
    list = AddNodeSorted(list,40);
    printAdjNodes(list);
    freeNodeAt(list,1);
    printAdjNodes(list);

}