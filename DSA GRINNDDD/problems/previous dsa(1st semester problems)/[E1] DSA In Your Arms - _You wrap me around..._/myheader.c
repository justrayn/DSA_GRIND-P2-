#include <stdio.h>
#include <stdbool.h>
#include "myheader.h"

// Initialize a new queue
Queue newQueue() {
    Queue q;
    q.front = 0;
    q.length = 0;
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
    return (q.length == 0);
}

// Check if queue is full
bool isFull(Queue q) {
    return (q.length == MAX_SIZE);
}

// Make queue empty
void makeEmpty(Queue *q) {
    q->front = 0;
    q->length = 0;
}

// Display queue contents in Q {elem1, elem2, elem3} format
void displayQueue(Queue q) {
    if (isEmpty(q)) {
        printf("Q {}\n");
        return;
    }
    
    printf("Q {");
    for (int i = 0; i < q.length; i++) {
        if (i > 0) {
            printf(", ");
        }
        int index = (q.front + i) % MAX_SIZE;
        printf("%d", q.array[index]);
    }
    printf("}\n");
}

// Visualize queue in tabular format
void visualizeQueue(Queue q) {
    printf("\n+-------+--------+----------+\n");
    printf("| INDEX |  DATA  |   REF    |\n");
    printf("+-------+--------+----------+\n");
    
    // Calculate tail position
    int tail = (q.length > 0) ? (q.front + q.length - 1) % MAX_SIZE : -1;
    
    for (int i = 0; i < MAX_SIZE; i++) {
        // Determine if this index contains valid data
        bool hasData = false;
        
        if (!isEmpty(q)) {
            for (int j = 0; j < q.length; j++) {
                if (i == (q.front + j) % MAX_SIZE) {
                    hasData = true;
                    break;
                }
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
        } else if (q.length == 1 && i == q.front) {
            printf(" %-8s |\n", "F,T");
        } else if (i == q.front) {
            printf(" %-8s |\n", "F");
        } else if (i == tail) {
            printf(" %-8s |\n", "T");
        } else {
            printf(" %-8s |\n", "");
        }
    }
    
    printf("+-------+--------+----------+\n");
    printf("Front: %d, Length: %d", q.front, q.length);
    if (!isEmpty(q)) {
        printf(", Tail: %d", tail);
    }
    printf("\n");
}