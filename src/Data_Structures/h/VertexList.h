typedef struct VertexList
{
    void (*addVertex)(void*, unsigned char);
    void (*removeVertex)(void*, unsigned char);
    void (*print)(void*);
};
