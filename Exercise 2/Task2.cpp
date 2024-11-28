#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Stack {
private:
    char* arr; 
    int top;          
    int size;     

public:
    // Constructor
    Stack(int s) {
        size = s;
        arr = new char[size];
        top = -1; 
    }

    // Destructor
    ~Stack() {
        delete[] arr; 
    }

    // Push an element onto the stack
    void push(char ch) {
        if (top < size - 1) {
            arr[++top] = ch;
        }
        else {
            cout << "Stack overflow!" << endl;
        }
    }

    // Pop an element from the stack
    char pop() {
        if (top >= 0) {
            return arr[top--];
        }
        else {
            cout << "Stack underflow!" << endl;
            return '\0'; 
        }
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }
};

void reverseString(string&inputFile, string&outputFile) {
    ifstream inFile(inputFile);
    if (!inFile) {
        cout << "Error opening input file." << endl;
        return;
    }

    string String;
    getline(inFile, String);
    inFile.close();

    Stack charStack(String.length());

    // Push all characters onto the stack
    for (int i = 0; i < String.length();++i) {
        charStack.push(String[i]);
    }

    // Pop characters from the stack to form the reversed string
    string reversedString;
    while (!charStack.isEmpty()) {
        reversedString += charStack.pop();
    }

    // Write the reversed string to the output file
    ofstream outFile(outputFile);
    if (!outFile) {
        cout << "Error opening output file." << endl;
        return;
    }

    outFile << reversedString;
    outFile.close();
}

int main() {
    string inputFile = "input.txt";
    string outputFile = "output.txt";

    reverseString(inputFile, outputFile);

    cout << "\n\t\tString reversed and written to " << outputFile << endl;

    cout << "\n\t\t=================================================" << endl;
    return 0;
}