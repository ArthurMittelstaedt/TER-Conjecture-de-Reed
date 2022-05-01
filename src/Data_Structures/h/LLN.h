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


extern int isEmptyN(LLN*);
extern void AddNodeN(LLN*, VertexId);
extern NodeN* findN(LLN*, VertexId id);
extern void removeN(LLN*, NodeN*);
extern void printLLN(LLN*);
extern LLN* newLLN(void);
extern void destroyLLN(LLN*);
extern NodeN* newNodeN(VertexId);
extern void destroyNodeN(NodeN*);
extern int containsN(LLN*, VertexId);
extern LLN* copyLLN(LLN*);

#endif