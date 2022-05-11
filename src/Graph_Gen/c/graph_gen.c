#ifndef GRAPH_GEN_C
#define GRAPH_GEN_C

#include <stdlib.h>
#include "../c/Odometer.c"
#include "../../Data_Structures/c/GraphCollection.c"
#include "../../Data_Structures/c/LLG.c"

LLG* GenGraphs(size_t n) {
    LLG* graphs = newLLG();
    size_t max_m = (n * (n - 1)) / 2;
    Odometer* o = newOdometer(max_m);
    addG(graphs, Independant(n));
    while (inc(o)) {
        GraphALL* g = Independant(n);
        int i = 0;
        for (int bit = odoStartIt(o); !odoEndIt(o); bit = odoNextIt(o)) {
            if (bit) {
                VertexId u = 0, v;
                // Need smarter way to find u and v
                int q = 0;
                int nq = n - 1;
                while (i >= nq) {
                    q = nq;
                    nq = q + q - 1;
                    u++;
                }
                v = u + (i - q) + 1;
                //
                addEdgeALL(g, u + 65, v + 65);
            }
            i++;
        }
        addG(graphs, g);
    }
    destroyOdometer(o);
    return graphs;
}


#endif