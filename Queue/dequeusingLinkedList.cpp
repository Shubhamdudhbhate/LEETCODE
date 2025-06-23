#include <iostream>
using namespace std;

// Node definition
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

// Deque class using doubly linked list
class Deque {
private:
    Node* front;
    Node* rear;

public:
    Deque() {
        front = rear = nullptr;
    }

    // Insert at front
    void pushFront(int val) {
        Node* newNode = new Node(val);
        if (!front) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    // Insert at rear
    void pushBack(int val) {
        Node* newNode = new Node(val);
        if (!rear) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
    }

    // Delete from front
    void popFront() {
        if (!front) {
            cout << "Deque is empty\n";
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front)
            front->prev = nullptr;
        else
            rear = nullptr; // deque became empty

        delete temp;
    }

    // Delete from rear
    void popBack() {
        if (!rear) {
            cout << "Deque is empty\n";
            return;
        }

        Node* temp = rear;
        rear = rear->prev;

        if (rear)
            rear->next = nullptr;
        else
            front = nullptr; // deque became empty

        delete temp;
    }

    // Get front element
    int getFront() {
        if (!front) {
            cout << "Deque is empty\n";
            return -1;
        }
        return front->data;
    }

    // Get rear element
    int getRear() {
        if (!rear) {
            cout << "Deque is empty\n";
            return -1;
        }
        return rear->data;
    }

    // Check if deque is empty
    bool isEmpty() {
        return front == nullptr;
    }
};

// Demo
int main() {
    Deque dq;

    dq.pushBack(10);
    dq.pushBack(20);
    dq.pushFront(5);
    dq.pushFront(2);

    cout << "Front: " << dq.getFront() << endl; // 2
    cout << "Rear: " << dq.getRear() << endl;   // 20

    dq.popFront(); // remove 2
    dq.popBack();  // remove 20

    cout << "After pops:\n";
    cout << "Front: " << dq.getFront() << endl; // 5
    cout << "Rear: " << dq.getRear() << endl;   // 10

    return 0;
}
