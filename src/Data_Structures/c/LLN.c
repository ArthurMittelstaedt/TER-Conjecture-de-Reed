#ifndef LLN_C
#define LLN_C

#include <stdio.h>
#include <stdlib.h>
#include "../h/LLN.h"

//allouer une place dans la memoire pour la liste et l'initialiser 
NodeN* newNodeN(VertexId id) {
    NodeN* newNode = malloc(sizeof(NodeN));
    if (!newNode)
        return NULL;
    newNode->id = id;
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->pn = NULL;
    newNode->pv = NULL;

    return newNode;
}

int isEmptyN(LLN* AL) {
    return AL->head == NULL; // if AL is NULL it will return 1 else 0
}

/*
    LLN* AddpnAt(LLN * AL, int pn, int position) {
        LLN* pointeur_precedent = AL;
        LLN* pointeur_courrant = AL;
        int i;
        LLN* element = initList(pn);
        if (isEmpty(AL)) {
            return element; //qu'on viens d'initialiser
        }
        //pos 0 et la liste nest pas vide :
        if (position == 0) {
            element->next = AL;
            return element;
        }
        i = 0;
        while (i < position) {//je boucle jusqu'a ce que j'arrive à ma position ue je veux
            i++;
            pointeur_precedent = pointeur_courrant;
            pointeur_courrant = pointeur_courrant->next;

        }
        //on le place et on dé 
        pointeur_precedent->next = element; //le courrant c'est notre nvll element
        element->next = pointeur_courrant;


        return AL;

    }
*/
void AddNodeN(LLN* AL, VertexId id) {
    NodeN* newHead = newNodeN(id);
    NodeN* oldHead = AL->head;
    newHead->next = oldHead;
    if (oldHead != NULL)
        oldHead->prev = newHead;
    AL->head = newHead;
    AL->length += 1;
}


/*
    LLN* AddpnSorted(LLN * AL, int pn) {
        LLN* pointeur_precedent = AL;
        LLN* pointeur_courrant = AL->next;

        LLN* element = initList(pn);

        if (isEmpty(AL)) {
            return element;
        }
        if (element->pn < AL->pn) {//s'il est le plus ptit je le placeen premier
            element->next = AL;
            return element;
        }
        while (element->pn > pointeur_courrant->pn) {
            pointeur_precedent = pointeur_courrant;
            pointeur_courrant = pointeur_courrant->next;

        }
        pointeur_precedent->next = element;
        element->next = pointeur_courrant;

        return AL;
    }

    LLN* SortAL(LLN * AL) {
        LLN* pointeur_precedent = AL;
        LLN* pointeur_courrant = AL;
        LLN* temp = AL;
        LLN* compare = AL;
        int k;
        if (isEmpty(AL)) {
            printf("la liste est vide \n");
            return NULL;
        }
        for (temp = AL;temp->next != NULL; temp = temp->next) {
            for (compare = temp->next; compare != NULL; compare = compare->next) {
                if (compare->pn < temp->pn) {
                    k = compare->pn;
                    compare->pn = temp->pn;
                    temp->pn = k;
                }
            }

        }
        return AL;
    }
*/
/*
VertexId getNodeAt(NodeN* AL, int position) {
    int i = 0;
    if (isEmpty(AL)) {
        printf("la liste est vide \n");
        return -1;
    }
    while (i < position) {
        i++;
        AL = AL->next;
    }
    //dès que j'arrive à la bonne position je retourne l'element qu'il faut
    return AL->id;
}




void setpnAt(LLN* AL, int pn, int position) {
    int i = 0;
    if (isEmpty(AL)) {
        printf("la liste est vide \n");
        return;
    }
    while (i < position) {
        i++;
        AL = AL->next;
    }
    AL->pn = pn;
}
*/

int containsN(LLN* AL, VertexId id) {
    NodeN* cur = AL->head;
    while (cur != NULL && cur->id != id) {
        cur = cur->next;
    }
    if (cur == NULL) return 0;
    else return 1;

}

NodeN* findN(LLN* AL, VertexId id) {
    NodeN* cur = AL->head;
    while (cur != NULL && cur->id != id) {
        cur = cur->next;
    }
    return cur;
}


void destroyNodeN(NodeN* n) {
    free(n);
}

void removeN(LLN* AL, NodeN* n) { // ici le n c'est le np de lemelent que j veut supp
    if (n != NULL) {
        NodeN* prev = n->prev;
        NodeN* next = n->next;
        destroyNodeN(n);
        //if (prev != NULL) {
            //prev->next = next;
        //}
        if (n->prev == NULL) {
            AL->head = next;
        }
        else {
            //AL->head = next;
            prev->next = next;
        }
        if (next != NULL)
            next->prev = prev;
        AL->length -= 1;
    }
}


LLN* newLLN(void) {
    LLN* l = malloc(sizeof(LLN));
    l->head = NULL;
    l->length = 0;
    return l;
}


void destroyLLN(LLN* AL) {
    NodeN* cur = AL->head;
    NodeN* temp = NULL;
    while (cur) {
        temp = cur->next;
        destroyNodeN(cur);
        cur = temp;
    }
    free(AL);
}




void printLLN(LLN* AL) {
    NodeN* cur = AL->head;
    printf("[");
    while (cur != NULL) { // tant que L est different de null = !isEmpty(AL)
        if (cur->next != NULL) {
            printf("%c", cur->id);
            printf(", ");
        }
        else {
            printf("%c", cur->id);
        }
        cur = cur->next; //pour que à chaque itération on parcours chacun des elements 
    }
    printf("]\n");
}

// Copies the list l, inverts the order of nodes
// LLN* copyLLN(LLN* l) {
//     LLN* clone = newLLN();
//     NodeN* cur = l->head;
//     while (cur != NULL) {
//         AddNodeN(clone, cur->id);
//         clone->head->pv = cur->pv;
//         clone->head->pn = cur->pn;
//         cur = cur->next;
//     }
//     return clone;
// }

LLN* copyLLN(LLN* l) {
    LLN* clone = newLLN();
    NodeN* curl = l->head;
    if (curl != NULL) {
        NodeN* curc = newNodeN(curl->id);
        curc->pv = curl->pv;
        curc->pn = curl->pn;
        clone->head = curc;
        curl = curl->next;
        while (curl != NULL) {
            NodeN* nextc = newNodeN(curl->id);
            nextc->pv = curl->pv;
            nextc->pn = curl->pn;
            curc->next = nextc;
            nextc->prev = curc;
            curc = nextc;
            curl = curl->next;
        }
        clone->length = l->length;
    }
    return clone;
}
#endif