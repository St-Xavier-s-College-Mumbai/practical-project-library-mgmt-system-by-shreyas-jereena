#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct {
    int id;             // Unique ID for each book
    char title[50];     // Title of the book
    char author[50];    // Author of the book
    int isAvailable;     // 1 for available, 0 for issued
} Book;

Book library[MAX_BOOKS];
int bookCount = 0;

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("\n📚✨ The Library is full! No space for more books! ✨📚\n");
        return;
    }
    printf("\n🎉✨ Adding a New Book! ✨🎉\n");
    
    // Input book ID
    printf("📖 Enter book ID: ");
    scanf("%d", &library[bookCount].id);
    
    // Input book title
    printf("\n📖 Enter book title: ");
    scanf(" %[^\n]", library[bookCount].title);
    
    // Input book author
    printf("✍️ Enter book author: ");
    scanf(" %[^\n]", library[bookCount].author);
    
    library[bookCount].isAvailable = 1; // Mark as available
    bookCount++;
    printf("\n🎊🎉 Book added successfully! 🎉🎊\n");
}

void updateBookAvailability(const char* title, int issue) {
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].title, title) == 0) {
            if (library[i].isAvailable == issue) {
                printf("\n⚠️ The book is already %s! ⚠️\n", issue ? "available" : "issued");
            } else {
                library[i].isAvailable = issue;
                printf("\n✅ Book %s successfully! ✅\n", issue ? "returned" : "issued");
            }
            return;
        }
    }
    printf("\n❌ Book not found! ❌\n");
}

void checkAvailability() {
    char title[50];
    printf("\n🔍 Enter book title to check availability: ");
    scanf(" %[^\n]", title);
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].title, title) == 0) {
            printf("\n📘 Book '%s' is currently %s. 📘\n", library[i].title, 
                   library[i].isAvailable ? "Available 😊" : "Issued 😔");
            return;
        }
    }
    printf("\n❌ Book not found! ❌\n");
}

void listBooks() {
    printf("\n📚✨ Listing All Books in the Library! ✨📚\n");
    if (bookCount == 0) {
        printf("\n📖 No books available in the library! 📖\n");
        return;
    }
    for (int i = 0; i < bookCount; i++) {
        printf("\n📖 ID: %d\nTitle: %s\n✍️ Author: %s\n%s\n", 
               library[i].id, library[i].title, library[i].author, 
               library[i].isAvailable ? "🟢 Available" : "🔴 Issued");
    }
}

int main() {
    int choice;
    do {
        printf("\n🌟🌟🌟 WELCOME TO THE LIBRARY MANAGEMENT SYSTEM 🌟🌟🌟\n");
        printf("\n📋 Main Menu 📋\n");
        printf("1. ➕ Add Book\n");
        printf("2. 📤 Issue Book\n");
        printf("3. 📥 Return Book\n");
        printf("4. 🔍 Check Availability\n");
        printf("5. 📚 List Books\n");
        printf("6. 🚪 Exit\n");
        printf("\n👉 Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: {
                char title[50];
                printf("\n📤 Enter book title to issue: ");
                scanf(" %[^\n]", title);
                updateBookAvailability(title, 0); // Issue book
                break;
            }
            case 3: {
                char title[50];
                printf("\n📥 Enter book title to return: ");
                scanf(" %[^\n]", title);
                updateBookAvailability(title, 1); // Return book
                break;
            }
            case 4: checkAvailability(); break;
            case 5: listBooks(); break;
            case 6: printf("\n🚪 Exiting... Goodbye! 👋\n"); break;
            default: printf("\n❌ Invalid choice! Please try again. ❌\n");
        }
    } while (choice != 6);

    return 0;
}
