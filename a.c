#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 10

typedef struct {
    int top;
    int elems[MAX];
}Stack;

Stack *init();
bool isEmpty(Stack *s);
bool isFull(Stack *s);
int peek(Stack *s);
int top(Stack *s);
void push(Stack *s);
int pop(Stack *s);

int main(){


    return 0;
}

Stack *init();
bool isEmpty(Stack *s);
bool isFull(Stack *s);
int peek(Stack *s);
int top(Stack *s);
void push(Stack *s);
int pop(Stack *s);