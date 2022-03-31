#ifndef LLN_H
#define LLN_H
#include "LLV.h"

typedef unsigned char VertexId;

typedef struct NodeN NodeN;

struct NodeN {
    VertexId id; //node
    NodeV* pv; //ladresse du noeud v qui contient le sommet d'identifiant id
    NodeN* next;
    NodeN* prev;
    NodeN* pn;
};

typedef struct LLN LLN;
struct LLN
{
    NodeN* head;
    int length; // si pas besoin , enlever;
};


int isEmptyN(LLN*); //Done
//int* AddNodeAtN(LLN*, int, int); 
//int* AddNodeSorted(LLN*, int);
void AddNodeN(LLN*, VertexId); //Done
//int getNodeAt(LLN*, int);
//void setNodeAt(LLN*, int, int);
NodeN* findN(LLN*, VertexId id);
void removeN(LLN*, NodeN*);
void printLLN(LLN*); //Done
//LLN* SortAL(LLN* AL);
LLN* newLLN(void);//Done
void destroyLLN(LLN*);//Done
NodeN* newNodeN(VertexId); //Done
void destroyNodeN(NodeN*);  //Done
int containN(LLN*, VertexId); // pas besoin pour le moment 


#endif