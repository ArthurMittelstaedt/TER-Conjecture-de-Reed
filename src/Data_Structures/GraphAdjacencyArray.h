struct VertexAdjacencyArray
{
    // Sorted array of the adjacent vertices given by their indexes in
    // GraphAdjacencyArray->vertices plus 1
    // May also contain the value 0, corresponding to no vertex
    unsigned char *neighbours;
    // Size of the "neighbours" array
    unsigned char neighbours_size;
};

struct GraphAdjacencyArray
{
    // Array of the graph's vertices
    // May also contain NULL entries
    struct VertexAdjacencyArray *vertices;
    // Size of the "vertices" array
    unsigned char vertices_size;
};
