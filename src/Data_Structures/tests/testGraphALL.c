#include "../c/LLN.c"
#include "../c/LLV.c"
#include "../c/GraphALL.c"

int main(void) {
    GraphALL* g = newGraphALL();
    printGraphALL(g);printf("\n");
    addVertexALL(g, 'a'); // 'a' 
    printGraphALL(g);printf("\n");
    addVertexALL(g, 'b'); // 'a'  'b'
    printGraphALL(g);printf("\n");
    addEdgeALL(g, 'b', 'a'); // 'a'--'b'
    printGraphALL(g);printf("\n");
    addEdgeALL(g, 'a', 'c'); // 'a'--'b'
    printGraphALL(g);printf("\n");
    addVertexALL(g, 'c'); // 'a'--'b'  'c'
    printGraphALL(g);printf("\n");
    addEdgeALL(g, 'b', 'c');// 'a'--'b'--'c'
    printGraphALL(g);printf("\n");
    removeEdgeALL(g, 'a', 'b');// 'a'  'b'--'c'
    printGraphALL(g);printf("\n");
    addEdgeALL(g, 'b', 'a'); // 'a'--'b'--'c'
    printGraphALL(g);printf("\n");
    removeVertexALL(g, 'b'); // 'a'  'c'
    printGraphALL(g);printf("\n");
    return 0;
}