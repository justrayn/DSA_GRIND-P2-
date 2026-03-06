#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

typedef struct{
    Node *head;
    int count;
}List;

List* init();
void insertFirst(List *list);
void insertLast(List *list, int data);
void insertPos(List *list, int data, int index);
void deleteStart(List *list);
void deleteLast(List *list);
void deletePos(List *list, int index);
void display(List *list);

int main(){
    return 0;
}

List* init(){
    List *list = malloc(sizeof(List));
    if(list != NULL){
        list->head = NULL;
        list->count = 0;
        return list;
    }
}
void insertFirst(List *list){
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    list->count++;
}
void insertLast(List *list, int data){
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if(list->head == NULL){
        list->head = newNode;
        list->count++;
    } else {
        Node* current;
         for(current = list->head; current->next != NULL; current = current->next){}
        current->next = newNode;
        list->count++;
    }
}
void insertPos(List *list, int data, int index){
    if(index <= list->count){
        insertFirst(list, data);
    } else if(index == list->count){
        insertLast(list, data);
    } else {
        Node* newNode = malloc(sizeof(Node));

    }
}
void deleteStart(List *list){
    
}
void deleteLast(List *list){

}
void deletePos(List *list, int index){

}
void display(List *list){

}