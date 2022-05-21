#include "../Graph_Gen/c/connected_gen.c"
#include "../Max_Clique/max_clique.c"
#include "../Coloring_Algos/Lawler.c"

const int N = 7;

int main(void) {
    for (int i = 0; i <= N; i++) {
        LLG* graphs = GenConnected(i);
        NodeG* ng = graphs->head;
        int nb_Clique_Skiped = 0;
        while (ng != NULL) {
            GraphALL* g = ng->g;
            size_t maxDegG = maxDeg(g);
            Color chrom = Lawler(g);
            //printf("chrom : %d, maxDeg : %d\n", chrom, maxDegG);
            int Verified = TRUE;
            if (chrom > (maxDegG + 2) / 2) {
                if (chrom > (maxClique(g) + maxDegG + 2) / 2) {
                    Verified = FALSE;
                }
            }
            else nb_Clique_Skiped++;
            ng = ng->next;
            if (!Verified) {
                printf("contre exemple!\n");
            }
            else {
                //printf("Ok\n");
            }
        }
        printf("Verified for size = %d (skiped clique for %d/%d)\n",
            i, nb_Clique_Skiped, graphs->length);
        destroyLLG(graphs);
    }
}