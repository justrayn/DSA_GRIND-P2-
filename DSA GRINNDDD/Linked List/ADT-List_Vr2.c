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
 List *L = initialize();
    
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
            insertFirst(L, cdata);
            break;
            
            case 2:
             printf("\n.using the insertLast..\n Input data to insert: ");
             scanf("%d", &cdata);
             insertLast(L, cdata);
            break;

            case 3:
             printf("\n.using the insertPos..\n Input data to insert: ");
              scanf("%d", &cdata);
              printf("\nwhat position?(0-%d)", L->count);
              scanf("%d", &cloc);
              insertPos(L, cdata, cloc);
            break;

            case 4:
            if(L->count == 0){
                printf("\nnothing to delete im sorry...\n");
            } else {
                printf("\n.using the deleteFirst..\ndeleting first data..\n");
            deleteStart(L);
            }
            break;

            case 5:
            if(L->count == 0){
                printf("\nnothing to delete im sorry...\n");
            } else {
                printf("\n.using the deleteLast..\ndeleting Last data..\n");
             deleteLast(L);
            }
             
            break;

            case 6:
            if(L->count == 0){
                printf("\nnothing to delete im sorry...\n");
            } else {
                printf("\n.using the deletePos..\nInput index of data to delete");
            scanf("%d", &cloc);
            deletePos(L, cloc);
            }
            
            break;

            case 7:
            if(L->count == 0){
                printf("\nnothing to locate im sorry...\n");
            }  else {
            printf("\n using Locate...\nInput data to locate..\n");
            scanf("%d", &cloc);
            found = locate(L, cloc);
            if(found == -1){
                printf("\ndata is not there..\n");
            } else {
                printf("\n%d is there!..\n", cloc);
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
    if(index >= list->count || index < 0){
        printf("invalid\n");
    }
    else if(index == 0){
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