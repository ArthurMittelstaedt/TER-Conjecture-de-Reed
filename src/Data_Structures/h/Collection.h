#ifndef COLLECTION
#define COLLECTION

typedef int (*comparator)(void*, void*);
typedef void (*printor)(void*);

typedef struct Collection
{
    void (*add)(struct Collection*, void*);
    void (*remove)(struct Collection*, void*);
    void (*print)(struct Collection*);
    int (*contains)(struct Collection*, void*);
    struct Collection* (*constructor)(void);
    void (*destroy)(struct Collection*);
    void (*printp)(struct Collection*, printor);
    void* (*find)(struct Collection*, void*, comparator);
    //iterator
    void* (*start)(struct Collection*);
    void* (*next)(struct Collection*);
    int (*end)(struct Collection*);
} Collection;

#endif