#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int items[MAX];
    int top;
} Stack;

// Function Prototypes
Stack* initialize();
bool isFull(Stack* s);
bool isEmpty(Stack* s);
void push(Stack* s, int value);
int pop(Stack* s);
int peek(Stack* s);
int top(Stack* s);
void display(Stack* s);

int main (){

    Stack *s = initialize();
    int num, choice;
    do{
        printf("\nMenu:\n[1]: Push\n[2]: Pop\n[3]: Peek\n[4]: Top\n[5]: Display\n[0]: Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                printf("Enter a number: ");
                scanf("%d", &num);
                push(s, num);
                break;
            case 2:
                num = pop(s);
                if(num != -1){
                    printf("%d popped\n", num);
                }
                break;
            case 3:
                if(!isEmpty(s)){
                    printf("Top element is %d\n", peek(s));
                } else {
                    printf("Stack is empty.\n");
                }
                break;
            case 4:
                int topval = top(s);
                printf("Top Value = %d\n", topval);
                break;
            case 5:
                display(s);
                break;
            case 0:
                printf("Exiting...");
                free(s);
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }
    } while(choice != 0);

    return 0;
}

// Functions
Stack* initialize(){
    Stack* newStack = malloc(sizeof(Stack));

    if(newStack != NULL){
        newStack->top = -1;
    }
    return newStack;
}
bool isFull(Stack* s){
    // Return true if top is top == MAX - 1
    return(s->top == MAX - 1) ? true : false;
}

bool isEmpty(Stack* s){
    // Return true if top is top == -1
    return(s->top == -1) ? true : false;
}

void push(Stack* s, int value){
    /*
    Check if the stack is full
    Increment the top
    Place the new value at the current top position
    */

    if(isFull(s)){
        printf("Stack is full.\n");
    } else {
        s->top++;
        s->items[s->top] = value;
    }
}

int pop(Stack* s){
    /*
    Check if the stack is empty
    Get the value at the current top of the stack
    Decrement the top
    Return the retrieved value
    */
    int retval = -1;
    if(isEmpty(s)){
        printf("Stack is empty.\n");
    } else {
     int value = s->items[s->top];  
    s->top--;
    retval = value;
    }
    return retval;
}

int peek(Stack* s){
    if(isEmpty(s)){
        printf("Stack is empty.\n");
        return -1;
    }
    return s->items[s->top];
}

int top(Stack* s){
    // Return value of top
    return s->top;
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