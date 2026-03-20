#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Node structure (array-based)
typedef struct {
    char data;
    int next;
} Node;

// Virtual Heap
typedef struct {
    Node H[MAX];
    int avail;
} VHeap;

// List = index (like pointer)
typedef int List;

// ================= INITIALIZE =================
void initialize(VHeap *V){
    int i;
    for(i = 0; i < MAX - 1; i++){
        V->H[i].next = i + 1;
    }
    V->H[MAX - 1].next = -1;
    V->avail = 0;
}

// ================= ALLOC =================
int allocSpace(VHeap *V){
    int temp = V->avail;

    if(temp != -1){
        V->avail = V->H[temp].next;
    }

    return temp;
}

// ================= DEALLOC =================
void deallocSpace(VHeap *V, int index){
    V->H[index].next = V->avail;
    V->avail = index;
}

// ================= INSERT FIRST =================
void insertFirst(List *L, VHeap *V, char elem){
    int temp = allocSpace(V);

    if(temp != -1){
        V->H[temp].data = elem;
        V->H[temp].next = *L;
        *L = temp;
    }
}

// ================= INSERT LAST =================
void insertLast(List *L, VHeap *V, char elem){
    int temp = allocSpace(V);

    if(temp != -1){
        V->H[temp].data = elem;
        V->H[temp].next = -1;

        if(*L == -1){
            *L = temp;
        } else {
            int trav;
            for(trav = *L; V->H[trav].next != -1; trav = V->H[trav].next){}
            V->H[trav].next = temp;
        }
    }
}

// ================= INSERT SORTED =================
void insertSorted(List *L, VHeap *V, char elem){
    int temp = allocSpace(V);

    if(temp != -1){
        V->H[temp].data = elem;

        int *trav = L;

        while(*trav != -1 && V->H[*trav].data < elem){
            trav = &V->H[*trav].next;
        }

        V->H[temp].next = *trav;
        *trav = temp;
    }
}

// ================= DELETE ONE =================
void deleteElem(List *L, VHeap *V, char elem){
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

// ================= DELETE ALL =================
void deleteAll(List *L, VHeap *V, char elem){
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
    printf("List: ");
    int trav;

    for(trav = L; trav != -1; trav = V.H[trav].next){
        printf("%c -> ", V.H[trav].data);
    }
    printf("NULL\n");
}

// ================= MAIN =================
int main(){
    VHeap V;
    List L = -1;

    initialize(&V);

    insertFirst(&L, &V, 'C');
    insertFirst(&L, &V, 'A');
    insertLast(&L, &V, 'D');
    insertSorted(&L, &V, 'B');

    display(L, V);

    deleteElem(&L, &V, 'B');
    display(L, V);

    insertSorted(&L, &V, 'C');
    insertSorted(&L, &V, 'C');
    display(L, V);

    deleteAll(&L, &V, 'C');
    display(L, V);

    return 0;
}