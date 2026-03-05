#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct Node{
    int data[MAX];
    typedef Node *next;
}NodeType, *List;

void init(List *l);
void display(List l);
void insertFront(List *l, int val);
void insertLast(List *l, int val);
void insertSorted(List *l, int val);
void deleteFront(List *l);
void deleteLast(List *l);


int main(){



    return 0;
}


void init(List *l){
    *l = NULL;
}
void display(List l){
    if(l != NULL){
        printf("Head -> ");
        while(l){
            printf("%d ", l->data);
            l = l->next;
        }
        printf("->NULL");
    }
}
void insertFront(List *l, int val){
    Link newD = malloc(sizeof(NodeType));
    if(newD != NULL){
        newD->data = val;
        newD->next = *l;
        *l = newD;
    }
}
void insertLast(List *l, int val){
    Link newD = malloc(sizeof(NodeType));
    if(newD != NULL){
        newD->data = val;
        newD->next = *l;
        if(l == NULL){
            insertFront(l, val);
        } else {
            List *trav;
            for(trav = l; (*trav)->next != NULL; trav = &(*trav)->next){}
            (*trav)->next = newD;
        }
    }
}
void insertSorted(List *l, int val){
    Link newD = malloc(sizeof(NodeType));
    if(newD != NULL){
        newD->data = val;
        newD->next = *l;
        if(l == NULL){
            insertFront(l, val);
        } else {
            List *trav;
            for(trav = l; (*trav) != NULL; trav = &(*trav)->next){}
            (*trav) = newD;
        }
    }
}
void deleteFront(List *l){

}
void deleteLast(List *l){

}