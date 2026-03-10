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

int main() {
    List *list = initialize();
    int op, cloc, found;
    Person tempP;

    while (1) {
        printf("\n\n--- Person List Manager (Linked) ---");
        printf("\n1. Insert First  2. Insert Last  3. Insert Pos");
        printf("\n4. Delete Start  5. Delete Last   6. Delete Pos");
        printf("\n7. Locate Person 8. Display List  0. Exit Program");
        printf("\nInput operation: ");
        
        if (scanf("%d", &op) != 1) break;

        switch (op) {
            case 0:
                empty(list);
                free(list);
                printf("Memory cleared. Goodbye!\n");
                exit(0);

            case 1:
            case 2:
            case 3:
                printf("Enter Name: ");
                scanf("%s", tempP.name);
                printf("Enter Age: ");
                scanf("%d", &tempP.age);
                
                if (op == 1) insertFirst(list, tempP);
                else if (op == 2) insertLast(list, tempP);
                else {
                    printf("Enter position (0-%d): ", list->count);
                    scanf("%d", &cloc);
                    insertPos(list, tempP, cloc);
                }
                break;

            case 4:
                if (list->count > 0) deleteStart(list);
                else printf("List is empty.\n");
                break;

            case 5:
                if (list->count > 0) deleteLast(list);
                else printf("List is empty.\n");
                break;

            case 6:
                if (list->count == 0) {
                    printf("List is empty.\n");
                } else {
                    printf("Enter index to delete (0-%d): ", list->count - 1);
                    scanf("%d", &cloc);
                    deletePos(list, cloc);
                }
                break;

            case 7:
                printf("Enter exact Name to find: ");
                scanf("%s", tempP.name);
                printf("Enter Age: ");
                scanf("%d", &tempP.age);
                found = locate(list, tempP);
                if (found != -1) printf("Found at index: %d\n", found);
                else printf("Person not found.\n");
                break;

            case 8:
                display(list);
                break;

            default:
                printf("Invalid option.\n");
        }
    }

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