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


void initialize();
void allocSpace();
void deallocSpace();



int main(){



    return 0;
}