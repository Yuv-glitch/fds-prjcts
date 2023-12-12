#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
class Queue {
	private:
		int arr[MAX_SIZE];
		int front,rear;
	public:
		Queue() {
			front = -1;
			rear = -1;
		}
	
	void push(int value){
		if (rear == MAX_SIZE - 1) {
			cout<<"Queue is full cannot add more elements" << endl;
			return;
		}
		
		if (front == -1){
			front ++;
		}
		arr[++rear] = value;
	}
	
	void pop() {
		if (front == -1){
			cout << "Queue is empty" << endl;
			return;
		}
		if (front == rear) {
			front = rear = -1;
			return;
		}
		int popped = arr[front];
		cout << popped << " popped from the queue" <<endl;
		front ++;
	}
	
	void display() {
		if (front == -1){
			cout << "Queue is empty" << endl;
			return;
		}
        for (int i = front; i <= rear; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
	}
	
};

int main() {
	int chc;
	Queue qu;
	do {
		cout << "QUEUE: " << endl;
		cout << "1 ADD" << endl;
		cout << "2 DELETE" << endl;
		cout << "3 DISPLAY" << endl;
		cout << "4 STOP" << endl;
		cin >> chc;
		switch(chc) {
			case 1:
				int i;
				cout << "Enter the element: ";
				cin >> i;
				qu.push(i);
				break;
			case 2:
				qu.pop();
				break;
			case 3:
				qu.display();
				break;
			default:
				if (chc != 4){
					cout << "Invalid operation" << endl;
				}
				break;
		}
	} while (chc != 4);
}
