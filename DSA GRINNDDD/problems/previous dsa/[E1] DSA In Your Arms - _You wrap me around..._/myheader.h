#ifndef MYHEADER_H
#define MYHEADER_H

#include <stdbool.h>

#define MAX_SIZE 10

// Queue structure using front and length
typedef struct {
    int array[MAX_SIZE];
    int front;
    int length;
} Queue;

// Function prototypes
Queue newQueue();
void enqueue(Queue *q, int elem);
int dequeue(Queue *q);
int front(Queue q);
bool isEmpty(Queue q);
bool isFull(Queue q);
void makeEmpty(Queue *q);
void displayQueue(Queue q);
void visualizeQueue(Queue q);

#endif