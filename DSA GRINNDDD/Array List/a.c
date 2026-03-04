#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef stuct{
    int elem[MAX];
    int count;
}Etype, *Eptr;

void init(Eptr L);
void insertPos(Eptr L, int data, int pos);
void deletePos(Eptr L, int pos);
void insertSorted(Eptr L, int data);
void makeNULL(Eptr L);
 
int main(){
    Eptr L = malloc(sizeof(Etype));
    return 0;
}

void init(Eptr L){
    L->count = 0;
}
void insertPos(Eptr L, int data, int pos){
    if(pos < 0 || pos > L->count || L->count >= MAX){
        printf("invalid please try again\n");
    } else {
        int i;
        for(i = L->count; i > pos;i--){
            L->elem[i] = L->elem[i -1];
        }
        L->count++;
        L->elem[pos] = data;
    }
}
void deletePos(Eptr L, int pos){
    if(pos < 0 || pos > L->count){
        printf("invalid please try again\n");
    } else {
        int i;
        for(i = pos; i < L->count -1;i++){
            L->elem[i] = L->elem[i + 1];
        }
        L->count--;
    }
}
void insertSorted(Eptr L, int data){
    f(pos < 0 || pos > L->count || L->count >= MAX){
        printf("invalid please try again\n");
    } else {
        for(i = L->count - 1; i > pos && L->elem[i] > data;i--){
            L->elem[i + 1] = L->elem[i];
        }
        L->count++;
        L->elem[i + 1] = data;
    }
}
void makeNULL(Eptr L){

}