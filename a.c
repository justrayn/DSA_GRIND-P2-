#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct {
    Node *top;
}Stack;

void sortQ(Queue* q){
    if(isEmpty(q)) return;
    Queue *sortQ = init();
    while(!isEmpty(q)){
        int minval = dequeue(q);
    }
}