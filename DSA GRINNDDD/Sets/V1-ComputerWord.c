#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 8

// Function Prototypes
void initialize(unsigned char *set);
void insert(unsigned char *set, int elem);
void delete(unsigned char *set, int elem); // Note: 'delete' works in C, but is a keyword in C++. Compile as .c!
bool find(unsigned char set, int elem);

// Note: Renamed 'union' to 'setUnion' because 'union' is a reserved keyword in C.
unsigned char setUnion(unsigned char A, unsigned char B);
unsigned char intersection(unsigned char A, unsigned char B);
unsigned char difference(unsigned char A, unsigned char B);
void display(unsigned char set);

int main() {
    unsigned char A, B, C;
    
    // Initialize our sets to 0 (empty)
    initialize(&A);
    initialize(&B);

    // Test Insert
    insert(&A, 1);
    insert(&A, 6);
    printf("Set A after inserts: ");
    display(A); // Expected: {1, 6}

    insert(&B, 3);
    insert(&B, 6);
    insert(&B, 7);
    printf("Set B after inserts: ");
    display(B); // Expected: {3, 6, 7}

    // Test Union
    C = setUnion(A, B);
    printf("Union of A and B: ");
    display(C); // Expected: {1, 3, 6, 7}

    // Test Intersection
    C = intersection(A, B);
    printf("Intersection of A and B: ");
    display(C); // Expected: {6}

    // Test Difference
    C = difference(A, B);
    printf("Difference (A - B): ");
    display(C); // Expected: {1}
    
    // Test Delete
    delete(&A, 6);
    printf("Set A after deleting 6: ");
    display(A); // Expected: {1}

    return 0;
}

// ---------------- Implementation ----------------

void initialize(unsigned char *set) {
    *set = 0; // Turns all 8 bits to 00000000
}

void insert(unsigned char *set, int elem) {
    // Safety check: only allow numbers 0 through 7
    if (elem >= 0 && elem < MAX) {
        // Create mask and Bitwise OR assignment
        *set = *set | (1 << elem); 
    }
}

void delete(unsigned char *set, int elem) {
    if (elem >= 0 && elem < MAX) {
        // Create mask, invert it with ~, then Bitwise AND
        *set = *set & ~(1 << elem);
    }
}

bool find(unsigned char set, int elem) {
    if (elem >= 0 && elem < MAX) {
        // Bitwise AND the set with the mask. If it's > 0, the bit is present.
        return (set & (1 << elem)) != 0; 
    }
    return false;
}

unsigned char setUnion(unsigned char A, unsigned char B) {
    return A | B; // Bitwise OR
}

unsigned char intersection(unsigned char A, unsigned char B) {
    return A & B; // Bitwise AND
}

unsigned char difference(unsigned char A, unsigned char B) {
    return A & (~B); // A AND (NOT B)
}

void display(unsigned char set) {
    printf("{");
    bool first = true;
    for (int i = 0; i < MAX; i++) {
        // If the bit at position i is set (1), print it
        if (find(set, i)) {
            if (!first) {
                printf(", ");
            }
            printf("%d", i);
            first = false;
        }
    }
    printf("}\n");
}