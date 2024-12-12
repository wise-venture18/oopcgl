// Write a C++ program that creates an output file, writes information to it, closes 
// the file, open it again as an input file and read the information from the file. 

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Create and write to an output file
    ofstream outFile("data.txt");
    if (!outFile) {
        cout << "Error opening file for writing!" << endl;
        return 1;
    }

    // Writing sample information to the file
    outFile << "Title: C++ Programming\n";
    outFile << "Author: John Doe\n";
    outFile << "Year: 2024\n";
    outFile << "Description: A comprehensive guide to learning C++ programming, including basic syntax, object-oriented principles, and advanced topics.\n";
    outFile.close();  // Close the output file after writing

    cout << "Data written to the file successfully." << endl;

    // Open the file again as an input file to read from it
    ifstream inFile("data.txt");
    if (!inFile) {
        cout << "Error opening file for reading!" << endl;
        return 1;
    }

    // Reading and displaying the content from the file
    string content;
    cout << "\nFile Content: \n";
    while (getline(inFile, content)) {
        cout << content << endl;
    }
    
    inFile.close();  // Close the input file after reading

    return 0;
}
