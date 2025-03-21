//this is for automate library operations such as book cataloging, issue tracking, and fine calculation.
// Including graphical user interfaces (GUIs) using libraries like QT.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define a structure to represent a book
struct Book {
    string title;
    string author;
    int id;
    bool isAvailable;
};

// Define a structure to represent a member
struct Member {
    string name;
    int id;
    vector<Book*> borrowedBooks;
};

// Function to add a new book to the library
void addBook(vector<Book>& library) {
    Book newBook;
    cout << "Enter book title: ";
    getline(cin >> ws, newBook.title);
    cout << "Enter author name: ";
    getline(cin >> ws, newBook.author);
    cout << "Enter book ID: ";
    cin >> newBook.id;
    newBook.isAvailable = true;

    library.push_back(newBook);
    cout << "Book added successfully!" << endl;
}

// Function to lend a book to a member
void lendBook(vector<Book>& library, vector<Member>& members) {
    int memberId, bookId;
    cout << "Enter member ID: ";
    cin >> memberId;
    cout << "Enter book ID: ";
    cin >> bookId;

    // Search for the member
    Member* member = nullptr;
    for (auto& m : members) {
        if (m.id == memberId) {
            member = &m;
            break;
        }
    }
    if (!member) {
        cout << "Member not found." << endl;
        return;
    }

    // Search for the book
    Book* book = nullptr;
    for (auto& b : library) {
        if (b.id == bookId) {
            book = &b;
            break;
        }
    }
    if (!book) {
        cout << "Book not found." << endl;
        return;
    }

    if (book->isAvailable) {
        book->isAvailable = false;
        member->borrowedBooks.push_back(book);
        cout << "Book successfully lent to " << member->name << "." << endl;
    } else {
        cout << "Book is already lent out." << endl;
    }
}

// Function to display all books in the library
void displayBooks(const vector<Book>& library) {
    cout << "Library Books:" << endl;
    for (const auto& book : library) {
        cout << "Title: " << book.title << ", Author: " << book.author << ", ID: " << book.id;
        if (book.isAvailable) {
            cout << " (Available)" << endl;
        } else {
            cout << " (Not Available)" << endl;
        }
    }
}

int main() {
    vector<Book> library;
    vector<Member> members;
    int choice;

    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Lend Book\n";
        cout << "3. Display Books\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cin.ignore(); // Ignore the newline character left by cin
                addBook(library);
                break;
            case 2:
                lendBook(library, members);
                break;
            case 3:
                displayBooks(library);
                break;
            case 4:
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice. Please enter a number from 1 to 4." << endl;
        }
    } while (choice != 4);

    return 0;
}