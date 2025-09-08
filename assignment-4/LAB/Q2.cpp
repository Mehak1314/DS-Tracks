#include<iostream>
using namespace std;

#define SIZE 10   // max size of queue

class Queue {
    int arr[SIZE];
    int front, rear;
public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void isFull() {
        if ((front == 0 && rear == SIZE - 1) || (front == (rear + 1) % SIZE)) {
            cout << "Queue is full" << endl;
        } else {
            cout << "Queue is not full" << endl;
        }
    }

    void isEmpty() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "Queue is not empty" << endl;
        }
    }

    void enqueue(int x) {
        if ((front == 0 && rear == SIZE - 1) || (front == (rear + 1) % SIZE)) {
            cout << "Queue is full. Cannot enqueue " << x << endl;
            return;
        }
        if (front == -1) { // first element
            front = 0;
        }
        rear = (rear + 1) % SIZE;
        arr[rear] = x;
        cout << x << " is added" << endl;
    }

    void dequeue() {
        if (front == -1) {
            cout << "Queue is Empty" << endl;
            return;
        }
        cout << arr[front] << " deleted from Queue." << endl;
        if (front == rear) { // only one element
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }

    void peek() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
        } else {
            cout << arr[front] << " is your Peek element" << endl;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    cout << "\nQUEUE MENU" << endl;
    int choice, val;
    do {
        cout << "\nEnter operation you want to perform: \n"
             << "1. IsFull\n2. IsEmpty\n3. Enqueue\n4. Dequeue\n5. Peek\n6. Display Queue\n0. Exit\n\nEnter: ";
        cin >> choice;
        switch (choice) {
        case 1:
            q.isFull();
            break;
        case 2:
            q.isEmpty();
            break;
        case 3:
            cout << "Enter element to add in queue: ";
            cin >> val;
            q.enqueue(val);
            break;
        case 4:
            q.dequeue();
            break;
        case 5:
            q.peek();
            break;
        case 6:
            q.display();
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 0);
}
