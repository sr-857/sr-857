#include <stdio.h>
#include <stdlib.h>

struct Song
{
    int songID;
    char songName[100];
    struct Song *next;
};

struct Song *head = NULL;

/* Add a new song */
void addSong()
{
    struct Song *newSong;
    struct Song *temp;

    newSong = (struct Song *)malloc(sizeof(struct Song));

    if (newSong == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter Song ID: ");
    scanf("%d", &newSong->songID);

    printf("Enter Song Name: ");
    scanf(" %[^\n]", newSong->songName);

    newSong->next = NULL;

    /* If playlist is empty */
    if (head == NULL)
    {
        head = newSong;
    }
    else
    {
        /* Move to the last song */
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        /* Attach new song at the end */
        temp->next = newSong;
    }

    printf("Song added to playlist successfully.\n");
}

/* Delete a song by ID */
void deleteSong()
{
    struct Song *temp;
    struct Song *previous;
    int id;

    printf("Enter Song ID to delete: ");
    scanf("%d", &id);

    temp = head;
    previous = NULL;

    /* Search for the song */
    while (temp != NULL && temp->songID != id)
    {
        previous = temp;
        temp = temp->next;
    }

    /* Song not found */
    if (temp == NULL)
    {
        printf("Song not found.\n");
        return;
    }

    /* If first song is being deleted */
    if (previous == NULL)
    {
        head = temp->next;
    }
    else
    {
        previous->next = temp->next;
    }

    free(temp);

    printf("Song deleted successfully.\n");
}

/* Search a song by ID */
void searchSong()
{
    struct Song *temp;
    int id;

    printf("Enter Song ID to search: ");
    scanf("%d", &id);

    temp = head;

    while (temp != NULL)
    {
        if (temp->songID == id)
        {
            printf("\nSong Found!\n");
            printf("Song ID   : %d\n", temp->songID);
            printf("Song Name : %s\n", temp->songName);
            return;
        }

        temp = temp->next;
    }

    printf("Song with ID %d not found.\n", id);
}

/* Display all songs */
void displayPlaylist()
{
    struct Song *temp;
    int position = 1;

    if (head == NULL)
    {
        printf("Playlist is empty.\n");
        return;
    }

    temp = head;

    printf("\n========== PLAYLIST ==========\n");

    while (temp != NULL)
    {
        printf("%d. Song ID   : %d\n", position, temp->songID);
        printf("   Song Name : %s\n", temp->songName);
        printf("------------------------------\n");

        position++;
        temp = temp->next;
    }
}

/* Main function */
int main()
{
    int choice;

    while (1)
    {
        printf("\n========== MUSIC PLAYER ==========\n");
        printf("1. Add Song\n");
        printf("2. Delete Song\n");
        printf("3. Search Song\n");
        printf("4. Display Playlist\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addSong();
                break;

            case 2:
                deleteSong();
                break;

            case 3:
                searchSong();
                break;

            case 4:
                displayPlaylist();
                break;

            case 5:
                printf("Exiting music player...\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
