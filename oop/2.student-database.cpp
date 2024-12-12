// Develop a program in C++ to create a database of student’s information system 
// containing the following information: Name, roll number, Class, Division, Date of 
// Birth, Blood group, Contact address, Telephone number, Driving license no. and 
// other. Construct the database with suitable member functions. Make use of 
// constructor, default constructor, copy constructor, destructor, static member 
// functions, friend class, this pointer, inline code and dynamic memory allocation 
// operators-new and delete as well as exception handling.

#include <iostream>
#include <string>
using namespace std;

class Admin; // Forward declaration for friend class

class Student {
    string name, dob, bloodGroup, address, license, className, telephoneNumber, other;
    char division;
    int roll;
    static int count; // Static member for keeping track of student count

public:
    // Default constructor
    Student() : name(""), roll(0), className(""), division('A'), dob(""), bloodGroup(""),
                address(""), license(""), telephoneNumber(""), other("") {
        count++;  // Increment count when a student object is created
    }

    // Copy constructor
    Student(const Student &s) {
        *this = s; // Using this pointer
        count++;   // Increment count when a new student is created via copy
    }

    // Destructor
    ~Student() { 
        count--;  // Decrement count when a student object is destroyed
    }

    // Inline function to display student details
    inline void display() const {
        cout << "Name: " << name << "\nRoll: " << roll << "\nClass: " << className
             << "\nDivision: " << division << "\nDOB: " << dob << "\nBlood Group: "
             << bloodGroup << "\nAddress: " << address << "\nTelephone: " << telephoneNumber
             << "\nLicense: " << license << "\nOther: " << other << "\n";
    }

    // Static member function to get the student count
    static int getCount() { return count; }

    // Friend function to modify student details
    friend void modifyStudent(Student &s, int rollNo);

    // Friend class to access private members of Student
    friend class Admin;

    // Function to input student details from the user
    void inputDetails() {
        cout << "Enter Name: ";
        cin >> name;  // Input name
        cout << "Enter Roll: ";
        cin >> roll;  // Input roll

        cout << "Enter Class: ";
        cin >> className;  // Input class

        cout << "Enter Division (A/B/C): ";
        cin >> division;  // Input division

        cout << "Enter DOB: ";
        cin >> dob;  // Input DOB

        cout << "Enter Blood Group: ";
        cin >> bloodGroup;  // Input blood group

        cout << "Enter Address: ";
        cin >> address;  // Input address

        cout << "Enter Telephone: ";
        cin >> telephoneNumber;  // Input telephone

        cout << "Enter License: ";
        cin >> license;  // Input license

        cout << "Enter Other details: ";
        cin >> other;  // Input other details
    }
};

int Student::count = 0; // Static member initialization

// Friend function definition to modify student based on roll number
void modifyStudent(Student &s, int rollNo) {
    if (s.roll == rollNo) {
        cout << "Enter New Name and Roll: ";
        cin >> s.name >> s.roll;  // Modify student's name and roll
    } else {
        cout << "No student found with roll number " << rollNo << ".\n";
    }
}

// Friend class to demonstrate access to private members
class Admin {
public:
    // Method to update division using friend access
    void updateDivision(Student &s, char newDivision) {
        s.division = newDivision;
    }
};

int main() {
    Student student;  // Create a Student object directly
    Admin admin;  // Admin object to modify student data
    int choice;
    bool isStudentInitialized = false;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Add Student\n2. Display Student\n3. Modify Student\n4. Update Division\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        try {
            if (choice == 1) {
                student.inputDetails();  // Input student details from user
                isStudentInitialized = true;
            }
            else if (choice == 2 && isStudentInitialized) {
                student.display();  // Display student details
            }
            else if (choice == 3 && isStudentInitialized) {
                int rollNo;
                cout << "Enter Roll No to modify: ";
                cin >> rollNo;  // Get the roll number for modification
                modifyStudent(student, rollNo);  // Modify student details based on roll number
            }
            else if (choice == 4 && isStudentInitialized) {
                char newDiv;
                cout << "Enter new division: ";
                cin >> newDiv;
                admin.updateDivision(student, newDiv);  // Update division using friend class
            }
            else if (choice == 5) {
                cout << "Exiting.\n";  // Exit the menu loop
            }
            else {
                cout << "Invalid input or no student data.\n";  // Invalid input handling
            }

        } catch (const exception &e) {
            cout << "An error occurred: " << e.what() << "\n";  // Exception handling for any runtime errors
        }

    } while (choice != 5);  // Repeat the menu until 'Exit' is selected

    return 0;
}

    } while (choice != 5);  // Repeat the menu until 'Exit' is selected

    return 0;
}
