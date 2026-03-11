#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct {
    char name[20];
    int age;
} Person;

typedef struct {
    Person elem[MAX]; // Changed from int to Person
    int count;
} Etype, *EPtr;

void initialize(EPtr L);
void insertPos(EPtr L, Person data, int position);
void deletePos(EPtr L, int position);
int locate(EPtr L, Person data);
Person retrieve(EPtr L, int position);
void insertSorted(EPtr L, Person data);
void display(EPtr L);
void makeNULL(EPtr L);

int main (){
    EPtr L = (EPtr)malloc(sizeof(Etype));
    initialize(L);

    while(1){

        int op, cLoc, found;
        Person p;

        printf("\nplease choose what kind of operation...\n\n");
        printf("1: Insert\n");
        printf("2: Delete\n");
        printf("3: Locate\n");
        printf("4: InsertSorted\n");
        printf("5: Show\n");
        printf("0: Exit\n");

        printf("Enter operation: ");
        scanf("%d", &op);

        switch(op){

        case 0:
            makeNULL(L);
            exit(0);

        case 1:
            if(L->count >= MAX){
                printf("Can't insert. List is full.\n");
            }else{

                printf("Enter name: ");
                scanf("%s", p.name);

                printf("Enter age: ");
                scanf("%d", &p.age);

                printf("Enter position (0-%d): ", L->count);
                scanf("%d", &cLoc);

                insertPos(L, p, cLoc);
            }
        break;

        case 2:
            if(L->count == 0){
                printf("Nothing to delete.\n");
            }else{

                printf("Enter position to delete: ");
                scanf("%d", &cLoc);

                deletePos(L, cLoc);
            }
        break;

        case 3:
            if(L->count == 0){
                printf("List is empty.\n");
            }else{
printf("Enter name to locate: ");
scanf("%s", p.name);
                found = locate(L, p);

                if(found != -1){
                    printf("Person found at index %d\n", found);
                }else{
                    printf("Person not found.\n");
                }
            }
        break;

        case 4:
            if(L->count >= MAX){
                printf("List is full.\n");
            }else{

                printf("Enter name: ");
                scanf("%s", p.name);

                printf("Enter age: ");
                scanf("%d", &p.age);

                insertSorted(L, p);
            }
        break;

        case 5:
            if(L->count == 0){
                printf("Nothing here...\n");
            }else{
                printf("Displaying data...\n");
                display(L);
            }
        break;

        default:
            printf("Invalid option.\n");
        }
    }
}
void initialize(EPtr L){ 
    L->count = 0; 
}

void insertPos(EPtr L, Person data, int position){
    if(position < 0 || position > L->count || L->count >= MAX){
        printf("Invalid Position!\n");
    } else {
        for(int i = L->count; i > position; i--){
            L->elem[i] = L->elem[i - 1]; // Struct assignment (copies all fields)
        }
        L->elem[position] = data;
        L->count++;
    }
}

void deletePos(EPtr L, int position){
    if(position < 0 || position >= L->count){
        printf("Invalid Position!\n");
    } else {
        for(int i = position; i < L->count - 1; i++){
            L->elem[i] = L->elem[i + 1];
        }
        L->count--;
    }
}

int locate(EPtr L, Person data){
    int i;
    int found = -1;

    for(i = 0; i < L->count && strcmp(L->elem[i].name, data.name) != 0; i++){}

    if(i < L->count){
        found = i;
    }

    return found;
}
Person retrieve(EPtr L, int position){
    Person dummy = {"None", -1}; // Return dummy if out of bounds
    if(position < L->count && position >= 0){
        return L->elem[position];
    } 
    return dummy;    
}

void insertSorted(EPtr L, Person data) {
    if (L->count >= MAX) {
        printf("No room at the inn\n");
    } else {
        int i;
        // Sorting by age
        for (i = L->count - 1; i >= 0 && L->elem[i].age > data.age; i--) {
            L->elem[i + 1] = L->elem[i];
        }
        L->elem[i + 1] = data;
        L->count++;
    }
}

void display(EPtr L){
    printf("List:\n");
    for(int i = 0; i < L->count; i++){
        printf("[%d] %s, %d\n", i, L->elem[i].name, L->elem[i].age);
    }
}

void makeNULL(EPtr L){
    free(L); 
}
