#include <stdio.h>
#include <stdbool.h>
#include "myheader.h"

// Add element to rear of queue
void enqueue(Queue *q, int elem) {
    if (isFull(*q)) {
        printf("Queue is full! Cannot enqueue %d.\n", elem);
        return;
    }
    
    if (isEmpty(*q)) {
        // First element must go to index 0
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX_SIZE;
    }
    
    q->array[q->rear] = elem;
}

// Remove and return element from front of queue
int dequeue(Queue *q) {
    if (isEmpty(*q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1; // Return -1 to indicate error
    }
    
    int result = q->array[q->front];
    
    // If queue becomes empty after dequeue
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
    }
    
    return result;
}

// Test function to demonstrate the queue operations
int main() {
    Queue q = newQueue();
    int choice;
    
    printf("Enter test case choice: ");
    scanf("%d", &choice);
    
    printf("=== Circular Queue Demo (front=-1, rear=-1 when empty) ===\n\n");
    
    switch(choice) {
        case 1:
            printf("1. Initial empty queue:\n");
            displayQueue(q);
            visualizeQueue(q);
            printf("isEmpty: %s, isFull: %s\n\n", isEmpty(q) ? "true" : "false", isFull(q) ? "true" : "false");
            break;
        case 2:
            printf("2. Enqueue first element (must go to index 0):\n");
            enqueue(&q, 10);
            displayQueue(q);
            visualizeQueue(q);
            printf("Front element: %d\n", front(q));
            printf("Front == Rear: %s (contains 1 element)\n", (q.front == q.rear) ? "true" : "false");
            printf("isEmpty: %s, isFull: %s\n\n", isEmpty(q) ? "true" : "false", isFull(q) ? "true" : "false");
            break;
        case 3:
            printf("3. Enqueue more elements:\n");
            enqueue(&q, 10);
            enqueue(&q, 20);
            enqueue(&q, 30);
            enqueue(&q, 40);
            displayQueue(q);
            visualizeQueue(q);
            printf("isEmpty: %s, isFull: %s\n\n", isEmpty(q) ? "true" : "false", isFull(q) ? "true" : "false");
            break;
        case 4:
            printf("4. Fill the queue completely:\n");
            enqueue(&q, 10);
            enqueue(&q, 20);
            enqueue(&q, 30);
            enqueue(&q, 40);
            enqueue(&q, 50);
            enqueue(&q, 60);
            enqueue(&q, 70);
            enqueue(&q, 80);
            enqueue(&q, 90);
            enqueue(&q, 100);
            displayQueue(q);
            visualizeQueue(q);
            printf("isEmpty: %s, isFull: %s\n\n", isEmpty(q) ? "true" : "false", isFull(q) ? "true" : "false");
            break;
        case 5:
        
            printf("5. Try to enqueue when full:\n");
            enqueue(&q, 10);
            enqueue(&q, 20);
            enqueue(&q, 30);
            enqueue(&q, 40);
            enqueue(&q, 50);
            enqueue(&q, 60);
            enqueue(&q, 70);
            enqueue(&q, 80);
            enqueue(&q, 90);
            enqueue(&q, 100);
            enqueue(&q, 110);
            displayQueue(q);
            visualizeQueue(q);
            printf("isEmpty: %s, isFull: %s\n\n", isEmpty(q) ? "true" : "false", isFull(q) ? "true" : "false");
            break;
        case 6:
            printf("\n6. Dequeue some elements:\n");
            enqueue(&q, 10);
            enqueue(&q, 20);
            enqueue(&q, 30);
            enqueue(&q, 40);
            enqueue(&q, 50);
            enqueue(&q, 60);
            enqueue(&q, 70);
            enqueue(&q, 80);
            enqueue(&q, 90);
            enqueue(&q, 100);
            printf("Dequeued: %d\n", dequeue(&q));
            printf("Dequeued: %d\n", dequeue(&q));
            printf("Dequeued: %d\n", dequeue(&q));
            displayQueue(q);
            visualizeQueue(q);
            printf("isEmpty: %s, isFull: %s\n\n", isEmpty(q) ? "true" : "false", isFull(q) ? "true" : "false");
            break;
        case 7:
            printf("\n7. Enqueue to demonstrate circular nature:\n");
            enqueue(&q, 10);
            enqueue(&q, 20);
            enqueue(&q, 30);
            enqueue(&q, 40);
            enqueue(&q, 50);
            enqueue(&q, 60);
            enqueue(&q, 70);
            enqueue(&q, 80);
            enqueue(&q, 90);
            enqueue(&q, 100);
            dequeue(&q);
            dequeue(&q);
            dequeue(&q);
            enqueue(&q, 200);
            enqueue(&q, 300);
            enqueue(&q, 400);
            displayQueue(q);
            visualizeQueue(q);
            printf("isEmpty: %s, isFull: %s\n\n", isEmpty(q) ? "true" : "false", isFull(q) ? "true" : "false");
            break;
        case 8:
            printf("\n8. Dequeue all elements to make empty:\n");
            enqueue(&q, 10);
            enqueue(&q, 20);
            enqueue(&q, 30);
            enqueue(&q, 40);
            enqueue(&q, 50);
            enqueue(&q, 60);
            enqueue(&q, 70);
            enqueue(&q, 80);
            enqueue(&q, 90);
            enqueue(&q, 100);
            dequeue(&q);
            dequeue(&q);
            dequeue(&q);
            enqueue(&q, 200);
            enqueue(&q, 300);
            enqueue(&q, 400);
            while (!isEmpty(q)) {
                printf("Dequeued: %d\n", dequeue(&q));
            }
            displayQueue(q);
            visualizeQueue(q);
            printf("isEmpty: %s, isFull: %s\n", isEmpty(q) ? "true" : "false", isFull(q) ? "true" : "false");
            break;  
        case 9:
            printf("\n9. Try to dequeue from empty queue:\n");
            enqueue(&q, 10);
            enqueue(&q, 20);
            enqueue(&q, 30);
            enqueue(&q, 40);
            enqueue(&q, 50);
            enqueue(&q, 60);
            enqueue(&q, 70);
            enqueue(&q, 80);
            enqueue(&q, 90);
            enqueue(&q, 100);
            dequeue(&q);
            dequeue(&q);
            dequeue(&q);
            enqueue(&q, 200);
            enqueue(&q, 300);
            enqueue(&q, 400);
            while (!isEmpty(q)) {
                printf("Dequeued: %d\n", dequeue(&q));
            }
            dequeue(&q);
            displayQueue(q);
            visualizeQueue(q);
            printf("isEmpty: %s, isFull: %s\n", isEmpty(q) ? "true" : "false", isFull(q) ? "true" : "false");
            break;
        case 10:
            printf("\n10. Test first element always goes to index 0:\n");
            enqueue(&q, 10);
            enqueue(&q, 20);
            enqueue(&q, 30);
            enqueue(&q, 40);
            enqueue(&q, 50);
            enqueue(&q, 60);
            enqueue(&q, 70);
            enqueue(&q, 80);
            enqueue(&q, 90);
            enqueue(&q, 100);
            dequeue(&q);
            dequeue(&q);
            dequeue(&q);
            enqueue(&q, 200);
            enqueue(&q, 300);
            enqueue(&q, 400);
            while (!isEmpty(q)) {
                printf("Dequeued: %d\n", dequeue(&q));
            }
            dequeue(&q);
            enqueue(&q, 999);
            displayQueue(q);
            visualizeQueue(q);
            printf("First element is at index: %d (should be 0)\n", q.front);
            printf("Front == Rear: %s (contains 1 element)\n", (q.front == q.rear) ? "true" : "false");       
            break;
        case 11:
            printf("\n11. Test makeEmpty function:\n");
            enqueue(&q, 111);
            enqueue(&q, 222);
            printf("Before makeEmpty:\n");
            displayQueue(q);
            makeEmpty(&q);
            printf("After makeEmpty:\n");
            displayQueue(q);
            visualizeQueue(q);
            break;
        default:
            printf("Invalid Input.");
    }
    
    return 0;
}