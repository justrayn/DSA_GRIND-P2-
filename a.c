#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node, *NodePtr, *List;


void init(List *l);
void insertFirst(List *l, int data);
void insertLast(List *l, int data);
void insertPos(List *l, int data, int pos);
void DeleteFirst(List *l);
void DeleteLast(List *l);
void DeletePos(List *l, int pos);

int main(){



    return 0;
}

void init(List *l){
    *l = NULL;
}
void insertFirst(List *l, int data){
    List newD = malloc(sizeof(Node));
    if(newd != NULL){
        newD->data = data;
        newD->next = *l;
        *l = newD;
    }
}
void insertLast(List *l, int data){
    List newD = malloc(sizeof(Node));
    if(newd != NULL){
        newD->data = data;
        newD->next = NULL;
        if(*l == NULL){
            *l = newD;
        } else {
            List *curr;
            for(curr = l; (*curr)->next != NULL; curr = &(*curr)->next){}
            &(*curr)->next = newD;
        }
    }
}

void DeleteFirst(List *l){
    NodePtr *curr = l;
    (*l) = (*l)->next;
    free(curr);
}
void DeleteLast(List *l){

}
void DeletePos(List *l, int pos){
    
}