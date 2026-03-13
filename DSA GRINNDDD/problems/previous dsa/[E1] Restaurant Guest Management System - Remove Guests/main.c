#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "guest.h"

void removeGuests(guest G[], int numGuests, table T[])
{
    int i, tableNum;
    tableList temp, *trav;
    
    for(i = 0; i < numGuests; i++){
        // Search all tables since we only have guest ID
        for(tableNum = 0; tableNum < NUMTABLES; tableNum++){
            for(trav = &T[tableNum].front; *trav != NULL && strcmp((*trav)->G.guestID, G[i].guestID) != 0; trav = &(*trav)->nextTable){}
            if(*trav != NULL){
                temp = *trav;
                *trav = temp->nextTable;
                
                // Update end pointer if we removed the last node
                if(temp == T[tableNum].end){
                    if(T[tableNum].front == NULL){
                        // List is now empty
                        T[tableNum].end = NULL;
                    } else {
                        // Find new last node
                        tableList travEnd = T[tableNum].front;
                        while(travEnd->nextTable != NULL){
                            travEnd = travEnd->nextTable;
                        }
                        T[tableNum].end = travEnd;
                    }
                }
                
                free(temp);
                // break; // Found and removed, move to next guest
            }
        }
    }
}

int main(void) {
    table tables[NUMTABLES];
    guest guestList[20] = {
        {"01", "Alice Tan",        VIP,     3},
        {"02", "Brian Cruz",       Regular, 1},
        {"03", "Catherine Lee",    VIP,     2},
        {"04", "David Santos",     Regular, 4},
        {"05", "Ella Martinez",    VIP,     1},
        {"06", "Frank Lim",        Regular, 3},
        {"07", "Grace Yu",         VIP,     2},
        {"08", "Henry Dela Cruz",  Regular, 4},
        {"09", "Isabelle Ong",     VIP,     3},
        {"10", "Jack Rivera",      Regular, 2},
        {"11", "Karen Sy",         VIP,     1},
        {"12", "Leo Mendoza",      Regular, 4},
        {"13", "Mika Tanaka",      VIP,     3},
        {"14", "Nathan Cruz",      Regular, 2},
        {"15", "Olivia Perez",     VIP,     1},
        {"16", "Paul Santos",      Regular, 4},
        {"17", "Queenie Lo",       VIP,     5},
        {"18", "Ryan Torres",      Regular, 6},
        {"19", "Sophia Wang",      VIP,     8},
        {"20", "Tommy Villanueva", Regular, 0}
    };
    guest guestListRemove[5];
    int i;
    
    initAllTables(tables);
    categorizeGuests(guestList, 20, tables);
    printf("INITIAL TABLE LIST\n");
    for(i = 0; i < NUMTABLES; i++){
        displayTableList(tables[i].front, i);
    }
    
    getGuests(guestListRemove, 5);
    removeGuests(guestListRemove, 5, tables);
    
    
    printf("AFTER REMOVE\n");
    for(i = 0; i < NUMTABLES; i++){
        displayTableList(tables[i].front, i);
    }
    
    return 0;
}