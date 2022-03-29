#include "../h/LinkedList.h"
#include "../c/LinkedList.c"

void testAsVertexSet() {
    int vTab[] = { 1, 2, 3, 4, 5 };
    struct Collection* l = (struct Collection*)constructorLL();
    for (int i = 0; i < 5; i++) {
        l->add(l, (void*)vTab[i]);
    }
    l->print(l);
    l->remove(l, (void*)5);
    l->print(l);
    l->remove(l, (void*)3);
    l->print(l);
    l->remove(l, (void*)1);
    l->print(l);
    l->destroy(l);
}

int main(void) {
    testAsVertexSet();
    return 0;
}