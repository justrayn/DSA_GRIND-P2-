#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 10

typedef struct {
    char name[20];
    int age;
} Person;

typedef struct {
    Person *elemPtr; // Changed from int* to Person*
    int count;
    int max;
} List;

List initialize(List L);
List insertPos(List L, Person data, int position);
List deletePos(List L, int position);
int locate(List L, Person data);
List insertSorted(List L, Person data);
void display(List L);
List resize(List L);

int main (){
    List L = initialize(L);
    
    // Initializing with Person data
    Person p1 = {"Alice", 20};
    Person p2 = {"Bob", 25};
    Person p3 = {"Charlie", 22};
    
    L = insertSorted(L, p1);
    L = insertSorted(L, p2);
    L = insertSorted(L, p3);

    display(L);
    printf("\ncount: %d\n", L.count);
    printf("max: %d\n", L.max);

    Person p4 = {"Dave", 21};
    L = insertPos(L, p4, 1);
    
    display(L);

    return 0;
}

List initialize(List L){
    // sizeof(Person) ensures enough space for the struct fields
    L.elemPtr = malloc(sizeof(Person) * LENGTH);
    L.max = LENGTH;
    L.count = 0;
    return L;
}

List insertPos(List L, Person data, int position){
    if(position < 0 || position > L.count){
        printf("Invalid Position.\n");
    } else {
        if (L.count >= L.max){
            printf("full resizing...\n");
            L = resize(L);
        }
        int i;
        for(i = L.count; i > position; i--){
            L.elemPtr[i] = L.elemPtr[i - 1];
        }
        L.elemPtr[position] = data;
        L.count++; 
    }
    return L;
}

List deletePos(List L, int position){
    if(position < 0 || position >= L.count){
        printf("Invalid Position.\n");
    } else {
        int i;
        for(i = position; i < L.count - 1; i++){
            L.elemPtr[i] = L.elemPtr[i + 1];
        }
        L.count--;
    }
    return L;
}

int locate(List L, Person data){
    int i;
    int found = -1;
    // Comparing based on age
    for(i = 0; i < L.count && L.elemPtr[i].age != data.age ; i++){}
    if(i < L.count){
        found = i;
    }
    return found;
}

List insertSorted(List L, Person data){
    if(L.count >= L.max){
        printf("info is full resizing...\n");
        L = resize(L);
    } 
    int i;
    for(i = L.count - 1; i >= 0 && L.elemPtr[i].age > data.age; i--){
            L.elemPtr[i + 1] = L.elemPtr[i];
    }
    L.elemPtr[i + 1] = data;
    L.count++;
    return L;
}

void display(List L){
    printf("\n--- Current List ---\n");
    for(int i = 0; i < L.count; i++){
        printf("[%d] %s (Age: %d)\n", i, L.elemPtr[i].name, L.elemPtr[i].age);
    }
}

List resize(List L){
    int newMax = L.max * 2;
    // Update sizeof(Person) here so realloc grabs the correct amount of memory
    Person *newPtr = realloc(L.elemPtr, sizeof(Person) * newMax);
    if(newPtr != NULL){
        L.elemPtr = newPtr;
        L.max = newMax;
    }
    return L;
}