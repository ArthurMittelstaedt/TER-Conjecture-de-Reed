#ifndef TEST_H
#define TEST_H

typedef int(*test)();


typedef struct UnitTest UnitTest;
struct UnitTest {
    char testName[30];
    test test;
};

typedef struct TestBatch TestBatch;
struct TestBatch {
    char BatchName[30];
    UnitTest* batch[100];
};

int runBatch(TestBatch*);

#endif