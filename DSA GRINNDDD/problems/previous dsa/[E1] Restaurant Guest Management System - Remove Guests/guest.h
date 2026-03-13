#ifndef GUEST_H
#define GUEST_H

#define NUMTABLES 10

typedef enum {VIP, Regular} category;

typedef struct {
    char guestID[3];
    char name[30];
    category guestType;
    int tableNumber; // Tables from 0 - 9
} guest;

typedef struct tableNode{
    guest G;
    struct tableNode* nextTable;
} tableNode, *tableList;

typedef struct{
    tableList front;
    tableList end;
} table;

void initTable(table* T);
void initAllTables(table T[]);
void displayTableList(tableList TL, int tableNum);
void categorizeGuests(guest G[], int numGuests, table T[]);
void getGuests(guest G[], int size);
void removeGuests(guest G[], int numGuests, table T[]);

#endif