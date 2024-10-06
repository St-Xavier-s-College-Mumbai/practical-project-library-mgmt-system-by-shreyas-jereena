#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct {
    char title[50];
    char author[50];
    int isAvailable;
} Book;

Book library[MAX_BOOKS];
int bookCount = 0;

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("\nLibrary is full!\n");
        return;
    }
    printf("\nEnter book title: ");
    scanf(" %[^\n]", library[bookCount].title);
    printf("\nEnter book author: ");
    scanf(" %[^\n]", library[bookCount].author);
    library[bookCount].isAvailable = 1; // Available
    bookCount++;
    printf("\nBook added successfully!\n\n");
}

void issueBook() {
    char title[50];
    printf("\nEnter book title to issue: ");
    scanf(" %[^\n]", title);
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].title, title) == 0) {
            if (library[i].isAvailable) {
                library[i].isAvailable = 0; // Mark as issued
                printf("\nBook issued successfully!\n");
                return;
            } else {
                printf("\nBook is currently issued!\n");
                return;
            }
        }
    }
    printf("\nBook not found!\n");
}

void returnBook() {
    char title[50];
    printf("\nEnter book title to return: ");
    scanf(" %[^\n]", title);
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].title, title) == 0) {
            if (!library[i].isAvailable) {
                library[i].isAvailable = 1; // Mark as available
                printf("\nBook returned successfully!\n");
                return;
            } else {
                printf("\nBook was not issued!\n");
                return;
            }
        }
    }
    printf("\nBook not found!\n");
}

void checkAvailability() {
    char title[50];
    printf("\nEnter book title to check availability: ");
    scanf(" %[^\n]", title);
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].title, title) == 0) {
            if (library[i].isAvailable) {
                printf("\nBook is available.\n");
            } else {
                printf("\nBook is not available.\n");
            }
            return;
        }
    }
    printf("\nBook not found!\n\n");
}

void listBooks() {
    printf("\nListing all books:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("\nTitle: %s, Author: %s, %s\n", library[i].title, library[i].author, 
               library[i].isAvailable ? "Available\n\n" : "Issued\n\n");
    }
}

void searchBook() {
    char title[50];
    printf("\nEnter book title to search: ");
    scanf(" %[^\n]", title);
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].title, title) == 0) {
            printf("\nFound: Title: %s, Author: %s, %s\n", library[i].title, library[i].author, 
                   library[i].isAvailable ? "Available\n" : "Issued\n");
            return;
        }
    }
    printf("\nBook not found!\n\n");
}

int main() {
    int choice;
    do {
        printf("\n<<<<<<<<<<<<<<<<<<<< LIBRARY MANAGEMENT SYSTEM >>>>>>>>>>>>>>>>>>>>>>>>\n");

        printf("\n\n ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~  MAIN MENU  ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ \n");

        printf("\n1. Add Book\n");
        printf("2. Issue Book\n");
        printf("3. Return Book\n");
        printf("4. Check Availability\n");
        printf("5. List Books\n");
        printf("6. Search Book\n");
        printf("7. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: issueBook(); break;
            case 3: returnBook(); break;
            case 4: checkAvailability(); break;
            case 5: listBooks(); break;
            case 6: searchBook(); break;
            case 7: printf("Exiting...\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
