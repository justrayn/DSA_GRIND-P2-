#include <stdio.h>
#include <stdlib.h>
#include "given.h"

// write your function here

void bubbleSortLinkedList(Node *head){
    
    Node *ptr;
    int temp;
    int swapped;
    if(head == NULL || head->next == NULL){
        printf("cannot sort it its too much for me!\n");
    } else {
        do{
            swapped = 0;
            for(ptr = head; ptr->next != NULL; ptr = ptr->next){
                if(ptr->data > ptr->next->data){
                    temp = ptr->data;
                    ptr->data = ptr->next->data;
                    ptr->next->data = temp;
                    swapped = 1;
                }
            }
            
        }while(swapped);
    }
}