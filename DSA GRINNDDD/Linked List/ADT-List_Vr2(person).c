#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[30];
    int age;
} Person;

typedef struct node {
    Person data;
    struct node *next;
} Node;

typedef struct {
    Node *head;
    int count;
} List;

// Variation 2
List* initialize();
void empty(List *list);
void insertFirst(List *list, Person data);
void insertLast(List *list, Person data);
void insertPos(List *list, Person data, int index);
void deleteStart(List *list);
void deleteLast(List *list);
void deletePos(List *list, int index);
Person retrieve(List *list, int index);
int locate(List *list, Person data);
void display(List *list);

int main (){
    List *list = initialize();

    Person p1 = {"Alice", 25};
    Person p2 = {"Bob", 30};
    Person p3 = {"Charlie", 22};
    Person p4 = {"Diana", 28};

    insertLast(list, p2);  // Bob
    insertLast(list, p3);  // Charlie
    insertFirst(list, p1); // Alice at start
    insertPos(list, p4, 2); // Diana at index 2

    display(list);
    
    Person retrieved = retrieve(list, 1);
    printf("Retrieved index 1: %s, %d\n", retrieved.name, retrieved.age);
    
    printf("Locate Bob: Index %d\n", locate(list, p2));

    deleteStart(list);
    deleteLast(list);
    deletePos(list, 1);

    printf("After Deleting: ");
    display(list);

    empty(list);
    free(list); // Clean up the list container itself

    return 0;
}

List* initialize(){
    List *newList = malloc(sizeof(List));
    if(newList == NULL){
        printf("Memory Allocation Failed\n");
        return NULL;
    }
    newList->head = NULL;
    newList->count = 0;
    return newList;
}

void empty(List *list){
    if (list == NULL) return;
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

void insertFirst(List *list, Person data){
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) return;
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    list->count++;
}

void insertLast(List *list, Person data){
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) return;
    newNode->data = data;
    newNode->next = NULL;
    
    if(list->head == NULL){
        list->head = newNode;
    } else {
        Node* current = list->head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
    }
    list->count++;
}

void insertPos(List *list, Person data, int index){
    if(index < 0 || index > list->count) return;

    if(index == 0){
        insertFirst(list, data);
    } else if(index == list->count){
        insertLast(list, data);
    } else {
        Node* newNode = malloc(sizeof(Node));
        newNode->data = data;
        Node* current = list->head;
        for(int i = 0; i < index - 1; i++){
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        list->count++;
    }
}

void deleteStart(List *list){
    if (list->head == NULL) return;
    Node* temp = list->head;
    list->head = list->head->next;
    free(temp);
    list->count--;
}

void deleteLast(List *list){
    if (list->count == 0) return;
    if (list->count == 1){
        free(list->head);
        list->head = NULL;
    } else {
        Node* current = list->head;
        while(current->next->next != NULL){
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
    }
    list->count--;
}

void deletePos(List *list, int index){
    if (index < 0 || index >= list->count) return;
    if (index == 0){
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

Person retrieve(List *list, int index){
    Person dummy = {"None", -1};
    if(index >= list->count || index < 0){
        printf("Invalid index\n");
        return dummy;
    } 
    Node* current = list->head;
    for(int i = 0; i < index; i++){
        current = current->next;
    }
    return current->data;
}

int locate(List *list, Person data){
    Node* current = list->head;
    int index = 0;
    while(current != NULL){
        if(current->data.age == data.age && strcmp(current->data.name, data.name) == 0){
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}

void display(List *list){
    Node* current = list->head;
    while(current != NULL){
        printf("[%s, %d] --> ", current->data.name, current->data.age);   
        current = current->next;
    }
    printf("NULL\n");
}