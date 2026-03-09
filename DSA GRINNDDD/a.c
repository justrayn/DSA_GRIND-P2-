#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct {
    int items[MAX];
    int top;
}Stack;

Stack *init();
bool isFull(Stack* s);
bool isEmpty(Stack s);
void push(Stack *s, int value);
int pop(Stack *s);
int peek(Stack *s);
int top(Stack *s);
void display(Stack *s);

int main(){



    return 0;
}


Stack *init(){
    Stack *newStack = malloc(sizeof(Stack));;
    if(newStack != NULL){
        newStack->top = -1;
        return newStack;
    }
}
bool isFull(Stack* s){
    return (s->top == MAX -1) ? true : false;
}
bool isEmpty(Stack s){
    return (s->top == -1) ? true : false;
}
void push(Stack *s, int value){
    if(isFull(s)){
        printf("stack is actually full\n\n");
    } else {
        s->top++;
        s->items[s->top] = value;
    }
}
int pop(Stack *s){

}
int peek(Stack *s){

}
int top(Stack *s){

}
void display(Stack *s){

}