#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10

typedef struct {
    int *elemPtr;
    int count;
    int max;
}List;

List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);
List resize(List L);

int main (){

    List L = initialize(L);
    L.elemPtr[0] = 1;
    L.elemPtr[1] = 3;
    L.elemPtr[2] = 2;
    L.elemPtr[3] = 5;
    L.count = 4;
    L.max = 4;
    display(L);
    printf("\ncount: %d\n", L.count);
    printf("max: %d", L.max);

    L = insertPos(L, 4, 2);

    return 0;
}

List initialize(List L){
    L.elemPtr = malloc(sizeof(int) * LENGTH);
    L.max = LENGTH;
    L.count = 0;
    return L;
}

List insertPos(List L, int data, int position){
    if(position < 0 || position > L.count){
        printf("Invalid Position.");
    } else {
    if (L.count >= L.max){
    printf("full resizing...\n")
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
        printf("Invalid Position.");
    } else {
    int i;
    for(i = position; i < L.count - 1; i++){
        L.elemPtr[i] = L.elemPtr[i + 1];
    }
    L.count--;
    }
    return L;
}

int locate(List L, int data){
    int i;
    int found = -1;
    for(i = 0; i < L.count && L.elemPtr[i] != data ; i++){}
    if(i < L.count){
        found = i;
    }
    return found;
}

List insertSorted(List L, int data){
    if(L.count >= L.max){
        printf("info is full resizing...\n");
        L = resize(L);
    } 
    int i;
    for(i = L.count - 1;i >= 0 && L.elemPtr[i] > data;i--){
            L.elemPtr[i + 1] = L.elemPtr[i];
    }
    L.elemPtr[i + 1] = data;
    L.count++;
    return L;
}

void display(List L){
    printf("elem: ");
    for(int i = 0; i < L.count; i++){
        printf("%d ", L.elemPtr[i]);
    }
}

List resize(List L){
    int newMax = L.max * 2;
    int *newPtr = realloc(L.elemPtr, sizeof(int) * newMax);
    if(newPtr != NULL){
    L.elemPtr = newPtr;
    L.max = newMax;
    }
    return L;
}