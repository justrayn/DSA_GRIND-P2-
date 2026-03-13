#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "guest.h"

void initTable(table* T)
{
    T->front = T->end = NULL;
}

void initAllTables(table T[])
{
    int i;
    for(i = 0; i < NUMTABLES; i++){
        initTable(&T[i]);
    }
}

void displayTableList(tableList TL, int tableNum)
{
    printf("Table Number [%d]: ", tableNum);
    for(;TL != NULL; TL = TL->nextTable){
        printf("[%s] %s | ", TL->G.guestID, TL->G.name);
    }
    printf("\n");
}

void categorizeGuests(guest G[], int numGuests, table T[])
{
    int i;
    tableList temp;
    
    for (i = 0; i < numGuests; i++) {
        temp = (tableList) malloc(sizeof(tableNode));
        if (temp != NULL) {
            temp->G = G[i];
            temp->nextTable = NULL;
            if (T[G[i].tableNumber].front == NULL) {
                T[G[i].tableNumber].front = T[G[i].tableNumber].end = temp;
            } else if (G[i].guestType == VIP) {
                temp->nextTable = T[G[i].tableNumber].front;
                T[G[i].tableNumber].front = temp;
            } else {
                T[G[i].tableNumber].end->nextTable = temp;
                T[G[i].tableNumber].end = temp;
            }
        }
    }
}

void getGuests(guest G[], int size)
{
    int i;
    
    for(i = 0; i < size; i++){
        printf("[%d] Enter the ID of a guest to delete: ", i+1);
        scanf("%s", G[i].guestID);  // Fixed: removed & operator and added .guestID
        // Initialize other fields to avoid garbage values
        strcpy(G[i].name, "");
        G[i].guestType = Regular;
        G[i].tableNumber = 0;
    }
}