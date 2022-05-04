#ifndef TEST_C
#define TEST_C

#include "test.h"
#include <stdlib.h>
#include <stdio.h>

int runBatch(TestBatch* tb) {
    int batch_success = 1;
    size_t i = 0;
    while (tb->batch[i] != NULL) {
        UnitTest* ut = tb->batch[i];
        int test_sucess = ut->test();
        if (!test_sucess) {
            batch_success = 0;
            printf("\nFailed test : %s\n", ut->testName);
            printf("-------------------------------------------------------\n");
        }
        i++;
    }
    return batch_success;
}

#endif