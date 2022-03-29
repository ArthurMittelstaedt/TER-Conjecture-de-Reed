#ifndef SET
#define SET

#define TRUE 1
#define FALSE 0

typedef struct Set Set;
typedef struct Set
{
    void (*add)(struct Set*, void*);
    void (*remove)(struct Set*, void*);
    void (*print)(struct Set*);
    int (*contains)(struct Set*, void*);
    struct Set* (*constructor)(void);
    void (*destroy)(struct Set*);
    void* (*find)(struct Set*, void*);
    //iterator
    void* (*start)(struct Set*);
    void* (*next)(struct Set*);
    int (*end)(struct Set*);
};

#endif