#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "arrayStack.h"

int main() {
    // write your code here
    int choice;
    int val;
    Stack *s = malloc(sizeof(Stack));
    Stack *s2 = malloc(sizeof(Stack));
    Stack *s3 = malloc(sizeof(Stack));
    initialize(s);
    initialize(s2);
    initialize(s3);
    while(1){
    
    printf("--- Warehouse Inventory Management System ---\n1. Push a container\n2. Pop a container\n3. Check if a container exists\n4. Display all stacks\n5. Exit");
    printf("\nEnter your choice: ");
    
    scanf("%d", &choice);
        switch(choice){
        case 1:
        printf("Enter container ID to push: ");
        scanf("%d", &val);
        if(!isFull(s)){
            push(s, val);
        } else if(!isFull(s2)){
            push(s2, val);
        } else {
            push(s3, val);
        }
        printf("Container %d pushed successfully.\n\n", val);
        break;
        
        case 2:
         if(isEmpty(s3) && isEmpty(s2) && !isEmpty(s)){
            pop(s);
             printf("Container %d popped successfully.\n\n", val);
        } else if(isEmpty(s3) && !isEmpty(s2) && !isEmpty(s)){
            pop(s2);
        } else if(!isEmpty(s3)){
            pop(s3);
        } else {
            
            printf("Error: All stacks are empty. Cannot pop container.\n\n");
     
        }
        break;
        
        case 3:
        int check;
        int found = 0;
        printf("Enter container ID to check: ");
        scanf("%d", &check);
        Stack *everyS[] = {s3, s2, s};
        Stack temp;
        initialize(&temp);
        for(int i = 0; i < 3; i++){
            while(!isEmpty(everyS[i])){
                int curr = pop(everyS[i]);
                if(curr == check){
                    found = 1;
                }
                push(&temp, curr);
            }
            
            while(!isEmpty(&temp)){
                push(everyS[i], pop(&temp));
            }
        }
        if(found == 1){
                printf("Container %d exists in a stack.\n\n", check);
            }else{
                printf("Container %d does not exist in any stack.\n\n", check);
            }
        break;
        
        case 4:
        printf("\n--- Stack 1 ---\n");
        display(s);
        printf("\n--- Stack 2 ---\n");
        display(s2);
        printf("\n--- Stack 3 ---\n");
        display(s3);
        printf("\n");
        break;
        
        case 5:
        printf("Exiting program.\n");
        exit(0);
        break;
    }
    }

    return 0;
}


#include <stdio.h>
#include <stdbool.h>
#include "types.h"

// write your functions here

void initialize(Stack *s){
    s->top = -1;
}
bool isFull(Stack *s){
    return (s->top == MAX -1) ? true : false;
}
bool isEmpty(Stack *s){
    return (s->top == -1) ? true : false;
}
void push(Stack *s, int value){
    if(!isFull(s)){
    s->top++;
    s->items[s->top] = value;
    }
}
int pop(Stack *s){
    if(!isEmpty(s)){
    int temp = s->items[s->top];
    s->top--;
    return temp;
    }
}
int peek(Stack *s){
    if(!isEmpty(s)){
        return s->items[s->top];
    }
}
int top(Stack *s){
    return s->top;
}
void display(Stack* s){
    if(isEmpty(s)){
        printf("Stack is empty.\n");
    }else {
        Stack tStack;
        initialize(&tStack);
        while(!isEmpty(s)){
        printf("%d\n", s->items[s->top]);
           int val = pop(s);
           push(&tStack, val);
        }
        // put it back
        
        while(!isEmpty(&tStack)){
           push(s, pop(&tStack));
        }
        
    }
}