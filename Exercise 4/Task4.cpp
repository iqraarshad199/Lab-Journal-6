#include <iostream>
#include <fstream>
#include <string>
#include <cctype> 

using namespace std;

class Stack {
private:
    int* arr; 
    int top;         
    int size;    

public:
    // Constructor
    Stack(int s) {
        size = s;
        arr = new int[size];
        top = -1; 
    }

    // Destructor
    ~Stack() {
        delete[] arr; 
    }

    // Push an element onto the stack
    void push(int value) {
        if (top < size - 1) {
            arr[++top] = value;
        }
    }

    // Pop an element from the stack
    int pop() {
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

// Function to evaluate a postfix expression
/*
**Iterates through each character, pushing digits onto the stack and applying
operators to evaluate expressions.
*/
int evaluatePostfix(string& expression) {
    Stack stack(expression.length());

    for (int i = 0; i < expression.length();i++) {
        char ch = expression[i];
        if (isdigit(ch)) { 
            stack.push(ch - '0'); 
        }
        else { 
            int operand2 = stack.pop();
            int operand1 = stack.pop();
            switch (ch) {
            case '+':
                stack.push(operand1 + operand2);
                break;
            case '-':
                stack.push(operand1 - operand2);
                break;
            case '*':
                stack.push(operand1 * operand2);
                break;
            case '/':
                if (operand2 != 0) {
                    stack.push(operand1 / operand2);
                }
                else {
                    cout << "\n\t\tError: Division by zero." << endl;
                    return 0;
                }
                break;
            default:
                cout << "\n\t\tError: Unknown operator " << ch << endl;
                return 0;
            }
        }
    }

    return stack.pop(); 
}

// Function to read from file and evaluate expression
void evaluateExpression(string& inputFile) {
    ifstream inFile(inputFile);
    if (!inFile) {
        cout << "\n\t\tError opening input file." << endl;
        return;
    }

    string expression;
    getline(inFile, expression); 

    int result = evaluatePostfix(expression);

    cout << "\n\t\tPostfix Expression: " << expression << endl;
    cout << "\t\tResult: " << result << endl;

    inFile.close(); 
}

int main() {
    cout << "\n\t\t==========================================================" << endl;
    string inputFile = "input.txt"; 

    evaluateExpression(inputFile); 

    cout << "\n\t\t==========================================================" << endl;
    return 0;
}