#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
} List;

List initialize (List L);
List insertPos (List L, int data, int position);
List deletePos(List L, int position);
int locate (List L, int data);
List insertSorted (List L, int data);
void display(List L);

int main (){
    List L = initialize(L);

    while(1){
        int op, cData, cLoc, found;
        printf("\nplease choose what kind of operation...\n\n");
        printf("\n1: Insert\n");
        printf("2: Delete\n");
        printf("3: Locate\n");
        printf("4: InsertSorted\n");
        printf("5: Show\n");
        printf("0: Exit\n");
        printf("Enter operation: ");
        scanf("%d", &op);

        switch(op){
            case 0:
            exit(0);
            break;

            case 1:
            if(L.count >= MAX){
                printf("can't do this case its full.\n");
            } else {
            printf("what do you wanna insert?...(just numbers plzplzplzpx)");
            scanf("%d", &cData);
            printf("and Where do you wanna put it?(0-%d)", L.count);
            scanf("%d", &cLoc);
            L = insertPos(L, cData, cLoc);
            }

            break;

            case 2:
            printf("\ndoing deletePos\n What position do you wanna delete?...");
            scanf("%d", &cLoc);
            L = deletePos(L, cLoc);
            break;
        
            case 3:
             if(L.count == 0){
                printf("cant do this case. nothing is in there\n");
            } else {
                printf("find what..?");
                scanf("%d", &cLoc);
                found = locate(L, cLoc);
                if(found != -1){
                    printf("wow its actually there.. in %d\n", found);
                } else {
                    printf("not there...\n");
                }
            }
            
            break;

            case 4:
            if(L.count >= MAX ){
                printf("can't do this case its full.\n");
            } else {
            printf("doing InsertSorted\nwhat do you wanna insert?...");
            scanf("%d", &cData);
            L = insertSorted (L, cData);
            }
            break;

            case 5:
            if(L.count == 0){
                printf("nothings here...\n");
            } else {
                 printf("displaying data...\n");
            display(L);
            }
           
            break;
        }
    


    }
    return 0;
}

List initialize (List L){
    L.count = 0;
    return L;
}

List insertPos (List L, int data, int position){
    if(position < 0 || position > L.count || L.count >= MAX){
        printf("Invalid Position or List is full.\n");
    } else {
    int i;
    for(i = L.count; i > position; i--){
        L.elem[i] = L.elem[i - 1];
    }
    L.elem[position] = data;
    L.count++;
    }
    return L;
}

List deletePos(List L, int position){

    if(position < 0 || position >= L.count){
        printf("Invalid Position.\n");
    } else {

    int i;
    for(i = position; i < L.count-1; i++){
        L.elem[i] = L.elem[i+1];
    }
    L.count--;
    }
    return L;
}

int locate (List L, int data){
    int i;
    for(i = 0; i < L.count && L.elem[i] != data; i++){}
    return (i < L.count) ? i : -1;
    
}

List insertSorted (List L, int data){

    if(L.count >= MAX){
        printf("List is full.\n");
    } else{
 
    int i;
    for(i = L.count-1;i >= 0 && L.elem[i] > data;i--){
        L.elem[i+1] = L.elem[i];
    }
    L.elem[i+1] = data;
    L.count++;
    
    }
   return L;
}

void display(List L){
    printf("elem: ");
    for(int i = 0; i < L.count; i++){
        printf("%d ", L.elem[i]);
    }
}