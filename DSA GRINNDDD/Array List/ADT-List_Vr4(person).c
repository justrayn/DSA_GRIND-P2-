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

    Person p1 = {"Alice", 25};
    Person p2 = {"Bob", 20};
    Person p3 = {"Charlie", 30};
    Person p4 = {"Diana", 22};

    insertSorted(&L, p1);
    insertSorted(&L, p2);
    insertSorted(&L, p3);
    insertSorted(&L, p4);

    display(&L);

    makeNULL(&L);
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
    // Compares age and name for equality
    for(i = 0; i < L->count && (L->elemPtr[i].age != data.age || strcmp(L->elemPtr[i].name, data.name) != 0); i++){}
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