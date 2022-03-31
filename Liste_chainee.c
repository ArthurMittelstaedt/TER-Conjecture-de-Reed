#include <stdio.h>
#include <stdlib.h>
#include "Liste_chainee.h"

static AdjNodes *initList(int); 
//allouer une place dans la memoire pour la liste et l'initialiser 
static AdjNodes *initList(int node){
    AdjNodes *adjlist = malloc(sizeof (adjlist));
    if(!adjlist)
        return NULL;
    adjlist -> node = node;
    adjlist-> suivant = NULL;
}

AdjNodes *EmptyList(void){
    return NULL;

}

int isEmpty(AdjNodes *AL){
    return AL == NULL; // if AL is NULL it will return 1 else 0

}

long lenlist(AdjNodes *AL){
    long len = 0;
    while( AL){ // tant que la liste n'est pas nulle  c-a-d. le suivant != NULL je rajoute à chaque fois 1 au len
        len++;
        AL= AL->suivant;
    }
    return len; 
}


AdjNodes *AddNodeAt (AdjNodes *AL , int Node , int position){
    AdjNodes *pointeur_precedent = AL;
    AdjNodes *pointeur_courrant = AL;
    int i;
    AdjNodes *element = initList(Node);
    if(isEmpty(AL)){
        return element; //qu'on viens d'initialiser
    }
    //pos 0 et la liste nest pas vide :
    if(position== 0){
        element -> suivant =AL;
        return element; 
    }
    i=0;
    while(i < position){//je boucle jusqu'a ce que j'arrive à ma position ue je veux
        i++;
        pointeur_precedent = pointeur_courrant ;
        pointeur_courrant = pointeur_courrant -> suivant;

    }
    //on le place et on décale l'ancien courrrant 
    pointeur_precedent -> suivant = element; //le courrant c'est notre nvll element
    element -> suivant = pointeur_courrant; 


    return AL;
    
}


AdjNodes *AddNodeSorted (AdjNodes *AL , int Node ){
    AdjNodes *pointeur_precedent = AL;
    AdjNodes *pointeur_courrant = AL->suivant;
    
    AdjNodes *element = initList(Node);

    if(isEmpty(AL)){
        return element; 
    }
    if(element->node < AL->node){//s'il est le plus ptit je le placeen premier
        element -> suivant =AL;
        return element; 
    }
    while ( element->node > pointeur_courrant->node ){
        pointeur_precedent = pointeur_courrant ;
        pointeur_courrant = pointeur_courrant -> suivant;
        
    }
    pointeur_precedent-> suivant = element;
    element->suivant = pointeur_courrant;

    return AL;
}

AdjNodes *SortAL(AdjNodes *AL  ){
    AdjNodes *pointeur_precedent = AL;
    AdjNodes *pointeur_courrant = AL;
    AdjNodes *temp = AL;
    AdjNodes *compare = AL;
    int k;
    if(isEmpty(AL)){
        printf("la liste est vide \n");
        return NULL ;
    }
    for(temp=AL;temp->suivant !=NULL; temp=temp->suivant){
        for(compare=temp->suivant; compare != NULL; compare=compare->suivant){
            if(compare->node < temp->node){
                k=compare->node;
                compare->node = temp->node;
                temp->node = k;
            }
        }

    }
    return AL;
}


int getNodeAt(AdjNodes *AL , int position){
    int i =0;
    if(isEmpty(AL)){
        printf("la liste est vide \n");
        return -1;
    }
    while(i < position){
        i++;
        AL =AL -> suivant;
    }
    //dès que j'arrive à la bonne position je retourne l'element qu'il faut
    return AL ->node;
}




void setNodeAt(AdjNodes *AL, int Node, int position){
    int i =0;
    if(isEmpty(AL)){
        printf("la liste est vide \n");
        return ;
    }
    while(i < position){
        i++;
        AL =AL -> suivant;
    }
    AL->node = Node; 
}



AdjNodes *freeNodeAt(AdjNodes *AL , int position){
     AdjNodes *pointeur_precedent = AL;
    AdjNodes *pointeur_courrant = AL;
    int i;
    if(isEmpty(AL)){
        return NULL; 
    }
    //pos 0 et la liste nest pas vide :
    if(position== 0){
        AL = AL -> suivant ;
        free(pointeur_courrant);
        return AL; 
    }
    i=0;
    while(i < position){//je boucle jusqu'a ce que j'arrive à ma position ue je veux
        i++;
        pointeur_precedent = pointeur_courrant ;
        pointeur_courrant = pointeur_courrant -> suivant;

    }
    //on décale tout 
    pointeur_precedent -> suivant =  pointeur_courrant -> suivant;  //zapper ou je suis
    free(pointeur_courrant);
    return AL;
}


AdjNodes *freeAdjNodes(AdjNodes *AL){
    AdjNodes *temp =NULL;
    while(AL){
        temp =AL->suivant; // on le garde ici car on va le désallouer mais on aura qd mm de leement suivat
        free(AL);
        AL= temp;
    }
    return AL;
}
void printAdjNodes(AdjNodes *AL){
    while(AL){ // tant que L est different de null = !isEmpty(AL)
        printf("%d ", AL->node);
        AL =AL->suivant; //pour que à chaque itération on parcours chacun des elements 

    }
    printf("\n");
}