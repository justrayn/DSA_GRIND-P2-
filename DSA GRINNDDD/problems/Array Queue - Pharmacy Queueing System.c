#include <stdio.h>
#include <stdlib.h>
#include "arrayQueue.h"
#include "types.h"

int main() {
    // write your code here
    Queue *regQ = initialize();
    int cust = 0;
    Queue *prioQ = initialize();
    while(1){
        int choice;
        printf("--- Pharmacy Queueing System ---\n1. Enter Regular Queue\n2. Enter Priority Queue\n3. Call Next Customer\n4. Display Queues\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
            if(!isFull(regQ)){
                cust++;
            enqueue(regQ, cust);
            printf("You have entered the Regular queue. Your number is %d.\n\n", cust);
            } else if(isFull(regQ)) {
                printf("Regular queue is full. Please try again later.\n\n");
            }
            break;
            
            case 2:
            if(!isFull(prioQ)){
            cust++;
            enqueue(prioQ, cust);
            printf("You have entered the Priority queue. Your number is %d.\n\n",cust);
            }  else if(isFull(regQ)) {
                printf("Priority queue is full. Please try again later.\n\n");
            }
            break;
            
            case 3:
            if(!isEmpty(prioQ) ){
                int calledcust = dequeue(prioQ);
                printf("Calling next customer from Priority Queue. Customer number: %d\n\n", calledcust);
            } else if(isEmpty(prioQ)&& !isEmpty(regQ)){
                int calledcust = dequeue(regQ);
                printf("Calling next customer from Regular Queue. Customer number: %d\n\n", calledcust);
    
            }
            
            break;
            
            case 4:
            printf("\n-- Current Queue Status --\n");
            printf("Regular Queue: ");
            display(regQ);
            printf("\nPriority Queue: ");
            display(prioQ);
            printf("\n\n");
            break;
            
            case 5:
            printf("Exiting program. Goodbye!");
            exit(1);
            break;
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "types.h"

// write your functions here

Queue* initialize(){
    Queue *newQ = malloc(sizeof(Queue));
    if(newQ != NULL){
        newQ->front = -1;
        newQ->rear = -1;
        newQ->list.count = 0;
        return newQ;
    }
}
void enqueue(Queue* q, int value){
    if(!isFull(q)){
        if(isEmpty(q)){
            q->front = 0;
            q->rear = 0;
        } else {
            q->rear = (q->rear + 1) % MAX;
        }
        
        q->list.count++;
        q->list.items[q->rear] = value;
    }
}
int dequeue(Queue* q){
    if(!isEmpty(q)){
        int val = q->list.items[q->front];
       if(q->list.count == 1){
           q->rear = -1;
           q->front = -1;
       } else {
           q->front = (q->front + 1) % MAX;
       }
       q->list.count--;
       return val;
    }
}
bool isFull(Queue* q){
    return (q->rear == MAX -1) ? true : false;
}
bool isEmpty(Queue* q){
    return (q->list.count == 0) ? true : false;
}
void display(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty.");
    }
    
        Queue* tempQ = initialize();
        while(!isEmpty(q)){
            int val = dequeue(q);
            printf("%d ", val);
            enqueue(tempQ, val);
        }
        
        while(!isEmpty(tempQ)){
            int val = dequeue(tempQ);
            enqueue(q, val);
        }
        free(tempQ);
    
}