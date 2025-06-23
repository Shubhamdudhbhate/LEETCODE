#include <iostream>
#include <vector>
using namespace std;

class MyCircularQueue {
private:
    vector<int> q;
    int front, rear, size, capacity;

public:
    MyCircularQueue(int k) {
        q.resize(k);
        capacity = k;
        front = -1;
        rear = -1;
        size = 0;
    }

    bool enQueue(int value) {
        if (isFull()) return false;

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }

        q[rear] = value;
        size++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;

        if (front == rear) {
            front = rear = -1; // queue becomes empty
        } else {
            front = (front + 1) % capacity;
        }

        size--;
        return true;
    }

    int Front() {
        return isEmpty() ? -1 : q[front];
    }

    int Rear() {
        return isEmpty() ? -1 : q[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};


int main() {
    CircularQueue cq(3);

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);

    cout << "Front: " << cq.getFront() << endl; // 10

    cq.dequeue(); // remove 10
    cq.enqueue(40); // wraps around

    cout << "Front: " << cq.getFront() << endl; // 20

    return 0;
}
