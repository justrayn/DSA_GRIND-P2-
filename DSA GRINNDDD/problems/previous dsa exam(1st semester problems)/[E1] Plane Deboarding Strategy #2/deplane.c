#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

void deplanePassengers(BoardingList* list) {
    printf("\nDeplaning passengers...\n");
    bool prevLeftTurn = false;  // Start with left group
    bool leftTurn = true;       // Start with left group

    int row = 0;
    while (list->passengerCount > 0) {
        row = 0;
        leftTurn = prevLeftTurn = !prevLeftTurn;
        while (row < MAX_ROWS) {
            Group* currentGroup =
                leftTurn ? &list->seatRows[row].ABC : &list->seatRows[row].DEF;
            bool groupHasPassengers = leftTurn ? !isEmpty_v1(currentGroup)
                                               : !isEmpty_v2(currentGroup);

            if (groupHasPassengers) {
                // Deplane all passengers from the current group
                while (leftTurn ? !isEmpty_v1(currentGroup)
                                : !isEmpty_v2(currentGroup)) {
                    int idx = leftTurn
                                  ? currentGroup->top
                                  : (currentGroup->top >= 0 &&
                                             currentGroup->top < MAX_PASSENGERS
                                         ? currentGroup->top
                                         : 0);
                    printf("Deplaning %s from row %d, seat %s\n",
                           currentGroup->p[idx].passengerName, row + 1,
                           leftTurn ? "ABC" : "DEF");
                    if (leftTurn) {
                        pop_v1(currentGroup);
                    } else {
                        pop_v2(currentGroup);
                    }
                    list->passengerCount--;
                }
                leftTurn = !leftTurn;  // Switch sides for next group
                row += 3;              // Skip two rows
            } else {
                // If current group is empty, check opposite group
                Group* oppositeGroup = leftTurn ? &list->seatRows[row].DEF
                                                : &list->seatRows[row].ABC;
                bool oppositeHasPassengers = leftTurn
                                                 ? !isEmpty_v2(oppositeGroup)
                                                 : !isEmpty_v1(oppositeGroup);
                if (oppositeHasPassengers) {
                    // Deplane all passengers from the current group
                    while (leftTurn ? !isEmpty_v2(oppositeGroup)
                                    : !isEmpty_v1(oppositeGroup)) {
                        int idx =
                            leftTurn
                                ? (oppositeGroup->top >= 0 &&
                                           oppositeGroup->top < MAX_PASSENGERS
                                       ? oppositeGroup->top
                                       : 0)
                                : oppositeGroup->top;
                        printf("Deplaning %s from row %d, seat %s\n",
                               oppositeGroup->p[idx].passengerName, row + 1,
                               leftTurn ? "DEF" : "ABC");
                        if (leftTurn) {
                            pop_v2(oppositeGroup);
                        } else {
                            pop_v1(oppositeGroup);
                        }
                        list->passengerCount--;
                    }
                    row += 3;  // Skip two rows
                } else {
                    // Both groups are empty, move to the next row
                    row++;
                }
            }
        }
    }
    printf("\nAll passengers have been deplaned.\n");
}