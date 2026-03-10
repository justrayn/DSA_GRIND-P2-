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

// Variation 1
List initialize();
List empty(List list);
List insertFirst(List list, int data);
List insertLast(List list, int data);
List insertPos(List list, int data, int index);
List deleteFirst(List list);
List deleteLast(List list);
List deletePos(List list, int index);
int retrieve(List list, int index);
int locate(List list, int data);
void display(List list);

int main (){

    List L = initialize();
    
    while(1){
        int op, cdata, cloc, found;
        printf("\n\n--Please choose an operation--\n");
        printf("\n0.exit program\n1.insertFirst\n2.insertLast\n3.insertPos\n4.deleteFirst\n5.deleteLast\n6.deletePos\n7.Locate\n8.diplying all i have got </3\nInput operation:");
        scanf("%d", &op);
        
        switch(op){
            case 0:
            exit(0);
            break;

            case 1:
            printf("\n.using the insertFirst..\n Input data to insert: ");
            scanf("%d", &cdata);
            L = insertFirst(L, cdata);
            break;
            
            case 2:
             printf("\n.using the insertLast..\n Input data to insert: ");
             scanf("%d", &cdata);
             L = insertLast(L, cdata);
            break;

            case 3:
             printf("\n.using the insertPos..\n Input data to insert: ");
              scanf("%d", &cdata);
              printf("\nwhat position?(0-%d)", L.count);
              scanf("%d", &cloc);
              L = insertPos(L, cdata, cloc);
            break;

            case 4:
            if(L.count == 0){
                printf("\nnothing to delete im sorry...\n");
            } else {
                printf("\n.using the deleteFirst..\ndeleting first data..\n");
            L = deleteFirst(L);
            }
            break;

            case 5:
            if(L.count == 0){
                printf("\nnothing to delete im sorry...\n");
            } else {
                printf("\n.using the deleteLast..\ndeleting Last data..\n");
             L = deleteLast(L);
            }
             
            break;

            case 6:
            if(L.count == 0){
                printf("\nnothing to delete im sorry...\n");
            } else {
                printf("\n.using the deletePos..\nInput index of data to delete");
            scanf("%d", &cloc);
            L = deletePos(L, cloc);
            }
            
            break;

            case 7:
            if(L.count == 0){
                printf("\nnothing to locate im sorry...\n");
            }  else {
            printf("\n using Locate...\nInput data to locate..\n");
            scanf("%d", &cloc);
            found = locate(L, cloc);
            if(found = -1){
                printf("\ndata is not there..\n");
            } else {
                printf("\n%d is there!..\n");
            }
            }
            
            break;
            

            case 8:
            printf("displaying data..\n");
            display(L);

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

List empty(List L){
    Node *current = L.head;
    Node *temp;
    while(current != NULL){
        temp = current;
        current = current->next;
        free(temp);
    }
    L.head = NULL;
    L.count = 0;
    return L;
}

List insertFirst(List list, int data){
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list.head;
    list.head = newNode;
    list.count++;
    return list;

}

List insertLast(List list, int data){
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if(list.head == NULL){
        list.head = newNode;
        list.count++;
        
    } else {
        Node* current = list.head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
        list.count++;
    }
    return list;
}

List insertPos(List list, int data, int index){
    if(index <= list.count){
        if(index == 0){
            list =insertFirst(list, data);
        } else if(index == list.count){
            list = insertLast(list, data);
        } else {
            Node* newNode = malloc(sizeof(Node));
            newNode->data = data;
            Node* current = list.head;
            for(int i = 0; i < index - 1 && current->next != NULL; i++){
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
            list.count++;
        }
        return list;
    }
}

List deleteFirst(List list){
    Node* current = list.head;
    list.head = list.head->next;
    free(current);
    list.count--;
    return list;

}

List deleteLast(List list){
    if(list.count == 1){
        free(list.head);
        list.head = NULL;
        list.count--;
        return list;
    }
    Node* current = list.head;
    for(int i = 0; i < list.count - 2; i++){
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    list.count--;
    return list;

}

List deletePos(List list, int index){
    if(index == 0){
        deleteFirst(list);
        return list;
    }

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

int retrieve(List list, int index){
    if(index >= list.count || index < 0){
        printf("Invalid index");
        return -1;
    }

    Node* current = list.head;
    for(int i = 0; i < index; i++){
        current = current->next;
    }
    return current->data;

}

int locate(List list, int data){

    int retval = -1;
    if(list.head != NULL){
    Node* current;
    int index = 0;
    for(current = list.head; current != NULL; index++){
        if(current->data == data){
            retval = index;
        }
        current = current->next;
    }
    }
    
    return retval;

}

void display(List list){
    Node *current = list.head;
    for(int i = 0; i < list.count; i++){
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL");
}