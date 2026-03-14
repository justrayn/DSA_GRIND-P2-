#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
} Etype, *EPtr;

void initialize(EPtr L);
void insertPos(EPtr L, int data, int position);
void deletePos(EPtr L, int position);
int locate(EPtr L, int data);
int retrieve(EPtr L, int position);
void insertSorted(EPtr L, int data);
void display(EPtr L);
void makeNULL(EPtr L);

int main (){
    EPtr L = (EPtr)malloc(sizeof(Etype));
    initialize(L);

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
            free(L);
            exit(0);

        case 1:
            if(L->count >= MAX){
                printf("Can't insert. List is full.\n");
            }else{

                printf("What do you want to insert?: ");
                scanf("%d", &cData);

                printf("Where do you want to put it? (0-%d): ", L->count);
                scanf("%d", &cLoc);

                insertPos(L, cData, cLoc);
            }
        break;

        case 2:
            if(L->count == 0){
                printf("Nothing to delete.\n");
            }else{

                printf("What position do you want to delete?: ");
                scanf("%d", &cLoc);

                deletePos(L, cLoc);
            }
        break;

        case 3:
            if(L->count == 0){
                printf("List is empty.\n");
            }else{

                printf("Find what?: ");
                scanf("%d", &cData);

                found = locate(L, cData);

                if(found != -1){
                    printf("Wow its actually there.. in %d\n", found);
                }else{
                    printf("Not there...\n");
                }
            }
        break;

        case 4:
            if(L->count >= MAX){
                printf("List is full.\n");
            }else{

                printf("What do you want to insert?: ");
                scanf("%d", &cData);

                insertSorted(L, cData);
            }
        break;

        case 5:
            if(L->count == 0){
                printf("Nothing here...\n");
            }else{
                printf("Displaying data...\n");
                display(L);
            }
        break;

        default:
            printf("Invalid option.\n");
        }
    }

    return 0;
}

void initialize(EPtr L){
    L->count = 0;
}

void insertPos(EPtr L, int data, int position){

    if(position < 0 || position > L->count || L->count >= MAX){
        printf("Invalid Position!\n");
    } else {

        for(int i = L->count; i > position; i--){
            L->elem[i] = L->elem[i - 1];
        }

        L->elem[position] = data;
        L->count++;
    }
}

void deletePos(EPtr L, int position){

    if(position < 0 || position >= L->count){
        printf("Invalid Position!\n");
    } else {

        for(int i = position; i < L->count - 1; i++){
            L->elem[i] = L->elem[i + 1];
        }

        L->count--;
    }
}

int locate(EPtr L, int data){
    int i;
    for(i = 0; i < L->count && L->elem[i] != data; i++){}
    return (i < l->count) ? i : -1;
}

int retrieve(EPtr L, int position){

    int data = -10000000;

    if(position >= 0 && position < L->count){
        data = L->elem[position];
    }

    return data;
}

void insertSorted(EPtr L, int data){

    if(L->count >= MAX){
        printf("List is full.\n");

    } else {

        int i;

        for(i = L->count - 1; i >= 0 && L->elem[i] > data; i--){
            L->elem[i + 1] = L->elem[i];
        }

        L->elem[i + 1] = data;
        L->count++;
    }
}

void display(EPtr L){

    printf("elem: ");

    for(int i = 0; i < L->count; i++){
        printf("%d ", L->elem[i]);
    }

    printf("\n");
}

void makeNULL(EPtr L){
    free(L);
}