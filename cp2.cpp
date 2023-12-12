#include<iostream>
using namespace std;

class CircularQueue {
private:
    int front, rear, maxSize;
    int* arr;

public:
    CircularQueue(int size) {
        maxSize = size + 1; // One extra space to differentiate between front and rear.
        arr = new int[maxSize];
        front = rear = 0;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    bool isEmpty() {
        return front == rear;
    }

    bool isFull() {
        return (rear + 1) % maxSize == front;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot accept more orders." << endl;
            return;
        }

        arr[rear] = value;
        rear = (rear + 1) % maxSize;
        cout << "Order " << value << " placed successfully." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "No orders to serve." << endl;
            return;
        }

        int order = arr[front];
        front = (front + 1) % maxSize;
        cout << "Order " << order << " served." << endl;
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "No orders in the queue." << endl;
            return;
        }

        cout << "Orders in the queue: ";
        int i = front;
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % maxSize;
        }
        cout << endl;
    }
};

int main() {
    int maxOrders;
    cout << "Enter the maximum number of orders the pizza parlor can accept: ";
    cin >> maxOrders;

    CircularQueue pizzaQueue(maxOrders);

    int choice, order;
    do {
        cout << "\nPizza Parlor System\n";
        cout << "1. Place an order\n";
        cout << "2. Serve an order\n";
        cout << "3. Display orders\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (!pizzaQueue.isFull()) {
                    cout << "Enter the order number: ";
                    cin >> order;
                    pizzaQueue.enqueue(order);
                } else {
                    cout << "Queue is full. Cannot accept more orders." << endl;
                }
                break;

            case 2:
                pizzaQueue.dequeue();
                break;

            case 3:
                pizzaQueue.displayQueue();
                break;

            case 4:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

