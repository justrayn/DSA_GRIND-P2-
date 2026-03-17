#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct Node {
    int data;
    struct Node *next;
}Node, *NodePtr;

void init(NodePtr *l){
    *l = NULL;
}

void insertLast(NodePtr *l, int data){
    NodePtr newD = malloc(sizeof(Node));
    if(newD != NULL){
    newD->data = data;
    newD->next = NULL;
    NodePtr *trav;
    for(trav = l; (*trav) != NULL; trav = &(*trav)->next){}
    (*trav) = newD;   
    }
}

void insertFirst(NodePtr *l, int data){
    NodePtr newD = malloc(sizeof(Node));
    if(newD != NULL){
        newD->data = data;
        newD->next = *l;
        (*l) = newD;
    }
}

void deleteFirst(NodePtr *l){
    NodePtr temp = *l;
    (*l) = (*l)->next;
    free(temp);
}

void modify(NodePtr *l, int k){
    NodePtr temp = NULL;
    NodePtr curr = *l;
    int count;
    
    for(count = 0; curr != NULL && count < k;count++, curr = curr->next){
        insertFirst(&temp, curr->data);
    }
    
    while(curr != NULL){
        insertLast(&temp, curr->data);
        curr = curr->next;
    }
    
    *l = temp;
    
    
    
}

void displayList(NodePtr l){
    while(l){
        printf("%d -> ", l->data);
        l = l->next;
    }
}
int main(){
    int el, k, a;
    NodePtr l;
    init(&l);
    printf("Enter the size of the linked list: ");
    scanf("%d", &el);
    
    printf("Enter k: ");
    scanf("%d", &k);
    
    for(int i = 0;i < el ;i++){
        printf("Enter element %d: ", i + 1);
        scanf("%d", &a);
        insertLast(&l, a);
    }
    
    printf("Original List: ");
    displayList(l);
    printf("\n");
    printf("Modified List: ");
    modify(&l,k);
    displayList(l);
    
    return 0;
}