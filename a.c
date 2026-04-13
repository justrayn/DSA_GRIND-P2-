#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 4
typedef char string[50];

typedef struct {
    string acct_name;
    string id;
}ign;

typedef struct {
    int speed;
    int accelaration;
    int weight;
    int reaction;
    int healing;
}Stats;

typedef struct {
    Stats body;
    Stats wheel;
    Stats parachute;
    Stats total;
}Car;


typedef struct{
    string charName;
    int weight;
}Character;

typedef struct{
    string name;
    string desc;
}Item;

typedef struct {
    ign handle;
    Character Selected;
    Car Chosen;
    Item inventory[3];
    int countINV;
    int coins;
}Player;

typedef struct {
    Player racer;
    int next;
}RacerNode;

typedef struct {
    RacerNode List[MAX];
    int avail;
}VHeap;

typedef struct {
    int List;
    int count;
}RaceList;

void initVHeap(VHeap* V);
int allocSpace(VHeap* V);
void deallocSpace(VHeap* V, int index);
void insertFirst(RaceList* L, VHeap* V,Player p);
void insertLast(RaceList* L, VHeap* V, Player p);
void insertPos(RaceList *L, VHeap *V, Player p, int pos);
void insertSorted(RaceList *L, VHeap *V, Player p);
void deleteFirst(RaceList *L, VHeap *V);
void deleteLast(RaceList *L, VHeap *V);
void deletePos(RaceList *L, VHeap *V, int pos);
void deleteByID(RaceList *L, VHeap *V, string id);
void additem(Player *p, Item I);
void useItem(Player *p);
void display(RaceList L, VHeap V);

int main(){
    VHeap V;
    RaceList RL = {-1, 0};

    initVHeap(&V);

    
    Player p1, p2, p3;

    strcpy(p1.handle.id, "P1");
    p1.coins = 50;
    p1.countINV = 0;

    strcpy(p2.handle.id, "P2");
    p2.coins = 30;
    p2.countINV = 0;

    strcpy(p3.handle.id, "P3");
    p3.coins = 70;
    p3.countINV = 0;

   
    insertSorted(&RL, &V, p1);
    insertSorted(&RL, &V, p2);
    insertSorted(&RL, &V, p3);

    printf("\n=== After InsertSorted ===\n");
    display(RL, V);

    
    deleteFirst(&RL, &V);

    printf("\n=== After deleteFirst ===\n");
    display(RL, V);

    
    Item i1 = {"Mushroom", "Speed Boost"};
    Item i2 = {"Shell", "Attack"};
    Item i3 = {"Banana", "Trap"};

    additem(&p1, i1);
    additem(&p1, i2);
    additem(&p1, i3);

    printf("\n=== Using Items (FIFO) ===\n");
    useItem(&p1);
    useItem(&p1);
    useItem(&p1);
    useItem(&p1); 
    return 0;
}

void initVHeap(VHeap* V){
    V->avail = 0;
    for(int i = 0; i < MAX - 1; i++){
        V->List[i].next = i + 1;
    }
    V->List[MAX - 1].next = -1;
}
int allocSpace(VHeap* V){
    int temp = V->avail;
    if(temp != -1){
        V->avail = V->List[temp].next;
    }
    return temp;
}
void deallocSpace(VHeap* V, int index){
    V->List[index].next = V->avail;
    V->avail = index;
}
void insertFirst(RaceList* L, VHeap* V,Player p){
    int new = allocSpace(V);
    if(new != -1){
        V->List[new].racer = p;
        V->List[new].next = L->List;
        L->List = new;
        L->count++;
    }
}
void insertLast(RaceList* L, VHeap* V, Player p){
    int new = allocSpace(V);

    if(new != -1){
        V->List[new].racer = p;
        V->List[new].next = -1;

        if(L->List == -1){
            L->List = new;
            L->count++;
        } else {
            int* trav;
            for(trav = &L->List; *trav != -1; trav = &V->List[*trav].next){}
            *trav = new;
            L->count++;
        }
    }
}
void insertPos(RaceList *L, VHeap *V, Player p, int pos){
    int new = allocSpace(V);

    if(new != -1){
        V->List[new].racer = p;

        int *trav = &L->List;

        for(int i = 0; i < pos && *trav != -1; i++){
            trav = &V->List[*trav].next;
        }

        V->List[new].next = *trav;
        *trav = new;

        L->count++;
    }
}
void insertSorted(RaceList *L, VHeap *V, Player p){
    int new = allocSpace(V);
    if(new != -1){
        V->List[new].racer = p;
        int *trav;
        for(trav = &L->List; *trav != -1 && V->List[*trav].racer.coins < p.coins; trav = &V->List[*trav].next){}
        V->List[new].next = *trav;
        *trav = new;
        L->count++;
    }
}
void deleteFirst(RaceList *L, VHeap *V){
    if(L->List != -1){
        int temp = L->List;
        L->List = V->List[temp].next;
        deallocSpace(V, temp);
        L->count--;
    }
}
void deleteLast(RaceList *L, VHeap *V){
    if(L->List != -1){
       if(V->List[L->List].next == -1){
            int temp = L->List;
            L->List = -1;
            deallocSpace(V, temp);
        } else {
            int *trav;
            for(trav = &L->List; V->List[*trav].next != -1; 
                trav = &V->List[*trav].next){}

            int temp = *trav;
            *trav = -1;
            deallocSpace(V, temp);
        }
        L->count--;
    }
}
void deletePos(RaceList *L, VHeap *V, int pos){
    if(pos >= 0 && pos < L->count){
        int *trav = &L->List;
        for(int i = 0; i < pos; i++, trav = &V->List[*trav].next){}
        int temp = *trav;
        *trav = V->List[temp].next;
        deallocSpace(V, temp);
        L->count--;
    }
}
void deleteByID(RaceList *L, VHeap *V, string id){
    if(L->List != -1){
        int *trav;
        for(trav = &L->List; *trav != -1 && strcmp(V->List[*trav].racer.handle.id, id) != 0; trav = &V->List[*trav].next ){}
        if(*trav != -1){
            int temp = *trav;
            *trav = V->List[temp].next;
            deallocSpace(V, temp);
            L->count--;
        }
    }
}
void additem(Player *p, Item I){
    
    if(p->countINV < 3){
        p->inventory[p->countINV] = I;
        p->countINV++;
    } else {
        printf("XX");
    }
}
void useItem(Player *p){
    if(p->countINV > 0){

        for(int i = 0; i < p->countINV - 1; i++){
            p->inventory[i] = p->inventory[i + 1];
        }
        p->countINV--;
    } else {
        printf("Inventory Empty!\n");
    }
}
void display(RaceList L, VHeap V){
    int trav = L.List;
    printf("players: ");

    while(trav != -1){
        printf("ID: %s | Coins: %d | Items: %d\n", V.List[trav].racer.handle.id, V.List[trav].racer.coins,  V.List[trav].racer.countINV);
        trav = V.List[trav].next;
    }
}