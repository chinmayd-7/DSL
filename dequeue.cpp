#include <iostream>
using namespace std;

class Deque {
private:
    int* arr;
    int capacity;
    int front;
    int rear;

public:
    Deque(int size) {
        capacity = size;
        arr = new int[capacity];
        front = -1;
        rear = 0;
    }

    ~Deque() {
        delete[] arr;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (front == -1 && rear == capacity - 1) || (front == rear + 1);
    }

    void insertFront(int item) {
        if (isFull()) {
            cout << "Deque is full" << endl;
            return;
        }

        if (isEmpty()) { // If the deque is empty
            front = 0;
            rear = 0;
        } else if (front == 0) { // If front is at the start
            front = capacity - 1;
        } else { // Move front to the previous position
            front--;
        }

        arr[front] = item;
    }

    void insertRear(int item) 
    {
        if (isFull()) {
            cout << "Deque is full" << endl;
            return;
        }

        if (isEmpty()) { // If the deque is empty
            front = 0;
            rear = 0;
        } else if (rear == capacity - 1) { // If rear is at the end
            rear = 0;
        } else { // Move rear to the next position
            rear++;
        }

        arr[rear] = item;
    }

    int deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return -1; // Indicating an error
        }

        int item = arr[front];
        if (front == rear) { // If the deque has only one element
            front = -1;
            rear = -1;
        } else if (front == capacity - 1) { // If front is at the end
            front = 0;
        } else { // Move front to the next position
            front++;
        }

        return item;
    }

    int deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return -1; // Indicating an error
        }

        int item = arr[rear];
        if (front == rear) { // If the deque has only one element
            front = -1;
            rear = -1;
        } else if (rear == 0) { // If rear is at the start
            rear = capacity - 1;
        } else { // Move rear to the previous position
            rear--;
        }

        return item;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return -1; // Indicating an error
        }
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return -1; // Indicating an error
        }
        return arr[rear];
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return;
        }

        cout << "Deque elements are: ";
        if (rear >= front) {
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        } else {
            for (int i = front; i < capacity; i++) {
                cout << arr[i] << " ";
            }
            for (int i = 0; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
};

// Example usage
int main() {
    Deque deque(5);

    deque.insertRear(10);
    deque.insertRear(20);
    deque.insertFront(5);
    deque.display(); // Output: 5 10 20

    cout << "Deleted from front: " << deque.deleteFront() << endl; // Output: 5
    deque.display(); // Output: 10 20

    cout << "Deleted from rear: " << deque.deleteRear() << endl; // Output: 20
    deque.display(); // Output: 10 

    return 0;
}