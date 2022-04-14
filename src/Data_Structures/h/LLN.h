#ifndef LLN_H
#define LLN_H
#include "LLV.h"

typedef unsigned char VertexId;

typedef struct NodeN NodeN;
typedef VertexId Color;

struct NodeN {
    VertexId id; //node
    struct NodeV* pv; //ladresse du noeud v qui contient le sommet d'identifiant id
    struct NodeN* next;
    struct NodeN* prev;
    struct NodeN* pn;
};

typedef struct LLN LLN;
struct LLN
{
    NodeN* head;
    int length; // si pas besoin , enlever;
};


extern int isEmptyN(LLN*); //Done
//int* AddNodeAtN(LLN*, int, int); 
//int* AddNodeSorted(LLN*, int);
extern void AddNodeN(LLN*, VertexId); //Done
//int getNodeAt(LLN*, int);
//void setNodeAt(LLN*, int, int);
extern NodeN* findN(LLN*, VertexId id);
extern void removeN(LLN*, NodeN*);
extern void printLLN(LLN*); //Done
//LLN* SortAL(LLN* AL);
extern LLN* newLLN(void);//Done
extern void destroyLLN(LLN*);//Done
extern NodeN* newNodeN(VertexId); //Done
extern void destroyNodeN(NodeN*);  //Done
extern int containsN(LLN*, VertexId); // pas besoin pour le moment 
extern LLN* copyLLN(LLN*);

#endif