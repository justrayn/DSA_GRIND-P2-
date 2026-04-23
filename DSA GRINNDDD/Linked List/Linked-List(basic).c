      #include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int data;
    struct Node *next;
}NodeType, *NodePtr, *List;

void initList(List *);
void displayList(List);
void insertFront(List *, int);
void insertRear(List *, int);
void insertSorted(List *, int);
void deleteFront(List *);
void deleteRear(List *);
void deleteAll(List *);

int main(){
    List list;
    initList(&list);
    insertFront(&list, 10);
    displayList(list);
    insertRear(&list, 1);
    displayList(list);
    insertSorted(&list, 100);
    displayList(list);
    insertSorted(&list, 20);
    displayList(list);
    deleteFront(&list);
    displayList(list);
    deleteAll(&list);
    displayList(list);

    return 0;
}

void initList(List *l){
    *l = NULL;
}

void displayList(List list){
    if(list == NULL){
        printf("empty.");
        return;
    }
    printf("Front -> ");
    while(list){
        
        printf("%d", list->data);
        if(list->next != NULL){
            printf(" -> ");
        } 
        list = list->next;
    }

    printf(" -> rear\n");
}

    void insertFront(List *l, int elem){
        List newD = malloc(sizeof(NodeType));
        if(newD == NULL){
            return;
        }

        newD->data = elem;
        newD->next = *l;
        *l = newD;
    }

void insertRear(List *l, int elem){
    List newD = malloc(sizeof(NodeType));
    if(newD == NULL){
        return;
    }
    newD->data = elem;
    newD->next = NULL;

    if(*l == NULL){
        *l = newD;
    } else {
        // List trav = *l;
        // while(trav->next != NULL){
        //     trav = trav->next;
        // }
        // trav->next = newD;

        List *trav;
            for(trav = l; (*trav)->next != NULL; trav = &(*trav)->next){}
            (*trav)->next = newD;

    }
}


void insertSorted(List *list, int elem){
     List newD = malloc(sizeof(NodeType));
    if(newD == NULL){
        return;
    }

    List *trav;

    for(trav = list; *trav != NULL && (*trav)->data < elem; trav = &(*trav)->next ){}
    newD->data = elem;
    newD->next = *trav;
    *trav = newD;
}

void deleteFront(List *list){
    if(*list == NULL){
        return;
    }

    List temp = *list;
    *list = (*list)->next;
    free(temp);
}
void deleteRear(List *l) {
    if (*l == NULL) return;

    List *trav;
    for (trav = l; (*trav)->next != NULL; trav = &(*trav)->next) {}

    free(*trav);
    *trav = NULL;
}


void deleteAll(List *list){
    List temp;

    while(*list != NULL){
        temp = *list;
        *list = (*list)->next;
        free(temp);
    }

}