#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int* ptr = malloc(sizeof(int));
    free(ptr);
    printf("%d", (ptr == NULL) ? 1 : 0);
    printf("%d", *ptr);
}