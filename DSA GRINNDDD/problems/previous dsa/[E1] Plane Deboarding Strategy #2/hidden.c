#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

// Function to display the current state of the boarding list.
void displayBoardingList(const BoardingList* list) {
    printf("\n--- Current Boarding List State ---\n\n");
    printf("     A        B        C       |   D        E        F\n");
    printf("  ----------------------------------------------------------\n");
    for (int i = 0; i < MAX_ROWS; i++) {
        // Prepare seat values for ABC (v1: bottom is A, top is C)
        char a[30] = "-", b[30] = "-", c[30] = "-";
        int abcTop = list->seatRows[i].ABC.top;
        if (abcTop >= 0 && strlen(list->seatRows[i].ABC.p[0].passengerName) > 0)
            strcpy(a, list->seatRows[i].ABC.p[0].passengerName);
        if (abcTop >= 1 && strlen(list->seatRows[i].ABC.p[1].passengerName) > 0)
            strcpy(b, list->seatRows[i].ABC.p[1].passengerName);
        if (abcTop >= 2 && strlen(list->seatRows[i].ABC.p[2].passengerName) > 0)
            strcpy(c, list->seatRows[i].ABC.p[2].passengerName);

        // Prepare seat values for DEF (v2: bottom is F, top is D)
        char d[30] = "-", e[30] = "-", f[30] = "-";
        int defTop = list->seatRows[i].DEF.top;
        // v2: top starts at MAX_PASSENGERS (empty), decreases as pushed
        // So, DEF.p[2] = F, DEF.p[1] = E, DEF.p[0] = D
        if (defTop <= 2 && strlen(list->seatRows[i].DEF.p[2].passengerName) > 0)
            strcpy(f, list->seatRows[i].DEF.p[2].passengerName);
        if (defTop <= 1 && strlen(list->seatRows[i].DEF.p[1].passengerName) > 0)
            strcpy(e, list->seatRows[i].DEF.p[1].passengerName);
        if (defTop <= 0 && strlen(list->seatRows[i].DEF.p[0].passengerName) > 0)
            strcpy(d, list->seatRows[i].DEF.p[0].passengerName);

        printf("%-1d | %-8s %-8s %-8s |  %-8s %-8s %-8s\n", i + 1, a, b, c, d,
               e, f);
    }
    printf("   ---------------------------------------------------------\n");
    printf("\nTotal passengers remaining: %d\n", list->passengerCount);
    printf("-----------------------------------\n");
}

// Mixed passengers
void initializeBoardingList1(BoardingList* list) {
    printf("Populating boarding list 1...\n");
    list->passengerCount = 0;

    // Initialize all groups as empty
    for (int i = 0; i < MAX_ROWS; i++) {
        initializeStack_v1(&list->seatRows[i].ABC);
        initializeStack_v2(&list->seatRows[i].DEF);
    }

    // Row 1
    push_v1(&list->seatRows[0].ABC, "John");
    push_v1(&list->seatRows[0].ABC, "Mary");
    push_v1(&list->seatRows[0].ABC, "Bob");
    push_v2(&list->seatRows[0].DEF, "Eve");
    push_v2(&list->seatRows[0].DEF, "Sam");
    list->passengerCount += 5;

    // Row 2
    push_v1(&list->seatRows[1].ABC, "Linda");
    push_v2(&list->seatRows[1].DEF, "Alice");
    push_v2(&list->seatRows[1].DEF, "Tom");
    list->passengerCount += 3;

    // Row 3
    push_v1(&list->seatRows[2].ABC, "Peter");
    push_v1(&list->seatRows[2].ABC, "Jane");
    list->passengerCount += 2;

    // Row 4 (empty groups to test the skipping logic)

    // Row 5
    push_v1(&list->seatRows[4].ABC, "Chris");
    push_v1(&list->seatRows[4].ABC, "Anna");
    push_v2(&list->seatRows[4].DEF, "Mike");
    push_v2(&list->seatRows[4].DEF, "Sue");
    push_v2(&list->seatRows[4].DEF, "Tim");
    list->passengerCount += 5;

    // Row 6
    push_v1(&list->seatRows[5].ABC, "David");
    push_v2(&list->seatRows[5].DEF, "Kate");
    push_v2(&list->seatRows[5].DEF, "Rob");
    list->passengerCount += 3;

    // Row 7 (empty groups)

    // Row 8
    push_v1(&list->seatRows[7].ABC, "Sammy");
    push_v1(&list->seatRows[7].ABC, "Liz");
    push_v2(&list->seatRows[7].DEF, "Nancy");
    push_v2(&list->seatRows[7].DEF, "Paul");
    list->passengerCount += 4;

    printf("Boarding list 1 populated with %d passengers.\n",
           list->passengerCount);
}

