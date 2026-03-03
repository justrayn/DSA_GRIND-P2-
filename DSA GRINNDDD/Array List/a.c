#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10;

typedef struct {
    int elem[MAX];
    int count;
}Etype, *Eptr;

void init(Eptr L);
void insert