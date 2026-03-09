#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Function Prototypes for Variation 2
Queue* initialize();
bool isEmpty(Queue* q);
bool isFull(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int front(Queue* q);
void display(Queue* q);

int main (){

    Queue *q = initialize();
        int num, choice;
    do{
        printf("\nMenu:\n[1]: enqueue\n[2]: dequeue\n[3]: front\n[4]: Display\n[0]: Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                printf("Enter a number: ");
                scanf("%d", &num);
                enqueue(q, num);
                break;
            case 2:
                num = dequeue(q);
                if(num != -1){
                    printf("%d dequeued\n", num);
                }
                break;
            case 3:
                if(!isEmpty(q)){
                    printf("front element is %d\n", front(q));
                } else {
                    printf("Queue is empty.\n");
                }
                break;
            case 4:
                display(q);
                break;
            case 0:
                printf("Exiting...");
                free(q);
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }
    } while(choice != 0);

    return 0;
}

// Functions
Queue* initialize(){
    /*
    Allocate memory for the Queue structure
    Initialize front to 1 and rear to 0
    */

    Queue *newQueue = malloc(sizeof(Queue));
    newQueue->front = 0;
    newQueue->rear = -1;
    return newQueue;
}

bool isEmpty(Queue* q){
    // Queue is empty if front == (rear + 1) % MAX
    return (q->front == (q->rear + 1) % MAX);
}

bool isFull(Queue* q){
    // Queue is full if front == (rear + 2) % MAX
    return (q->front == (q->rear + 2) % MAX);
}

void enqueue(Queue* q, int value){
    /*
    Check if the queue is full
    Increment the rear pointer circularly (rear = (rear + 1) % MAX)
    Insert the new element at the new rear position
    */

    if(isFull(q)){
        printf("Queue is full.\n");
        return;
    }

    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
}

int dequeue(Queue* q){
    /*
    Check if the queue is empty
    Get the element at the front of the queue
    Increment the front pointer circularly (front = (front + 1) % MAX)
    Return the dequeued element
    */

    if(isEmpty(q)){
        printf("Queue is empty.\n");
        return -1;
    }

    int value = q->items[q->front];
    q->front = (q->front + 1) % MAX;
    return value;
}

int front(Queue* q){
    /*
    Check if the queue is empty
    Return the element at the current front position
    */

    if(isEmpty(q)){
        printf("Queue is empty.\n");
        return -1;
    }
    return q->items[q->front];
}

void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    Queue *tempQ = initialize();
    printf("Items: ");

    while (!isEmpty(q)) {
        int val = dequeue(q);
        printf("%d ", val);
        enqueue(tempQ, val);
    }
    printf("\n");

    // Put them back in the original queue
    while (!isEmpty(tempQ)) {
        enqueue(q, dequeue(tempQ));
    }
    free(tempQ);
}