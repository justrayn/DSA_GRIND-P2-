#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

void initializeStack_v1(Group* g) { g->top = -1; }

bool isFull_v1(Group* g) { return g->top == MAX_PASSENGERS - 1; }

bool isEmpty_v1(Group* g) { return g->top == -1; }

void push_v1(Group* g, char* value) {
    if (isFull_v1(g)) {
        printf("Error: Group is full.\n");
    } else {
        strcpy(g->p[++(g->top)].passengerName, value);
    }
}

void pop_v1(Group* g) {
    if (isEmpty_v1(g)) {
        printf("Error: Group is empty.\n");
    } else {
        g->top--;
    }
}

void initializeStack_v2(Group* g) { g->top = MAX_PASSENGERS; }

bool isFull_v2(Group* g) { return g->top == 0; }

bool isEmpty_v2(Group* g) { return g->top == MAX_PASSENGERS; }

void push_v2(Group* g, char* value) {
    if (isFull_v2(g)) {
        printf("Error: Group is full.\n");
    } else {
        strcpy(g->p[--(g->top)].passengerName, value);
    }
}

void pop_v2(Group* g) {
    if (isEmpty_v2(g)) {
        printf("Error: Group is empty.\n");
    } else {
        g->top++;
    }
}