#include "VertexList.h"
typedef struct Node
{
    // Vertex id
    unsigned char v;
    struct Node* next;
    struct Node* prev;
};

extern void addVertex(void* this, unsigned char v);
extern void removeVertex(void* this, unsigned char v);
extern void print(void* this);

typedef struct LinkedList
{
    struct VertexList VertexList = { addVertex,
                                    removeVertex,
                                    print };
    struct Node* head;
};

extern struct LinkedList* newLinkedList();