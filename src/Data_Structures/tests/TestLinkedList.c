#include "../h/LinkedList.h"
#include "../c/LinkedList.c"

int intPointerComparator(void* p1, void* p2) {
    return *((int*)p1) = *((int*)p2);
}
void intPointerPrintor(void* p) {
    printf("%d", *((int*)p));
}

void testAsVertexSet() {
    printf("test");
    int vTab[] = { 1, 2, 3, 4, 5 };
    struct Set* l = (struct Set*)constructorLL(intPointerComparator, intPointerPrintor);
    for (int i = 0; i < 5; i++) {
        l->add(l, &vTab[i]);
    }
    l->print(l);
    l->remove(l, &vTab[4]);
    l->print(l);
    l->remove(l, &vTab[2]);
    l->print(l);
    l->remove(l, &vTab[0]);
    l->print(l);
    l->destroy(l);
}

int main(void) {
    testAsVertexSet();
    return 0;
}