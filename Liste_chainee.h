#ifndef LISTE_CHAINEE_H
#define LISTE_CHAINEE_H


typedef struct AdjNodes AdjNodes;
typedef struct List List ;
struct AdjNodes {
    int node;
    AdjNodes *suivant;
};



AdjNodes *EmptyList(void);
int isEmpty(AdjNodes *);
long lenlist(AdjNodes *);
AdjNodes *AddNodeAt (AdjNodes * , int , int);
AdjNodes *AddNodeSorted (AdjNodes * , int  );
int getNodeAt(AdjNodes *, int);
void setNodeAt(AdjNodes *, int, int);
AdjNodes *freeNodeAt(AdjNodes* , int);
AdjNodes *freeAdjNodes(AdjNodes*);
void printAdjNodes(AdjNodes *);
AdjNodes *SortAL (AdjNodes *AL  );





#endif