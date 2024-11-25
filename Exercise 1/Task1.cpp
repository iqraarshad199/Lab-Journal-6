#include<iostream>
using namespace std;

class Stack {
private:
	int* arr;
	int top;
	int size;
public:
	Stack(int s) {
		arr = new int[s];
		size = s;
		top = -1;
	}
	bool isEmpty() {
		if (top == -1)
			return true;
		else
			return false;
	}
	void push(int val) {
		if (top == size - 1) {
			cout << "\t\t\tStack overflow." << endl;
		}
		else {
			arr[++top] = val;
		}
	}
	int pop() {
		if (top == -1) {
			cout << "\t\t\tStack underflow." << endl;
		}
		else {
			return arr[top--];
		}
	}
	void dectobin(int num) {
		if (num == 0) {
			cout << "\t\t\tBinary representation: 0" << endl;
			return;
		}
		while (num > 0) {
			push(num % 2);
			num = num / 2;
		}
		cout << "\t\t\tBinary representation : ";
		while (!isEmpty()) {
			cout << pop();
		}
	}
	void dectooct(int num) {
		if (num == 0) {
			cout << "\t\t\tOctal representation : 0";
		}
		while (num > 0) {
			push(num % 8);
			num = num / 8;
		}
		cout << "\n\t\t\tOctal representation : ";
		while (!isEmpty()) {
			cout << pop();
		}
	}
};

int main() {
	cout << "\n\t\t\t===============================Lab Joural 6=============================" << endl;
	int n;
	cout << "\n\t\t\tEnter a decimal number:";
	cin >> n;
	Stack stack(32);
	stack.dectobin(n);
	stack.dectooct(n);

	cout << "\n\t\t\t========================================================================" << endl;
	return 0;
}
