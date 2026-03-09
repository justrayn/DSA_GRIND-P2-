#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10 

typedef struct {
    int items[MAX];
    int front;
    int rear;
}Queue;

Queue* init();
bool isEmpty(Queue* q);
bool isFull(Queue* q);
void enqueue(Queue* q, int val);
int dequeue(Queue* q);
int front(Queue *q);
void display(Queue *q);

int main(){




    return 0;
}


Queue* init(){
    Queue *newQ = malloc(sizeof(Queue));
    if(newQ != NULL){
        newQ->front = 0;
        newQ->rear = -1;
        return newQ;
    }
}
bool isEmpty(Queue* q){
    return (q->front == (q->rear + 1) % MAX);
}
bool isFull(Queue* q){
    return (q->front == (q->rear + 2) % MAX);
}
void enqueue(Queue* q, int val){
    
}
int dequeue(Queue* q){

}
int front(Queue *q){

}
void display(Queue *q){

}