#ifndef COLLECTION
#define COLLECTION

typedef int (*comparator)(void*, void*);
typedef void (*printor)(void*);

typedef struct Collection
{
    void (*add)(void*, void*);
    void (*remove)(void*, void*);
    void (*print)(void*);
    int (*contains)(void*, void*);
    void* (*constructor)(void);
    void (*destroy)(void*);
    void (*printp)(void*, printor);
    void* (*find)(void*, void*, comparator);
    //iterator
    void* (*start)(void*);
    void* (*next)(void*);
    int (*end)(void*);
} Collection;

#endif