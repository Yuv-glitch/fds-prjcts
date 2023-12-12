#include <iostream>
using namespace std;
// Simple stack implementation using an array
class Stack {
private:
    static const int maxSize = 1000; // Adjust the size as needed
    char data[maxSize];
    int top;

public:
    Stack() {
    	top = -1;
	}
    void push(char value) {
        if (top < maxSize - 1) {
            data[++top] = value;
        }
    }

    char pop() {
        if (top >= 0) {
            return data[top--];
        }
        return '\0'; // Assuming null character for an empty stack
    }

    bool isEmpty() const {
        return top == -1;
    }
};

// Function to reverse a string using a stack
string reverseString(const string& input) {
    Stack charStack;

    // Push each character onto the stack
	for (int i = 0; i < input.length(); ++i) {
	    charStack.push(input[i]);
	}


    // Pop characters from the stack to form the reversed string
    string reversedString;
    while (!charStack.isEmpty()) {
        reversedString += charStack.pop();
    }

    return reversedString;
}

int main() {
    string originalString = "Hello, World!";
    string reversedString = reverseString(originalString);

    cout << "Original string: " << originalString << endl;
	cout << "Reversed string: " << reversedString << endl;

    return 0;
}

