#include <stdio.h>
#include "header.h"

int main() {
    Queue q;
    initQueue(&q);

    int tickets;
    printf("Enter total tickets: ");
    scanf("%d", &tickets);

    int choice;

    while (1) {
        printf("\n===== TICKET SYSTEM =====\n");
        printf("1. Add Customer\n");
        printf("2. Serve Customer\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        if (choice == 1) {
            Customer c;
            printf("Enter name: ");
            scanf("%s", c.name);
            printf("Tickets requested: ");
            scanf("%d", &c.ticketsRequested);

            enqueue(&q, c);

        } else if (choice == 2) {
            serveCustomer(&q, &tickets);

        } else if (choice == 3) {
            displayQueue(&q);

        } else if (choice == 4) {
            printf("Exiting system...\n");
            break;

        } else {
            printf("❌ Invalid choice\n");
        }
    }

    return 0;
}