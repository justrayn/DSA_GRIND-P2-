#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10

typedef struct {
    int *elemPtr;
    int count;
    int max;
} List;

List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);
List resize(List L);

int main (){

    List L;
    L = initialize(L);

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
            free(L.elemPtr);
            exit(0);

        case 1:
            printf("What do you want to insert?: ");
            scanf("%d", &cData);

            printf("Where do you want to put it? (0-%d): ", L.count);
            scanf("%d", &cLoc);

            L = insertPos(L, cData, cLoc);
        break;

        case 2:
            if(L.count == 0){
                printf("Nothing to delete.\n");
            }else{
                printf("What position do you want to delete?: ");
                scanf("%d", &cLoc);

                L = deletePos(L, cLoc);
            }
        break;

        case 3:
            if(L.count == 0){
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
            printf("What do you want to insert?: ");
            scanf("%d", &cData);

            L = insertSorted(L, cData);
        break;

        case 5:
            if(L.count == 0){
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

List initialize(List L){
    L.elemPtr = malloc(sizeof(int) * LENGTH);
    L.max = LENGTH;
    L.count = 0;
    return L;
}

List insertPos(List L, int data, int position){

    if(position < 0 || position > L.count){
        printf("Invalid Position.\n");

    } else {

        if(L.count >= L.max){
            printf("Full resizing...\n");
            L = resize(L);
        }

        for(int i = L.count; i > position; i--){
            L.elemPtr[i] = L.elemPtr[i - 1];
        }

        L.elemPtr[position] = data;
        L.count++;
    }

    return L;
}

List deletePos(List L, int position){

    if(position < 0 || position >= L.count){
        printf("Invalid Position.\n");

    } else {

        for(int i = position; i < L.count - 1; i++){
            L.elemPtr[i] = L.elemPtr[i + 1];
        }

        L.count--;
    }

    return L;
}

int locate(List L, int data){

    int i;
    int found = -1;

    for(i = 0; i < L.count && L.elemPtr[i] != data; i++){}

    if(i < L.count){
        found = i;
    }

    return found;
}

List insertSorted(List L, int data){

    if(L.count >= L.max){
        printf("Info is full resizing...\n");
        L = resize(L);
    }

    int i;

    for(i = L.count - 1; i >= 0 && L.elemPtr[i] > data; i--){
        L.elemPtr[i + 1] = L.elemPtr[i];
    }

    L.elemPtr[i + 1] = data;
    L.count++;

    return L;
}

void display(List L){

    printf("elem: ");

    for(int i = 0; i < L.count; i++){
        printf("%d ", L.elemPtr[i]);
    }

    printf("\n");
}

List resize(List L){

    int newMax = L.max * 2;

    int *newPtr = realloc(L.elemPtr, sizeof(int) * newMax);

    if(newPtr != NULL){
        L.elemPtr = newPtr;
        L.max = newMax;
    }

    return L;
}