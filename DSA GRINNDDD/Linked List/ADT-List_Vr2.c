#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *head;
    int count;
} List;

// Variation 2
List* initialize();
void empty(List *list);
void insertFirst(List *list, int data);
void insertLast(List *list, int data);
void insertPos(List *list, int data, int index);
void deleteStart(List *list);
void deleteLast(List *list);
void deletePos(List *list, int index);
int retrieve(List *list, int index);
int locate(List *list, int data);
void display(List *list);

int main (){

    List *list = initialize();
    insertLast(list, 2);
    insertLast(list, 6);
    insertLast(list, 5);

    insertFirst(list, 7);
    insertLast(list, 7);
    insertPos(list, 7, 2);
    display(list);
    
    deleteStart              (list);
    deleteLast(list);
    deletePos(list, 1);

    printf("Retrieved index 1: %d\n", retrieve(list, 1));
    printf("Locate data 6: %d\n", locate(list, 6));
    printf("After Deleting: ");
    display(list);
    empty(list);

    return 0;
}

List* initialize(){

    List *List = malloc(sizeof(List));
    if(List == NULL){
        printf("Memory Allocation Failed");
        return NULL;
    }
    List->head = NULL;
    List->count = 0;
    return List;

}


void empty(List *list){
    Node *current = list->head;
    Node *temp;
    while(current != NULL){
        temp = current;
        current = current->next;
        free(temp);
    }
    list->head = NULL;
    list->count = 0;

}

void insertFirst(List *list, int data){
    Node *newNode = malloc(sizeof(Node));
    if(newNode != NULL){
        newNode->data = data;
        newNode->next = list->head;
        list->head = newNode;
        list->count++;
    }
}
   

void insertLast(List *list, int data){
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if(list->head == NULL){
        list->head = newNode;
        list->count++;
    } else {
        Node* current = list->head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
        list->count++;
    }


}

void insertPos(List *list, int data, int index){
    if(index <= list->count){
        if(index == 0){
        insertFirst(list, data);
        } else if(index == list->count){
            insertLast(list, data);
        } else {
        Node* newNode = malloc(sizeof(Node));
        newNode->data = data;
        Node* current = list->head;
        for(int i = 0; i < index - 1 && current->next != NULL; i++){
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        list->count++;
        }
    }

}

void deleteStart(List *list){
    if(list->head != NULL){
        Node* current = list->head;
        list->head = list->head->next;
        free(current);
        list->count--;
    }
     
}

void deleteLast(List *list){
    if(list->count == 0){
        printf("nothing to delete dumass");
    } else if(list->count == 1){
        free(list->head);
        list->head = NULL;
        list->count--;

    } else {
        Node* current = list->head;
        for(int i = 0; i < list->count - 2; i++){
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
        list->count--;
    }
    

}

void deletePos(List *list, int index){
    if(index == 0){
        deleteStart(list);
    } else {
        Node* current = list->head;
        for(int i = 0; i < index - 1; i++){
            current = current->next;
        }
        
        Node* temp = current->next;
        current->next = temp->next;
        free(temp);
        list->count--;
    }
}

int retrieve(List *list, int index){
    int val = -1;
    if(index >= list->count || index < 0){
        printf("Invalid index");
    } else {
        Node* current = list->head;
        for(int i = 0; i < index; i++){
            current = current->next;
        }
        val = current->data;
    }
    return val;
}

int locate(List *list, int data){
    int retval = -1;
    Node* current = list->head;
    int index = 0;

    while(current != NULL && retval == -1){
        if(current->data == data){
            retval = index;
        } else {
            current = current->next;
            index++;
        }
    }

    return retval;
}

void display(List *list){
    Node* current = list->head;
    while(current != NULL){
       printf("%d --> ", current->data);   
        current = current->next;
    }
    printf("NULL\n");
}