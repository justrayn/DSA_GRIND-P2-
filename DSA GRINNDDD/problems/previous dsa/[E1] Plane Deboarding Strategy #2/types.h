#ifndef TYPES_H
#define TYPES_H

#include <stdbool.h>

#define MAX_ROWS 8
#define MAX_PASSENGERS 3

typedef struct {
    char passengerName[30];
} Passenger;

// Stack definition
typedef struct {
    Passenger p[MAX_PASSENGERS];
    int top;
} Group;

typedef struct {
    Group ABC;  // Array Stack V1 (bottom is A)
    Group DEF;  // Array Stack V2 (bottom is F)
} Row;

typedef struct {
    Row seatRows[MAX_ROWS];
    int passengerCount;
} BoardingList;


// function prototypes
void initializeStack_v1(Group* g);
bool isFull_v1(Group* g);
bool isEmpty_v1(Group* g);
void push_v1(Group* g, char* value);
void pop_v1(Group* g);
void initializeStack_v2(Group* g);
bool isFull_v2(Group* g);
bool isEmpty_v2(Group* g);
void push_v2(Group* g, char* value);
void pop_v2(Group* g);
void deplanePassengers(BoardingList* list);

// hidden
void displayBoardingList(const BoardingList* list);
void initializeBoardingList1(BoardingList* list);
void initializeBoardingList2(BoardingList* list);
void initializeBoardingList3(BoardingList* list);
void initializeBoardingList4(BoardingList* list);

#endif