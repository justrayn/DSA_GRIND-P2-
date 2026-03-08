#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

typedef struct {
    int count;
    Node *head;
}List;

List* init();
void display(List l);
void insertFirst(List *l, int data);
void insertLast(List *l, int data);
void insertPos(List *l, int data, int index);
void deleteFirst(List *l, int data);
void deleteLast(List *l, int data);
void deletePos(List *l, int index);

int main(){


    return 0;
}

List* init(){
    List *l = malloc(sizeof(List));
    if(l != NULL){
        l->head = NULL;
        l->count = 0;
        return l;
    }
}
void display(List l){
    if(l->count == 0){
        printf("nothing in here dummy\n\n");
    } else {
        Node *curr;
        printf("Head ->");
        for(curr = l->head; curr != NULL; curr = curr->next){
            printf("%d -> ", curr->data);
        }
        printf("NULL");
    }
}
void insertFirst(List *l, int data){
    Node *newNode = malloc(sizeof(Node));
    if(newNode != NULL){
        
    }
}
void insertLast(List *l, int data){

}
void insertPos(List *l, int data, int index){

}
void deleteFirst(List *l, int data){

}
void deleteLast(List *l, int data){

}
void deletePos(List *l, int index){

}