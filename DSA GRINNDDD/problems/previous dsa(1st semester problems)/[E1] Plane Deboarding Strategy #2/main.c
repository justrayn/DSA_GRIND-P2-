#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

int main() {
    BoardingList list;
    int choice;

    printf("Select a boarding list to initialize:\n");
    printf("1. Mixed passengers\n");
    printf("2. More passengers, different distribution\n");
    printf("3. Fewer passengers, clustered at the back\n");
    printf("4. All seats full\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            initializeBoardingList1(&list);
            break;
        case 2:
            initializeBoardingList2(&list);
            break;
        case 3:
            initializeBoardingList3(&list);
            break;
        case 4:
            initializeBoardingList4(&list);
            break;
        default:
            printf("Invalid choice. Exiting.\n");
            return 1;
    }

    // Display the initial state
    displayBoardingList(&list);

    // Action menu
    int action;
    do {
        printf("\nSelect an action:\n");
        printf("1. Deplane passengers\n");
        printf("2. Display boarding list\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &action);

        switch (action) {
            case 1:
                deplanePassengers(&list);
                displayBoardingList(&list);
                break;
            case 2:
                displayBoardingList(&list);
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid action. Try again.\n");
        }
    } while (action != 0);

    return 0;
}