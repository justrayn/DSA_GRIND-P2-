#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void enqueue(Queue *q, Customer c) {
    q->count++;
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = c;
    int data = q->rear;
    printf("%s added to queue\n", c.name);
}

Customer dequeue(Queue *q) {
    Customer tempC = q->data[q->front];
    q->front = (q->front + 1) % MAX;
    q->count--;
    return tempC;
}

void serveCustomer(Queue *q, int *tickets) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    Customer tempC = dequeue(q);

    printf("Serving %s...\n", tempC.name);

    if (*tickets == 0) {
        printf("No tickets left for %s\n", tempC.name);
        printf("Remaining tickets: 0\n\n");
        return;
    }

    if (*tickets >= tempC.ticketsRequested) {
        *tickets -= tempC.ticketsRequested;

        printf("Booked %d tickets for %s\n",
               tempC.ticketsRequested, tempC.name);
        printf("Remaining tickets: %d\n\n", *tickets);
    } else {
        printf("Only %d tickets left. Partial booking for %s\n",
               *tickets, tempC.name);

        *tickets = 0;

        printf("Remaining tickets: 0\n\n");
    }
}

// typedef struct {
//     char name[20];
//     int ticketsRequested;
// } Customer;

// typedef struct {
//     Customer data[MAX];
//     int front, rear, count;
// } Queue;


// [E1] - Ticket Booking System - QUEUE
// by Edrian Guanzon

// A ticket booking system is used to manage reservations for a limited number of tickets in events, movies, or transportation. Customers arrive in a queue and request a certain number of tickets. The system serves customers in a first-come, first-served order. If there are not enough tickets, the system either partially fulfills the request or rejects it. Implement the queue as a circular array to efficiently reuse memory.

 

// Objective

// Must provide the following options:
// Add Customer – enqueue a new customer into the queue
// Serve Customer – dequeue the first customer and allocate tickets
// Display Queue – show all customers in the current queue with requested tickets
// Exit – terminate the program
// The system should:
// Track the total available tickets
// Reduce the available tickets when a customer is served
// Handle partial allocation if tickets are insufficient
// Print messages indicating success, partial allocation, or sold-out status
 

// Function Definition

// enqueue() -> Adds customer to ticket booking queue
// dequeue() -> removes customer from ticket booking queue after serving the customer
// serveCustomer() -> removes the first customer from the ticket booking queue and allocates tickets according to their request. It also updates the total available tickets. Print messages for the following scenarios:
// Full allocation: The customer's request is fully satisfied.
// Partial allocation: Only some of the requested tickets are available. the function allocates what remains.
// No tickets left: The request cannot be fulfiled because the tickets are sold out.
// Sample Output 1

// Enter total tickets: 5

// ===== TICKET SYSTEM =====
// 1. Add Customer
// 2. Serve Customer
// 3. Display Queue
// 4. Exit
// Choose: 1
// Enter name: Alice
// Tickets requested: 2
// Alice added to queue

// ===== TICKET SYSTEM =====
// 1. Add Customer
// 2. Serve Customer
// 3. Display Queue
// 4. Exit
// Choose: 1
// Enter name: Bob
// Tickets requested: 3
// Bob added to queue

// ===== TICKET SYSTEM =====
// 1. Add Customer
// 2. Serve Customer
// 3. Display Queue
// 4. Exit
// Choose: 3

// Current Queue:
// 1. Alice (2 tickets)
// 2. Bob (3 tickets)


// ===== TICKET SYSTEM =====
// 1. Add Customer
// 2. Serve Customer
// 3. Display Queue
// 4. Exit
// Choose: 2
// Serving Alice...
// Booked 2 tickets for Alice
// Remaining tickets: 3


// ===== TICKET SYSTEM =====
// 1. Add Customer
// 2. Serve Customer
// 3. Display Queue
// 4. Exit
// Choose: 3

// Current Queue:
// 1. Bob (3 tickets)


// ===== TICKET SYSTEM =====
// 1. Add Customer
// 2. Serve Customer
// 3. Display Queue
// 4. Exit
// Choose: 2
// Serving Bob...
// Booked 3 tickets for Bob
// Remaining tickets: 0


