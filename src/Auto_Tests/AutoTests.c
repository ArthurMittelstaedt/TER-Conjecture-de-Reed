#ifndef AUTO_TESTS_C
#define AUTO_TESTS_C

#include "Coloring_Algos/Lawler_Batch.c"
#include "test.c"

TestBatch* batches[100] = {
    &Lawler_Batch,
    NULL// DO NOT REMOVE
};

int main(void) {
    int success = 1;
    size_t i = 0;
    while (batches[i] != NULL) {
        TestBatch* tb = batches[i];
        printf("Running Batch : %s ===============================\n", tb->BatchName);
        int batch_success = runBatch(tb);
        if (batch_success) {
            printf("Batch Success :) ======================================\n");
        }
        else {
            printf("Batch Failed :( =======================================\n");
            success = 0;
        }
        i++;
    }
    if (success) {
        printf("END : SUCCESS");
    }
    else {
        printf("END : FAIL");
    }
}

#endif