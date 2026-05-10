#include <stdio.h>
#include <stdbool.h>

#define MAX 20 // As defined in your notes [cite: 155]

typedef struct {
    int arr[MAX];
    int last; // Index of the last element [cite: 157]
} PriorityQueue;

// 1. Initialize: Sets the last index to -1 (empty) [cite: 159, 170]
void initialize(PriorityQueue *H) {
    H->last = -1;
}

// 2. Insert: Uses the "Bubble Up" method [cite: 39, 169]
void insert(PriorityQueue *H, int data) {
    if (H->last < MAX - 1) { // Check if there is space [cite: 161]
        H->last++;
        int current = H->last;
        H->arr[current] = data; // Add to the left-most available spot [cite: 4, 166]

        // Bubble Up: Swap with parent if the new data is bigger [cite: 39, 40, 44]
        // Parent index = (n-1)/2 [cite: 73]
        while (current > 0) {
            int parent = (current - 1) / 2;
            if (H->arr[current] > H->arr[parent]) { // Use < for Min-Heap 
                int temp = H->arr[current];
                H->arr[current] = H->arr[parent];
                H->arr[parent] = temp;
                current = parent;
            } else {
                break; // Properly placed [cite: 58]
            }
        }
    }
}

// 3. Delete: Implements the 3-step deletion process [cite: 84, 85, 169]
int deleteMax(PriorityQueue *H) {
    if (H->last == -1) return -1; // Empty check

    int rootValue = H->arr[0]; // The root is the "Boss" to delete [cite: 85, 90]

    // Step 2: Replace root with the most recently added node (the last element) [cite: 86, 95]
    H->arr[0] = H->arr[H->last];
    H->last--; // "Free" the old last node [cite: 97, 116]

    // Step 3: Adjust by Sinking Down [cite: 89, 123, 131]
    int current = 0;
    while (true) {
        int left = (2 * current) + 1;  // Left Child formula [cite: 72]
        int right = (2 * current) + 2; // Right Child formula [cite: 72]
        int largest = current;

        // Compare with children and find the bigger one to swap with [cite: 134]
        if (left <= H->last && H->arr[left] > H->arr[largest]) {
            largest = left;
        }
        if (right <= H->last && H->arr[right] > H->arr[largest]) {
            largest = right;
        }

        if (largest != current) {
            // Swap the newly promoted node with its bigger child [cite: 134, 138]
            int temp = H->arr[current];
            H->arr[current] = H->arr[largest];
            H->arr[largest] = temp;
            current = largest; // Continue sinking [cite: 131]
        } else {
            break; // No more swaps needed; we stop [cite: 140]
        }
    }

    return rootValue;
}

void display(PriorityQueue H) {
    printf("Heap: ");
    for (int i = 0; i <= H.last; i++) {
        printf("%d ", H.arr[i]);
    }
    printf("\n");
}

int main() {
    PriorityQueue PQ;
    initialize(&PQ);

    insert(&PQ, 41); // Example values from your PDF [cite: 5, 28]
    insert(&PQ, 39); [cite: 6, 29]
    insert(&PQ, 33); [cite: 7, 30]
    insert(&PQ, 50); // Testing "Bubble Up" with 50 [cite: 37, 44]
    
    display(PQ); // Should show 50 at root

    printf("Deleted Max: %d\n", deleteMax(&PQ)); // Should remove 50 [cite: 90]
    display(PQ);

    return 0;
}