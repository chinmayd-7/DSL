#include <iostream>
using namespace std;

// Global constant for maximum number of orders
const int MAX_ORDERS = 4;

class PizzaParlor {
private:
    int* orders; // Array to hold order IDs
    int front;   // Index of the first order
    int rear;    // Index of the last order

public:
    // Constructor to initialize the circular queue
    PizzaParlor() {
        orders = new int[MAX_ORDERS];
        front = -1;
        rear = -1;
    }

    // Destructor to free memory
    ~PizzaParlor() {
        delete[] orders;
    }

    // Check if the queue is full
    bool isFull() {
        return ((rear + 1) % MAX_ORDERS == front);
    }

    // Check if the queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Add an order to the queue
    void addOrder(int orderID) {
        if (isFull()) {
            cout << "Cannot accept order " << orderID << ": The queue is full.\n";
            return;
        }

        if (isEmpty()) { // First order
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % MAX_ORDERS; // Circular increment
        }

        orders[rear] = orderID;
        cout << "Order " << orderID << " has been added.\n";
    }

    // Serve an order from the queue
    void serveOrder() {
        if (isEmpty()) {
            cout << "No orders to serve.\n";
            return;
        }

        cout << "Order " << orders[front] << " is served.\n";

        if (front == rear) { // Only one order in the queue
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_ORDERS; // Circular increment
        }
    }

    // Display the current orders in the queue without using `getQueueSize`
    void displayOrders() {
        if (isEmpty()) {
            cout << "No pending orders.\n";
            return;
        }

        cout << "Current orders: ";
        int index = front;
        while (index!=rear) {
            cout << orders[index] << " ";
            index = (index + 1) % MAX_ORDERS; // Circular increment
        }
        cout << orders[rear] << "\n";
        cout << endl;
    }
};

// Main function
int main() {
    PizzaParlor parlor;

    int choice, orderID;
    while (true) {
        cout << "\n1. Add Order\n2. Serve Order\n3. Display Orders\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter order ID: ";
                cin >> orderID;
                parlor.addOrder(orderID);
                break;
            case 2:
                parlor.serveOrder();
                break;
            case 3:
                parlor.displayOrders();
                break;
            case 4:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
