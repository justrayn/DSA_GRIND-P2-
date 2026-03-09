#include <stdio.h>

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
        int op;
        printf("please choose what kind of operation...\n\n");
        scanf("%d", &op);
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
    int found = -1;
    for(i = 0; i < L.count && L.elem[i] != data; i++){}
    if( i < L.count){
        found = i;
    }
    return found;
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