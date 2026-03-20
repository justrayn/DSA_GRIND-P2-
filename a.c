#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

typedef struct {
    Node *front;
    Node *rear;
}Queue;

Queue* init();
bool isFull(Queue *q);
bool isEmpty(Queue *q);
void enQ(Queue *q, int data);
void deQ(Queue *q);
int front(Queue *q);
void display(Queue *q);

int main(){

    return 0;
}

Queue* init(){

}
bool isFull(Queue *q){
    return false;
}
bool isEmpty(Queue *q){
    return (q->front == NULL) ? true : false;
}
void enQ(Queue *q, int data){
    Node *newQ = malloc(sizeof(Node));
    newQ->data = data;
    newQ->next = NULL;
    if(isEmpty(q)){
        q->front = newQ:
        q->rear = newQ;
    } else {
        q->rear->next = newQ;
        q->rear = newQ;
    }
}
void deQ(Queue *q){
    Node *curr = q->front;
    curr->next = q->next;
    free(curr);
    if(isEmpty(q)){
        q->rear = NULL;
    }


}
int front(Queue *q){

}
void display(Queue *q){

}