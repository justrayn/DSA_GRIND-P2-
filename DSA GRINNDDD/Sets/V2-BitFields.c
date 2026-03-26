#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 8 // Changed from 10 to 8 since the bit field holds exactly 8 bits

typedef struct {
    unsigned int field : 8; // This tells the compiler to strictly use 8 bits
} Set;

// Function Prototypes
void initialize(Set *set);
void insert(Set *set, int element);
void delete(Set *set, int element); // Note: Compile as .c (delete is a keyword in C++)
bool find(Set set, int element);
Set setUnion(Set A, Set B);
Set intersection(Set A, Set B); // Fixed spelling from 'intersecion'
Set difference(Set A, Set B);

// Changed parameter to take 'Set set' instead of 'unsigned chat set' to match the struct variation
void display(Set set); 

int main() {
    Set A, B, C;

    // Note: Professor's checklist said initialize(A), but since the function
    // requires a pointer, we must pass the address with &A.
    initialize(&A);
    initialize(&B);

    // Test Insert
    insert(&A, 0);
    insert(&A, 4);
    insert(&A, 5);
    printf("Set A after inserts: ");
    display(A); // Expected: {0, 4, 5}

    // Set up B for math tests
    insert(&B, 2);
    insert(&B, 5);
    printf("Set B after inserts: ");
    display(B); // Expected: {2, 5}

    // Test Union
    C = setUnion(A, B);
    printf("Union of A and B: ");
    display(C); // Expected: {0, 2, 4, 5}

    // Test Intersection
    C = intersection(A, B);
    printf("Intersection of A and B: ");
    display(C); // Expected: {5}

    // Test Difference
    C = difference(A, B);
    printf("Difference (A - B): ");
    display(C); // Expected: {0, 4}

    // Test Delete
    delete(&A, 5);
    delete(&A, 4);
    printf("Set A after deleting 5 and 4: ");
    display(A); // Expected: {0}

    return 0;
}

// ---------------- Implementation ----------------

void initialize(Set *set) {
    // Use the arrow operator (->) to access the struct's member through a pointer
    set->field = 0; 
}

void insert(Set *set, int element) {
    if (element >= 0 && element < MAX) {
        // Bitwise OR assignment on the 'field'
        set->field = set->field | (1 << element);
    }
}

void delete(Set *set, int element) {
    if (element >= 0 && element < MAX) {
        // Bitwise AND with an inverted mask on the 'field'
        set->field = set->field & ~(1 << element);
    }
}

bool find(Set set, int element) {
    if (element >= 0 && element < MAX) {
        // Use the dot operator (.) because 'set' is passed by value, not as a pointer
        return (set.field & (1 << element)) != 0;
    }
    return false;
}

Set setUnion(Set A, Set B) {
    Set C;
    // Perform bitwise OR on the fields and store in C's field
    C.field = A.field | B.field;
    return C;
}

Set intersection(Set A, Set B) {
    Set C;
    // Perform bitwise AND on the fields
    C.field = A.field & B.field;
    return C;
}

Set difference(Set A, Set B) {
    Set C;
    // Perform A AND (NOT B) on the fields
    C.field = A.field & ~(B.field);
    return C;
}

void display(Set set) {
    printf("{");
    bool first = true;
    for (int i = 0; i < MAX; i++) {
        // Use our find function to check if the bit is set
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