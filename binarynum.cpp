#include <iostream>
using namespace std;

// Node structure for doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Doubly linked list class
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
    	head = NULL;
    	tail = NULL;
	}

    // Function to insert a binary digit at the end of the list
    void insertBinaryDigit(int bit) {
        Node* newNode = new Node{bit, NULL, NULL};
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Function to display the binary number
    void display() {
        Node* current = head;
        while (current) {
            cout << current->data;
            current = current->next;
        }
        cout << endl;
    }

    // Function to compute 1's complement
    void onesComplement() {
        Node* current = head;
        while (current) {
            current->data = 1 - current->data;
            current = current->next;
        }
    }

    // Function to compute 2's complement
    void twosComplement() {
        onesComplement();
        int carry = 1;
        Node* current = tail;

        while (current && carry) {
            int sum = current->data + carry;
            current->data = sum % 2;
            carry = sum / 2;
            current = current->prev;
        }
    }

    // Function to add two binary numbers
//    DoublyLinkedList addBinary(DoublyLinkedList& binaryNum) {
//        DoublyLinkedList result;
//        int carry = 0;
//
//        Node* a = tail;
//        Node* b = binaryNum.tail;
//
//        while (a || b || carry) {
//            int sum = (a ? a->data : 0) + (b ? b->data : 0) + carry;
//            result.insertBinaryDigit(sum % 2);
//            carry = sum / 2;
//
//            if (a) a = a->prev;
//            if (b) b = b->prev;
//        }
//
//        return result;
//    }
};

int main() {
    // Example usage
    DoublyLinkedList binaryNum1, binaryNum2;

    // Insert binary digits for the first number
    binaryNum1.insertBinaryDigit(1);
    binaryNum1.insertBinaryDigit(0);
    binaryNum1.insertBinaryDigit(1);

    // Insert binary digits for the second number
    binaryNum2.insertBinaryDigit(1);
    binaryNum2.insertBinaryDigit(1);
    binaryNum2.insertBinaryDigit(1);

    cout << "Binary Number 1: ";
    binaryNum1.display();

    cout << "Binary Number 2: ";
    binaryNum2.display();

    // Compute and display 1's complement of binaryNum1
    binaryNum1.onesComplement();
    cout << "1's Complement of Binary Number 1: ";
    binaryNum1.display();

    // Compute and display 2's complement of binaryNum2
    binaryNum2.twosComplement();
    cout << "2's Complement of Binary Number 2: ";
    binaryNum2.display();

    // Add binaryNum1 and binaryNum2
//    DoublyLinkedList sum = binaryNum1.addBinary(binaryNum2);
//    cout << "Sum of Binary Numbers: ";
//    sum.display();

    return 0;
}

