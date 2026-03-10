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

// Variation 1
List initialize();
List empty(List list);
List insertFirst(List list, Person data);
List insertLast(List list, Person data);
List insertPos(List list, Person data, int index);
List deleteFirst(List list);
List deleteLast(List list);
List deletePos(List list, int index);
Person retrieve(List list, int index);
int locate(List list, Person data);
void display(List list);

int main() {
    List L = initialize();
    int op, cloc, found;
    Person tempP;

    while (1) {
        printf("\n--- Person List (Variation 1) ---");
        printf("\n1. insertFirst\n2. insertLast\n3. insertPos\n4. deleteFirst\n5. deleteLast\n6. deletePos\n7. locate\n8. display\n0. exit");
        printf("\nInput operation: ");
        scanf("%d", &op);

        switch (op) {
            case 0:
                L = empty(L); // Clean up memory before leaving
                exit(0);
                break;

            case 1: // Insert First
            case 2: // Insert Last
                printf("Enter Name: ");
                scanf("%s", tempP.name);
                printf("Enter Age: ");
                scanf("%d", &tempP.age);
                
                if (op == 1) L = insertFirst(L, tempP);
                else L = insertLast(L, tempP);
                break;

            case 3: // Insert Pos
                printf("Enter Name: ");
                scanf("%s", tempP.name);
                printf("Enter Age: ");
                scanf("%d", &tempP.age);
                printf("Enter Position (0-%d): ", L.count);
                scanf("%d", &cloc);
                L = insertPos(L, tempP, cloc);
                break;

            case 4: // Delete First
                L = deleteFirst(L);
                break;

            case 5: // Delete Last
                L = deleteLast(L);
                break;

            case 6: // Delete Pos
                printf("Enter index to delete: ");
                scanf("%d", &cloc);
                L = deletePos(L, cloc);
                break;

            case 7: // Locate
                printf("Enter Name to find: ");
                scanf("%s", tempP.name);
                printf("Enter Age to find: ");
                scanf("%d", &tempP.age);
                found = locate(L, tempP);
                if (found != -1) {
                    printf("Found %s at index %d\n", tempP.name, found);
                } else {
                    printf("Person not found.\n");
                }
                break;

            case 8: // Display
                display(L);
                break;

            default:
                printf("Invalid operation.\n");
        }
    }
    return 0;
}

List initialize(){
    List newList;
    newList.head = NULL;
    newList.count = 0;
    return newList;
}

List empty(List list){
    Node *current = list.head;
    Node *temp;
    while(current != NULL){
        temp = current;
        current = current->next;
        free(temp);
    }
    list.head = NULL;
    list.count = 0;
    return list;
}

List insertFirst(List list, Person data){
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list.head;
    list.head = newNode;
    list.count++;
    return list;
}

List insertLast(List list, Person data){
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if(list.head == NULL){
        list.head = newNode;
    } else {
        Node* current = list.head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
    }
    list.count++;
    return list;
}

List insertPos(List list, Person data, int index){
    if(index <= list.count && index >= 0){
        if(index == 0){
            return insertFirst(list, data);
        } else if(index == list.count){
            return insertLast(list, data);
        } else {
            Node* newNode = malloc(sizeof(Node));
            newNode->data = data;
            Node* current = list.head;
            for(int i = 0; i < index - 1; i++){
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
            list.count++;
        }
    }
    return list;
}

List deleteFirst(List list){
    if(list.head != NULL){
        Node* temp = list.head;
        list.head = list.head->next;
        free(temp);
        list.count--;
    }
    return list;
}

List deleteLast(List list){
    if(list.count == 0) return list;
    if(list.count == 1){
        free(list.head);
        list.head = NULL;
    } else {
        Node* current = list.head;
        while(current->next->next != NULL){
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
    }
    list.count--;
    return list;
}

List deletePos(List list, int index){
    if(index < 0 || index >= list.count) return list;
    if(index == 0) return deleteFirst(list);

    Node* current = list.head;
    for(int i = 0; i < index - 1; i++){
        current = current->next;
    }
    Node* temp = current->next;
    current->next = temp->next;
    free(temp);
    list.count--;
    return list;
}

Person retrieve(List list, int index){
    if(index >= list.count || index < 0){
        printf("Invalid index\n");
        Person dummy = {"None", -1};
        return dummy;
    }

    Node* current = list.head;
    for(int i = 0; i < index; i++){
        current = current->next;
    }
    return current->data;
}

int locate(List list, Person data){
    Node* current = list.head;
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

void display(List list){
    Node *current = list.head;
    while(current != NULL){
        printf("[%s, %d] -> ", current->data.name, current->data.age);
        current = current->next;
    }
    printf("NULL\n");
}