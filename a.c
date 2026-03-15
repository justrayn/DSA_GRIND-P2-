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
    
    display(s); // Should show 30, 20, 10
    
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
    if (s->top < MAX - 1) { // Fixed: prevent overflow
        s->item[++(s->top)] = data;
    } else {
        printf("Stack Overflow\n");
    }
}

int pop(Stack *s) {
    if (s->top == -1) return -1;
    return s->item[(s->top)--]; // Decrement after returning
}

int peek(Stack *s) {
    if (s->top == -1) return -1;
    return s->item[s->top];
}

void display(Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack (Top to Bottom):\n");
    // We just iterate backwards through the array
    for (int i = s->top; i >= 0; i--) {
        printf("| %d |\n", s->item[i]);
    }
    printf("-----\n");
}