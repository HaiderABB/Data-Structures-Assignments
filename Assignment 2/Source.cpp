#include <iostream>
using namespace std;

// Define a structure to represent a customer
struct Customer {
    int items;
    int age;
    Customer* next;

    Customer(int items, int age) : items(items), age(age), next(nullptr) {}
};

// Define a custom priority queue data structure based on age
class PriorityQueue {
private:
    Customer* front;
    Customer* rear;

public:
    PriorityQueue() : front(nullptr), rear(nullptr) {}

    // Enqueue a customer based on age and item count
// Enqueue a customer based on age and item count
    void enqueue(int items, int age) {
        Customer* newCustomer = new Customer(items, age);

        if (!front || front->age > age || (front->age == age && front->items > items)) {
            newCustomer->next = front;
            front = newCustomer;
            if (!rear) {
                rear = front;
            }
        }
        else {
            Customer* current = front;
            Customer* previous = nullptr;

            while (current && (current->age < age || (current->age == age && current->items <= items))) {
                previous = current;
                current = current->next;
            }

            if (!previous) {
                newCustomer->next = front;
                front = newCustomer;
            }
            else {
                previous->next = newCustomer;
                newCustomer->next = current;

                if (!current) {
                    rear = newCustomer;
                }
            }
        }
    }

    // Dequeue the customer with the highest priority (oldest customer)
    void dequeue() {
        if (front) {
            Customer* temp = front;
            front = front->next;
            delete temp;
        }
        if (!front) {
            rear = nullptr; // Update rear if the queue is empty
        }
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Display the customers in the queue
    void displayQueue() {
        Customer* current = front;
        while (current) {
            cout << "Items: " << current->items << ", Age: " << current->age << endl;
            current = current->next;
        }
    }

    Customer* getFront() {
        return front;
    }
};

int main() {
    PriorityQueue queues[4]; // Four priority queues

    for (int i = 0; i < 4; i++) {
        int items, age;

        cout << "Enter the number of items for the initial customer in Queue " << i + 1 << ": ";
        cin >> items;

        cout << "Enter the age for the initial customer in Queue " << i + 1 << ": ";
        cin >> age;

        queues[i].enqueue(items, age);
        cout << "Customer placed in Queue " << i + 1 << endl;
    }

    while (true) {
        int items, age;

        cout << "Enter the number of items (or -1 to exit): ";
        cin >> items;

        if (items == -1) {
            break;
        }

        cout << "Enter the age: ";
        cin >> age;

        int shortestQueue = 0; // Initialize with the first queue
        int maxItems = -1;

        for (int i = 0; i < 4; i++) {
            if (queues[i].isEmpty()) {
                shortestQueue = i;
                break;
            }
            else if (queues[i].getFront()->age > age) {
                shortestQueue = i;
                break;
            }
            else if (queues[i].getFront()->age == age && (maxItems == -1 || queues[i].getFront()->items < maxItems)) {
                shortestQueue = i;
                maxItems = queues[i].getFront()->items;
            }
        }

        queues[shortestQueue].enqueue(items, age);
        cout << "Customer placed in Queue " << shortestQueue + 1 << endl;

        // Display the contents of all four queues
        cout << "Current Queue Status:" << endl;
        for (int i = 0; i < 4; i++) {
            cout << "Queue " << i + 1 << ":\n";
            if (queues[i].isEmpty()) {
                cout << "No customers in this queue.\n";
            }
            else {
                queues[i].displayQueue();
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}