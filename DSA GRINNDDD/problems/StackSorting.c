#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

typedef struct{
   Node *top;
}Stack;

Stack* init();
void push(Stack *s, int val);
int pop(Stack *s);
int peek(Stack *s);
void sortStack(Stack *s);

int main(){
    
    int choice;
    
    Stack *s = init();
    
    printf("Enter the number of elements in the stack: ");
    scanf("%d", &choice);
    int el;
    for(int i = 1; i <= choice;i++){
        printf("Enter element %d: ", i);
        scanf("%d", &el);
        push(s, el);

    }
    sortStack(s);
    printf("Sorted Stack: ");
    while(s->top != NULL){
        printf("%d ", pop(s));
    }
    return 0;
}

Stack* init(){
    Stack *nStack = malloc(sizeof(Stack));
    if(nStack != NULL){
        nStack->top = NULL;
        return nStack;
    }
}
void push(Stack *s, int val){
    Node *newNode = malloc(sizeof(Node));
    if(newNode != NULL){
        newNode->data = val;
        newNode->next = s->top;
        s->top = newNode;
    }
}
int pop(Stack *s){
    if(s->top == NULL){
        printf("Nothing follows...\n\n");
    } else {
        Node *temp = s->top;
        int retval = s->top->data;
        s->top = s->top->next;
        free(temp);
        return retval;
    }
}

int peek(Stack *s){
    return s->top->data;
}
void sortStack(Stack *s){
    Stack *aux = init();
   
    while(s->top != NULL){
        int temp = pop(s);
        while(aux->top != NULL && peek(aux) < temp){
            push(s, pop(aux));
        }
        push(aux, temp);
    }
    
    while(aux->top != NULL){
        push(s, pop(aux));
    }
    free(aux);
}