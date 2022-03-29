typedef struct VertexList
{
    void (*addVertex)(void *this, unsigned char);
    void (*removeVertex)(void *this, unsigned char);
};
