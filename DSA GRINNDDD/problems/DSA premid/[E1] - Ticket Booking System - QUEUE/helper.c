#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

int isEmpty(Queue *q) {
    return q->count == 0;
}

int isFull(Queue *q) {
    return q->count == MAX;
}

void displayQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    printf("\nCurrent Queue:\n");
    for (int i = 0; i < q->count; i++) {
        int index = (q->front + i) % MAX;
        printf("%d. %s (%d tickets)\n",
               i + 1,
               q->data[index].name,
               q->data[index].ticketsRequested);
    }
    printf("\n");
}