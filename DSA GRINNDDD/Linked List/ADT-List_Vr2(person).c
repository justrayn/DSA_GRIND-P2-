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

    while(1){
        int op, cloc, found;
        Person tempP;

        printf("\n\n--Please choose an operation--\n");
        printf("\n0.exit program");
        printf("\n1.insertFirst");
        printf("\n2.insertLast");
        printf("\n3.insertPos");
        printf("\n4.deleteStart");
        printf("\n5.deleteLast");
        printf("\n6.deletePos");
        printf("\n7.locate");
        printf("\n8.display all");
        printf("\nInput operation: ");
        scanf("%d", &op);

        switch(op){

            case 0:
                empty(list);
                free(list);
                printf("\nMemory cleared. Goodbye!\n");
                exit(0);
                break;

            case 1:
                printf("\nUsing insertFirst...\n");
                printf("Enter Name: ");
                scanf("%s", tempP.name);
                printf("Enter Age: ");
                scanf("%d", &tempP.age);

                insertFirst(list, tempP);
                break;

            case 2:
                printf("\nUsing insertLast...\n");
                printf("Enter Name: ");
                scanf("%s", tempP.name);
                printf("Enter Age: ");
                scanf("%d", &tempP.age);

                insertLast(list, tempP);
                break;

            case 3:
                printf("\nUsing insertPos...\n");
                printf("Enter Name: ");
                scanf("%s", tempP.name);
                printf("Enter Age: ");
                scanf("%d", &tempP.age);

                printf("Enter position (0-%d): ", list->count);
                scanf("%d", &cloc);

                insertPos(list, tempP, cloc);
                break;

            case 4:
                if(list->count == 0){
                    printf("\nNothing to delete...\n");
                } else {
                    printf("\nUsing deleteStart...\n");
                    deleteStart(list);
                }
                break;

            case 5:
                if(list->count == 0){
                    printf("\nNothing to delete...\n");
                } else {
                    printf("\nUsing deleteLast...\n");
                    deleteLast(list);
                }
                break;

            case 6:
                if(list->count == 0){
                    printf("\nNothing to delete...\n");
                } else {
                    printf("\nUsing deletePos...\n");
                    printf("Enter index to delete: ");
                    scanf("%d", &cloc);

                    deletePos(list, cloc);
                }
                break;

            case 7:
                if(list->count == 0){
                    printf("\nNothing to locate...\n");
                } else {
                    printf("\nUsing locate...\n");
                    printf("Enter Name: ");
                    scanf("%s", tempP.name);
                    printf("Enter Age: ");
                    scanf("%d", &tempP.age);

                    found = locate(list, tempP);

                    if(found == -1){
                        printf("\nPerson not found.\n");
                    } else {
                        printf("\n%s found at index %d\n", tempP.name, found);
                    }
                }
                break;

            case 8:
                printf("\nDisplaying list...\n");
                display(list);
                break;

            default:
                printf("\nInvalid operation.\n");
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
