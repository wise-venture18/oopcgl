// Imagine a publishing company which does marketing for book and audio 
// cassette versions. Create a class publication that stores the title (a string) and 
// price (type float) of publications. From this class derive two classes: book which 
// adds a page count (type int) and tape which adds a playing time in minutes (type 
// float). Write a program that instantiates the book and tape class, allows user to 
// enter data and displays the data members. If an exception is caught, replace all 
// the data member values with zero values.

#include <iostream>
#include <string>
using namespace std;

// Base class Publication
class Publication {
protected:
    string title;
    float price;

public:
    Publication() : title(""), price(0.0) {}

    void setData() {
        // Input data
        cout << "Enter title: ";
        cin >> title;  // Using cin to input string (without spaces)

        cout << "Enter price: ";
        cin >> price;  // Using cin to input float

        // Error handling
        if (title.empty()) {
            throw "Title cannot be empty";  // Throwing an error if title is empty
        }
        if (price < 0) {
            throw "Price cannot be negative";  // Throwing an error if price is negative
        }
    }

    void display() const {
        cout << "Title: " << title << ", Price: " << price << endl;
    }
};

// Derived class Book
class Book : public Publication {
private:
    int pageCount;

public:
    Book() : pageCount(0) {}

    void setData() {
        Publication::setData();
        // Input data
        cout << "Enter page count: ";
        cin >> pageCount;

        // Error handling
        if (pageCount < 0) {
            throw "Page count cannot be negative";  // Throwing an error if page count is negative
        }
    }

    void display() const {
        Publication::display();
        cout << "Page Count: " << pageCount << endl;
    }
};

// Derived class Tape
class Tape : public Publication {
private:
    float playingTime;

public:
    Tape() : playingTime(0.0) {}

    void setData() {
        Publication::setData();
        // Input data
        cout << "Enter playing time (in minutes): ";
        cin >> playingTime;

        // Error handling
        if (playingTime < 0) {
            throw "Playing time cannot be negative";  // Throwing an error if playing time is negative
        }
    }

    void display() const {
        Publication::display();
        cout << "Playing Time: " << playingTime << " minutes" << endl;
    }
};

int main() {
    Book book;
    Tape tape;

    int choice;
    bool bookAdded = false, tapeAdded = false;

    do {
        // Displaying menu
        cout << "\n--- Menu ---\n";
        cout << "1. Add Book Details\n";
        cout << "2. Add Tape Details\n";
        cout << "3. Display Book Details\n";
        cout << "4. Display Tape Details\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        try {
            if (choice == 1) {
                cout << "\nEnter Book Details:\n";
                book.setData();  // Input book data
                bookAdded = true;  // Mark book data as added
            }
            else if (choice == 2) {
                cout << "\nEnter Tape Details:\n";
                tape.setData();  // Input tape data
                tapeAdded = true;  // Mark tape data as added
            }
            else if (choice == 3 && bookAdded) {
                cout << "\nBook Details:\n";
                book.display();  // Display book data
            }
            else if (choice == 4 && tapeAdded) {
                cout << "\nTape Details:\n";
                tape.display();  // Display tape data
            }
            else if (choice == 3 && !bookAdded) {
                cout << "Book details not entered yet.\n";
            }
            else if (choice == 4 && !tapeAdded) {
                cout << "Tape details not entered yet.\n";
            }
            else if (choice == 5) {
                cout << "Exiting program.\n";  // Exit the menu loop
            }
            else {
                cout << "Invalid choice, please try again.\n";  // Invalid input handling
            }
        }
        catch (const char* msg) {
            // Exception handling
            cout << "Error: " << msg << endl;
            // Resetting data members to default zero values
            book = Book();  // Reset book data to default values
            tape = Tape();  // Reset tape data to default values
            cout << "Data has been reset due to error.\n";
        }

    } while (choice != 5);  // Repeat the menu until 'Exit' is selected

    return 0;
}
