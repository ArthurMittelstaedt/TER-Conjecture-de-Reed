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
    int vTab[] = { 1, 2, 3, 4, 5 };
    struct LinkedList* l = constructorLL();
    for (int i = 0; i < 5; i++) {
        addLL(l, (void*)vTab[i]);
    }
    printLL(l);
    removeLL(l, (void*)5);
    printLL(l);
    removeLL(l, (void*)3);
    printLL(l);
    removeLL(l, (void*)1);
    printLL(l);
    printf("contien 2 : %d\n", containsLL(l, (void*)2));
    printf("contien 10 : %d\n", containsLL(l, (void*)10));
    destroyLL(l);
}