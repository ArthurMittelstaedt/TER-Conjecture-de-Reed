#include "LinkedList.c";

int main(void) {
    unsigned char* vTab = [1, 2, 3, 4, 5];
    LinkedList* l = newLinkedList();
    for (i = 0; i < 5; i++) {
        addVertex(l, vTab[i]);
    };
    print(l);
}