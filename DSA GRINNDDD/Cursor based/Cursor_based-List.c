#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 4


//cursor base var 1

typedef struct {
    int data;
    int next;
}Cell, HeapSpace[MAX];

 typedef struct {
    HeapSpace H;
    int avail;
}VHeap;

typedef int List;

void initialize(VHeap *V);
int allocSpace(VHeap* V);
void deallocSpace(VHeap* V, int index);
void insertFirst(int* L, VHeap* V, int elem);
void insertLast(int *L, VHeap* V, int elem);
void insertPos(int* L, VHeap* V, int elem);
void insertSorted(int* L, VHeap* V, int elem);
void delete(int* L, VHeap* V, int elem);
void deleteAllOccurence(int* L, VHeap* V, int elem);
void display(int L, VHeap V);

int main(){



    return 0;
}

void initialize(VHeap *V){
    V->avail = 0;
    for(int i = 0 ; i < MAX;i++){
        V->H[i].next = i + 1;
    }
    V->H[MAX - 1].next = -1;
}
int allocSpace(VHeap* V){
    int data = 0;
    if(V->avail <= MAX - 1){
        data = V->H[V->avail];
        V->avail = V->H[V->avail].next;
    }
    return data;
}
void deallocSpace(VHeap* V, int index){
    V->H[index].next = V->avail;
    V->avail = index;
}
void insertFirst(int* L, VHeap* V, int elem){
    int new = allocSpace(V);

    if(new != -1){
        V->H[new].data = elem;
        V->H[new].next = *L;
        *L = new;
    }
}
void insertLast(int *L, VHeap* V, int elem){
    int new = allocSpace(V);

    if(new != -1){
        V->H[new].data = elem;
        V->H[new].next = -1;

        if(*L == -1){
            *L = new;
        } else {
            int temp = *L;
            while(V->H[temp].next != -1){
                temp = V->H[temp].next;
            }
            V->H[temp].next = new;
        }
    }
}
void insertPos(int* L, VHeap* V, int elem){

}
void insertSorted(int* L, VHeap* V, int elem){

}
void delete(int* L, VHeap* V, int elem){

}
void deleteAllOccurence(int* L, VHeap* V, int elem){

}
void display(int L, VHeap V){
    int temp = L;

    while(temp != -1){
        printf("%d ", V.H[temp].data);
        temp = V.H[temp].next;
    }
    printf("\n");
}