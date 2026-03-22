#ifndef PLAYLIST_H
#define PLAYLIST_H

#define MAX_SONGS 10

typedef struct {
    char song_name[50];
    char artist[50];
    int next;
} SongNode;

typedef struct {
    SongNode nodes[MAX_SONGS];
    int avail;
} VHeap;

typedef int List;

void initVHeap(VHeap *vh);
int allocSpace(VHeap *vh);
void freeSpace(VHeap *vh, int index);

void insertEnd(List *L, VHeap *vh, char song[], char artist[]);
void deleteSong(List *L, VHeap *vh, char song[]);
void displayList(List L, VHeap vh);

#endif