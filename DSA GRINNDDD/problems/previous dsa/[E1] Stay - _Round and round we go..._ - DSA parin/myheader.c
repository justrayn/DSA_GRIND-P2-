#include <stdio.h>
#include <stdbool.h>
#include "myheader.h"

// Initialize a new queue
Queue newQueue() {
    Queue q;
    q.front = -1;
    q.rear = -1;
    return q;
}

// Return front element without removing it
int front(Queue q) {
    if (isEmpty(q)) {
        printf("Queue is empty! No front element.\n");
        return -1; // Return -1 to indicate error
    }
    
    return q.array[q.front];
}

// Check if queue is empty
bool isEmpty(Queue q) {
    return (q.front == -1 && q.rear == -1);
}

// Check if queue is full
bool isFull(Queue q) {
    return ((q.rear + 1) % MAX_SIZE == q.front && q.front != -1);
}

// Make queue empty
void makeEmpty(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Display queue contents in Q {elem1, elem2, elem3} format
void displayQueue(Queue q) {
    if (isEmpty(q)) {
        printf("Q {}\n");
        return;
    }
    
    printf("Q {");
    int current = q.front;
    bool first = true;
    
    while (true) {
        if (!first) {
            printf(", ");
        }
        printf("%d", q.array[current]);
        first = false;
        
        if (current == q.rear) {
            break;
        }
        current = (current + 1) % MAX_SIZE;
    }
    
    printf("}\n");
}

// Visualize queue in tabular format
void visualizeQueue(Queue q) {
    printf("\n+-------+--------+----------+\n");
    printf("| INDEX |  DATA  |   REF    |\n");
    printf("+-------+--------+----------+\n");
    
    for (int i = 0; i < MAX_SIZE; i++) {
        // Determine if this index contains valid data
        bool hasData = false;
        
        if (!isEmpty(q)) {
            if (q.front <= q.rear) {
                // Normal case: front <= rear
                hasData = (i >= q.front && i <= q.rear);
            } else {
                // Wraparound case: rear < front
                hasData = (i >= q.front || i <= q.rear);
            }
        }
        
        printf("| %5d | ", i);
        if (hasData) {
            printf("%6d |", q.array[i]);
        } else {
            printf("%6s |", "");
        }
        
        // Determine reference
        if (isEmpty(q)) {
            printf(" %-8s |\n", "");
        } else if (i == q.front && i == q.rear) {
            printf(" %-8s |\n", "F,R");
        } else if (i == q.front) {
            printf(" %-8s |\n", "F");
        } else if (i == q.rear) {
            printf(" %-8s |\n", "R");
        } else {
            printf(" %-8s |\n", "");
        }
    }
    
    printf("+-------+--------+----------+\n");
    printf("Front: %d, Rear: %d\n", q.front, q.rear);
}