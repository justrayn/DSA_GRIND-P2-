#ifndef QUEUE_H
#define QUEUE_H

#define MAX 5

typedef struct {
    char name[20];
    int ticketsRequested;
} Customer;

typedef struct {
    Customer data[MAX];
    int front, rear, count;
} Queue;

void initQueue(Queue *q);
int isEmpty(Queue *q);
int isFull(Queue *q);
void enqueue(Queue *q, Customer c);
Customer dequeue(Queue *q);
void displayQueue(Queue *q);
void serveCustomer(Queue *q, int *tickets);

#endif