#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

typedef struct {
    int *elemPtr;
    int count;
    int max;
} List;

void initialize(List *L);
void insertPos(List *L, int data, int position);
void deletePos(List *L, int position);
int locate(List *L, int data);
int retrieve(List *L, int position);
void insertSorted(List *L, int data);
void display(List *L);
void resize(List *L);
void makeNULL(List *L);
int main (){
    List L;
    initialize(&L);

    while(1){

        int op, cData, cLoc, found;

        printf("\nplease choose what kind of operation...\n\n");
        printf("1: Insert\n");
        printf("2: Delete\n");
        printf("3: Locate\n");
        printf("4: InsertSorted\n");
        printf("5: Show\n");
        printf("0: Exit\n");

        printf("Enter operation: ");
        scanf("%d", &op);

        switch(op){

        case 0:
            makeNULL(&L);
            exit(0);

        case 1:
            printf("What do you want to insert?: ");
            scanf("%d", &cData);

            printf("Where do you want to put it? (0-%d): ", L.count);
            scanf("%d", &cLoc);

            insertPos(&L, cData, cLoc);
        break;

        case 2:
            if(L.count == 0){
                printf("Nothing to delete.\n");
            }else{
                printf("Enter position to delete: ");
                scanf("%d", &cLoc);

                deletePos(&L, cLoc);
            }
        break;

        case 3:
            if(L.count == 0){
                printf("List is empty.\n");
            }else{

                printf("Find what?: ");
                scanf("%d", &cData);

                found = locate(&L, cData);

                if(found != -1){
                    printf("Wow its actually there.. in %d\n", found);
                }else{
                    printf("Not there...\n");
                }
            }
        break;

        case 4:
            printf("What do you want to insert?: ");
            scanf("%d", &cData);

            insertSorted(&L, cData);
        break;

        case 5:
            if(L.count == 0){
                printf("Nothing here...\n");
            }else{
                printf("Displaying data...\n");
                display(&L);
            }
        break;

        default:
            printf("Invalid option.\n");
        }
    }

    return 0;
}
void initialize(List *L){
    L->elemPtr = malloc(sizeof(int) * LENGTH);
    L->max = LENGTH;
    L->count = 0;
}

void insertPos(List *L, int data, int position){
    if(position > L->count || position < 0){
        printf("Invalid Position.\n");
    } else {
        if(L->count >= L->max){
        resize(L);
        }

        int i;
        for(i = L->count; i > position; i--){
            L->elemPtr[i] = L->elemPtr[i - 1];
        }

        L->elemPtr[position] = data;
        L->count++;
    }
}

void deletePos(List *L, int position){
    if(position >= L->count || position < 0){
        printf("Invalid Position.\n");
    } else {
        int i;
        for(i = position; i < L->count - 1; i++){
            L->elemPtr[i] = L->elemPtr[i + 1];
        }
        L->count--;
    }
}

int locate(List *L, int data){
    int i;
    int found = -1;
    for(i = 0; i < L->count && L->elemPtr[i] != data ; i++){}
    if(i < L->count){
        found = i;
    }
    return found;
}

int retrieve(List *L, int position){
    int found = -10000;
    if(position >= L->count || position < 0){
        printf("Invalid Position.\n");
    } else {
        found = L->elemPtr[position];
    }
    return found;
}

void insertSorted(List *L, int data){
    if(L->count >= L->max){
        resize(L);
    }
    int i;
    for(i = L->count - 1; i >= 0 && L->elemPtr[i] > data; i--){
        L->elemPtr[i + 1] = L->elemPtr[i];
    }
    L->elemPtr[i + 1] = data;
    L->count++;
}

void display(List *L){
    int i;
    for(i = 0; i < L->count; i++){
        printf("%d ", L->elemPtr[i]);
    }
    printf("\n");
}

void resize(List *L){
    L->max *= 2;
    L->elemPtr = realloc(L->elemPtr, sizeof(int) * L->max);
}

void makeNULL(List *L){
    if(L->elemPtr != NULL){
         free(L->elemPtr);
    L->elemPtr = NULL;
    }
    L->count = 0;
    L->max = 0;
}