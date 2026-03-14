#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int elems[MAX];
    int count;
}NodeType, *NodePtr;

void init(NodePtr l);
void insertPos(NodePtr l, int data, int pos);
void deletePos(NodePtr l, int pos);
void insertSorted(NodePtr l, int data);
void makeNULL(NodePtr l);

int main(){




    return 0;
}

void init(NodePtr l){
    l->count = 0;
}
void insertPos(NodePtr l, int data, int pos){
    if(pos < 0 || pos > l->count || l->count >= MAX){
        printf("invalid!\n");
    } else {
        for(int i = l->count ; i > pos ; i--){
            l->elems[i] = l->elems[i - 1];
        }
        l->count++;
        l->elems[pos] = data;
    }
}
void deletePos(NodePtr l, int pos){
    if(pos < 0 || pos > l->count) {
        printf("invalid!\n");
    } else if(l->count == 0){
        printf("theres nothing to delete..\n");
    } else {
        for(int i = pos;i < l->count - 1;i++){
            l->elems[i] = l->elemx[i + 1];
        }
        l->count--;
    }
}
void insertSorted(NodePtr l, int data)[
    if(l->count >= MAX){
        printf("invalid!\n");
    } else {
        for(int i = l->count - 1 ; i >= 0 && l->elems[i] > data ; i--){
            l->elems[i + 1] = l->elems[i];
        }
        l->count++;
        l->elems[i + 1] = data;
    }
]
void makeNULL(NodePtr l){
    free(l);
}
