#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store book information
struct Book {
    int id;
    char title[50];
    char author[50];
    struct Book* next;  // Pointer to the next book in the linked list
};

struct Book* head = NULL;  // Global head pointer for the linked list

// Function to create a new book node
struct Book* createBook(int id, char title[], char author[]) {
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
    newBook->id = id;
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->next = NULL;
    return newBook;
}

// Function to add a new book to the library
void addBook(int id, char title[], char author[]) {
    struct Book* newBook = createBook(id, title, author);

    // Add the new book at the beginning of the linked list
    newBook->next = head;
    head = newBook;
    printf("Book added successfully!\n");
}

// Function to display all books in the library
void displayBooks() {
    struct Book* temp = head;

    if (temp == NULL) {
        printf("The library is empty!\n");
        return;
    }

    printf("\nList of books in the library:\n");
    while (temp != NULL) {
        printf("ID: %d, Title: %s, Author: %s\n", temp->id, temp->title, temp->author);
        temp = temp->next;
    }
}

// Function to delete a book by ID
void deleteBook(int id) {
    struct Book *temp = head, *prev = NULL;

    // If the book to be deleted is the head node
    if (temp != NULL && temp->id == id) {
        head = temp->next;
        free(temp);
        printf("Book with ID %d deleted successfully!\n", id);
        return;
    }

    // Search for the book with the given ID
    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    // If the book was not found
    if (temp == NULL) {
        printf("Book with ID %d not found!\n", id);
        return;
    }

    // Unlink the book from the list and free memory
    prev->next = temp->next;
    free(temp);
    printf("Book with ID %d deleted successfully!\n", id);
}

// Function to search for a book by its ID
void searchBook(int id) {
    struct Book* temp = head;

    // Search for the book with the given ID
    while (temp != NULL) {
        if (temp->id == id) {
            printf("Book found - ID: %d, Title: %s, Author: %s\n", temp->id, temp->title, temp->author);
            return;
        }
        temp = temp->next;
    }

    printf("Book with ID %d not found!\n", id);
}

int main() {
    int choice, id;
    char title[50], author[50];

    do {
        printf("\nLibrary Management System Menu:\n");
        printf("1. Add Book\n2. Display All Books\n3. Delete Book\n4. Search Book\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter book ID: ");
                scanf("%d", &id);
                printf("Enter book title: ");
                scanf(" %[^\n]%*c", title);  // Reading string with spaces
                printf("Enter book author: ");
                scanf(" %[^\n]%*c", author);  // Reading string with spaces
                addBook(id, title, author);
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                printf("Enter book ID to delete: ");
                scanf("%d", &id);
                deleteBook(id);
                break;
            case 4:
                printf("Enter book ID to search: ");
                scanf("%d", &id);
                searchBook(id);
                break;
            case 5:
                printf("Exiting the system...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
