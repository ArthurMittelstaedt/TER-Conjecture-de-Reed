#include "GraphAdjacencyList.h"
#ifndef SET_OF_VAL
#define SET_OF_VAL

#define TRUE 1
#define FALSE 0

typedef unsigned char vertexId;

typedef struct VertexAL VertexAL;
struct VertexAL
{
    // vertex's identifier, unique among the graph
    unsigned char id;
    // adjacency list
    struct SetOfV* neighbours;
};

extern VertexAL* constructorVertexAL(struct SetOfV* (*ALConstructor)(void), vertexId v);
extern void destroyVertexAL(VertexAL* v);

typedef struct SetOfVAL SetOfVAL;
struct SetOfVAL
{
    int (*add)(struct SetOfVAL*, vertexId);
    int (*remove)(struct SetOfVAL*, vertexId);
    void (*print)(struct SetOfVAL*);
    int (*contains)(struct SetOfVAL*, vertexId);
    VertexAL* (*find)(struct SetOfVAL*, vertexId);
    struct SetOfVAL* (*constructor)(void);
    void (*destroy)(struct SetOfVAL*);
    //iterator
    VertexAL* (*start)(struct SetOfVAL*);
    VertexAL* (*next)(struct SetOfVAL*);
    int (*end)(struct SetOfVAL*);
    struct SetOfV* (*ALconstructor)(void);
};

#endif