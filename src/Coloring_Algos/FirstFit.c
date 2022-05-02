#ifndef FIRST_FIT_C
#define FIRST_FIT_C

#include <stdlib.h>
#include <stdio.h>
#include "../Data_Structures/c/GraphALL.c"

typedef enum BOOL BOOL;
enum BOOL { FALSE, TRUE };

// For permutation generation part --------------------------
typedef VertexId Labels;
typedef int Perm_Element_index;

typedef enum Dir Dir;
enum Dir { LEFT, RIGHT };

typedef struct V_perm V_perm;
struct V_perm {
    NodeV** vertices;
    Labels* labels; // should not be = 0
    Dir* dir;
    int length;
};

// Implementation of the Steinhaus–Johnson–Trotter algorithm
void printPerm(V_perm* p) {
    for (int i = 0; i < p->length; i++) {
        if (i <= p->length - 1) {
            printf("%c, ", p->vertices[i]->id);
        }
        else {
            printf("%c", p->vertices[i]->id);
        }
    }
}

V_perm* destroyPerm(V_perm* p) {
    free(p->vertices);
    free(p->labels);
    free(p->dir);
    free(p);
}

V_perm* firstPerm(GraphALL* g) {
    int length = g->vertices->length;
    V_perm* p = (V_perm*)malloc(sizeof(V_perm));
    p->vertices = (NodeV**)malloc(sizeof(NodeV*) * length);
    p->labels = (Labels*)malloc(sizeof(Labels) * length);
    p->dir = (Dir*)malloc(sizeof(Dir) * length);
    p->length = length;
    NodeV* curV = g->vertices->head;
    for (int i = 0; i < length; i++) {
        p->vertices[i] = curV;
        curV = curV->next;
        p->labels[i] = i + 1;
        p->dir[i] = LEFT;
    }
    return p;
};

// switches elements of p at indexes i1 and i2
// A.E: 0 < i1 <=> i2 < p->length 
void switchPermElement(V_perm* p, int i1, int i2) {
    NodeV* tempV = p->vertices[i1];
    Labels tempLabel = p->labels[i1];
    Dir tempDir = p->dir[i1];

    p->vertices[i1] = p->vertices[i2];
    p->labels[i1] = p->labels[i2];
    p->dir[i1] = p->dir[i2];

    p->vertices[i2] = tempV;
    p->labels[i2] = tempLabel;
    p->dir[i2] = tempDir;
}

// inverts the direction of elements greater than u
void invertDir(V_perm* p, Labels u) {
    int length = p->length;
    for (int i = 0; i < length; i++) {
        if (p->labels[i] > u) {
            switch (p->dir[i])
            {
            case LEFT:
                p->dir[i] = RIGHT;
                break;
            case RIGHT:
                p->dir[i] = LEFT;
                break;
            }
        }
    }
}

// Return the index of the maximum mobile element of the permutation
// -1 if there is no mobile element
Perm_Element_index findMaximumMobile(V_perm* p) {
    Labels maxMobile = 0;
    Perm_Element_index indexMaxMobile = -1;
    Perm_Element_index length = p->length;
    Labels first = p->labels[0];
    if (p->dir[0] == RIGHT && 1 < length && first > p->labels[1]) {
        maxMobile = first;
        indexMaxMobile = 0;
    }
    for (Perm_Element_index i = 1; i < length - 1; i++) {
        Labels cur = p->labels[i];
        switch (p->dir[i])
        {
        case LEFT:
            if (cur > p->labels[i - 1])
                if (maxMobile < cur) {
                    maxMobile = cur;
                    indexMaxMobile = i;
                }
            break;
        case RIGHT:
            if (cur > p->labels[i + 1])
                if (maxMobile < cur) {
                    maxMobile = cur;
                    indexMaxMobile = i;
                }
            break;
        }
    }
    Labels last = p->labels[length - 1];
    if (p->dir[length - 1] == LEFT && length - 2 >= 0
        && last > p->labels[length - 2]) {
        if (maxMobile < last) {
            maxMobile = last;
            indexMaxMobile = length - 1;
        }
    }
    return indexMaxMobile;

}

// Returns the next permutation following Steinhaus–Johnson–Trotter algorithm's
// principle.
// Returns FALSE if p is the last permutation (no more mobile element)
BOOL nextPerm(V_perm* p) {
    Perm_Element_index index_u = findMaximumMobile(p);
    if (index_u == -1)
        return FALSE;
    Labels u = p->labels[index_u];
    switch (p->dir[index_u])
    {
    case LEFT:
        switchPermElement(p, index_u, index_u - 1);
        break;
    case RIGHT:
        switchPermElement(p, index_u, index_u + 1);
        break;
    }
    invertDir(p, u);
    return TRUE;
}
// ---------------------------------------------------------

// E.A. g is not colored
Color FirstFit(NodeV** v_perm, int length) {

    Color colmax = 0;
    // first vertex =1 and go to the next one
    if (v_perm != NULL) {
        v_perm[0]->col = 1;
        colmax = 1;
    }
    // parcourir les sommets
    for (int k = 1; k < length; k++) {

        NodeN* curN = v_perm[k]->neighbours->head;
        // parcourir des voisins de chaque sommets
        BOOL* tab = (BOOL*)malloc(colmax * sizeof(BOOL));
        for (int i = 0;i < colmax; i++) {
            tab[i] = FALSE;
        }
        while (curN != NULL) {
            // si ce voisin a une couleur !=0 je met 1 a la case tab[la couleur ]
            if (curN->pv->col != 0) {
                tab[curN->pv->col - 1] = TRUE;
            }
            // sinon je regarde le voisins qui suit et si oui aussi je regarde le voisin qui suit sil a une couleur 
            curN = curN->next;

        }
        // je parcour le tab , je colore mon sommet avec lindexe de la premiere case =0 dans tab
        int i = 0;
        while (i < colmax && tab[i] == TRUE) {
            i++;
        }
        v_perm[k]->col = i + 1;
        // si la couleur de curV est et si inf aussi en passe et si sup  ce sera la nouvelle taille prochain tab
        colmax = (v_perm[k]->col > colmax) ? v_perm[k]->col : colmax;
        free(tab);
        // je passe au sommet qui suit 
    }

    return colmax;

}

Color FirstFitchromatic_number(GraphALL* g) {
    int length = g->vertices->length;
    V_perm* perm = firstPerm(g);
    Color chromatic_number = FirstFit(perm->vertices, length);
    int i = 1;//--------
    while (nextPerm(perm) != FALSE) {
        //printf("perm N ° %d\n", i);
        resetColALL(g);
        Color cur_chrom_number = FirstFit(perm->vertices, length);
        chromatic_number = (cur_chrom_number > chromatic_number) ? chromatic_number : cur_chrom_number;
        i++;//--------
    }
    destroyPerm(perm);
    return chromatic_number;
}

#endif