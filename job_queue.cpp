#include <iostream>
using namespace std;

const int MAX = 5;  // Maximum size of the job queue
int queue[MAX];     // Array representing the queue
int front = -1;     // Index of the front job
int rear = -1;      // Index of the rear job

// Function to check if the queue is full
bool isFull() {
    return rear == MAX - 1;
}

// Function to check if the queue is empty
bool isEmpty() {
    return front == -1 || front > rear;
}

// Function to add a job to the queue (enqueue)
void addJob(int job) {
    if (isFull()) {
        cout << "Queue is full. Cannot add job: " << job << endl;
        return;
    }

    // If the queue is empty, initialize front and rear
    if (front == -1) {
        front = 0;
    }

    // Add the job to the rear of the queue
    queue[++rear] = job;
    cout << "Added job " << job << " to the queue." << endl;
}

// Function to delete a job from the queue (dequeue)
void deleteJob() {
    if (isEmpty()) {
        cout << "Queue is empty. No jobs to delete." << endl;
        return;
    }

    cout << "Deleted job " << queue[front] << " from the queue." << endl;
    front++;  // Move the front pointer forward

    // Reset the queue if no jobs are left
    if (front > rear) {
        front = rear = -1;
    }
}

// Function to display the jobs in the queue
void displayQueue() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }

    cout << "Current jobs in the queue: ";
    for (int i = front; i <= rear; i++) {
        cout << queue[i] << " ";
    }
    cout << endl;
}

// Main function to simulate the job queue
int main() {
    int choice, job;

    while (true) {
        // Menu for operations on the job queue
        cout << "\n1. Add Job\n2. Delete Job\n3. Display Jobs\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:  // Add a job
                cout << "Enter job ID to add: ";
                cin >> job;
                addJob(job);
                break;

            case 2:  // Delete a job
                deleteJob();
                break;

            case 3:  // Display the current jobs in the queue
                displayQueue();
                break;

            case 4:  // Exit the program
                cout << "Exiting..." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please enter again." << endl;
        }
    }

    return 0;
}
