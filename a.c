#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10


typedef struct {
    int items[MAX];
    int count;
}Etype, *Eptr;

void init(Eptr l);
void insertPos(Eptr l, int data, int index);
void deletePos(Eptr l,int index);
void insertSorted(Eptr l, int data);
void makeNULL(Eptr l);


int main(){



    return 0;
}

void init(Eptr l){
    l->count = 0;
}
void insertPos(Eptr l, int data, int index){
    if(index < 0 || index > l->count || l->count >= MAX){
        printf("invalid..\n");
    } else {
        for(int i = l->count; i > index ; i--){
            l->items[i] = l->items[i - 1];
        }
        l->items[index] = data;
        l->count++;
    }
}
void deletePos(Eptr l,int index){
    if(index < 0 || index > l->count || l->count == 0){
        printf("invalid...\n");
    } else {
        for(int i = index; i < l->count;i++){
            l->items[i] = l->items[i + 1];
        }
        l->count--;
    }
}
void insertSorted(Eptr l, int data){
    if(l->count >= MAX){
        printf("invalid..\n");
    } else {
        for(int i = l->count - 1; i >= 0 && l->elem[i] > data ; i--){
            l->items[i + 1] = l->items[i];
        }
        l->items[ i+ 1] = data;
        l->count++;
    }
}
void makeNULL(Eptr l){

}
