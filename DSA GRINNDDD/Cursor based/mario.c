#define MAX 15
#include <stdio.h>
#include <stdlib.h>

typedef char string[50];
typedef struct{
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
    string Name;
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
    int Avail;
}VirtualList;

typedef struct {
    int List;
    int count;
}RaceList;
int main(){
    return 0;
}
void initialize(VirtualList *V);
int allocSpace(VirtualList *V);
void deallocSpace(VirtualList *V, int index);

//create the enQ and deQ for the inventory space, should be a circular queue
// you can add a sacrficial space 
//insertion and deletion 
int main(){

    return 0;
}

void initialize(VirtualList *V){
    for(int i = 0; i < MAX -1 ;i++){
        V->List[i].next = i + 1;
    }
    V->List[MAX -1].next = -1;
    V->Avail = 0;
}

// ================= ALLOC =================
int allocSpace(VirtualList *V){
    // int temp = V->avail;

    // if(temp != -1){
    //     V->avail = V->H[temp].next;
    // }

    // return temp;

    if(V->Avail != -1){
        V->Avail
    }
}

// ================= DEALLOC =================
void deallocSpace(VirtualList *V, int index){
    // V->H[index].next = V->avail;
    // V->avail = index;
}