#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX log10

typedef struct Node{
    int data;
    struct Node *next;
} Node, *NodePtr;

typedef struct {
    int count;
    Node *head;
}List, *ListPtr;

ListPtr init();
void insertLast(ListPtr l, int data);
void noDup(ListPtr l);
void display(ListPtr l);

int main(){
    
    int size;
    ListPtr list = init();
    printf("Enter the size of the linked list: ");
    scanf("%d", &size);    
    int tdata;    
    for(int i = 0; i < size;i++){
        printf("Enter element %d: ", i + 1);
        scanf("%d", &tdata);
        insertLast(list, tdata);
    }
    
    printf("Linked list after removing duplicates: ");
    noDup(list);
    display(list);
    
    return 0;
}

ListPtr init(){
    ListPtr newN = malloc(sizeof(List));
    if(newN != NULL){
        newN->count = 0;
        newN->head = NULL;
    }
    return newN;
}
void insertLast(ListPtr l,int data){
    NodePtr newN = malloc(sizeof(Node));
    if(newN != NULL){
        newN->data = data;
        newN->next = NULL;
        if(l->head == NULL){
            l->head = newN;
        } else {
            NodePtr curr;
            for(curr = l->head;curr->next != NULL;curr = curr->next){}
            curr->next = newN;
        }
        l->count++;
    }
}
void noDup(ListPtr l){
    if(l->head == NULL){
        printf("nothing in here...\n");
    } else {
        NodePtr curr;
        NodePtr temp;
        for(curr = l->head; curr->next != NULL;  ){
            if(curr->data == curr->next->data){
                temp = curr->next;
                curr->next = temp->next;
                free(temp);
                l->count--;
            } else {
                curr = curr->next;
            }
        }
    }
}

void display(ListPtr l){
    NodePtr trav;
    for(trav = l->head; trav != NULL; trav = trav->next){
        printf("%d ", trav->data);
    }
}