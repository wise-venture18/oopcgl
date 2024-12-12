//Q. Write C++ program using STL for sorting and searching user defined records such as
// personal records (Name, DOB, Telephone number etc) using vector container.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Structure to store personal records
struct PersonalRecord {
    string name;
    string dob;
    string telephone;

    // Display record
    void display() {
        cout << "Name: " << name << ", DOB: " << dob << ", Telephone: " << telephone << endl;
    }
};

// Function to sort records by name
bool compareByName(PersonalRecord a, PersonalRecord b) {
    return a.name < b.name;
}

// Function to search for a record by name
void searchByName(vector<PersonalRecord> records, string name) {
    bool found = false;
    for (int i = 0; i < records.size(); i++) {
        if (records[i].name == name) {
            cout << "Record found:" << endl;
            records[i].display();
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Record not found." << endl;
    }
}

int main() {
    vector<PersonalRecord> records;
    int choice;

    do {
        // Menu options
        cout << "\nMenu:\n1. Add Record\n2. Display All Records\n3. Sort Records by Name\n4. Search Record by Name\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // to clear the newline character from the input buffer

        if (choice == 1) {
            PersonalRecord record;
            cout << "Enter Name: ";
            getline(cin, record.name);
            cout << "Enter Date of Birth (DD/MM/YYYY): ";
            getline(cin, record.dob);
            cout << "Enter Telephone Number: ";
            getline(cin, record.telephone);
            records.push_back(record);
            cout << "Record added successfully." << endl;
        } 
        else if (choice == 2) {
            // Display all records
            cout << "\nAll Records:" << endl;
            for (int i = 0; i < records.size(); i++) {
                records[i].display();
            }
        } 
        else if (choice == 3) {
            // Sort records by name
            sort(records.begin(), records.end(), compareByName);
            cout << "Records sorted by name." << endl;

            // Display sorted records
            cout << "\nSorted Records:" << endl;
            for (int i = 0; i < records.size(); i++) {
                records[i].display();
            }
        } 
        else if (choice == 4) {
            // Search for a record by name
            string searchName;
            cout << "Enter name to search: ";
            getline(cin, searchName);
            searchByName(records, searchName);
        } 
        else if (choice == 5) {
            cout << "Exiting program." << endl;
        } 
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
