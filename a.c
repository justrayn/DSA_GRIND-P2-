#include <stdio.h>
#include <stdlib.h>

#define MAX 10
typedef struct {
    int item[MAX];
    int top;
} Stack;

// Function Prototypes
Stack *init(); 
void push(Stack *s, int data);
int pop(Stack *s);
int peek(Stack *s);
void display(Stack *s);

int main() {
    Stack *s = init();
    push(s, 10);
    push(s, 20);
    push(s, 30);

    display(s);

    return 0;
}

Stack *init() {
    Stack *s = malloc(sizeof(Stack));
    if (s != NULL) {
        s->top = -1;
    }
    return s;
}

void push(Stack *s, int data) {
    // MAX - 1 ensures we don't go out of bounds (0-9)
    if (s->top < MAX - 1) {
        s->top++;
        s->item[s->top] = data;
    }
}

int pop(Stack *s) {
    int val = -1; // Single return variable
    if (s->top != -1) {
        val = s->item[s->top];
        s->top--;
    }
    return val;
}

int peek(Stack *s) {
    int val = -1; // Single return variable
    if (s->top != -1) {
        val = s->item[s->top];
    }
    return val;
}

void display(Stack *s) {
    // 1. Initialize the temporary stack correctly
    Stack *temp = init(); 
    
    if (s->top != -1) {
        printf("Stack contents:\n");
        
        // 2. Move from S to TEMP to see items
        // We use a while loop because s->top changes
        while (s->top != -1) {
            int current = peek(s);
            printf("| %d |\n", current);
            push(temp, pop(s));
        }
        printf("-----\n");

        // 3. Move items BACK from TEMP to S to restore the stack
        while (temp->top != -1) {
            push(s, pop(temp));
        }
    } else {
        printf("Stack is empty.\n");
    }
    
    // Clean up the temporary stack memory
    free(temp);
}