// More passengers, different distribution
void initializeBoardingList2(BoardingList* list) {
    printf("Populating boarding list 2...\n");
    list->passengerCount = 0;

    for (int i = 0; i < MAX_ROWS; i++) {
        initializeStack_v1(&list->seatRows[i].ABC);
        initializeStack_v2(&list->seatRows[i].DEF);
    }

    // Row 1
    push_v1(&list->seatRows[0].ABC, "Alice");
    push_v1(&list->seatRows[0].ABC, "Ben");
    push_v2(&list->seatRows[0].DEF, "Carl");
    push_v2(&list->seatRows[0].DEF, "Diana");
    list->passengerCount += 4;

    // Row 2
    push_v1(&list->seatRows[1].ABC, "Eli");
    push_v1(&list->seatRows[1].ABC, "Fay");
    push_v1(&list->seatRows[1].ABC, "Gina");
    push_v2(&list->seatRows[1].DEF, "Hank");
    list->passengerCount += 4;

    // Row 3
    push_v2(&list->seatRows[2].DEF, "Ivy");
    push_v2(&list->seatRows[2].DEF, "Jack");
    list->passengerCount += 2;

    // Row 4
    push_v1(&list->seatRows[3].ABC, "Kim");
    push_v1(&list->seatRows[3].ABC, "Leo");
    push_v2(&list->seatRows[3].DEF, "Mona");
    list->passengerCount += 3;

    // Row 5
    push_v1(&list->seatRows[4].ABC, "Nina");
    push_v2(&list->seatRows[4].DEF, "Oscar");
    list->passengerCount += 2;

    // Row 6
    push_v1(&list->seatRows[5].ABC, "Pam");
    push_v1(&list->seatRows[5].ABC, "Quinn");
    push_v2(&list->seatRows[5].DEF, "Ray");
    push_v2(&list->seatRows[5].DEF, "Sue");
    push_v2(&list->seatRows[5].DEF, "Ted");
    list->passengerCount += 5;

    // Row 7
    push_v1(&list->seatRows[6].ABC, "Uma");
    list->passengerCount += 1;

    // Row 8
    push_v2(&list->seatRows[7].DEF, "Vic");
    push_v2(&list->seatRows[7].DEF, "Will");
    push_v2(&list->seatRows[7].DEF, "Xena");
    list->passengerCount += 3;

    printf("Boarding list 2 populated with %d passengers.\n",
           list->passengerCount);
}

// Fewer passengers, clustered at the back
void initializeBoardingList3(BoardingList* list) {
    printf("Populating boarding list 3...\n");
    list->passengerCount = 0;

    for (int i = 0; i < MAX_ROWS; i++) {
        initializeStack_v1(&list->seatRows[i].ABC);
        initializeStack_v2(&list->seatRows[i].DEF);
    }

    // Row 5
    push_v1(&list->seatRows[4].ABC, "Zack");
    push_v2(&list->seatRows[4].DEF, "Yara");
    list->passengerCount += 2;

    // Row 6
    push_v1(&list->seatRows[5].ABC, "Wendy");
    push_v1(&list->seatRows[5].ABC, "Vera");
    push_v2(&list->seatRows[5].DEF, "Ulysses");
    list->passengerCount += 3;

    // Row 7
    push_v1(&list->seatRows[6].ABC, "Tim");
    push_v2(&list->seatRows[6].DEF, "Sophie");
    list->passengerCount += 2;

    // Row 8
    push_v1(&list->seatRows[7].ABC, "Ron");
    push_v1(&list->seatRows[7].ABC, "Quincy");
    push_v2(&list->seatRows[7].DEF, "Pat");
    push_v2(&list->seatRows[7].DEF, "Olga");
    list->passengerCount += 4;

    printf("Boarding list 3 populated with %d passengers.\n",
           list->passengerCount);
}

// All seats full
void initializeBoardingList4(BoardingList* list) {
    printf("Populating boarding list with all seats full...\n");
    list->passengerCount = 0;

    // Initialize all groups as empty
    for (int i = 0; i < MAX_ROWS; i++) {
        initializeStack_v1(&list->seatRows[i].ABC);
        initializeStack_v2(&list->seatRows[i].DEF);
    }

    // Fill every seat in every row with unique passenger names
    char name[30];
    int passengerNum = 1;
    for (int i = 0; i < MAX_ROWS; i++) {
        // Fill ABC (left side)
        for (int j = 0; j < MAX_PASSENGERS; j++) {
            snprintf(name, sizeof(name), "P%d", passengerNum++);
            push_v1(&list->seatRows[i].ABC, name);
            list->passengerCount++;
        }
        // Fill DEF (right side)
        for (int j = 0; j < MAX_PASSENGERS; j++) {
            snprintf(name, sizeof(name), "P%d", passengerNum++);
            push_v2(&list->seatRows[i].DEF, name);
            list->passengerCount++;
        }
    }

    printf("Full boarding list populated with %d passengers.\n",
           list->passengerCount);
}