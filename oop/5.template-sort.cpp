// Write a function template for selection sort that inputs, sorts and outputs an
// integer array and a float array.

#include <iostream>
using namespace std;

// Template function for selection sort
template <typename T>
void selectionSort(T arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the elements
        T temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Template function to display an array
template <typename T>
void displayArray(T arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice;
    cout << "Selection Sort Program\n";
    cout << "1. Integer Array\n";
    cout << "2. Float Array\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        // Input integer array
        int size;
        cout << "Enter the size of the integer array: ";
        cin >> size;

        int intArr[size];
        cout << "Enter " << size << " integers: ";
        for (int i = 0; i < size; ++i) {
            cin >> intArr[i];
        }

        cout << "Original Integer Array: ";
        displayArray(intArr, size);

        selectionSort(intArr, size);

        cout << "Sorted Integer Array: ";
        displayArray(intArr, size);

    } else if (choice == 2) {
        // Input float array
        int size;
        cout << "Enter the size of the float array: ";
        cin >> size;

        float floatArr[size];
        cout << "Enter " << size << " floats: ";
        for (int i = 0; i < size; ++i) {
            cin >> floatArr[i];
        }

        cout << "Original Float Array: ";
        displayArray(floatArr, size);

        selectionSort(floatArr, size);

        cout << "Sorted Float Array: ";
        displayArray(floatArr, size);

    } else {
        cout << "Invalid choice! Exiting program." << endl;
    }

    return 0;
}
