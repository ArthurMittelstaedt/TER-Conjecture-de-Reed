#ifndef SET
#define SET

#define TRUE 1
#define FALSE 0

typedef int (*comparator)(void*, void*);
typedef void (*printor)(void*);

typedef struct Set Set;
struct Set
{
    int (*add)(struct Set*, void*);
    int (*remove)(struct Set*, void*);
    void (*print)(struct Set*);
    int (*contains)(struct Set*, void*);
    struct Set* (*constructor)(void);
    void (*destroy)(struct Set*);
    void* (*find)(struct Set*, void*);
    void* (*findComp)(struct Set*, void*, comparator);
    //iterator
    void* (*start)(struct Set*);
    void* (*next)(struct Set*);
    int (*end)(struct Set*);
    comparator comparator;
    printor printor;
};

#endif