#include <stdio.h>
#include <string.h>
#include "header.h"

void initVHeap(VHeap *vh) {
    for (int i = 0; i < MAX_SONGS - 1; i++) {
        vh->nodes[i].next = i + 1;
    }
    vh->nodes[MAX_SONGS - 1].next = -1;
    vh->avail = 0;
}

int allocSpace(VHeap *vh) {
    int index = vh->avail;
    if (index != -1) {
        vh->avail = vh->nodes[index].next;
    }
    return index;
}

void freeSpace(VHeap *vh, int index) {
    vh->nodes[index].next = vh->avail;
    vh->avail = index;
}

void displayList(List L, VHeap vh) {
    if (L == -1) {
        printf("Playlist is empty.\n");
        return;
    }

    printf("\n--- Playlist ---\n");
    int temp = L;
    while (temp != -1) {
        printf("%s by %s\n",
               vh.nodes[temp].song_name,
               vh.nodes[temp].artist);
        temp = vh.nodes[temp].next;
    }
}