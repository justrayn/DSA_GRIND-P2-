#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    char name[20];
    int age;
} Person;

typedef struct {
    Person elem[MAX];
    int count;
} List;

List initialize (List L);
List insertPos (List L, Person data, int position);
List deletePos(List L, int position);
int locate (List L, Person data);
List insertSorted (List L, Person data);
void display(List L);

int main (){
    List L;
    L = initialize(L);

    while(1){
        int op, cLoc, found;
        Person p;

        printf("\nplease choose what kind of operation...\n\n");
        printf("1: Insert\n");
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

        case 1:
            if(L.count >= MAX){
                printf("Can't insert. List is full.\n");
            }else{

                printf("Enter name: ");
                scanf("%s", p.name);

                printf("Enter age: ");
                scanf("%d", &p.age);

                printf("Enter position (0-%d): ", L.count);
                scanf("%d", &cLoc);

                L = insertPos(L, p, cLoc);
            }
        break;

        case 2:
            if(L.count == 0){
                printf("Nothing to delete.\n");
            }else{
                printf("Enter position to delete: ");
                scanf("%d", &cLoc);

                L = deletePos(L, cLoc);
            }
        break;

        case 3:
            if(L.count == 0){
                printf("List is empty.\n");
            }else{

                printf("Enter age to locate: ");
                scanf("%d", &p.age);

                found = locate(L, p);

                if(found != -1){
                    printf("Person found at index %d\n", found);
                }else{
                    printf("Person not found.\n");
                }
            }
        break;

        case 4:
            if(L.count >= MAX){
                printf("List is full.\n");
            }else{

                printf("Enter name: ");
                scanf("%s", p.name);

                printf("Enter age: ");
                scanf("%d", &p.age);

                L = insertSorted(L, p);
            }
        break;

        case 5:
            if(L.count == 0){
                printf("List is empty.\n");
            }else{
                display(L);
            }
        break;

        default:
            printf("Invalid option.\n");
        }
    }

    return 0;
}
List initialize (List L){
    L.count = 0;
    return L;
}

List insertPos (List L, Person data, int position){
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

int locate (List L, Person data){
    int i;
    int found = -1;
    // Comparing based on age (or you could use strcmp for names)
    for(i = 0; i < L.count && L.elem[i].age != data.age; i++){}
    if( i < L.count){
        found = i;
    }
    return found;
}

List insertSorted (List L, Person data){
    if(L.count >= MAX){
        printf("List is full.\n");
    } else{
        int i;
        // Sorting by age
        for(i = L.count-1; i >= 0 && L.elem[i].age > data.age; i--){
            L.elem[i+1] = L.elem[i];
        }
        L.elem[i+1] = data;
        L.count++;
    }
    return L;
}

void display(List L){
    printf("List:\n");
    for(int i = 0; i < L.count; i++){
        printf("[%d] %s, %d\n", i, L.elem[i].name, L.elem[i].age);
    }
}