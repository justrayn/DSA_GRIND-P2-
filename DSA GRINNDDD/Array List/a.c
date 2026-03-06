#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
}Etype, *Eptr;

void init(Eptr l);
void insertPos(Eptr l, int pos, int data);
void deletePos(Eptr l, int pos, int data);
void insertSorted(Eptr l, int data);
void makeNULL(Eptr l);

int main(){
    Eptr l = malloc(sizeof(Etype));

    return 0;
}

void init(Eptr l){
    l->count = 0;
}
void insertPos(Eptr l, int pos, int data){
    if(pos < 0 || pos > l->count || l->count >= MAX){
        printf("ur being way too much bro...\n");
    } else {
        for(i = l->count; i > pos; i--){
            l->elem[i] = l->elem[i - 1];
        }
        l->count++;
        l->elem[pos] = data;
    }
}
void deletePos(Eptr l, int pos, int data){
    if(pos < 0 || pos > l->count){
        printf("ur being way too much bro...\n");
    } else {
        for(i = pos; i < l->count - 1; i++){
            l->elem[i] = l->elem[i + 1];
        }
        l->count--;
    }
}
void insertSorted(Eptr l, int data){
    if(l->count >= MAX){
        printf("ur being way too much bro...\n");
    } else {
        for(i = l->count - 1; i > 0 && l->elem[i] > data; i--){
            l->elem[i + 1] = l->elem[i];
        }
        l->count++;
        l->elem[pos + 1];
    }
}
void makeNULL(Eptr l){
    free(l);
}