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

    // Initializing with Person data
    strcpy(L->elem[0].name, "Alice"); L->elem[0].age = 20;
    strcpy(L->elem[1].name, "Bob");   L->elem[1].age = 25;
    L->count = 2;

    int operation;
    do {
        printf("\n1: Insert\n");
        printf("2: Delete\n");
        printf("3: Locate\n");
        printf("4: InsertSorted\n");
        printf("0: Exit\n");
        printf("Enter operation: ");
        scanf("%d", &operation);

        Person p1 = {"Dave", 22};
        Person p2 = {"Eve", 28};

        switch (operation){
            case 0:
                makeNULL(L); // Using your function to free memory
                return 0;
            case 1:
                insertPos(L, p1, 1);
                display(L);
                printf("\nCount: %d\n", L->count);
                break;
            case 2:
                deletePos(L, 1);
                display(L);
                printf("\nCount: %d\n", L->count);
                break;
            case 3: {
                // Locating based on the p1 struct
                int location = locate(L, p1);
                if(location != -1){
                    printf("Data found at index %d\n", location);
                } else {
                    printf("Data not Found!\n");
                }
                display(L);
                break;
            }
            case 4:
                insertSorted(L, p2);
                display(L);
                printf("count: %d\n", L->count);
                break;
        }
    } while (operation != 0);
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
    // Cannot compare structs directly; comparing by age
    for(i = 0; i < L->count && L->elem[i].age != data.age; i++){}
    if( i < L->count){
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