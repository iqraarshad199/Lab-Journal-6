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
    }

    // Pop an element from the stack
    char pop() {
        if (top >= 0) {
            return arr[top--];
        }
        else {
            cout << "\n\t\tStack underflow." << endl;
            return -1;
        }
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return top == -1;
    }
};

// Function to verify parentheses in an expression read from a file
void verifyExpressionFromFile(const string& inputFile) {
    ifstream inFile(inputFile);
    if (!inFile) {
        cout << "\n\t\tError opening input file." << endl;
        return;
    }

    string exp;
    getline(inFile, exp); 

    Stack s(exp.size());

    for (int i = 0; i < exp.size(); i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            s.push(exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (s.isEmpty()) {
                cout << "\n\t\tInvalid expression" << endl;
                return; 
            }
            else {
                s.pop(); 
            }
        }
    }

    // Check for unmatched opening brackets left in the stack
    if (!s.isEmpty()) {
        cout << "\n\t\tInvalid expression" << endl;
        return; 
    }

    cout << "\n\t\tValid expression" << endl;
}

int main() {
    const string inputFile = "input.txt"; 

    verifyExpressionFromFile(inputFile); 

    cout << "\n\t\t======================================================" << endl;
    return 0;
}