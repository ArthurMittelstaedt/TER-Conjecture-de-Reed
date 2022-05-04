#include "../test.h"
#include <stdlib.h>
#include "../../Coloring_Algos/Lawler.c"
#include "../../Data_Structures/c/GraphCollection.c"

int grotsch() {
    GraphALL* g = Gortzsch();
    int exp = 4;
    int chrom = Lawler(g);
    if (chrom == exp)
        return TRUE;
    else {
        printf("Expected %d, got %d", exp, chrom);
        return FALSE;
    }
};
UnitTest Ugrotsch = {
            "Lawler on Grotzsch's Graph",
            grotsch
};

int cube() {
    GraphALL* g = Cube();
    int exp = 2;
    int chrom = Lawler(g);
    if (chrom == exp)
        return TRUE;
    else {
        printf("Expected %d, got %d", exp, chrom);
        return FALSE;
    }
}
UnitTest Ucube = {
            "Lawler on Cube Graph",
            cube
};

TestBatch Lawler_Batch = {
    "Lawler",
    {
        &Ugrotsch,
        &Ucube,
        NULL// DO NOT REMOUVE
    }
};