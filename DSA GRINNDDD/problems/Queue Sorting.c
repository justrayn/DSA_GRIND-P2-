#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10

typedef struct{
    int items[MAX];
    int front;
    int rear;
}Queue;

Queue* initialize();
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
bool isFull(Queue* q);
bool isEmpty(Queue* q);
void display(Queue* q);
void sortQ(Queue* q);

int main(){
    
    Queue *q = initialize();
    int size;
    
    printf("Enter the size of the queue: ");
    scanf("%d", &size);
    printf("Enter %d integers to add to the queue: ", size);
    for(int i = 0 ; i < size; i++){
        int data;
        scanf("%d", &data);
        enqueue(q, data);
    }
    sortQ(q);
    printf("Sorted queue: ");
    display(q);
    
    
    return 0;
}
Queue* initialize(){
    Queue *newQ = malloc(sizeof(Queue));
    if(newQ != NULL){
        newQ->front = 0;
        newQ->rear = -1;
        return newQ;
    }
}
void enqueue(Queue* q, int value){
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
}
int dequeue(Queue* q){
    int val = q->items[q->front];
     q->front = (q->front + 1) % MAX;
    return val;
}
bool isFull(Queue* q){
    return (q->front == (q->rear + 2) % MAX) ? true : false;
}
bool isEmpty(Queue* q){
    return (q->front == (q->rear + 1) % MAX) ? true : false;
}
void display(Queue* q){
   if(!isEmpty(q)){
       Queue *tempQ = initialize();
       
       while(!isEmpty(q)){
           int val = dequeue(q);
           printf("%d ", val);
           enqueue(tempQ, val);
       }
       
       printf("\n");
       
       while(!isEmpty(tempQ)){
           enqueue(q, dequeue(tempQ));
       }
       
       free(tempQ);
   }
}

void sortQ(Queue* q) {
    if (isEmpty(q)) return;

    Queue *sortedQ = initialize();

    while (!isEmpty(q)) {
        int minVal = dequeue(q);
        Queue *tempQ = initialize();

        // Find the minimum
        while (!isEmpty(q)) {
            int current = dequeue(q);

            if (current < minVal) {
                enqueue(tempQ, minVal);
                minVal = current;
            } else {
                enqueue(tempQ, current);
            }
        }

        // Restore remaining elements
        while (!isEmpty(tempQ)) {
            enqueue(q, dequeue(tempQ));
        }

        free(tempQ);

        // Add minimum to sorted queue
        enqueue(sortedQ, minVal);
    }

    // Copy back to original queue
    while (!isEmpty(sortedQ)) {
        enqueue(q, dequeue(sortedQ));
    }

    free(sortedQ);
}