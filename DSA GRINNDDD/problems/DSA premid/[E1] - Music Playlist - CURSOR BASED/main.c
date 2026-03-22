#include <stdio.h>
#include <string.h>
#include "header.h"

int main() {
    VHeap vh;
    List playlist = -1;
    int choice;
    char song[50], artist[50];

    initVHeap(&vh);

    do {
        printf("==== MUSIC PLAYLIST MENU ====\n");
        printf("1. Add Song\n");
        printf("2. Delete Song\n");
        printf("3. Display Playlist\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter song name: ");
                fgets(song, sizeof(song), stdin);
                song[strcspn(song, "\n")] = 0;

                printf("Enter artist: ");
                fgets(artist, sizeof(artist), stdin);
                artist[strcspn(artist, "\n")] = 0;

                insertEnd(&playlist, &vh, song, artist);
                break;

            case 2:
                printf("Enter song name to delete: ");
                fgets(song, sizeof(song), stdin);
                song[strcspn(song, "\n")] = 0;

                deleteSong(&playlist, &vh, song);
                break;

            case 3:
                displayList(playlist, vh);
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 4);

    return 0;
}