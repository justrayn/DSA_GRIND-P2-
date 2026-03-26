#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 8
//computer word bite vertor

void initialize(unsigned char *set);
void insert(unsigned  char *set, int elem);
void delete(unsigned char *set, int element);
bool find(unsigned char set, int elem);
unsigned char setUnion(unsigned char A, unsigned char B);
unsigned char intersection(unsigned char A, unsigned char B);
unsigned char difference(unsigned char A, unsigned char B);

int main(){

    unsigned char s;
    initiatlize(&s);


    return 0;
}


void initialize(unsigned char *set){
    *set = 0;
}
void insert(unsigned  char *set, int elem){
    if(elem >= 0 && elem < MAX){
        
    }
}
void delete(unsigned char *set, int element){

}
bool find(unsigned char set, int elem){

}
unsigned char setUnion(unsigned char A, unsigned char B){

}
unsigned char intersection(unsigned char A, unsigned char B){

}
unsigned char difference(unsigned char A, unsigned char B){

}