
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int data;
    int next;
} Cell;

typedef Cell HeapSpace[MAX];

typedef struct {
    HeapSpace H;
    int avail;
} VHeap;

typedef int List;

// FUNCTION PROTOTYPES
void initialize(VHeap *V);
int allocSpace(VHeap* V);
void deallocSpace(VHeap* V, int index);

void insertFirst(List *L, VHeap* V, int elem);
void insertLast(List *L, VHeap* V, int elem);
void insertPos(List *L, VHeap* V, int elem, int pos);
void insertSorted(List *L, VHeap* V, int elem);

void delete(List *L, VHeap* V, int elem);
void deleteAllOccurrence(List *L, VHeap* V, int elem);

void display(List L, VHeap V);

// ================= MAIN =================
int main(){
    VHeap V;
    List L = -1;

    initialize(&V);

    insertFirst(&L, &V, 50);
    insertFirst(&L, &V, 77);
    insertLast(&L, &V, 30);
    insertLast(&L, &V, 99);

    printf("List: ");
    display(L, V);

    insertPos(&L, &V, 100, 2);
    printf("After insertPos: ");
    display(L, V);

    insertSorted(&L, &V, 60);
    printf("After insertSorted: ");
    display(L, V);

    delete(&L, &V, 77);
    printf("After delete 77: ");
    display(L, V);

    deleteAllOccurrence(&L, &V, 30);
    printf("After deleteAllOccurrence 30: ");
    display(L, V);

    return 0;
}

// ================= CORE =================

void initialize(VHeap *V){
    V->avail = 0;
    for(int i = 0; i < MAX - 1; i++){
        V->H[i].next = i + 1;
    }
    V->H[MAX - 1].next = -1;
}

int allocSpace(VHeap* V){
    int temp = V->avail;

    if(temp != -1){
        V->avail = V->H[temp].next;
    }

    return temp;
}

void deallocSpace(VHeap* V, int index){
    V->H[index].next = V->avail;
    V->avail = index;
}

// ================= INSERT =================

void insertFirst(List *L, VHeap* V, int elem){
    int new = allocSpace(V);

    if(new != -1){
        V->H[new].data = elem;
        V->H[new].next = *L;
        *L = new;
    }
}

void insertLast(List *L, VHeap* V, int elem){
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

// insert at POSITION (0-based)
void insertPos(List *L, VHeap* V, int elem, int pos){
    int new = allocSpace(V);

    if(new != -1){
        V->H[new].data = elem;

        if(pos == 0){
            V->H[new].next = *L;
            *L = new;
        } else {
            int temp = *L;
            int i;

            for(i = 0; i < pos - 1 && temp != -1; i++){
                temp = V->H[temp].next;
            }

            if(temp != -1){
                V->H[new].next = V->H[temp].next;
                V->H[temp].next = new;
            }
        }
    }
}

// insert sorted (ascending)
void insertSorted(List *L, VHeap* V, int elem){
    int new = allocSpace(V);

    if(new != -1){
        V->H[new].data = elem;

        int *trav = L;

        while(*trav != -1 && V->H[*trav].data < elem){
            trav = &V->H[*trav].next;
        }

        V->H[new].next = *trav;
        *trav = new;
    }
}

// ================= DELETE =================

void delete(List *L, VHeap* V, int elem){
    int *trav = L;

    while(*trav != -1 && V->H[*trav].data != elem){
        trav = &V->H[*trav].next;
    }

    if(*trav != -1){
        int temp = *trav;
        *trav = V->H[temp].next;
        deallocSpace(V, temp);
    }
}

void deleteAllOccurrence(List *L, VHeap* V, int elem){
    int *trav = L;

    while(*trav != -1){
        if(V->H[*trav].data == elem){
            int temp = *trav;
            *trav = V->H[temp].next;
            deallocSpace(V, temp);
        } else {
            trav = &V->H[*trav].next;
        }
    }
}

// ================= DISPLAY =================

void display(List L, VHeap V){
    int temp = L;

    while(temp != -1){
        printf("%d ", V.H[temp].data);
        temp = V.H[temp].next;
    }
    printf("\n");
}