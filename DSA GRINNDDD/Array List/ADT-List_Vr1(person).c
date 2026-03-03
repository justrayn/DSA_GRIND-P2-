#include <stdio.h>
#include <string.h>

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
    List L = initialize(L);
    int operation;
    
    // Manual initialization of some data
    strcpy(L.elem[0].name, "Alice"); L.elem[0].age = 20;
    strcpy(L.elem[1].name, "Bob");   L.elem[1].age = 25;
    strcpy(L.elem[2].name, "Charlie"); L.elem[2].age = 30;
    L.count = 3;

    do {
        printf("\n1: Insert (Fixed Data)\n");
        printf("2: Delete\n");
        printf("3: Locate\n");
        printf("4: InsertSorted\n");
        printf("0: Exit\n");
        printf("Enter operation: ");
        scanf("%d", &operation);

        Person p1 = {"Dave", 22};
        Person p2 = {"Eve", 28};

        switch (operation){
            case 0:
                return 0;
            case 1:
                L = insertPos(L, p1, 1);
                display(L);
                printf("\nCount: %d\n", L.count);
                break;
            case 2:   
                L = deletePos(L, 1);
                display(L);
                printf("\nCount: %d\n", L.count);
                break;
            case 3:
                // Locating Alice
                int location = locate(L, L.elem[0]);
                if(location != -1){
                    printf("Data found at index %d\n", location);
                } else {
                    printf("Data not Found!\n");
                }
                display(L);
                break;
            case 4:
                L = insertSorted(L, p2);
                display(L);
                printf("\nCount: %d\n", L.count);
                break;
        }
    } while (operation != 0);

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