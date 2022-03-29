#include "../h/LinkedListOfV.h"
#include "../c/LinkedListOfV.c"

void testAsSetOfV() {
    int vTab[] = { 1, 2, 3, 4, 5 };
    SetOfV* l = (SetOfV*)constructorLLV();
    for (int i = 0; i < 5; i++) {
        l->add(l, vTab[i]);
    }
    l->print(l);
    l->remove(l, 5);
    l->print(l);
    l->remove(l, 3);
    l->print(l);
    l->remove(l, 1);
    l->print(l);
    l->destroy(l);
}

int main(void) {
    testAsSetOfV();
    return 0;
}