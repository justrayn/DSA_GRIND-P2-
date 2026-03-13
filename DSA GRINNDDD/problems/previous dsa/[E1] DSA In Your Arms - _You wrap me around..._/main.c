#include <stdio.h>
#include <stdbool.h>
#include "myheader.h"

// Add element to rear of queue
void enqueue(Queue *q, int elem) {
    if (isFull(*q)) {
        printf("Queue is full! Cannot enqueue %d.\n", elem);
        return;
    }
    
    // Calculate tail position: (front + length) % MAX_SIZE
    int tail = (q->front + q->length) % MAX_SIZE;
    q->array[tail] = elem;
    q->length++;
}

// Remove and return element from front of queue
int dequeue(Queue *q) {
    if (isEmpty(*q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1; // Return -1 to indicate error
    }
    
    int result = q->array[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->length--;
    
    return result;
}

// Test function to demonstrate the queue operations
int main() {
    Queue q = newQueue();
    int testcase;
    
    printf("Enter test case no.: ");
    scanf("%d", &testcase);
    
    printf("=== Circular Queue Demo (front + length implementation) ===\n\n");
    
    switch(testcase) {
        case 1:
            printf("1. Initial empty queue:\n");
            displayQueue(q);
            visualizeQueue(q);
            printf("isEmpty: %s, isFull: %s\n\n", isEmpty(q) ? "true" : "false", isFull(q) ? "true" : "false");
            break;
        case 2:
            printf("2. Enqueue first element:\n");
            enqueue(&q, 10);
            displayQueue(q);
            visualizeQueue(q);
            printf("Front element: %d\n", front(q));
            printf("Length: %d (contains 1 element)\n", q.length);
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
            enqueue(&q, 110);
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
            enqueue(&q, 110);
            printf("Dequeued: %d\n", dequeue(&q));
            printf("Dequeued: %d\n", dequeue(&q));
            printf("Dequeued: %d\n", dequeue(&q));
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
            enqueue(&q, 110);
            printf("Dequeued: %d\n", dequeue(&q));
            printf("Dequeued: %d\n", dequeue(&q));
            printf("Dequeued: %d\n", dequeue(&q));
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
            enqueue(&q, 110);
            dequeue(&q);
            dequeue(&q);
            dequeue(&q);
            enqueue(&q, 200);
            enqueue(&q, 300);
            enqueue(&q, 400);
            while (!isEmpty(q)) {
                dequeue(&q);
            }
            dequeue(&q);
            displayQueue(q);
            visualizeQueue(q);
            printf("isEmpty: %s, isFull: %s\n", isEmpty(q) ? "true" : "false", isFull(q) ? "true" : "false");
            break;
        case 10:
            printf("\n10. Test front advancement and circular wraparound:\n");
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
            dequeue(&q);
            dequeue(&q);
            dequeue(&q);
            enqueue(&q, 200);
            enqueue(&q, 300);
            enqueue(&q, 400);
            while (!isEmpty(q)) {
                dequeue(&q);
            }
            dequeue(&q);
            enqueue(&q, 999);
            displayQueue(q);
            visualizeQueue(q);
            printf("Front starts at index: %d\n", q.front);
            printf("isEmpty: %s, isFull: %s\n", isEmpty(q) ? "true" : "false", isFull(q) ? "true" : "false");
            break;
        case 11:
            printf("\n11. Test makeEmpty function:\n");
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
            dequeue(&q);
            dequeue(&q);
            dequeue(&q);
            enqueue(&q, 200);
            enqueue(&q, 300);
            enqueue(&q, 400);
            while (!isEmpty(q)) {
                dequeue(&q);
            }
            dequeue(&q);
            enqueue(&q, 999);
            enqueue(&q, 111);
            enqueue(&q, 222);
            printf("Before makeEmpty:\n");
            displayQueue(q);
            makeEmpty(&q);
            printf("After makeEmpty:\n");
            displayQueue(q);
            visualizeQueue(q);
            printf("isEmpty: %s, isFull: %s\n", isEmpty(q) ? "true" : "false", isFull(q) ? "true" : "false");
            break;
        case 12:
            printf("\n12. Test wraparound behavior:\n");
            // Set front to near end to test wraparound
            q.front = 8;
            q.length = 0;
            enqueue(&q, 777);
            enqueue(&q, 888);
            enqueue(&q, 999);
            printf("Front at index 8, enqueue 3 elements:\n");
            displayQueue(q);
            visualizeQueue(q);
            printf("isEmpty: %s, isFull: %s\n", isEmpty(q) ? "true" : "false", isFull(q) ? "true" : "false");
            break;
        default:
            printf("Invalid Input.\n");
    }
    
    return 0;
}