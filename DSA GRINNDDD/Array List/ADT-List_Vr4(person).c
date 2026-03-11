#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENGTH 10

typedef struct {
    char name[20];
    int age;
} Person;

typedef struct {
    Person *elemPtr;
    int count;
    int max;
} List;

void initialize(List *L);
void insertPos(List *L, Person data, int position);
void deletePos(List *L, int position);
int locate(List *L, Person data); // Note: compares age/name
Person retrieve(List *L, int position);
void insertSorted(List *L, Person data);
void display(List *L);
void resize(List *L);
void makeNULL(List *L);


int main (){
    List L;
    initialize(&L);

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
            makeNULL(&L);
            exit(0);

        case 1:
            printf("Enter name: ");
            scanf("%s", p.name);

            printf("Enter age: ");
            scanf("%d", &p.age);

            printf("Enter position (0-%d): ", L.count);
            scanf("%d", &cLoc);

            insertPos(&L, p, cLoc);
        break;

        case 2:
            if(L.count == 0){
                printf("Nothing to delete.\n");
            }else{
                printf("Enter position to delete: ");
                scanf("%d", &cLoc);

                deletePos(&L, cLoc);
            }
        break;

        case 3:
            if(L.count == 0){
                printf("List is empty.\n");
            }else{
        
                printf("Enter name to locate: ");
                scanf("%s", p.name);
        
                found = locate(&L, p);
        
                if(found != -1){
                    printf("Person found at index %d\n", found);
                }else{
                    printf("Person not found.\n");
                }
            }
        break;

        case 4:
            printf("Enter name: ");
            scanf("%s", p.name);

            printf("Enter age: ");
            scanf("%d", &p.age);

            insertSorted(&L, p);
        break;

        case 5:
            if(L.count == 0){
                printf("Nothing here...\n");
            }else{
                printf("Displaying data...\n");
                display(&L);
            }
        break;

        default:
            printf("Invalid option.\n");
        }
    }

    return 0;
}

void initialize(List *L){
    L->elemPtr = malloc(sizeof(Person) * LENGTH);
    L->max = LENGTH;
    L->count = 0;
}

void insertPos(List *L, Person data, int position){
    if(position > L->count || position < 0){
        printf("Invalid Position.\n");
    } else {
        if(L->count >= L->max){
            resize(L);
        }

        int i;
        for(i = L->count; i > position; i--){
            L->elemPtr[i] = L->elemPtr[i - 1];
        }

        L->elemPtr[position] = data;
        L->count++;
    }
}

void deletePos(List *L, int position){
    if(position >= L->count || position < 0){
        printf("Invalid Position.\n");
    } else {
        int i;
        for(i = position; i < L->count - 1; i++){
            L->elemPtr[i] = L->elemPtr[i + 1];
        }
        L->count--;
    }
}

int locate(List *L, Person data){
    int i;
    int found = -1;

    for(i = 0; i < L->count && strcmp(L->elemPtr[i].name, data.name) != 0; i++){}

    if(i < L->count){
        found = i;
    }

    return found;
}
Person retrieve(List *L, int position){
    Person dummy = {"None", -1};
    if(position >= L->count || position < 0){
        printf("Invalid Position.\n");
        return dummy;
    } else {
        return L->elemPtr[position];
    }
}

void insertSorted(List *L, Person data){
    if(L->count >= L->max){
        resize(L);
    }
    int i;
    // Sorting by age
    for(i = L->count - 1; i >= 0 && L->elemPtr[i].age > data.age; i--){
        L->elemPtr[i + 1] = L->elemPtr[i];
    }
    L->elemPtr[i + 1] = data;
    L->count++;
}

void display(List *L){
    int i;
    for(i = 0; i < L->count; i++){
        printf("[%s, %d] ", L->elemPtr[i].name, L->elemPtr[i].age);
    }
    printf("\n");
}

void resize(List *L){
    L->max *= 2;
    L->elemPtr = realloc(L->elemPtr, sizeof(Person) * L->max);
}

void makeNULL(List *L){
    if(L->elemPtr != NULL){
         free(L->elemPtr);
         L->elemPtr = NULL;
    }
    L->count = 0;
    L->max = 0;
}
