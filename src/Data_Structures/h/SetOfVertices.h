#ifndef SET_OF_VERTICES
#define SET_OF_VERTICES

#define TRUE 1
#define FALSE 0

typedef unsigned char vertexId;

typedef struct SetOfV SetOfV;
struct SetOfV
{
    void (*add)(struct SetOfV*, vertexId);
    void (*remove)(struct SetOfV*, vertexId);
    void (*print)(struct SetOfV*);
    int (*contains)(struct SetOfV*, vertexId);
    struct SetOfV* (*constructor)(void);
    void (*destroy)(struct SetOfV*);
    //iterator
    vertexId(*start)(struct SetOfV*);
    vertexId(*next)(struct SetOfV*);
    int (*end)(struct SetOfV*);
};

#endif