// ===== TICKET SYSTEM =====
// 1. Add Customer
// 2. Serve Customer
// 3. Display Queue
// 4. Exit
// Choose: 3
// Queue is empty

// ===== TICKET SYSTEM =====
// 1. Add Customer
// 2. Serve Customer
// 3. Display Queue
// 4. Exit
// Choose: 4
// Exiting system...
// Sample Output 2

// Enter total tickets: 5

// ===== TICKET SYSTEM =====
// 1. Add Customer
// 2. Serve Customer
// 3. Display Queue
// 4. Exit
// Choose: 1
// Enter name: Alice
// Tickets requested: 6
// Alice added to queue

// ===== TICKET SYSTEM =====
// 1. Add Customer
// 2. Serve Customer
// 3. Display Queue
// 4. Exit
// Choose: 3

// Current Queue:
// 1. Alice (6 tickets)


// ===== TICKET SYSTEM =====
// 1. Add Customer
// 2. Serve Customer
// 3. Display Queue
// 4. Exit
// Choose: 2
// Serving Alice...
// Only 5 tickets left. Partial booking for Alice
// Remaining tickets: 0


// ===== TICKET SYSTEM =====
// 1. Add Customer
// 2. Serve Customer
// 3. Display Queue
// 4. Exit
// Choose: 4
// Exiting system...
// Sample Output 3

// Enter total tickets: 5

// ===== TICKET SYSTEM =====
// 1. Add Customer
// 2. Serve Customer
// 3. Display Queue
// 4. Exit
// Choose: 1
// Enter name: Alice
// Tickets requested: 2
// Alice added to queue

// ===== TICKET SYSTEM =====
// 1. Add Customer
// 2. Serve Customer
// 3. Display Queue
// 4. Exit
// Choose: 1
// Enter name: Bob
// Tickets requested: 3
// Bob added to queue

// ===== TICKET SYSTEM =====
// 1. Add Customer
// 2. Serve Customer
// 3. Display Queue
// 4. Exit
// Choose: 1
// Enter name: Dave
// Tickets requested: 2
// Dave added to queue

// ===== TICKET SYSTEM =====
// 1. Add Customer
// 2. Serve Customer
// 3. Display Queue
// 4. Exit
// Choose: 3

// Current Queue:
// 1. Alice (2 tickets)
// 2. Bob (3 tickets)
// 3. Dave (2 tickets)


// ===== TICKET SYSTEM =====
// 1. Add Customer
// 2. Serve Customer
// 3. Display Queue
// 4. Exit
// Choose: 2
// Serving Alice...
// Booked 2 tickets for Alice
// Remaining tickets: 3


// ===== TICKET SYSTEM =====
// 1. Add Customer
// 2. Serve Customer
// 3. Display Queue
// 4. Exit
// Choose: 3

// Current Queue:
// 1. Bob (3 tickets)
// 2. Dave (2 tickets)


// ===== TICKET SYSTEM =====
// 1. Add Customer
// 2. Serve Customer
// 3. Display Queue
// 4. Exit
// Choose: 2
// Serving Bob...
// Booked 3 tickets for Bob
// Remaining tickets: 0


// ===== TICKET SYSTEM =====
// 1. Add Customer
// 2. Serve Customer
// 3. Display Queue
// 4. Exit
// Choose: 3

// Current Queue:
// 1. Dave (2 tickets)


// ===== TICKET SYSTEM =====
// 1. Add Customer
// 2. Serve Customer
// 3. Display Queue
// 4. Exit
// Choose: 2
// Serving Dave...
// No tickets left for Dave
// Remaining tickets: 0


// ===== TICKET SYSTEM =====
// 1. Add Customer
// 2. Serve Customer
// 3. Display Queue
// 4. Exit
// Choose: 3
// Queue is empty

// ===== TICKET SYSTEM =====
// 1. Add Customer
// 2. Serve Customer
// 3. Display Queue
// 4. Exit
// Choose: 4
// Exiting system...