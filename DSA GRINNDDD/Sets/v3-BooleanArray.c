#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX 8

// Defines 'Set' as an array of 8 booleans
typedef bool Set[MAX];

// Function Prototypes (Updated to match professor's checklist)
void initialize(Set set);
void insert(Set set, int element);
void delete(Set set, int element); // Remember to compile as .c
bool find(Set set, int element);

// Added the third parameter 'Set C' to store the results
void setUnion(Set A, Set B, Set C);
void intersection(Set A, Set B, Set C); 
void difference(Set A, Set B, Set C);
void display(Set set);

int main() {
    Set A, B, C;

    // Initialize our sets to empty (all false)
    initialize(A);
    initialize(B);
    initialize(C);

    // Test Insert
    insert(A, 0);
    insert(A, 2);
    insert(A, 7);
    printf("Set A: ");
    display(A); // Expected: {0, 2, 7}

    // Set up B for math tests
    insert(B, 2);
    insert(B, 4);
    insert(B, 5);
    printf("Set B: ");
    display(B); // Expected: {2, 4, 5}

    // Test Union
    setUnion(A, B, C);
    printf("Union of A and B: ");
    display(C); // Expected: {0, 2, 4, 5, 7}

    // Test Intersection
    intersection(A, B, C);
    printf("Intersection of A and B: ");
    display(C); // Expected: {2}

    // Test Difference
    difference(A, B, C);
    printf("Difference (A - B): ");
    display(C); // Expected: {0, 7}

    // Test Delete
    delete(A, 0);
    delete(A, 7);
    printf("Set A after deleting 0 and 7: ");
    display(A); // Expected: {2}

    return 0;
}

// ---------------- Implementation ----------------

void initialize(Set set) {
    for (int i = 0; i < MAX; i++) {
        set[i] = false;
    }
}

void insert(Set set, int element) {
    // Safety check
    if (element >= 0 && element < MAX) {
        set[element] = true;
    }
}

void delete(Set set, int element) {
    // Safety check
    if (element >= 0 && element < MAX) {
        set[element] = false;
    }
}

bool find(Set set, int element) {
    // Safety check
    if (element >= 0 && element < MAX) {
        return set[element];
    }
    return false;
}

void setUnion(Set A, Set B, Set C) {
    for (int i = 0; i < MAX; i++) {
        // True if in A OR in B
        C[i] = A[i] || B[i];
    }
}

void intersection(Set A, Set B, Set C) {
    for (int i = 0; i < MAX; i++) {
        // True if in A AND in B
        C[i] = A[i] && B[i];
    }
}

void difference(Set A, Set B, Set C) {
    for (int i = 0; i < MAX; i++) {
        // True ONLY if in A AND NOT in B
        C[i] = A[i] && !B[i];
    }
}

void display(Set set) {
    printf("{");
    bool first = true;
    for (int i = 0; i < MAX; i++) {
        // If the value at index i is true, it means the element is in the set
        if (set[i] == true) {
            if (!first) {
                printf(", ");
            }
            printf("%d", i);
            first = false;
        }
    }
    printf("}\n");
}