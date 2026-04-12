#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

typedef struct {
    int data;
    int next;
}Cell, HeapSpace[MAX];

typedef struct {
    Heapspace H;
    int avail;
}VHeap;


void initialize(VHeap *V);
int allocSpace(VHeap *V);
void deallocSpace(VHeap *V, int inedex);

int main(){



    return 0;
}


void initialize(VHeap *V){
    V->avail = 0;
}
int allocSpace(VHeap *V){
    for(int i = 0; i < MAX; i++){
        V->H[i].next;
    }
}
void deallocSpace(VHeap *V, int inedex){

}
