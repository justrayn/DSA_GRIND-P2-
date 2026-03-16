#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int elems[MAX];
    int top;
}Stack;

Stack *init();
void push(Stack *s, int data);
int pop(Stack *s);
int peek(Stack *s);
bool isFull(Stack *s);
bool isEmpty(Stack *s);
void display(Stack *s);


int main(){

    Stack *s = init();
    push(s, 10);
    push(s, 11);
    push(s, 12);
    display(s);

    return 0;
}

Stack *init(){
    Stack *s = malloc(sizeof(Stack));
    if(s != NULL){
        s->top = -1;
    }
    return s;
}

int peek(Stack *s){
    return (s->top != -1) ? s->elems[s->top] : -1;
}
void push(Stack *s, int data){
    if(s->top == MAX -1){
        printf("don't force it!!");
    } else {
        s->top++;
        s->elems[s->top] = data;
    }
}
int pop(Stack *s){
    int item = -1;
    if(peek(s) != -1){
        item = s->elems[s->top];
        s->top--;
    }
   return item;
}
bool isFull(Stack *s){
    return (s->top == MAX -1) ? true : false;
}
bool isEmpty(Stack *s){
    return (s->top == -1) ? true : false;
}
void display(Stack *s){
    Stack *temp = init();
    while(s->top != -1){
        int curr = peek(s);
        printf("%d\n", curr);
        push(temp, pop(s));
    }

    while(temp->top != -1){
        push(s, pop(temp));
    }
}
