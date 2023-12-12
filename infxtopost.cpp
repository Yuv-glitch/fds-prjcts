#include <iostream>
#include <cctype>  // for isalnum
#include <cstring> // for strlen

using namespace std;

class Stack {
private:
    int maxSize;
    int top;
    char* stackArray;

public:
//    Stack(int size) : maxSize(size), top(-1) {
//        stackArray = new char[maxSize];
//    }
	Stack(int size){
		maxSize = size;
		top = -1;
		stackArray = new char[maxSize];
	}

    ~Stack() {
        delete[] stackArray;
    }

    bool isFull() const {
        return top == maxSize - 1;
    }

    bool isEmpty() const {
        return top == -1;
    }

    void push(char value) {
        if (!isFull()) {
            stackArray[++top] = value;
            // ++top increments the value of top and returns the new value
            // top++ also increments but it will return the value before incrementation
        }
    }

    char pop() {
        if (!isEmpty()) {
            return stackArray[top--];
        }
        return '\0'; // '\0' represents an empty character (null character)
    }

    char peek() const {
        if (!isEmpty()) {
            return stackArray[top];
        }
        return '\0';
    }
};

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int getPrecedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0; // for '(' (lowest precedence)
}

string infixToPostfix(const char* infix) {
    Stack s(strlen(infix));
    string postfix;

    for (int i = 0; i < strlen(infix); ++i) {
        char c = infix[i];

        if (isalnum(c)) {
            postfix += c; // Operand, add to postfix
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix += s.pop();
            }
            s.pop(); // Pop the '('
        } else if (isOperator(c)) {
            while (!s.isEmpty() && getPrecedence(s.peek()) >= getPrecedence(c)) {
                postfix += s.pop();
            }
            s.push(c);
        }
    }

    // Pop any remaining operators from the stack
    while (!s.isEmpty()) {
        postfix += s.pop();
    }

    return postfix;
}

int main() {
    const char* infix_expression = "a + b * (c ^ d - e) / f";
    string postfix_expression = infixToPostfix(infix_expression);
    
    cout << "Infix Expression: " << infix_expression << endl;
    cout << "Postfix Expression: " << postfix_expression << endl;

    return 0;
}

