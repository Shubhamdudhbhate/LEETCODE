#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularQueue {
private:
    Node* front;
    Node* rear;

public:
    CircularQueue() {
        front = rear = nullptr;
    }

    // Enqueue
    void enqueue(int val) {
        Node* newNode = new Node(val);

        if (!front) {
            front = rear = newNode;
            rear->next = front;
        } else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front;
        }
    }

    // Dequeue
    void dequeue() {
        if (!front) {
            cout << "Queue is empty\n";
            return;
        }

        // Only one node
        if (front == rear) {
            delete front;
            front = rear = nullptr;
        } else {
            Node* temp = front;
            front = front->next;
            rear->next = front;
            delete temp;
        }
    }

    // Display all elements
    void display() {
        if (!front) {
            cout << "Queue is empty\n";
            return;
        }

        Node* temp = front;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);
        cout << endl;
    }

    // Get front element
    int getFront() {
        if (!front) {
            cout << "Queue is empty\n";
            return -1;
        }
        return front->data;
    }
};

int main() {
    CircularQueue cq;
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);

    cq.display(); // 10 20 30

    cq.dequeue();
    cq.display(); // 20 30

    cout << "Front: " << cq.getFront() << endl;

    return 0;
}
