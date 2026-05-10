#include <stdio.h>
#include <stdlib.h>


unsigned char bittoword(bool Arr[]){
    unsigned char sample = 0;
    for(int i = 0; i < 8; i++){
        if(arr[i] == true){
            sample = sample | (1 << i);
        }
    }
}

void wordtobitVector(unsigned char c, bool arr[]){
    for(int i = 0; i < 8; i++){
        if(c & (1 << i) != 0){
            arr[i] = true;
        } else {
            arr[i] = false;
        }
    }
}