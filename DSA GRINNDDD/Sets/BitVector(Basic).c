#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <string.h>

bool *createBit(int Arr[], int n, int maxSize);
void displayBit(bool bv[], int n);
void insertElem(bool Arr[], int elem);
void deleteElem(bool Arr[], int elem);

int main(){
    int A[] = {1, 2, 3};
    int B[] = {1, 9};
    int nA = sizeof(A) / sizeof(int);
    int nB = sizeof(B) / sizeof(int);
    int maxSize = 10;
    bool *Z = createBit(A, nA, maxSize);
    bool *X = createBit(B, nB, maxSize);
    printf("A:\n");
    displayBit(Z, maxSize);
    printf("B:\n");
    displayBit(X, maxSize);
    
}

bool *createBit(int Arr[], int n, int maxSize){
    bool *bv = calloc(maxSize + 1, sizeof(bool));
    for(int i = 0; i < n;i++){
        bv[Arr[i]] = true;
    }
    return bv;
}
void displayBit(bool bv[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", i);
    }
    printf("\n");
    for(int i = 0; i < n; i++){
        printf("%d ", bv[i]);
    }
    printf("\n");
}
void insertElem(bool Arr[], int elem){
    Arr[elem] = true; 
}
void deleteElem(bool Arr[], int elem){
    Arr[elem] = false;
}